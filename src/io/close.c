// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <unistd.h>

int close(int fd) {
  long returnValue = syscall(3, fd);

  if (returnValue >= 0) {
    return returnValue;
  }

  errno = -returnValue;
  return -1;
}
