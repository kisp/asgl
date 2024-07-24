/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/binding.lisp                           */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/binding.eclh"
/*      local function IF-LET                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1if_let(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bindings;
   cl_object v5;
   cl_object v6then_form;
   cl_object v7else_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bindings = v8;
   }
   v5 = v3;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6then_form = v8;
   }
   if (Null(v5)) { goto L16; }
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7else_form = v8;
    goto L15;
   }
L16:;
   v7else_form = ECL_NIL;
L15:;
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   {
    cl_object v8binding_list;
    cl_object v9variables;
    if (!(ECL_CONSP(v4bindings))) { goto L24; }
    T0 = ecl_car(v4bindings);
    if (!(ECL_SYMBOLP(T0))) { goto L24; }
    v8binding_list = ecl_list1(v4bindings);
    goto L23;
L24:;
    v8binding_list = v4bindings;
L23:;
    {
     cl_object v10;
     v10 = (ECL_SYM("CAR",180)->symbol.gfdef);
     {
      cl_object v11;
      cl_object v12;
      v11 = ECL_NIL;
      {
       cl_object v13;
       v13 = v8binding_list;
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v12 = v13;
      }
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L35:;
       if (!(ecl_endp(v12))) { goto L37; }
       goto L36;
L37:;
       v11 = _ecl_car(v12);
       {
        cl_object v15;
        v15 = _ecl_cdr(v12);
        if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
        v12 = v15;
       }
       {
        cl_object v15;
        v15 = v14;
        if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
        T0 = v15;
       }
       T1 = ecl_function_dispatch(cl_env_copy,v10)(1, v11);
       v14 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v14,T0);
       goto L35;
L36:;
       v9variables = ecl_cdr(v13);
       goto L27;
      }
     }
    }
L27:;
    T0 = CONS(ECL_SYM("AND",87),v9variables);
    T1 = cl_list(4, ECL_SYM("IF",946), T0, v6then_form, v7else_form);
    value0 = cl_list(3, ECL_SYM("LET",477), v8binding_list, T1);
    return value0;
   }
  }
 }
}
/*      local function WHEN-LET                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2when_let(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bindings;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bindings = v5;
   }
   {
    cl_object v5binding_list;
    cl_object v6variables;
    if (!(ECL_CONSP(v4bindings))) { goto L9; }
    T0 = ecl_car(v4bindings);
    if (!(ECL_SYMBOLP(T0))) { goto L9; }
    v5binding_list = ecl_list1(v4bindings);
    goto L8;
L9:;
    v5binding_list = v4bindings;
L8:;
    {
     cl_object v7;
     v7 = (ECL_SYM("CAR",180)->symbol.gfdef);
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v5binding_list;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ecl_list1(ECL_NIL);
       v11 = v10;
L20:;
       if (!(ecl_endp(v9))) { goto L22; }
       goto L21;
L22:;
       v8 = _ecl_car(v9);
       {
        cl_object v12;
        v12 = _ecl_cdr(v9);
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v9 = v12;
       }
       {
        cl_object v12;
        v12 = v11;
        if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
        T0 = v12;
       }
       T1 = ecl_function_dispatch(cl_env_copy,v7)(1, v8);
       v11 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v11,T0);
       goto L20;
L21:;
       v6variables = ecl_cdr(v10);
       goto L12;
      }
     }
    }
L12:;
    T0 = CONS(ECL_SYM("AND",87),v6variables);
    T1 = cl_listX(3, ECL_SYM("WHEN",905), T0, v3);
    value0 = cl_list(3, ECL_SYM("LET",477), v5binding_list, T1);
    return value0;
   }
  }
 }
}
/*      local function WHEN-LET*                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4when_let_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bindings;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bindings = v5;
   }
   {
    cl_object v5binding_list;
    if (!(ECL_CONSP(v4bindings))) { goto L9; }
    T0 = ecl_car(v4bindings);
    if (!(ECL_SYMBOLP(T0))) { goto L9; }
    v5binding_list = ecl_list1(v4bindings);
    goto L8;
L9:;
    v5binding_list = v4bindings;
L8:;
    T0 = ecl_car(v5binding_list);
    T1 = ecl_list1(T0);
    T2 = ecl_caar(v5binding_list);
    T4 = ecl_cdr(v5binding_list);
    T3 = LC3bind(T4, v3);
    T4 = cl_listX(3, ECL_SYM("WHEN",905), T2, T3);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T4);
    return value0;
   }
  }
 }
}
/*      local function BIND                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3bind(cl_object v1bindings, cl_object v2forms)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1bindings)) { goto L1; }
  T0 = ecl_car(v1bindings);
  T1 = ecl_list1(T0);
  T2 = ecl_caar(v1bindings);
  T4 = ecl_cdr(v1bindings);
  T3 = LC3bind(T4, v2forms);
  T4 = cl_listX(3, ECL_SYM("WHEN",905), T2, T3);
  T5 = cl_list(3, ECL_SYM("LET",477), T1, T4);
  value0 = ecl_list1(T5);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v2forms;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lib/alexandria/binding.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclam0zuatJiYACM_r9g2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/binding.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclam0zuatJiYACM_r9g2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[3]);                        /*  IF-LET          */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[4]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[4]);                        /*  WHEN-LET        */
  si_set_documentation(3, VV[1], ECL_SYM("FUNCTION",396), VVtemp[8]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[9], VVtemp[10]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[5]);                        /*  WHEN-LET*       */
  si_set_documentation(3, VV[2], ECL_SYM("FUNCTION",396), VVtemp[11]);
}
