/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/arrays.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/arrays.eclh"
/*      function definition for COPY-ARRAY                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1copy_array(cl_narg narg, cl_object v1array, ...)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2element_type;
  cl_object v3fill_pointer;
  cl_object v4adjustable;
  ecl_va_list args; ecl_va_start(args,v1array,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L1copy_arraykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v2element_type = cl_array_element_type(v1array);
   } else {
    v2element_type = keyvars[0];
   }
   if (Null(keyvars[4])) {
    if (!((ECL_ARRAYP(v1array)?(void)0:FEtype_error_array(v1array),ECL_ARRAY_HAS_FILL_POINTER_P(v1array)))) { goto L4; }
    v3fill_pointer = cl_fill_pointer(v1array);
    goto L2;
L4:;
    v3fill_pointer = ECL_NIL;
    goto L2;
L2:;
   } else {
    v3fill_pointer = keyvars[1];
   }
   if (Null(keyvars[5])) {
    v4adjustable = ecl_make_bool((ECL_ARRAYP(v1array)? (void)0: FEtype_error_array(v1array),ECL_ADJUSTABLE_ARRAY_P(v1array)));
   } else {
    v4adjustable = keyvars[2];
   }
  }
  {
   cl_object v5dimensions;
   cl_object v6new_array;
   v5dimensions = cl_array_dimensions(v1array);
   v6new_array = si_make_pure_array(v2element_type, v5dimensions, v4adjustable, v3fill_pointer, ECL_NIL, ecl_make_fixnum(0));
   {
    cl_fixnum v7;
    v7 = ecl_fixnum(cl_array_total_size(v1array));
    {
     cl_fixnum v8i;
     v8i = 0;
     goto L13;
L12:;
     T0 = ecl_aref(v1array,v8i);
     ecl_aset(v6new_array,v8i,T0);
     v8i = (v8i)+1;
L13:;
     if (!((v8i)<(v7))) { goto L18; }
     goto L12;
L18:;
    }
   }
   value0 = v6new_array;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "lib/alexandria/arrays.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl6zVmPLti1MIGM_KoHycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/arrays.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecl6zVmPLti1MIGM_KoHycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[1]);                           /*  COPY-ARRAY      */
  ecl_function_dispatch(cl_env_copy,VV[2])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[4]) /*  SET-DOCUMENTATION */;
}
