/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/strings.lisp                           */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/strings.eclh"
/*      local function STRING-DESIGNATOR                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1string_designator(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = VV[1];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lib/alexandria/strings.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclOk91d7g9HuD9M_m9g2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/strings.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclOk91d7g9HuD9M_m9g2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
 {
  cl_object T0;
  si_set_documentation(3, VV[0], ECL_SYM("TYPE",869), VVtemp[1]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC1string_designator,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[0], VVtemp[2], T0);
 }
}
