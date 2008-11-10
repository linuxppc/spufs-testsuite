/*
 * Testsuite for the Linux SPU filesystem
 *
 * Copyright (C) IBM Corporation, 2008
 *
 * Author: Jeremy Kerr <jk@ozlabs.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/**
 * Ensure we can only open the sputrace log file once.
 */
#define _ATFILE_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <fcntl.h>

#include <test/spu_syscalls.h>

int main(void)
{
	int trace_fd[2];

	trace_fd[0] = open("/proc/sputrace", O_RDONLY);
	assert(trace_fd[0] >= 0);

	trace_fd[1] = open("/proc/sputrace", O_RDONLY);
	if (trace_fd[1] >= 0) {
		fprintf(stderr, "open(/proc/sputrace) succeeded, "
				"expecting failure\n");
		return EXIT_FAILURE;
	}

	if (errno != EBUSY) {
		fprintf(stderr, "open(/proc/sputrace) failed with errno %d, "
				"expecting EBUSY(%d)\n", errno, EBUSY);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
