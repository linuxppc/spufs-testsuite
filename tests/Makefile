# Testsuite for the Linux SPU filesystem
#
# Copyright (C) IBM Corporation, 2008
#
# Author: Jeremy Kerr <jk@ozlabs.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

dirs = 00-testsuite 02-spu_create 03-spu_run 04-context 05-gang		\
       06-context-lifetime 07-lsmap 08-reg-file 09-mailbox 10-syscalls	\
       11-coredump 12-nosched 13-affinity 14-dma 15-class0 16-debug	\
       18-save-restore 20-scheduler 21-sputrace

all: $(dirs)

# we want the sub-makefiles to use Makefile.lib, which includes the
# test dir's Makefile
MAKEFILES=../../lib/Makefile.lib

$(dirs) : % : %/Makefile
	@$(MAKE) -C $@ all

clean:
	for d in $(dirs); do ($(MAKE) -C $$d clean); done

.PHONY: all clean $(dirs)

