// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
int sleep(unsigned int seconds)
{
    struct timespec t;
    t.tv_sec = seconds;
    t.tv_nsec = 0;
    nanosleep(&t, &t);
    return 0;
}
