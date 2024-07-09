// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
  char *dest = destination;

  while (*source != '\0') {
    *dest = *source;
    dest++;
    source++;
  }

  *dest = '\0';

  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  char *dest = destination;

  while (*source != '\0' && len > 0) {
    *dest = *source;
    dest++;
    source++;
    len--;
  }

  while (len > 0) {
    *dest = '\0';
    dest++;
    len--;
  }

  return destination;
}

char *strcat(char *destination, const char *source) {
  char *dest = destination;

  while (*dest != '\0') {
    dest++;
  }

  while (*source != '\0') {
    *dest = *source;
    dest++;
    source++;
  }

  *dest = '\0';

  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  char *dest = destination;

  while (*dest != '\0') {
    dest++;
  }

  while (*source != '\0' && len > 0) {
    *dest = *source;
    dest++;
    source++;
    len--;
  }

  *dest = '\0';

  return destination;
}

int strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }

  if (*str1 == *str2) {
    return 0;
  } else if (*str1 < *str2) {
    return -1;
  } else {
    return 1;
  }

  return -1;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  while (len > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
    len--;
  }

  if (len == 0 || (*str1 == *str2)) {
    return 0;
  } else if (*str1 < *str2) {
    return -1;
  } else {
    return 1;
  }

  return -1;
}

size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++)
    ;

  return i;
}

char *strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == c) {
      return (char *)str;
    }
    str++;
  }

  return NULL;
}

char *strrchr(const char *str, int c) {
  char *last = NULL;

  while (*str != '\0') {
    if (*str == c) {
      last = (char *)str;
    }
    str++;
  }

  return (char *)last;
}

char *strstr(const char *haystack, const char *needle) {
  const char *h, *n;

    if (*needle == '\0')
        return (char *) haystack;

    while (*haystack != '\0')
    {
        h = haystack;
        n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0')
            return (char *) haystack;

        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }

  const char *last = NULL;

  while (*haystack != '\0') {
    const char *h = haystack;
    const char *n = needle;

    while (*n != '\0' && *h == *n) {
      h++;
      n++;
    }

    if (*n == '\0') {
      last = haystack;
    }

    haystack++;
  }
  return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num) {
  unsigned char *dest = (unsigned char *)destination;
  const unsigned char *src = (const unsigned char *)source;

  for (size_t i = 0; i < num; i++) {
    dest[i] = src[i];
  }
  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  unsigned char *dest = (unsigned char *)destination;
  const unsigned char *src = (const unsigned char *)source;

  if (dest < src) {
    for (size_t i = 0; i < num; i++) {
      dest[i] = src[i];
    }
  } else {
    for (size_t i = num; i > 0; i--) {
      dest[i - 1] = src[i - 1];
    }
  }

  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  const unsigned char *p1 = (const unsigned char *)ptr1;
  const unsigned char *p2 = (const unsigned char *)ptr2;

  for (size_t i = 0; i < num; i++) {
    if (p1[i] < p2[i]) {
      return -1;
    } else if (p1[i] > p2[i]) {
      return 1;
    }
  }

  return 0;
}

void *memset(void *source, int value, size_t num) {
  unsigned char *p = (unsigned char *)source;
  unsigned char byteValue = (unsigned char)value;

  for (size_t i = 0; i < num; i++) {
    p[i] = byteValue;
  }
  return source;
}
