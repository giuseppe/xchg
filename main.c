/* xchg
 * Copyright (C) 2019 Giuseppe Scrivano
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  int ret;

  if (argc != 3)
    error (EXIT_FAILURE, 0, "please specify two arguments");

  ret = renameat2 (AT_FDCWD, argv[1], AT_FDCWD, argv[2], RENAME_EXCHANGE);
  if (ret < 0)
    error (EXIT_FAILURE, errno, "renameat2");

  exit (EXIT_SUCCESS);
}
