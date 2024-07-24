/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/conditions.lisp                        */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/conditions.eclh"
/*      function definition for REQUIRED-ARGUMENT                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1required_argument(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1name = ECL_NIL;
   } else {
    i++;
    v1name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_error(2, VV[1], v1name);
  return value0;
 }
}
/*      function definition for SIMPLE-STYLE-WARNING                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2simple_style_warning(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(5, VV[2], ECL_SYM("FORMAT-CONTROL",1243), v1message, ECL_SYM("FORMAT-ARGUMENTS",1242), v2args) /*  WARN */;
  return value0;
 }
}
/*      function definition for SIMPLE-READER-ERROR                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3simple_reader_error(cl_narg narg, cl_object v1stream, cl_object v2message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  ecl_va_list args; ecl_va_start(args,v2message,narg,2);
  v3args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(7, VV[3], ECL_SYM("STREAM",1318), v1stream, ECL_SYM("FORMAT-CONTROL",1243), v2message, ECL_SYM("FORMAT-ARGUMENTS",1242), v3args);
  return value0;
 }
}
/*      function definition for SIMPLE-PARSE-ERROR                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4simple_parse_error(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(5, VV[4], ECL_SYM("FORMAT-CONTROL",1243), v1message, ECL_SYM("FORMAT-ARGUMENTS",1242), v2args);
  return value0;
 }
}
/*      function definition for SIMPLE-PROGRAM-ERROR                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5simple_program_error(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(5, VV[5], ECL_SYM("FORMAT-CONTROL",1243), v1message, ECL_SYM("FORMAT-ARGUMENTS",1242), v2args);
  return value0;
 }
}
/*      local function IGNORE-SOME-CONDITIONS                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6ignore_some_conditions(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v5;
   }
   T0 = CONS(ECL_SYM("PROGN",671),v3);
   {
    cl_object v5condition;
    cl_object v6;
    v5condition = ECL_NIL;
    {
     cl_object v7;
     v7 = v4;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L15:;
     if (!(ecl_endp(v6))) { goto L17; }
     goto L16;
L17:;
     v5condition = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     {
      cl_object v9;
      v9 = v8;
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T2 = v9;
     }
     T3 = CONS(v5condition,VV[7]);
     v8 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v8,T2);
     goto L15;
L16:;
     T1 = ecl_cdr(v7);
     goto L8;
    }
   }
L8:;
   value0 = cl_listX(3, ECL_SYM("HANDLER-CASE",416), T0, T1);
   return value0;
  }
 }
}
/*      local function UNWIND-PROTECT-CASE                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC7unwind_protect_case(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6abort_flag;
   cl_object v7protected_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v8;
   }
   v5 = v4;
   if (Null(v5)) { goto L10; }
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6abort_flag = v8;
    goto L9;
   }
L10:;
   v6abort_flag = ECL_NIL;
L9:;
   if (!(v3==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7protected_form = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   {
    cl_object v8;
    v8 = v6abort_flag;
    if (ECL_SYMBOLP(v8)) { goto L25; }
    v6abort_flag = si_do_check_type(v8, VV[9], ECL_NIL, VV[10]);
L25:;
   }
   {
    cl_object v8gflag;
    v8gflag = cl_gensym(1, VV[11]);
    T0 = cl_list(2, v8gflag, ECL_T);
    T1 = ecl_list1(T0);
    T2 = cl_list(3, ECL_SYM("SETF",750), v8gflag, ECL_NIL);
    T3 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-PROG1",575), v7protected_form, T2);
    if (Null(v6abort_flag)) { goto L31; }
    T5 = cl_list(2, v6abort_flag, v8gflag);
    T4 = ecl_list1(T5);
    goto L29;
L31:;
    T4 = ECL_NIL;
    goto L29;
L29:;
    {
     cl_object v9cleanup_kind;
     cl_object v10forms;
     cl_object v11;
     v9cleanup_kind = ECL_NIL;
     v10forms = ECL_NIL;
     {
      cl_object v12;
      v12 = v3;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      v11 = v12;
     }
     {
      cl_object v12;
      cl_object v13;
      v12 = ecl_list1(ECL_NIL);
      v13 = v12;
L41:;
      if (!(ecl_endp(v11))) { goto L43; }
      goto L42;
L43:;
      {
       cl_object v14;
       v14 = _ecl_car(v11);
       v9cleanup_kind = ecl_car(v14);
       v14 = ecl_cdr(v14);
       v10forms = v14;
      }
      {
       cl_object v14;
       v14 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       v11 = v14;
      }
      {
       cl_object v14;
       v14 = v13;
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T6 = v14;
      }
      if (!(ecl_eql(v9cleanup_kind,VV[12]))) { goto L62; }
      T8 = cl_list(2, ECL_SYM("NOT",584), v8gflag);
      T7 = cl_listX(3, ECL_SYM("WHEN",905), T8, v10forms);
      goto L61;
L62:;
      if (!(ecl_eql(v9cleanup_kind,ECL_SYM("ABORT",1198)))) { goto L64; }
      T7 = cl_listX(3, ECL_SYM("WHEN",905), v8gflag, v10forms);
      goto L61;
L64:;
      if (!(ecl_eql(v9cleanup_kind,VV[13]))) { goto L66; }
      T7 = CONS(ECL_SYM("PROGN",671),v10forms);
      goto L61;
L66:;
      T7 = si_ecase_error(v9cleanup_kind, VV[14]);
L61:;
      v13 = ecl_list1(T7);
      (ECL_CONS_CDR(T6)=v13,T6);
      goto L41;
L42:;
      T5 = ecl_cdr(v12);
      goto L33;
     }
    }
L33:;
    T6 = cl_listX(3, ECL_SYM("LET",477), T4, T5);
    T7 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T3, T6);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T7);
    return value0;
   }
  }
 }
}

#include "lib/alexandria/conditions.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl0sKp2nr5Zar9M_0Qg2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/conditions.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecl0sKp2nr5Zar9M_0Qg2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[15]);                          /*  REQUIRED-ARGUMENT */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[4]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  clos_load_defclass(VV[2], VVtemp[7], ECL_NIL, ECL_NIL);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[16]);                          /*  SIMPLE-STYLE-WARNING */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[11], VVtemp[12]) /*  ANNOTATE */;
  clos_load_defclass(VV[3], VVtemp[13], ECL_NIL, ECL_NIL);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[17]);                          /*  SIMPLE-READER-ERROR */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[17], VVtemp[18]) /*  ANNOTATE */;
  clos_load_defclass(VV[4], VVtemp[19], ECL_NIL, ECL_NIL);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[20], VVtemp[21]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[18]);                          /*  SIMPLE-PARSE-ERROR */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LOCATION",1777), VVtemp[22], VVtemp[23]) /*  ANNOTATE */;
  clos_load_defclass(VV[5], VVtemp[24], ECL_NIL, ECL_NIL);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LOCATION",1777), VVtemp[25], VVtemp[26]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[19]);                          /*  SIMPLE-PROGRAM-ERROR */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[29]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[20]);                       /*  IGNORE-SOME-CONDITIONS */
  si_set_documentation(3, VV[6], ECL_SYM("FUNCTION",396), VVtemp[30]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[33]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[21]);                       /*  UNWIND-PROTECT-CASE */
  si_set_documentation(3, VV[8], ECL_SYM("FUNCTION",396), VVtemp[34]);
}
