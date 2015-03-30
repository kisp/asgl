// ASGL an abstract argumentation solver in ECL and GECODE.
// Copyright (C) 2015  Kilian Sprotte

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
#include "myfoo.h"

char *slurp_file(cl_object namestring, long *size) {
  char *path = ecl_base_string_pointer_safe(namestring);

  FILE *fp;
  long lSize;
  char *buffer;

  fp = fopen (path, "rb");
  if( !fp ) { perror(path); exit(1); }

  fseek( fp , 0L , SEEK_END);
  lSize = ftell( fp );
  rewind( fp );

  /* allocate memory for entire content */
  buffer = (char*)calloc( 1, lSize+1 );
  if( !buffer ) { fclose(fp); fputs("memory alloc fails",stderr); exit(1);}

  /* copy */
  if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

  fclose(fp);
  *size = lSize;
  return buffer;
}
