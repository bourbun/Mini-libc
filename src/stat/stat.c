// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	long returnValue = syscall(4, path, buf);

    if (returnValue >= 0) {
        return returnValue;
    } else {
        errno = -returnValue;
        return -1;
    }
}

