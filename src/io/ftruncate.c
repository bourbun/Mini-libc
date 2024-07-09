// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>
#include <internal/types.h>

int ftruncate(int fd, off_t length) {
  long returnValue = syscall(77, fd, length);

  if (returnValue >= 0) {
    return returnValue;
  }

  errno = -returnValue;
  return -1;
}
