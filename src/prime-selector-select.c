/*
 * prime-selector-select.c
 * 
 * Copyright 2015 Jens Sauer <jsauer65@gmail.com>
 * 
 * This is a helper program for 'prime-selector'.
 * It will install with SUID flag as a result every user can
 * change the PRIME status via 'prime-select'.
 * 
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include <unistd.h>

int
main (int argc, char **argv)
{
  if (argc < 2)
    {
      printf ("usage: primeselect intel|nvidia\n");
      return 0;
    }
  if (strcmp (argv[1], "intel") == 0)
    {
      printf ("activate Intel GPU\n");
      /*
       * TODO:
       * Rewrite to be 'prime-select' independet
       * No error handling from 'prime-select'
       */
      execl ("/usr/bin/prime-select", "prime-select", "intel", NULL);
      return 0;
    }
  else if (strcmp (argv[1], "nvidia") == 0)
    {
      printf ("activate Nvidia GPU\n");
      /*
       * TODO:
       * Rewrite to be 'prime-select' independet
       * No error handling from 'prime-select'
       */
      execl ("/usr/bin/prime-select", "prime-select", "nvidia", NULL);
      return 0;
    }
  else
    {
      printf ("wrong argument:\nusage: primeselect intel|nvidia\n");
      return 0;
    }
  return 0;
}
