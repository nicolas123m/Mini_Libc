// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
int nanosleep(const struct timespec *req, struct timespec * rem)
{
    int ret = syscall(__NR_nanosleep, req, rem);

	if ( ret < 0 ) {
		errno = -ret;
		return -1;
	}

	return ret;
	return -1;
}
