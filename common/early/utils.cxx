/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: common/early/utils.lisp                               */
#include <ecl/ecl-cmp.h>
#include "common/early/utils.eclh"
/*      function definition for COMPONENT-PRESENT-P                   */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L1component_present_p(cl_object v1value)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  if (Null(v1value)) { goto L2; }
  {
   bool v2;
   v2 = ecl_eql(v1value,ECL_SYM("UNSPECIFIC",1324));
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for DIRECTORY-PATHNAME-P                  */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L2directory_pathname_p(cl_object v1pathspec)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = cl_pathname_name(1, v1pathspec);
  if ((L1component_present_p(T0))!=ECL_NIL) { goto L2; }
  T0 = cl_pathname_type(1, v1pathspec);
  if ((L1component_present_p(T0))!=ECL_NIL) { goto L2; }
  value0 = v1pathspec;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for ASGL-HOME                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L3asgl_home()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v1var;
   value0 = si_getenv(VV[3]);
   if ((value0)!=ECL_NIL) { goto L3; }
   v1var = ECL_NIL;
   goto L1;
L3:;
   v1var = value0;
   goto L1;
L1:;
   if ((v1var)!=ECL_NIL) { goto L5; }
   cl_error(1, VV[4]);
L5:;
   {
    cl_object v2home;
    v2home = cl_probe_file(v1var);
    if (Null(v2home)) { goto L11; }
    if ((L2directory_pathname_p(v2home))!=ECL_NIL) { goto L8; }
    goto L9;
L11:;
    goto L9;
L9:;
    T0 = si_getenv(VV[3]);
    cl_error(2, VV[5], T0);
L8:;
    value0 = v2home;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      local function AIF                                            */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC4aif(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4test;
   cl_object v5then;
   cl_object v6else;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4test = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v5then = v7;
   }
   if (Null(v3)) { goto L15; }
   {
    cl_object v7;
    v7 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v6else = v7;
    goto L14;
   }
L15:;
   v6else = ECL_NIL;
L14:;
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   T0 = cl_list(2, VV[7], v4test);
   T1 = ecl_list1(T0);
   T2 = cl_list(4, ECL_SYM("IF",946), VV[7], v5then, v6else);
   value0 = cl_list(3, ECL_SYM("LET",477), T1, T2);
   return value0;
  }
 }
}
/*      local function WITH-TIMING                                    */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC5with_timing(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4form;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4form = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = v4form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function LOG*                                           */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC6log_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4level;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4level = v5;
   }
   {
    cl_object v5;
    v5 = v4level;
    {
     cl_object v6;
     v6 = ecl_make_fixnum(0);
     if (!(ECL_FIXNUMP(v5)||ECL_BIGNUMP(v5))) { goto L14; }
     v6 = v5;
     if (ecl_number_compare(v6,ecl_make_fixnum(0))>=0) { goto L10; }
     goto L11;
L14:;
     goto L11;
    }
L11:;
    v4level = si_do_check_type(v5, VV[13], ECL_NIL, VV[14]);
L10:;
   }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for PRINT-ERROR-LOG                       */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L7print_error_log(cl_object v1eout, cl_object v2e)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  cl_format(2, v1eout, VV[16]);
  cl_format(3, v1eout, VV[17], v2e);
  cl_format(2, v1eout, VV[18]);
  {
   cl_object v3x;
   T0 = si_ihs_top();
   v3x = ecl_minus(T0,ecl_make_fixnum(2));
L6:;
   if (!(ecl_number_compare(v3x,ecl_make_fixnum(1))<0)) { goto L8; }
   goto L7;
L8:;
   T0 = si_ihs_fun(v3x);
   cl_format(3, v1eout, VV[17], T0);
   cl_format(2, v1eout, VV[19]);
   {
    cl_object v4env;
    T0 = si_ihs_env(v3x);
    v4env = ecl_function_dispatch(cl_env_copy,VV[42])(1, T0) /*  DECODE-IHS-ENV */;
    {
     cl_object v5;
     v5 = v4env;
     goto L18;
L17:;
     {
      cl_object v6ip;
      v6ip = ECL_CONS_CAR(v5);
      T0 = _ecl_car(v6ip);
      T1 = _ecl_cdr(v6ip);
      cl_format(4, v1eout, VV[20], T0, T1);
     }
     v5 = ECL_CONS_CDR(v5);
L18:;
     if (Null(v5)) { goto L25; }
     goto L17;
L25:;
    }
   }
   cl_format(2, v1eout, VV[21]);
   v3x = ecl_one_minus(v3x);
   goto L6;
L7:;
  }
  value0 = cl_format(2, v1eout, VV[21]);
  return value0;
 }
}
/*      function definition for REQUIRES-COMPILE-P                    */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L9requires_compile_p(cl_object v1source_file)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v2fasl_file;
   T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, v1source_file) /*  COMPILE-FILE-PATHNAME */;
   v2fasl_file = cl_probe_file(T0);
   value0 = Null(v2fasl_file)?ECL_T:ECL_NIL;
   if ((value0)!=ECL_NIL) { goto L3; }
   value0 = LC8file_newer_p(v1source_file, v2fasl_file);
   return value0;
L3:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function FILE-NEWER-P                                   */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC8file_newer_p(cl_object v1new_file, cl_object v2old_file)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = cl_file_write_date(v1new_file);
  T1 = cl_file_write_date(v2old_file);
  value0 = ecl_make_bool(ecl_number_compare(T0,T1)>0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for COMPILE-FILE-IF-NEEDED                */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L10compile_file_if_needed(cl_object v1filename, cl_object v2loadp)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  if (Null(L9requires_compile_p(v1filename))) { goto L1; }
  (cl_env_copy->function=(ECL_SYM("COMPILE-FILE",234)->symbol.gfdef))->cfun.entry(1, v1filename) /*  COMPILE-FILE */;
L1:;
  if (Null(v2loadp)) { goto L3; }
  T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, v1filename) /*  COMPILE-FILE-PATHNAME */;
  cl_load(1, T0);
L3:;
  value0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, v1filename) /*  COMPILE-FILE-PATHNAME */;
  return value0;
 }
}
/*      function definition for MEAN                                  */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L11mean(cl_object v1sequence)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = (ECL_SYM("+",14)->symbol.gfdef);
  T1 = cl_reduce(2, T0, v1sequence);
  {
   cl_fixnum v2;
   v2 = ecl_length(v1sequence);
   value0 = ecl_divide(T1,ecl_make_fixnum(v2));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MEDIAN                                */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L12median(cl_object v1sequence)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  value0 = L13percentile(v1sequence, ecl_make_fixnum(50));
  return value0;
 }
}
/*      function definition for PERCENTILE                            */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L13percentile(cl_object v1sequence, cl_object v2percent)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3sorted_vect;
   cl_fixnum v4n;
   cl_object v5k;
   cl_object v6floor_k;
   T0 = ecl_copy_seq(v1sequence);
   T1 = (ECL_SYM("<",72)->symbol.gfdef);
   T2 = cl_sort(2, T0, T1);
   v3sorted_vect = si_coerce_to_vector(T2, ECL_T, ECL_SYM("*",18), ECL_T);
   v4n = (v3sorted_vect)->vector.fillp;
   T0 = ecl_divide(v2percent,ecl_make_fixnum(100));
   v5k = ecl_times(ecl_make_fixnum(v4n),T0);
   v6floor_k = ecl_floor1(v5k);
   if (!(ecl_number_equalp(v5k,v6floor_k))) { goto L6; }
   {
    cl_object v7;
    v7 = v3sorted_vect;
    T1 = v7;
    {
     cl_fixnum v8;
     {
      cl_object v9;
      v9 = v5k;
      if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
      v8 = ecl_fixnum(v9);
     }
     T0 = ecl_aref_unsafe(T1,v8);
    }
   }
   {
    cl_object v7;
    v7 = v3sorted_vect;
    T2 = v7;
    {
     cl_fixnum v8;
     {
      cl_object v9;
      v9 = ecl_one_minus(v5k);
      if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
      v8 = ecl_fixnum(v9);
     }
     T1 = ecl_aref_unsafe(T2,v8);
    }
   }
   T2 = ecl_plus(T0,T1);
   value0 = ecl_divide(T2,ecl_make_fixnum(2));
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   {
    cl_object v7;
    v7 = v3sorted_vect;
    T0 = v7;
    {
     cl_fixnum v8;
     {
      cl_object v9;
      v9 = v6floor_k;
      if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
      v8 = ecl_fixnum(v9);
     }
     value0 = ecl_aref_unsafe(T0,v8);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      function definition for SUMMARY                               */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L14summary(cl_object v1sequence)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_fixnum v2;
   v2 = ecl_length(v1sequence);
   if (!((v2)<(1000))) { goto L1; }
  }
  T0 = (ECL_SYM("MIN",557)->symbol.gfdef);
  T1 = cl_reduce(2, T0, v1sequence);
  T2 = L13percentile(v1sequence, ecl_make_fixnum(25));
  T3 = cl_format(3, ECL_NIL, VV[30], T2);
  T4 = L12median(v1sequence);
  T5 = cl_format(3, ECL_NIL, VV[30], T4);
  T6 = L11mean(v1sequence);
  T7 = cl_format(3, ECL_NIL, VV[30], T6);
  T8 = L13percentile(v1sequence, ecl_make_fixnum(75));
  T9 = cl_format(3, ECL_NIL, VV[30], T8);
  T10 = (ECL_SYM("MAX",551)->symbol.gfdef);
  T11 = cl_reduce(2, T10, v1sequence);
  value0 = cl_list(12, VV[28], T1, VV[29], T3, VV[31], T5, VV[32], T7, VV[33], T9, VV[34], T11);
  return value0;
L1:;
  T0 = (ECL_SYM("MIN",557)->symbol.gfdef);
  T1 = cl_reduce(2, T0, v1sequence);
  T2 = L11mean(v1sequence);
  T3 = cl_format(3, ECL_NIL, VV[30], T2);
  T4 = (ECL_SYM("MAX",551)->symbol.gfdef);
  T5 = cl_reduce(2, T4, v1sequence);
  value0 = cl_list(6, VV[28], T1, VV[32], T3, VV[34], T5);
  return value0;
 }
}

#include "common/early/utils.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclb840kDV4LgEAM_N7f2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/early/utils.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclb840kDV4LgEAM_N7f2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[35]);                          /*  COMPONENT-PRESENT-P */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[5]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[6], VVtemp[7]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[8]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[36]);                          /*  DIRECTORY-PATHNAME-P */
  si_set_documentation(3, VV[1], ECL_SYM("FUNCTION",396), VVtemp[9]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[10], VVtemp[11]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[37]);                          /*  ASGL-HOME       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[12], VVtemp[13]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[14]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[38]);                       /*  AIF             */
  si_Xmake_special(VV[8]);
  if (ecl_boundp(cl_env_copy,VV[8])) { goto L30; }
  cl_set(VV[8],ECL_NIL);
L30:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[15], VVtemp[16]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LOCATION",1777), VVtemp[17], VVtemp[18]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[19]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[39]);                       /*  WITH-TIMING     */
  si_Xmake_special(VV[10]);
  if (ecl_boundp(cl_env_copy,VV[10])) { goto L43; }
  cl_set(VV[10],ECL_NIL);
L43:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[10], ECL_SYM("LOCATION",1777), VVtemp[20], VVtemp[21]) /*  ANNOTATE */;
  si_do_deftype(3, VV[11], VVtemp[22], VVtemp[23]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[12], ECL_SYM("LOCATION",1777), VVtemp[24], VVtemp[25]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[12], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[26]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[40]);                       /*  LOG*            */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[29]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[41]);                          /*  PRINT-ERROR-LOG */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LOCATION",1777), VVtemp[30], VVtemp[31]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[32]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[43]);                          /*  REQUIRES-COMPILE-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LOCATION",1777), VVtemp[33], VVtemp[34]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[35]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[44]);                          /*  COMPILE-FILE-IF-NEEDED */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LOCATION",1777), VVtemp[36], VVtemp[37]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[38]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[45]);                          /*  MEAN            */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LOCATION",1777), VVtemp[39], VVtemp[40]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[38]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[46]);                          /*  MEDIAN          */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LOCATION",1777), VVtemp[41], VVtemp[42]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[43]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[47]);                          /*  PERCENTILE      */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LOCATION",1777), VVtemp[44], VVtemp[45]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[38]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[48]);                          /*  SUMMARY         */
}
