/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/definitions.lisp                       */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/definitions.eclh"
/*      function definition for %REEVALUATE-CONSTANT                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5_reevaluate_constant(cl_object volatile v1name, cl_object volatile v2value, cl_object volatile v3test)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_boundp(cl_env_copy,v1name)) { goto L1; }
  value0 = v2value;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   volatile cl_object v4;
   v4 = cl_symbol_value(v1name);
   if ((cl_constantp(1, v1name))!=ECL_NIL) { goto L4; }
   cl_cerror(4, VV[1], VV[2], v1name, v4);
   value0 = v2value;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (Null(ecl_function_dispatch(cl_env_copy,v3test)(2, v4, v2value))) { goto L7; }
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L9;
     if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L10;
     ecl_internal_error("GO found an inexistent tag");
     }
     {
      cl_object v5;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC1__g8,env2,Cblock);
      T0 = v5;
     }
     {
      cl_object v5;
      v5 = ecl_make_cfun((cl_objectfn_fixed)LC2__g9,ECL_NIL,Cblock,1);
      T1 = v5;
     }
     T2 = ecl_function_dispatch(cl_env_copy,VV[12])(6, ECL_SYM("NAME",1278), ECL_SYM("IGNORE",428), ECL_SYM("FUNCTION",1244), T0, VV[3], T1) /*  MAKE-RESTART */;
     {
      cl_object v5;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC3__g10,env2,Cblock);
      T3 = v5;
     }
     {
      cl_object v5;
      v5 = ecl_make_cfun((cl_objectfn_fixed)LC4__g11,ECL_NIL,Cblock,1);
      T4 = v5;
     }
     T5 = ecl_function_dispatch(cl_env_copy,VV[12])(6, ECL_SYM("NAME",1278), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1244), T3, VV[3], T4) /*  MAKE-RESTART */;
     T6 = cl_list(2, T2, T5);
     T7 = CONS(T6,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T7); /*  *RESTART-CLUSTERS* */
     {
      cl_object v5;
      T0 = cl_list(4, v1name, v4, v2value, v3test);
      v5 = ecl_function_dispatch(cl_env_copy,VV[13])(4, VV[6], T0, ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("ERROR",337)) /*  COERCE-TO-CONDITION */;
      T0 = ecl_car(ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
      T1 = CONS(v5,T0);
      T2 = CONS(T1,ecl_symbol_value(VV[7]));
      ecl_bds_bind(cl_env_copy,VV[7],T2);         /*  *CONDITION-RESTARTS* */
      value0 = cl_error(1, v5);
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
     }
L9:;
     value0 = v4;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     return value0;
L10:;
     value0 = v2value;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
  }
 }
}
/*      closure G8                                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1__g8(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*      local function G9                                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2__g9(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, VV[4], v1stream);
  return value0;
 }
}
/*      closure G10                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3__g10(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(1));
 }
 }
}
/*      local function G11                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4__g11(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, VV[5], v1stream);
  return value0;
 }
}
/*      local function DEFINE-CONSTANT                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6define_constant(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5initial_value;
   cl_object v6;
   cl_object v7test;
   cl_object v8;
   cl_object v9documentation;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v10;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5initial_value = v10;
   }
   v6 = si_search_keyword(2, v3, ECL_SYM("TEST",1321));
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1943)))) { goto L16; }
   v7test = VV[9];
   goto L15;
L16:;
   v7test = v6;
L15:;
   v8 = si_search_keyword(2, v3, ECL_SYM("DOCUMENTATION",1225));
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1943)))) { goto L20; }
   v9documentation = ECL_NIL;
   goto L19;
L20:;
   v9documentation = v8;
L19:;
   si_check_keyword(2, v3, VV[10]);
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(4, VV[0], T0, v5initial_value, v7test);
   if (Null(v9documentation)) { goto L24; }
   T2 = ecl_list1(v9documentation);
   goto L23;
L24:;
   T2 = ECL_NIL;
L23:;
   value0 = cl_listX(4, ECL_SYM("DEFCONSTANT",277), v4name, T1, T2);
   return value0;
  }
 }
}

#include "lib/alexandria/definitions.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclEwTbx6vhJ21IM_ftf2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/definitions.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclEwTbx6vhJ21IM_ftf2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[11]);                          /*  %REEVALUATE-CONSTANT */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[4], VVtemp[5]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[6]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[14]);                       /*  DEFINE-CONSTANT */
  si_set_documentation(3, VV[8], ECL_SYM("FUNCTION",396), VVtemp[7]);
}
