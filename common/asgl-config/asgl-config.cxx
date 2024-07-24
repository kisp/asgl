/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:54 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/common/asgl-config/asgl-config.lisp */
#include <ecl/ecl-cmp.h>
#include "common/asgl-config/asgl-config.eclh"
/*      function definition for HAVE-GECODE-GIST-HH                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1have_gecode_gist_hh()
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   {
    int v2;
    {
int res;
#ifdef HAVE_GECODE_GIST_HH
res = 0;
#else
res = 1;
#endif
v2= res;
}
    v1 = (cl_fixnum)(v2);
   }
   value0 = ecl_make_bool((v1)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ENABLE-COVER                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2enable_cover()
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   {
    int v2;
    {
int res;
#ifdef ENABLE_COVER
res = 0;
#else
res = 1;
#endif
v2= res;
}
    v1 = (cl_fixnum)(v2);
   }
   value0 = ecl_make_bool((v1)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ENABLE-TIMING                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3enable_timing()
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   {
    int v2;
    {
int res;
#ifdef ENABLE_TIMING
res = 0;
#else
res = 1;
#endif
v2= res;
}
    v1 = (cl_fixnum)(v2);
   }
   value0 = ecl_make_bool((v1)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ENABLE-LOGGING                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4enable_logging()
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   {
    int v2;
    {
int res;
#ifdef ENABLE_LOGGING
res = 0;
#else
res = 1;
#endif
v2= res;
}
    v1 = (cl_fixnum)(v2);
   }
   value0 = ecl_make_bool((v1)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ENABLE-FOBJ-LEAK-CHECKS               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5enable_fobj_leak_checks()
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   {
    int v2;
    {
int res;
#ifdef ENABLE_FOBJ_LEAK_CHECKS
res = 0;
#else
res = 1;
#endif
v2= res;
}
    v1 = (cl_fixnum)(v2);
   }
   value0 = ecl_make_bool((v1)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "common/asgl-config/asgl-config.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclXWUiJ5qKAXSIM_ObCycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/asgl-config/asgl-config.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclXWUiJ5qKAXSIM_ObCycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  ecl_function_dispatch(cl_env_copy,VV[10])(12, VVtemp[0], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[11]);                          /*  HAVE-GECODE-GIST-HH */
  if (Null(L1have_gecode_gist_hh())) { goto L9; }
  cl_set(ECL_SYM("*FEATURES*",36),CONS(VV[1],ecl_symbol_value(ECL_SYM("*FEATURES*",36))));
L9:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LOCATION",1862), VVtemp[4], VVtemp[5]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[12]);                          /*  ENABLE-COVER    */
  if (Null(L2enable_cover())) { goto L17; }
  cl_set(ECL_SYM("*FEATURES*",36),CONS(VV[3],ecl_symbol_value(ECL_SYM("*FEATURES*",36))));
L17:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[4], ECL_SYM("LOCATION",1862), VVtemp[6], VVtemp[7]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[4], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[13]);                          /*  ENABLE-TIMING   */
  if (Null(L3enable_timing())) { goto L25; }
  cl_set(ECL_SYM("*FEATURES*",36),CONS(VV[5],ecl_symbol_value(ECL_SYM("*FEATURES*",36))));
L25:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LOCATION",1862), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[14]);                          /*  ENABLE-LOGGING  */
  if (Null(L4enable_logging())) { goto L33; }
  cl_set(ECL_SYM("*FEATURES*",36),CONS(VV[7],ecl_symbol_value(ECL_SYM("*FEATURES*",36))));
L33:;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[10], VVtemp[11]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, ECL_NIL) /*  ANNOTATE */;
  ecl_cmp_defun(VV[15]);                          /*  ENABLE-FOBJ-LEAK-CHECKS */
  if (Null(L5enable_fobj_leak_checks())) { goto L41; }
  cl_set(ECL_SYM("*FEATURES*",36),CONS(VV[9],ecl_symbol_value(ECL_SYM("*FEATURES*",36))));
L41:;
}
