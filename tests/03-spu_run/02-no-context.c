/*
 * Testsuite for the Linux SPU filesystem
 *
 * Copyright (C) IBM Corporation, 2007
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
#define _ATFILE_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>

#include <test/spu_syscalls.h>

int main(void)
{
	int rc, fd;
	uint32_t entry, status;

	fd = open("/dev/null", O_RDWR);
	assert(fd >= 0);

	rc = spu_run(fd, &entry, &status);

	if (rc != -1) {
		fprintf(stderr, "spu_run didn't fail\n");
		return EXIT_FAILURE;
	}

	if (errno != EINVAL) {
		fprintf(stderr, "spu_run failed with wrong errno (%d)\n",
				errno);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
