// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <string.h>
int puts(const char *str)
{
    ssize_t ret =  write(1, str, strlen(str));
    ret = ret + write(1, "\n\0", 2);

    return ret;
}
