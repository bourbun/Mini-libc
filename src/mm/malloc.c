// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    mem_list_add(ptr, size);
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void* ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    memset(ptr, 0, total_size);
    mem_list_add(ptr, total_size);
    return ptr;
}

void free(void *ptr)
{
	struct mem_list *aux = mem_list_find(ptr);
	if (aux == NULL) {
		return;
	}
	munmap(ptr, aux->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list *node = mem_list_find(ptr);

	void *new_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	memcpy(new_start, ptr, node->len);

	munmap(ptr, node->len);

	node->start = new_start;
	node->len = size;

	return new_start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
