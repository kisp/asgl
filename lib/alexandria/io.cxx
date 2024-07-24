/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/io.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/io.eclh"
/*      local function WITH-OPEN-FILE*                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1with_open_file_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6stream;
   cl_object v7filespec;
   cl_object v8;
   cl_object v9direction;
   cl_object v10;
   cl_object v11element_type;
   cl_object v12;
   cl_object v13if_exists;
   cl_object v14;
   cl_object v15if_does_not_exist;
   cl_object v16;
   cl_object v17external_format;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v18;
    v18 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v18;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v18;
    v18 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6stream = v18;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v18;
    v18 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7filespec = v18;
   }
   v8 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("DIRECTION",1246)) /*  SEARCH-KEYWORD */;
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L23; }
   v9direction = ECL_NIL;
   goto L22;
L23:;
   v9direction = v8;
L22:;
   v10 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("ELEMENT-TYPE",1252)) /*  SEARCH-KEYWORD */;
   if (!((v10)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L27; }
   v11element_type = ECL_NIL;
   goto L26;
L27:;
   v11element_type = v10;
L26:;
   v12 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("IF-EXISTS",1276)) /*  SEARCH-KEYWORD */;
   if (!((v12)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L31; }
   v13if_exists = ECL_NIL;
   goto L30;
L31:;
   v13if_exists = v12;
L30:;
   v14 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("IF-DOES-NOT-EXIST",1274)) /*  SEARCH-KEYWORD */;
   if (!((v14)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L35; }
   v15if_does_not_exist = ECL_NIL;
   goto L34;
L35:;
   v15if_does_not_exist = v14;
L34:;
   v16 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("EXTERNAL-FORMAT",1264)) /*  SEARCH-KEYWORD */;
   if (!((v16)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L39; }
   v17external_format = ECL_NIL;
   goto L38;
L39:;
   v17external_format = v16;
L38:;
   ecl_function_dispatch(cl_env_copy,VV[37])(2, v5, VV[1]) /*  CHECK-KEYWORD */;
   {
    cl_object v18;
    cl_object v19;
    cl_object v20;
    cl_object v21;
    cl_object v22;
    v18 = cl_gensym(1, VV[2]);
    v19 = cl_gensym(1, VV[3]);
    v20 = cl_gensym(1, VV[4]);
    v21 = cl_gensym(1, VV[5]);
    v22 = cl_gensym(1, VV[6]);
    T0 = cl_list(2, v18, v9direction);
    T1 = cl_list(2, v19, v11element_type);
    T2 = cl_list(2, v20, v13if_exists);
    T3 = cl_list(2, v21, v15if_does_not_exist);
    T4 = cl_list(2, v22, v17external_format);
    T5 = cl_list(5, T0, T1, T2, T3, T4);
    T7 = cl_list(3, ECL_SYM("LIST",483), ECL_SYM("DIRECTION",1246), v18);
    T8 = cl_list(3, ECL_SYM("WHEN",907), v18, T7);
    T9 = cl_list(3, ECL_SYM("LIST",483), ECL_SYM("ELEMENT-TYPE",1252), v19);
    T10 = cl_list(3, ECL_SYM("WHEN",907), v19, T9);
    T11 = cl_list(3, ECL_SYM("LIST",483), ECL_SYM("IF-EXISTS",1276), v20);
    T12 = cl_list(3, ECL_SYM("WHEN",907), v20, T11);
    T13 = cl_list(3, ECL_SYM("LIST",483), ECL_SYM("IF-DOES-NOT-EXIST",1274), v21);
    T14 = cl_list(3, ECL_SYM("WHEN",907), v21, T13);
    T15 = cl_list(3, ECL_SYM("LIST",483), ECL_SYM("EXTERNAL-FORMAT",1264), v22);
    T16 = cl_list(3, ECL_SYM("WHEN",907), v22, T15);
    T17 = cl_list(6, ECL_SYM("APPEND",90), T8, T10, T12, T14, T16);
    T18 = cl_list(4, ECL_SYM("APPLY",91), VV[7], v7filespec, T17);
    T19 = cl_list(2, v6stream, T18);
    T6 = cl_listX(3, ECL_SYM("WITH-OPEN-STREAM",914), T19, v3);
    value0 = cl_list(3, ECL_SYM("LET",479), T5, T6);
    return value0;
   }
  }
 }
}
/*      local function WITH-INPUT-FROM-FILE                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2with_input_from_file(cl_object v1, cl_object v2)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6stream_name;
   cl_object v7file_name;
   cl_object v8;
   cl_object v9direction_p;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v10;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6stream_name = v10;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7file_name = v10;
   }
   v8 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("DIRECTION",1246)) /*  SEARCH-KEYWORD */;
   {
    bool v10;
    v10 = (v8)==(ECL_SYM("MISSING-KEYWORD",2037));
    v9direction_p = (v10)?ECL_NIL:ECL_T;
   }
   ecl_function_dispatch(cl_env_copy,VV[37])(3, v5, VV[9], ECL_T) /*  CHECK-KEYWORD */;
   if (Null(v9direction_p)) { goto L24; }
   cl_error(1, VV[10]);
L24:;
   T0 = cl_listX(5, v6stream_name, v7file_name, ECL_SYM("DIRECTION",1246), ECL_SYM("INPUT",1286), v5);
   value0 = cl_listX(3, VV[0], T0, v3);
   return value0;
  }
 }
}
/*      local function WITH-OUTPUT-TO-FILE                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3with_output_to_file(cl_object v1, cl_object v2)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6stream_name;
   cl_object v7file_name;
   cl_object v8;
   cl_object v9direction_p;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v10;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6stream_name = v10;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[35])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7file_name = v10;
   }
   v8 = ecl_function_dispatch(cl_env_copy,VV[36])(2, v5, ECL_SYM("DIRECTION",1246)) /*  SEARCH-KEYWORD */;
   {
    bool v10;
    v10 = (v8)==(ECL_SYM("MISSING-KEYWORD",2037));
    v9direction_p = (v10)?ECL_NIL:ECL_T;
   }
   ecl_function_dispatch(cl_env_copy,VV[37])(3, v5, VV[9], ECL_T) /*  CHECK-KEYWORD */;
   if (Null(v9direction_p)) { goto L24; }
   cl_error(1, VV[12]);
L24:;
   T0 = cl_listX(5, v6stream_name, v7file_name, ECL_SYM("DIRECTION",1246), ECL_SYM("OUTPUT",1316), v5);
   value0 = cl_listX(3, VV[0], T0, v3);
   return value0;
  }
 }
}
/*      function definition for READ-FILE-INTO-STRING                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4read_file_into_string(volatile cl_narg narg, cl_object volatile v1pathname, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object volatile v2buffer_size;
  cl_object volatile v3external_format;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L4read_file_into_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2buffer_size = ecl_make_fixnum(4096);
   } else {
    v2buffer_size = keyvars[0];
   }
   v3external_format = keyvars[1];
  }
  {
   volatile cl_object v4file_stream;
   T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
   if (Null(ECL_SYM("INPUT",1286))) { goto L5; }
   T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("INPUT",1286));
   goto L4;
L5:;
   T1 = ECL_NIL;
L4:;
   goto L8;
   T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), ECL_NIL);
   goto L7;
L8:;
   T2 = ECL_NIL;
L7:;
   goto L11;
   T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), ECL_NIL);
   goto L10;
L11:;
   T3 = ECL_NIL;
L10:;
   goto L14;
   T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), ECL_NIL);
   goto L13;
L14:;
   T4 = ECL_NIL;
L13:;
   if (Null(v3external_format)) { goto L17; }
   T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), v3external_format);
   goto L16;
L17:;
   T5 = ECL_NIL;
L16:;
   T6 = cl_append(5, T1, T2, T3, T4, T5);
   v4file_stream = cl_apply(3, T0, v1pathname, T6);
   {
    volatile bool unwinding = FALSE;
    cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
    ecl_frame_ptr next_fr;
    ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
    if (__ecl_frs_push_result) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",57),ECL_NIL); /*  *PRINT-PRETTY* */
    {
     volatile cl_object v7datum;
     v7datum = cl_make_string_output_stream(0);
     {
      volatile bool unwinding = FALSE;
      cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
      ecl_frame_ptr next_fr;
      ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
      if (__ecl_frs_push_result) {
        unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
      } else {
      {
       cl_object v10buffer;
       v10buffer = si_make_pure_array(ECL_SYM("CHARACTER",224), v2buffer_size, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
       {
        cl_object v11bytes_read;
        v11bytes_read = ECL_NIL;
L25:;
        v11bytes_read = cl_read_sequence(2, v10buffer, v4file_stream);
        cl_write_sequence(6, v10buffer, v7datum, ECL_SYM("START",1344), ecl_make_fixnum(0), ECL_SYM("END",1253), v11bytes_read);
        if (ecl_number_equalp(v11bytes_read,v2buffer_size)) { goto L30; }
        goto L26;
L30:;
        goto L25;
L26:;
       }
      }
      cl_env_copy->values[0] = cl_get_output_stream_string(v7datum);
      }
      ecl_frs_pop(cl_env_copy);
      v9=ecl_stack_push_values(cl_env_copy);
      cl_close(1, v7datum);
      ecl_stack_pop_values(cl_env_copy,v9);
      if (unwinding) ecl_unwind(cl_env_copy,next_fr);
      ECL_STACK_SET_INDEX(cl_env_copy,v8);
      ecl_bds_unwind1(cl_env_copy);
     }
    }
    }
    ecl_frs_pop(cl_env_copy);
    v6=ecl_stack_push_values(cl_env_copy);
    cl_close(1, v4file_stream);
    ecl_stack_pop_values(cl_env_copy,v6);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v5);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for WRITE-STRING-INTO-FILE                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5write_string_into_file(volatile cl_narg narg, cl_object volatile v1string, cl_object volatile v2pathname, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object volatile v3if_exists;
  cl_object volatile v4if_does_not_exist;
  cl_object volatile v5external_format;
  ecl_va_list args; ecl_va_start(args,v2pathname,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L5write_string_into_filekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v3if_exists = ECL_SYM("ERROR",1257);
   } else {
    v3if_exists = keyvars[0];
   }
   v4if_does_not_exist = keyvars[1];
   v5external_format = keyvars[2];
  }
  {
   volatile cl_object v6file_stream;
   T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
   if (Null(ECL_SYM("OUTPUT",1316))) { goto L5; }
   T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("OUTPUT",1316));
   goto L4;
L5:;
   T1 = ECL_NIL;
L4:;
   goto L8;
   T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), ECL_NIL);
   goto L7;
L8:;
   T2 = ECL_NIL;
L7:;
   if (Null(v3if_exists)) { goto L11; }
   T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), v3if_exists);
   goto L10;
L11:;
   T3 = ECL_NIL;
L10:;
   if (Null(v4if_does_not_exist)) { goto L14; }
   T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), v4if_does_not_exist);
   goto L13;
L14:;
   T4 = ECL_NIL;
L13:;
   if (Null(v5external_format)) { goto L17; }
   T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), v5external_format);
   goto L16;
L17:;
   T5 = ECL_NIL;
L16:;
   T6 = cl_append(5, T1, T2, T3, T4, T5);
   v6file_stream = cl_apply(3, T0, v2pathname, T6);
   {
    volatile bool unwinding = FALSE;
    cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
    ecl_frame_ptr next_fr;
    ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
    if (__ecl_frs_push_result) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    cl_env_copy->values[0] = cl_write_sequence(2, v1string, v6file_stream);
    }
    ecl_frs_pop(cl_env_copy);
    v8=ecl_stack_push_values(cl_env_copy);
    cl_close(1, v6file_stream);
    ecl_stack_pop_values(cl_env_copy,v8);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v7);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for READ-FILE-INTO-BYTE-VECTOR            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L6read_file_into_byte_vector(cl_object volatile v1pathname)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2stream;
   T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
   if (Null(ECL_SYM("INPUT",1286))) { goto L4; }
   T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("INPUT",1286));
   goto L3;
L4:;
   T1 = ECL_NIL;
L3:;
   T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), VV[16]);
   goto L6;
   T2 = ECL_NIL;
L6:;
   goto L10;
   T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), ECL_NIL);
   goto L9;
L10:;
   T3 = ECL_NIL;
L9:;
   goto L13;
   T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), ECL_NIL);
   goto L12;
L13:;
   T4 = ECL_NIL;
L12:;
   goto L16;
   T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), ECL_NIL);
   goto L15;
L16:;
   T5 = ECL_NIL;
L15:;
   T6 = cl_append(5, T1, T2, T3, T4, T5);
   v2stream = cl_apply(3, T0, v1pathname, T6);
   {
    volatile bool unwinding = FALSE;
    cl_index v3=ECL_STACK_INDEX(cl_env_copy),v4;
    ecl_frame_ptr next_fr;
    ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
    if (__ecl_frs_push_result) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     cl_object v5length;
     v5length = cl_file_length(v2stream);
     goto L22;
L21:;
     si_assert_failure(1, ECL_SYM("LENGTH",478));
L22:;
     if ((v5length)!=ECL_NIL) { goto L25; }
     goto L21;
L25:;
     {
      cl_object v6result;
      v6result = si_make_pure_array(ECL_SYM("BYTE8",1365), v5length, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
      cl_read_sequence(2, v6result, v2stream);
      cl_env_copy->values[0] = v6result;
      cl_env_copy->nvalues = 1;
     }
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    cl_close(1, v2stream);
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for WRITE-BYTE-VECTOR-INTO-FILE           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7write_byte_vector_into_file(volatile cl_narg narg, cl_object volatile v1bytes, cl_object volatile v2pathname, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object volatile v3if_exists;
  cl_object volatile v4if_does_not_exist;
  ecl_va_list args; ecl_va_start(args,v2pathname,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L7write_byte_vector_into_filekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3if_exists = ECL_SYM("ERROR",1257);
   } else {
    v3if_exists = keyvars[0];
   }
   v4if_does_not_exist = keyvars[1];
  }
  {
   cl_object v5;
   v5 = v1bytes;
   if ((cl_typep(2, v5, VV[18]))!=ECL_NIL) { goto L4; }
   v1bytes = si_do_check_type(v5, VV[18], ECL_NIL, VV[19]);
L4:;
  }
  {
   volatile cl_object v5stream;
   T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
   if (Null(ECL_SYM("OUTPUT",1316))) { goto L10; }
   T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("OUTPUT",1316));
   goto L9;
L10:;
   T1 = ECL_NIL;
L9:;
   T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), VV[16]);
   goto L12;
   T2 = ECL_NIL;
L12:;
   if (Null(v3if_exists)) { goto L16; }
   T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), v3if_exists);
   goto L15;
L16:;
   T3 = ECL_NIL;
L15:;
   if (Null(v4if_does_not_exist)) { goto L19; }
   T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), v4if_does_not_exist);
   goto L18;
L19:;
   T4 = ECL_NIL;
L18:;
   goto L22;
   T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), ECL_NIL);
   goto L21;
L22:;
   T5 = ECL_NIL;
L21:;
   T6 = cl_append(5, T1, T2, T3, T4, T5);
   v5stream = cl_apply(3, T0, v2pathname, T6);
   {
    volatile bool unwinding = FALSE;
    cl_index v6=ECL_STACK_INDEX(cl_env_copy),v7;
    ecl_frame_ptr next_fr;
    ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
    if (__ecl_frs_push_result) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    cl_env_copy->values[0] = cl_write_sequence(2, v1bytes, v5stream);
    }
    ecl_frs_pop(cl_env_copy);
    v7=ecl_stack_push_values(cl_env_copy);
    cl_close(1, v5stream);
    ecl_stack_pop_values(cl_env_copy,v7);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v6);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for COPY-FILE                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L8copy_file(volatile cl_narg narg, cl_object volatile v1from, cl_object volatile v2to, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object volatile v3if_to_exists;
  cl_object volatile v4element_type;
  cl_object volatile v5finish_output;
  ecl_va_list args; ecl_va_start(args,v2to,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L8copy_filekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v3if_to_exists = ECL_SYM("SUPERSEDE",1348);
   } else {
    v3if_to_exists = keyvars[0];
   }
   if (Null(keyvars[4])) {
    v4element_type = VV[16];
   } else {
    v4element_type = keyvars[1];
   }
   v5finish_output = keyvars[2];
  }
  {
   volatile cl_object v6input;
   T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
   if (Null(ECL_SYM("INPUT",1286))) { goto L6; }
   T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("INPUT",1286));
   goto L5;
L6:;
   T1 = ECL_NIL;
L5:;
   if (Null(v4element_type)) { goto L9; }
   T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), v4element_type);
   goto L8;
L9:;
   T2 = ECL_NIL;
L8:;
   goto L12;
   T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), ECL_NIL);
   goto L11;
L12:;
   T3 = ECL_NIL;
L11:;
   goto L15;
   T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), ECL_NIL);
   goto L14;
L15:;
   T4 = ECL_NIL;
L14:;
   goto L18;
   T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), ECL_NIL);
   goto L17;
L18:;
   T5 = ECL_NIL;
L17:;
   T6 = cl_append(5, T1, T2, T3, T4, T5);
   v6input = cl_apply(3, T0, v1from, T6);
   {
    volatile bool unwinding = FALSE;
    cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
    ecl_frame_ptr next_fr;
    ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
    if (__ecl_frs_push_result) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     volatile cl_object v9output;
     T0 = (ECL_SYM("OPEN",613)->symbol.gfdef);
     if (Null(ECL_SYM("OUTPUT",1316))) { goto L24; }
     T1 = cl_list(2, ECL_SYM("DIRECTION",1246), ECL_SYM("OUTPUT",1316));
     goto L23;
L24:;
     T1 = ECL_NIL;
L23:;
     if (Null(v4element_type)) { goto L27; }
     T2 = cl_list(2, ECL_SYM("ELEMENT-TYPE",1252), v4element_type);
     goto L26;
L27:;
     T2 = ECL_NIL;
L26:;
     if (Null(v3if_to_exists)) { goto L30; }
     T3 = cl_list(2, ECL_SYM("IF-EXISTS",1276), v3if_to_exists);
     goto L29;
L30:;
     T3 = ECL_NIL;
L29:;
     goto L33;
     T4 = cl_list(2, ECL_SYM("IF-DOES-NOT-EXIST",1274), ECL_NIL);
     goto L32;
L33:;
     T4 = ECL_NIL;
L32:;
     goto L36;
     T5 = cl_list(2, ECL_SYM("EXTERNAL-FORMAT",1264), ECL_NIL);
     goto L35;
L36:;
     T5 = ECL_NIL;
L35:;
     T6 = cl_append(5, T1, T2, T3, T4, T5);
     v9output = cl_apply(3, T0, v2to, T6);
     {
      volatile bool unwinding = FALSE;
      cl_index v10=ECL_STACK_INDEX(cl_env_copy),v11;
      ecl_frame_ptr next_fr;
      ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG);
      if (__ecl_frs_push_result) {
        unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
      } else {
      cl_env_copy->values[0] = L9copy_stream(6, v6input, v9output, ECL_SYM("ELEMENT-TYPE",1252), v4element_type, VV[21], v5finish_output);
      }
      ecl_frs_pop(cl_env_copy);
      v11=ecl_stack_push_values(cl_env_copy);
      cl_close(1, v9output);
      ecl_stack_pop_values(cl_env_copy,v11);
      if (unwinding) ecl_unwind(cl_env_copy,next_fr);
      ECL_STACK_SET_INDEX(cl_env_copy,v10);
     }
    }
    }
    ecl_frs_pop(cl_env_copy);
    v8=ecl_stack_push_values(cl_env_copy);
    cl_close(1, v6input);
    ecl_stack_pop_values(cl_env_copy,v8);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v7);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for COPY-STREAM                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9copy_stream(cl_narg narg, cl_object v1input, cl_object v2output, ...)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3element_type;
  cl_object v4buffer_size;
  cl_object v5buffer;
  cl_object v6start;
  cl_object v7end;
  cl_object v8finish_output;
  ecl_va_list args; ecl_va_start(args,v2output,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,L9copy_streamkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[6])) {
    v3element_type = cl_stream_element_type(v1input);
   } else {
    v3element_type = keyvars[0];
   }
   if (Null(keyvars[7])) {
    v4buffer_size = ecl_make_fixnum(4096);
   } else {
    v4buffer_size = keyvars[1];
   }
   if (Null(keyvars[8])) {
    v5buffer = si_make_pure_array(v3element_type, v4buffer_size, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   } else {
    v5buffer = keyvars[2];
   }
   if (Null(keyvars[9])) {
    v6start = ecl_make_fixnum(0);
   } else {
    v6start = keyvars[3];
   }
   v7end = keyvars[4];
   v8finish_output = keyvars[5];
  }
  {
   cl_object v9;
   v9 = v6start;
   {
    cl_object v10;
    v10 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v9)||ECL_BIGNUMP(v9))) { goto L11; }
    v10 = v9;
    if (ecl_greatereq(v10,ecl_make_fixnum(0))) { goto L7; }
    goto L8;
L11:;
    goto L8;
   }
L8:;
   v6start = si_do_check_type(v9, VV[23], ECL_NIL, VV[24]);
L7:;
  }
  {
   cl_object v9;
   v9 = v7end;
   if (v9==ECL_NIL) { goto L18; }
   {
    cl_object v10;
    v10 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v9)||ECL_BIGNUMP(v9))) { goto L23; }
    v10 = v9;
    if (ecl_greatereq(v10,ecl_make_fixnum(0))) { goto L18; }
    goto L19;
L23:;
    goto L19;
   }
L19:;
   v7end = si_do_check_type(v9, VV[25], ECL_NIL, VV[26]);
L18:;
  }
  {
   cl_object v9;
   v9 = v4buffer_size;
   {
    cl_object v10;
    v10 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v9)||ECL_BIGNUMP(v9))) { goto L34; }
    v10 = v9;
    if (ecl_greatereq(v10,ecl_make_fixnum(1))) { goto L30; }
    goto L31;
L34:;
    goto L31;
   }
L31:;
   v4buffer_size = si_do_check_type(v9, VV[27], ECL_NIL, VV[28]);
L30:;
  }
  if (Null(v7end)) { goto L39; }
  if (!(ecl_lower(v7end,v6start))) { goto L39; }
  cl_error(2, VV[29], VV[22]);
L39:;
  {
   cl_object v9output_position;
   cl_object v10input_position;
   v9output_position = ecl_make_fixnum(0);
   v10input_position = ecl_make_fixnum(0);
   if (ecl_zerop(v6start)) { goto L44; }
L46:;
   if (ecl_lower(v10input_position,v6start)) { goto L48; }
   goto L47;
L48:;
   {
    cl_fixnum v11n;
    {
     cl_fixnum v12;
     v12 = ecl_length(v5buffer);
     T0 = ecl_minus(v6start,v10input_position);
     T1 = ((ecl_float_nan_p(T0) || ecl_lowereq(ecl_make_fixnum(v12),T0))?ecl_make_fixnum(v12):T0);
     v11n = ecl_fixnum(cl_read_sequence(4, v5buffer, v1input, ECL_SYM("END",1253), T1));
    }
    if (!((v11n)==0)) { goto L52; }
    cl_error(3, VV[30], VV[22], v6start);
L52:;
    v10input_position = ecl_plus(v10input_position,ecl_make_fixnum(v11n));
   }
   goto L46;
L47:;
L44:;
   goto L58;
L57:;
   si_assert_failure(1, VV[31]);
L58:;
   if (ecl_number_equalp(v10input_position,v6start)) { goto L61; }
   goto L57;
L61:;
L64:;
   if (v7end==ECL_NIL) { goto L66; }
   if (ecl_lower(v10input_position,v7end)) { goto L66; }
   goto L65;
L66:;
   {
    cl_fixnum v11n;
    if (Null(v7end)) { goto L72; }
    {
     cl_fixnum v12;
     v12 = ecl_length(v5buffer);
     T1 = ecl_minus(v7end,v10input_position);
     T0 = ((ecl_float_nan_p(T1) || ecl_lowereq(ecl_make_fixnum(v12),T1))?ecl_make_fixnum(v12):T1);
     goto L71;
    }
L72:;
    T0 = ECL_NIL;
L71:;
    v11n = ecl_fixnum(cl_read_sequence(4, v5buffer, v1input, ECL_SYM("END",1253), T0));
    if (!((v11n)==0)) { goto L74; }
    if (Null(v7end)) { goto L76; }
    cl_error(3, VV[32], VV[22], v7end);
    goto L74;
L76:;
    goto L63;
L74:;
    v10input_position = ecl_plus(v10input_position,ecl_make_fixnum(v11n));
    cl_write_sequence(4, v5buffer, v2output, ECL_SYM("END",1253), ecl_make_fixnum(v11n));
    v9output_position = ecl_plus(v9output_position,ecl_make_fixnum(v11n));
   }
   goto L64;
L65:;
L63:;
   if (Null(v8finish_output)) { goto L83; }
   cl_finish_output(1, v2output);
L83:;
   value0 = v9output_position;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "lib/alexandria/io.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecliPHAkciDuw0AM_cYHycC71(cl_object flag)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object *VVtemp;
 if (flag != OBJNULL){
 Cblock = flag;
 #ifndef ECL_DYNAMIC_VV
 flag->cblock.data = VV;
 #endif
 flag->cblock.data_size = VM;
 flag->cblock.temp_data_size = VMtemp;
 flag->cblock.data_text = compiler_data_text;
 flag->cblock.cfuns_size = compiler_cfuns_size;
 flag->cblock.cfuns = compiler_cfuns;
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/io.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecliPHAkciDuw0AM_cYHycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[33]);                       /*  WITH-OPEN-FILE* */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[4]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[38]);                       /*  WITH-INPUT-FROM-FILE */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[8], ECL_SYM("FUNCTION",398), VVtemp[8]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LOCATION",1862), VVtemp[9], VVtemp[10]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[39]);                       /*  WITH-OUTPUT-TO-FILE */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[11], ECL_SYM("FUNCTION",398), VVtemp[11]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LOCATION",1862), VVtemp[12], VVtemp[13]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[14]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[40]);                          /*  READ-FILE-INTO-STRING */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[13], ECL_SYM("FUNCTION",398), VVtemp[15]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LOCATION",1862), VVtemp[16], VVtemp[17]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[18]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[43]);                          /*  WRITE-STRING-INTO-FILE */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[14], ECL_SYM("FUNCTION",398), VVtemp[19]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LOCATION",1862), VVtemp[20], VVtemp[21]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[22]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[47]);                          /*  READ-FILE-INTO-BYTE-VECTOR */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[15], ECL_SYM("FUNCTION",398), VVtemp[23]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LOCATION",1862), VVtemp[24], VVtemp[25]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[26]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[48]);                          /*  WRITE-BYTE-VECTOR-INTO-FILE */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[17], ECL_SYM("FUNCTION",398), VVtemp[27]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LOCATION",1862), VVtemp[28], VVtemp[29]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[30]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[49]);                          /*  COPY-FILE       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[22], ECL_SYM("LOCATION",1862), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[22], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[33]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[53]);                          /*  COPY-STREAM     */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[22], ECL_SYM("FUNCTION",398), VVtemp[34]) /*  SET-DOCUMENTATION */;
}
