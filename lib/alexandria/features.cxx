/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/features.lisp                          */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/features.eclh"
/*      function definition for FEATUREP                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1featurep(cl_object v1feature_expression)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1feature_expression;
   if (!(ECL_SYMBOLP(v2))) { goto L2; }
   T0 = ecl_memql(v1feature_expression,ecl_symbol_value(ECL_SYM("*FEATURES*",34)));
   {
    bool v3;
    v3 = T0==ECL_NIL;
    value0 = (v3)?ECL_NIL:ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L2:;
   if (!(ECL_CONSP(v2))) { goto L5; }
   {
    cl_object v4;
    v4 = ecl_car(v1feature_expression);
    if (ECL_SYMBOLP(v4)) { goto L9; }
    {
     cl_object v5;
     v5 = si_do_check_type(v4, ECL_SYM("SYMBOL",840), ECL_NIL, VV[1]);
     {
      cl_object v6;
      v6 = v1feature_expression;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      T0 = v6;
     }
     (ECL_CONS_CAR(T0)=v5,T0);
    }
L9:;
   }
   {
    cl_object v4;
    T0 = ecl_car(v1feature_expression);
    v4 = cl_identity(T0);
    if (Null(cl_stringE(2, v4, VV[2]))) { goto L17; }
    T0 = ecl_fdefinition(VV[0]);
    T1 = ecl_cdr(v1feature_expression);
    value0 = cl_every(2, T0, T1);
    return value0;
L17:;
    if (Null(cl_stringE(2, v4, VV[3]))) { goto L20; }
    T0 = ecl_fdefinition(VV[0]);
    T1 = ecl_cdr(v1feature_expression);
    value0 = cl_some(2, T0, T1);
    return value0;
L20:;
    if (Null(cl_stringE(2, v4, VV[4]))) { goto L23; }
    goto L27;
L26:;
    si_assert_failure(1, VV[5]);
L27:;
    {
     cl_fixnum v5;
     v5 = ecl_length(v1feature_expression);
     if ((2)==(v5)) { goto L30; }
    }
    goto L26;
L30:;
    T0 = ecl_cadr(v1feature_expression);
    T1 = L1featurep(T0);
    value0 = Null(T1)?ECL_T:ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L23:;
    value0 = cl_error(3, VV[6], v4, ECL_SYM("STRING=",822));
    return value0;
   }
L5:;
   value0 = si_etypecase_error(v2, VV[7]);
   return value0;
  }
 }
}

#include "lib/alexandria/features.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclq3qz1Rgh1vqFM_Fwg2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/features.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclq3qz1Rgh1vqFM_Fwg2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[8]);                           /*  FEATUREP        */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[4]);
}
