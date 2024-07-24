/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: common/early/package.lisp                             */
#include <ecl/ecl-cmp.h>
#include "common/early/package.eclh"

#include "common/early/package.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclhQzNQYq3zy1HM_J7f2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/early/package.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclhQzNQYq3zy1HM_J7f2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  ecl_function_dispatch(cl_env_copy,VV[0])(10, VVtemp[0], ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, VVtemp[2], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
}
