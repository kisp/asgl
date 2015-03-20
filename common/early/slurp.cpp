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
