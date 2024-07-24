/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/features.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/features.eclh"
/*      function definition for FEATUREP                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1featurep(cl_object v1feature_expression)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1feature_expression))) { goto L1; }
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   v2 = ecl_symbol_value(ECL_SYM("*FEATURES*",36));
   v3 = v1feature_expression;
   v4 = v2;
   T0 = ecl_memql(v3,v4);
  }
  {
   bool v2;
   v2 = T0==ECL_NIL;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_CONSP(v1feature_expression))) { goto L7; }
  {
   cl_object v3;
   v3 = ecl_car(v1feature_expression);
   if (ECL_SYMBOLP(v3)) { goto L11; }
   {
    cl_object v4;
    v4 = si_do_check_type(v3, ECL_SYM("SYMBOL",842), ECL_NIL, VV[1]);
    {
     cl_object v5;
     v5 = v1feature_expression;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     T0 = v5;
    }
    (ECL_CONS_CAR(T0)=v4,T0);
   }
L11:;
  }
  {
   cl_object v3;
   T0 = ecl_car(v1feature_expression);
   v3 = cl_identity(T0);
   if (Null(cl_stringE(2, v3, VV[2]))) { goto L19; }
   T0 = ecl_fdefinition(VV[0]);
   T1 = ecl_cdr(v1feature_expression);
   value0 = cl_every(2, T0, T1);
   return value0;
L19:;
   if (Null(cl_stringE(2, v3, VV[3]))) { goto L22; }
   T0 = ecl_fdefinition(VV[0]);
   T1 = ecl_cdr(v1feature_expression);
   value0 = cl_some(2, T0, T1);
   return value0;
L22:;
   if (Null(cl_stringE(2, v3, VV[4]))) { goto L25; }
   goto L29;
L28:;
   si_assert_failure(1, VV[5]);
L29:;
   {
    cl_fixnum v4;
    v4 = ecl_length(v1feature_expression);
    if ((2)==(v4)) { goto L32; }
   }
   goto L28;
L32:;
   T0 = ecl_cadr(v1feature_expression);
   T1 = L1featurep(T0);
   value0 = Null(T1)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L25:;
   value0 = cl_error(3, VV[6], v3, ECL_SYM("STRING=",824));
   return value0;
  }
L7:;
  value0 = si_etypecase_error(v1feature_expression, VV[7]);
  return value0;
 }
}

#include "lib/alexandria/features.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclq3qz1Rgh1vqFM_kFGycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/features.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclq3qz1Rgh1vqFM_kFGycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[8]);                           /*  FEATUREP        */
  ecl_function_dispatch(cl_env_copy,VV[9])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[4]) /*  SET-DOCUMENTATION */;
}
