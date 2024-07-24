/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/macros.lisp                            */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/macros.eclh"
/*      local function WITH-GENSYMS                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2with_gensyms(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4names;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4names = v5;
   }
   {
    cl_object v5;
    {
     cl_object v6;
     v6 = ecl_make_cfun((cl_objectfn_fixed)LC1__g16,ECL_NIL,Cblock,1);
     v5 = v6;
    }
    {
     cl_object v6;
     cl_object v7;
     v6 = ECL_NIL;
     {
      cl_object v8;
      v8 = v4names;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L16:;
      if (!(ecl_endp(v7))) { goto L18; }
      goto L17;
L18:;
      v6 = _ecl_car(v7);
      {
       cl_object v10;
       v10 = _ecl_cdr(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v7 = v10;
      }
      {
       cl_object v10;
       v10 = v9;
       if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
       T1 = v10;
      }
      T2 = ecl_function_dispatch(cl_env_copy,v5)(1, v6);
      v9 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v9,T1);
      goto L16;
L17:;
      T0 = ecl_cdr(v8);
      goto L8;
     }
    }
   }
L8:;
   value0 = cl_listX(3, ECL_SYM("LET",477), T0, v3);
   return value0;
  }
 }
}
/*      local function G16                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1__g16(cl_object v1name)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  SYMBOL          */
   cl_object v4;                                  /*  STRING          */
   if (!(ECL_SYMBOLP(v1name))) { goto L2; }
   T0 = ecl_symbol_name(v1name);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v1name;
   value0 = cl_env_copy->values[0];
   goto L1;
L2:;
   if (Null(cl_typep(2, v1name, VV[1]))) { goto L4; }
   T0 = ecl_car(v1name);
   T1 = ecl_cadr(v1name);
   T2 = cl_string(T1);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T2;
   cl_env_copy->values[0] = T0;
   value0 = cl_env_copy->values[0];
   goto L1;
L4:;
   value0 = si_etypecase_error(v1name, VV[2]);
L1:;
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   T0 = cl_list(2, ECL_SYM("GENSYM",400), v4);
   value0 = cl_list(2, v3, T0);
   return value0;
  }
 }
}
/*      local function WITH-UNIQUE-NAMES                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3with_unique_names(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4names;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4names = v5;
   }
   value0 = cl_listX(3, VV[0], v4names, v3);
   return value0;
  }
 }
}
/*      local function ONCE-ONLY                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC8once_only(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4specs;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4specs = v5;
   }
   {
    cl_object v5;
    cl_object v6;
    {
     cl_fixnum v7;
     v7 = ecl_length(v4specs);
     v5 = ecl_function_dispatch(cl_env_copy,VV[45])(2, ecl_make_fixnum(v7), VV[5]) /*  MAKE-GENSYM-LIST */;
    }
    {
     cl_object v7;
     {
      cl_object v8;
      v8 = ecl_make_cfun((cl_objectfn_fixed)LC4__g53,ECL_NIL,Cblock,1);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v4specs;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ecl_list1(ECL_NIL);
       v11 = v10;
L17:;
       if (!(ecl_endp(v9))) { goto L19; }
       goto L18;
L19:;
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
       goto L17;
L18:;
       v6 = ecl_cdr(v10);
       goto L9;
      }
     }
    }
L9:;
    {
     cl_object v7;
     {
      cl_object v8;
      v8 = ecl_make_cfun((cl_objectfn_fixed)LC5__g68,ECL_NIL,Cblock,2);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v5;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ECL_NIL;
       {
        cl_object v12;
        v12 = v6;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v11 = v12;
       }
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L47:;
        if (!(ecl_endp(v9))) { goto L49; }
        goto L48;
L49:;
        v8 = _ecl_car(v9);
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        if (!(ecl_endp(v11))) { goto L57; }
        goto L48;
L57:;
        v10 = _ecl_car(v11);
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
         T1 = v14;
        }
        T2 = ecl_function_dispatch(cl_env_copy,v7)(2, v8, v10);
        v13 = ecl_list1(T2);
        (ECL_CONS_CDR(T1)=v13,T1);
        goto L47;
L48:;
        T0 = ecl_cdr(v12);
        goto L35;
       }
      }
     }
    }
L35:;
    {
     cl_object v7;
     {
      cl_object v8;
      v8 = ecl_make_cfun((cl_objectfn_fixed)LC6__g80,ECL_NIL,Cblock,2);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v5;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ECL_NIL;
       {
        cl_object v12;
        v12 = v6;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v11 = v12;
       }
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L85:;
        if (!(ecl_endp(v9))) { goto L87; }
        goto L86;
L87:;
        v8 = _ecl_car(v9);
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        if (!(ecl_endp(v11))) { goto L95; }
        goto L86;
L95:;
        v10 = _ecl_car(v11);
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
         T2 = v14;
        }
        T3 = ecl_function_dispatch(cl_env_copy,v7)(2, v8, v10);
        v13 = ecl_list1(T3);
        (ECL_CONS_CDR(T2)=v13,T2);
        goto L85;
L86:;
        T1 = ecl_cdr(v12);
        goto L73;
       }
      }
     }
    }
L73:;
    T2 = CONS(ECL_SYM("LIST",481),T1);
    {
     cl_object v7;
     {
      cl_object v8;
      v8 = ecl_make_cfun((cl_objectfn_fixed)LC7__g92,ECL_NIL,Cblock,2);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v6;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ECL_NIL;
       {
        cl_object v12;
        v12 = v5;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v11 = v12;
       }
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L123:;
        if (!(ecl_endp(v9))) { goto L125; }
        goto L124;
L125:;
        v8 = _ecl_car(v9);
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        if (!(ecl_endp(v11))) { goto L133; }
        goto L124;
L133:;
        v10 = _ecl_car(v11);
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
         T4 = v14;
        }
        T5 = ecl_function_dispatch(cl_env_copy,v7)(2, v8, v10);
        v13 = ecl_list1(T5);
        (ECL_CONS_CDR(T4)=v13,T4);
        goto L123;
L124:;
        T3 = ecl_cdr(v12);
        goto L111;
       }
      }
     }
    }
L111:;
    T4 = cl_listX(3, ECL_SYM("LET",477), T3, v3);
    T5 = cl_list(4, ECL_SYM("LIST",481), VV[7], T2, T4);
    value0 = cl_list(3, ECL_SYM("LET",477), T0, T5);
    return value0;
   }
  }
 }
}
/*      local function G53                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4__g53(cl_object v1spec)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1spec))) { goto L1; }
  {
   cl_object v2;
   cl_object v3name;
   cl_object v4form;
   v2 = v1spec;
   if (!(v2==ECL_NIL)) { goto L5; }
   si_dm_too_few_arguments(v1spec);
L5:;
   {
    cl_object v5;
    v5 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3name = v5;
   }
   if (!(v2==ECL_NIL)) { goto L11; }
   si_dm_too_few_arguments(v1spec);
L11:;
   {
    cl_object v5;
    v5 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4form = v5;
   }
   if (Null(v2)) { goto L16; }
   si_dm_too_many_arguments(v1spec);
L16:;
   value0 = CONS(v3name,v4form);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_SYMBOLP(v1spec))) { goto L18; }
  value0 = CONS(v1spec,v1spec);
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  value0 = si_etypecase_error(v1spec, VV[6]);
  return value0;
 }
}
/*      local function G68                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5__g68(cl_object v1g, cl_object v2n)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v2n);
  T1 = cl_string(T0);
  T2 = cl_list(2, ECL_SYM("GENSYM",400), T1);
  value0 = cl_list(2, v1g, T2);
  return value0;
 }
}
/*      local function G80                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6__g80(cl_object v1g, cl_object v2n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cdr(v2n);
  value0 = cl_list(3, ECL_SYM("LIST",481), v1g, T0);
  return value0;
 }
}
/*      local function G92                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC7__g92(cl_object v1n, cl_object v2g)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1n);
  value0 = cl_list(2, T0, v2g);
  return value0;
 }
}
/*      function definition for PARSE-BODY                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9parse_body(cl_narg narg, cl_object v1body, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2documentation;
  cl_object v3whole;
  ecl_va_list args; ecl_va_start(args,v1body,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L9parse_bodykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2documentation = keyvars[0];
   v3whole = keyvars[1];
  }
  {
   cl_object v4doc;
   cl_object v5decls;
   cl_object v6current;
   v4doc = ECL_NIL;
   v5decls = ECL_NIL;
   v6current = ECL_NIL;
L5:;
   v6current = ecl_car(v1body);
   if (Null(v2documentation)) { goto L8; }
   if (!(ECL_STRINGP(v6current))) { goto L8; }
   if (Null(ecl_cdr(v1body))) { goto L8; }
   if (Null(v4doc)) { goto L13; }
   value0 = v3whole;
   if ((value0)!=ECL_NIL) { goto L17; }
   T0 = v1body;
   goto L15;
L17:;
   T0 = value0;
   goto L15;
L15:;
   cl_error(2, VV[9], T0);
   goto L12;
L13:;
   {
    cl_object v7;
    v7 = v1body;
    {
     cl_object v8;
     v8 = v7;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
    }
    if (Null(v7)) { goto L24; }
    {
     cl_object v8;
     v8 = ECL_CONS_CDR(v7);
     v1body = v8;
     v7 = ECL_CONS_CAR(v7);
    }
L24:;
    v4doc = v7;
   }
L12:;
   goto L5;
L8:;
   if (!(ECL_LISTP(v6current))) { goto L30; }
   T0 = ecl_car(v6current);
   if (!((T0)==(ECL_SYM("DECLARE",274)))) { goto L30; }
   {
    cl_object v7;
    v7 = v1body;
    {
     cl_object v8;
     v8 = v7;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
    }
    if (Null(v7)) { goto L40; }
    {
     cl_object v8;
     v8 = ECL_CONS_CDR(v7);
     v1body = v8;
     v7 = ECL_CONS_CAR(v7);
    }
L40:;
    T0 = v7;
   }
   v5decls = CONS(T0,v5decls);
   goto L5;
L30:;
   T0 = cl_nreverse(v5decls);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v4doc;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v1body;
   return cl_env_copy->values[0];
  }
 }
}
/*      function definition for PARSE-ORDINARY-LAMBDA-LIST            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L13parse_ordinary_lambda_list(cl_narg narg, cl_object v1lambda_list, ...)
{
 cl_object T0, T1, T2, T3;
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2normalize;
  cl_object v3normalize_optional;
  cl_object v4normalize_keyword;
  cl_object v5normalize_auxilary;
  ecl_va_list args; ecl_va_start(args,v1lambda_list,narg,1);
  lex0[0] = v1lambda_list;                        /*  LAMBDA-LIST     */
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L13parse_ordinary_lambda_listkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v2normalize = ECL_T;
   } else {
    v2normalize = keyvars[0];
   }
   lex0[1] = keyvars[1];                          /*  ALLOW-SPECIALIZERS */
   if (Null(keyvars[7])) {
    v3normalize_optional = v2normalize;
   } else {
    v3normalize_optional = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v4normalize_keyword = v2normalize;
   } else {
    v4normalize_keyword = keyvars[3];
   }
   if (Null(keyvars[9])) {
    v5normalize_auxilary = v2normalize;
   } else {
    v5normalize_auxilary = keyvars[4];
   }
  }
  {
   cl_object v6state;
   cl_object v7allow_other_keys;
   cl_object v8auxp;
   cl_object v9required;
   cl_object v10optional;
   cl_object v11rest;
   cl_object v12keys;
   cl_object v13keyp;
   cl_object v14aux;
   v6state = ECL_SYM("REQUIRED",1008);
   v7allow_other_keys = ECL_NIL;
   v8auxp = ECL_NIL;
   v9required = ECL_NIL;
   v10optional = ECL_NIL;
   v11rest = ECL_NIL;
   v12keys = ECL_NIL;
   v13keyp = ECL_NIL;
   v14aux = ECL_NIL;
   {
    cl_object v15;
    v15 = lex0[0];
    goto L18;
L17:;
    {
     cl_object v16elt;
     v16elt = ecl_car(v15);
     {
      cl_object v17;
      v17 = v16elt;
      if (!((v17)==(ECL_SYM("&OPTIONAL",11)))) { goto L24; }
      if (!((v6state)==(ECL_SYM("REQUIRED",1008)))) { goto L26; }
      v6state = v16elt;
      goto L22;
L26:;
      LC10fail(lex0, v16elt);
      goto L22;
L24:;
      if (!((v17)==(ECL_SYM("&REST",12)))) { goto L29; }
      if (!(ecl_eql(v6state,ECL_SYM("REQUIRED",1008)))) { goto L36; }
      goto L33;
      goto L34;
L36:;
      goto L34;
L34:;
      if (!((v6state)==(ECL_SYM("&OPTIONAL",11)))) { goto L31; }
      goto L32;
L33:;
L32:;
      v6state = v16elt;
      goto L22;
L31:;
      LC10fail(lex0, v16elt);
      goto L22;
L29:;
      if (!((v17)==(ECL_SYM("&KEY",10)))) { goto L40; }
      if (!(ecl_eql(v6state,ECL_SYM("REQUIRED",1008)))) { goto L48; }
      goto L45;
      goto L46;
L48:;
      goto L46;
L46:;
      if (!((v6state)==(ECL_SYM("&OPTIONAL",11)))) { goto L52; }
      goto L45;
      goto L50;
L52:;
      goto L50;
L50:;
      if (!(ecl_eql(v6state,VV[17]))) { goto L43; }
      goto L44;
L45:;
L44:;
      v6state = v16elt;
      goto L42;
L43:;
      LC10fail(lex0, v16elt);
L42:;
      v13keyp = ECL_T;
      goto L22;
L40:;
      if (!((v17)==(ECL_SYM("&ALLOW-OTHER-KEYS",6)))) { goto L57; }
      if (!((v6state)==(ECL_SYM("&KEY",10)))) { goto L59; }
      v7allow_other_keys = ECL_T;
      v6state = v16elt;
      goto L22;
L59:;
      LC10fail(lex0, v16elt);
      goto L22;
L57:;
      if (!((v17)==(ECL_SYM("&AUX",7)))) { goto L64; }
      if (!((v6state)==(ECL_SYM("&REST",12)))) { goto L66; }
      LC10fail(lex0, v16elt);
      goto L22;
L66:;
      if (Null(v8auxp)) { goto L68; }
      ecl_function_dispatch(cl_env_copy,VV[55])(3, VV[19], v16elt, lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
      goto L22;
L68:;
      v8auxp = ECL_T;
      v6state = v16elt;
      goto L22;
L64:;
      if (!((v16elt)==(ECL_SYM("&WHOLE",13)))) { goto L78; }
      goto L75;
      goto L76;
L78:;
      goto L76;
L76:;
      if (!((v16elt)==(ECL_SYM("&ENVIRONMENT",9)))) { goto L82; }
      goto L75;
      goto L80;
L82:;
      goto L80;
L80:;
      if (!((v16elt)==(ECL_SYM("&BODY",8)))) { goto L73; }
      goto L74;
L75:;
L74:;
      ecl_function_dispatch(cl_env_copy,VV[55])(3, VV[23], v16elt, lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
L73:;
      {
       cl_object v18;
       v18 = v6state;
       if (!(ecl_eql(v18,ECL_SYM("REQUIRED",1008)))) { goto L86; }
       LC11check_variable(2, lex0, v16elt, VV[24]);
       v9required = CONS(v16elt,v9required);
       goto L22;
L86:;
       if (!((v18)==(ECL_SYM("&OPTIONAL",11)))) { goto L90; }
       if (!(ECL_CONSP(v16elt))) { goto L93; }
       {
        cl_object v19;
        cl_object v20;
        cl_object v21name;
        v19 = v16elt;
        v20 = v19;
        if (!(v20==ECL_NIL)) { goto L98; }
        si_dm_too_few_arguments(v19);
L98:;
        {
         cl_object v22;
         v22 = ecl_car(v20);
         v20 = ecl_cdr(v20);
         v21name = v22;
        }
        LC11check_variable(2, lex0, v21name, VV[25]);
        if (Null(ecl_cdr(v20))) { goto L104; }
        LC12check_spec(lex0, v20, VV[26]);
        goto L92;
L104:;
        if (Null(v3normalize_optional)) { goto L92; }
        v16elt = ecl_append(v16elt,VV[27]);
        goto L92;
       }
L93:;
       LC11check_variable(2, lex0, v16elt, VV[25]);
       if (Null(v3normalize_optional)) { goto L92; }
       v16elt = CONS(v16elt,VV[28]);
L92:;
       T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v16elt) /*  ENSURE-LIST */;
       v10optional = CONS(T0,v10optional);
       goto L22;
L90:;
       if (!((v18)==(ECL_SYM("&REST",12)))) { goto L112; }
       LC11check_variable(2, lex0, v16elt, VV[29]);
       v11rest = v16elt;
       v6state = VV[17];
       goto L22;
L112:;
       if (!((v18)==(ECL_SYM("&KEY",10)))) { goto L118; }
       if (!(ECL_CONSP(v16elt))) { goto L121; }
       {
        cl_object v19;
        cl_object v20;
        cl_object v21var_or_kv;
        cl_object v22tail;
        v19 = v16elt;
        v20 = v19;
        if (!(v20==ECL_NIL)) { goto L126; }
        si_dm_too_few_arguments(v19);
L126:;
        {
         cl_object v23;
         v23 = ecl_car(v20);
         v20 = ecl_cdr(v20);
         v21var_or_kv = v23;
        }
        v22tail = v20;
        if (!(ECL_CONSP(v21var_or_kv))) { goto L133; }
        {
         cl_object v23;
         cl_object v24keyword;
         cl_object v25var;
         v23 = v21var_or_kv;
         if (!(v23==ECL_NIL)) { goto L137; }
         si_dm_too_few_arguments(v21var_or_kv);
L137:;
         {
          cl_object v26;
          v26 = ecl_car(v23);
          v23 = ecl_cdr(v23);
          v24keyword = v26;
         }
         if (!(v23==ECL_NIL)) { goto L143; }
         si_dm_too_few_arguments(v21var_or_kv);
L143:;
         {
          cl_object v26;
          v26 = ecl_car(v23);
          v23 = ecl_cdr(v23);
          v25var = v26;
         }
         if (Null(v23)) { goto L148; }
         si_dm_too_many_arguments(v21var_or_kv);
L148:;
         if (ECL_SYMBOLP(v24keyword)) { goto L150; }
         ecl_function_dispatch(cl_env_copy,VV[55])(3, VV[30], v24keyword, lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
L150:;
         LC11check_variable(2, lex0, v25var, VV[31]);
         goto L132;
        }
L133:;
        LC11check_variable(2, lex0, v21var_or_kv, VV[31]);
        if (Null(v4normalize_keyword)) { goto L132; }
        T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v21var_or_kv) /*  MAKE-KEYWORD */;
        v21var_or_kv = cl_list(2, T0, v21var_or_kv);
L132:;
        if (Null(ecl_cdr(v22tail))) { goto L156; }
        LC12check_spec(lex0, v22tail, VV[32]);
        goto L155;
L156:;
        if (Null(v4normalize_keyword)) { goto L155; }
        v22tail = ecl_append(v22tail,VV[27]);
L155:;
        v16elt = CONS(v21var_or_kv,v22tail);
        goto L120;
       }
L121:;
       LC11check_variable(2, lex0, v16elt, VV[31]);
       if (Null(v4normalize_keyword)) { goto L163; }
       T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v16elt) /*  MAKE-KEYWORD */;
       T1 = cl_list(2, T0, v16elt);
       v16elt = cl_list(3, T1, ECL_NIL, ECL_NIL);
       goto L162;
L163:;
L162:;
L120:;
       v12keys = CONS(v16elt,v12keys);
       goto L22;
L118:;
       if (!((v18)==(ECL_SYM("&AUX",7)))) { goto L166; }
       if (!(ECL_CONSP(v16elt))) { goto L169; }
       {
        cl_object v19;
        cl_object v20var;
        cl_object v21init;
        v19 = v16elt;
        if (!(v19==ECL_NIL)) { goto L173; }
        si_dm_too_few_arguments(v16elt);
L173:;
        {
         cl_object v22;
         v22 = ecl_car(v19);
         v19 = ecl_cdr(v19);
         v20var = v22;
        }
        if (Null(v19)) { goto L179; }
        {
         cl_object v22;
         v22 = ecl_car(v19);
         v19 = ecl_cdr(v19);
         v21init = v22;
         goto L178;
        }
L179:;
        v21init = ECL_NIL;
L178:;
        if (Null(v19)) { goto L184; }
        si_dm_too_many_arguments(v16elt);
L184:;
        LC11check_variable(2, lex0, v20var, VV[33]);
        goto L168;
       }
L169:;
       LC11check_variable(2, lex0, v16elt, VV[33]);
       if (Null(v5normalize_auxilary)) { goto L189; }
       T0 = VV[27];
       goto L188;
L189:;
       T0 = ECL_NIL;
L188:;
       v16elt = CONS(v16elt,T0);
L168:;
       v14aux = CONS(v16elt,v14aux);
       goto L22;
L166:;
       ecl_function_dispatch(cl_env_copy,VV[55])(2, VV[34], lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
      }
     }
L22:;
    }
    v15 = ecl_cdr(v15);
L18:;
    if (Null(v15)) { goto L194; }
    goto L17;
L194:;
   }
   T0 = cl_nreverse(v9required);
   T1 = cl_nreverse(v10optional);
   T2 = cl_nreverse(v12keys);
   T3 = cl_nreverse(v14aux);
   cl_env_copy->nvalues = 7;
   cl_env_copy->values[6] = v13keyp;
   cl_env_copy->values[5] = T3;
   cl_env_copy->values[4] = v7allow_other_keys;
   cl_env_copy->values[3] = T2;
   cl_env_copy->values[2] = v11rest;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*      local function CHECK-SPEC                                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12check_spec(volatile cl_object *lex0, cl_object v1spec, cl_object v2what)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4init;
   cl_object v5suppliedp;
   v3 = v1spec;
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1spec);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4init = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1spec);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5suppliedp = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1spec);
L14:;
   value0 = LC11check_variable(3, lex0, v5suppliedp, v2what, ECL_NIL);
   return value0;
  }
 }
}
/*      local function CHECK-VARIABLE                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11check_variable(cl_narg narg, volatile cl_object *lex0, cl_object v1elt, cl_object v2what, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3allow_specializers;
  va_list args; va_start(args,v2what);
  {
   int i = 2;
   if (i >= narg) {
    v3allow_specializers = lex0[1];
   } else {
    i++;
    v3allow_specializers = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (ECL_SYMBOLP(v1elt)) { goto L7; }
  if (Null(v3allow_specializers)) { goto L5; }
  if (!(ECL_CONSP(v1elt))) { goto L5; }
  {
   cl_fixnum v4;
   v4 = ecl_length(v1elt);
   if (!((2)==(v4))) { goto L5; }
  }
  T0 = ecl_car(v1elt);
  if (!(ECL_SYMBOLP(T0))) { goto L5; }
  goto L6;
L7:;
L6:;
  if (Null(cl_constantp(1, v1elt))) { goto L2; }
  goto L3;
L5:;
  goto L3;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[55])(4, VV[12], v2what, v1elt, lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function FAIL                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC10fail(volatile cl_object *lex0, cl_object v1elt)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[55])(3, VV[11], v1elt, lex0[0]) /*  SIMPLE-PROGRAM-ERROR */;
  return value0;
 }
}
/*      function definition for EXPAND-DESTRUCTURING-CASE             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L15expand_destructuring_case(cl_object v1key, cl_object v2clauses, cl_object v3case)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;
   v4 = cl_gensym(1, VV[36]);
   T0 = cl_list(2, v4, v1key);
   T1 = ecl_list1(T0);
   {
    cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(v4,env1);                  /*  KEY             */
    T3 = cl_list(3, ECL_SYM("TYPEP",875), ECL_CONS_CAR(CLV0), VV[37]);
    T4 = cl_list(2, ECL_SYM("CAR",180), ECL_CONS_CAR(CLV0));
    {
     cl_object v5;
     {
      cl_object v6;
      v6 = ecl_make_cclosure_va((cl_objectfn)LC14__g169,env1,Cblock);
      v5 = v6;
     }
     {
      cl_object v6;
      cl_object v7;
      v6 = ECL_NIL;
      {
       cl_object v8;
       v8 = v2clauses;
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v7 = v8;
      }
      {
       cl_object v8;
       cl_object v9;
       v8 = ecl_list1(ECL_NIL);
       v9 = v8;
L11:;
       if (!(ecl_endp(v7))) { goto L13; }
       goto L12;
L13:;
       v6 = _ecl_car(v7);
       {
        cl_object v10;
        v10 = _ecl_cdr(v7);
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        v7 = v10;
       }
       {
        cl_object v10;
        v10 = v9;
        if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
        T6 = v10;
       }
       T7 = ecl_function_dispatch(cl_env_copy,v5)(1, v6);
       v9 = ecl_list1(T7);
       (ECL_CONS_CDR(T6)=v9,T6);
       goto L11;
L12:;
       T5 = ecl_cdr(v8);
       goto L3;
      }
     }
    }
L3:;
    T6 = cl_listX(3, v3case, T4, T5);
    T7 = cl_list(2, ECL_SYM("QUOTE",679), v3case);
    T8 = cl_list(4, ECL_SYM("ERROR",337), VV[38], T7, ECL_CONS_CAR(CLV0));
    T2 = cl_list(4, ECL_SYM("IF",946), T3, T6, T8);
   }
   value0 = cl_list(3, ECL_SYM("LET",477), T1, T2);
   return value0;
  }
 }
}
/*      closure G169                                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14__g169(cl_narg narg, cl_object v1clause, ...)
{
 cl_object T0, T1;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  KEY             */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   cl_object v5keys;
   v2 = v1clause;
   if (!(v2==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1clause);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3 = v6;
   }
   v4 = v3;
   if (!(v4==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1clause);
L10:;
   {
    cl_object v6;
    v6 = ecl_car(v4);
    v4 = ecl_cdr(v4);
    v5keys = v6;
   }
   T0 = cl_list(2, ECL_SYM("CDR",198), ECL_CONS_CAR(CLV0));
   T1 = cl_listX(4, ECL_SYM("DESTRUCTURING-BIND",300), v4, T0, v2);
   value0 = cl_list(2, v5keys, T1);
   return value0;
  }
 }
 }
}
/*      local function DESTRUCTURING-CASE                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC16destructuring_case(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4keyform;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4keyform = v5;
   }
   value0 = L15expand_destructuring_case(v4keyform, v3, ECL_SYM("CASE",181));
   return value0;
  }
 }
}
/*      local function DESTRUCTURING-CCASE                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC17destructuring_ccase(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4keyform;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4keyform = v5;
   }
   value0 = L15expand_destructuring_case(v4keyform, v3, ECL_SYM("CCASE",183));
   return value0;
  }
 }
}
/*      local function DESTRUCTURING-ECASE                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC18destructuring_ecase(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4keyform;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4keyform = v5;
   }
   value0 = L15expand_destructuring_case(v4keyform, v3, ECL_SYM("ECASE",321));
   return value0;
  }
 }
}

#include "lib/alexandria/macros.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4KRmknIfrdJJM_8gg2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/macros.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecl4KRmknIfrdJJM_8gg2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[42]);                       /*  WITH-GENSYMS    */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[4]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[43]);                       /*  WITH-UNIQUE-NAMES */
  si_set_documentation(3, VV[3], ECL_SYM("FUNCTION",396), VVtemp[7]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[44]);                       /*  ONCE-ONLY       */
  si_set_documentation(3, VV[4], ECL_SYM("FUNCTION",396), VVtemp[11]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[12], VVtemp[13]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[14]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[46]);                          /*  PARSE-BODY      */
  si_set_documentation(3, VV[8], ECL_SYM("FUNCTION",396), VVtemp[15]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[10], ECL_SYM("LOCATION",1777), VVtemp[16], VVtemp[17]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[10], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[18]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[49]);                          /*  PARSE-ORDINARY-LAMBDA-LIST */
  si_set_documentation(3, VV[10], ECL_SYM("FUNCTION",396), VVtemp[19]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LOCATION",1777), VVtemp[20], VVtemp[21]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[22]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[58]);                          /*  EXPAND-DESTRUCTURING-CASE */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LOCATION",1777), VVtemp[23], VVtemp[24]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[59]);                       /*  DESTRUCTURING-CASE */
  si_set_documentation(3, VV[39], ECL_SYM("FUNCTION",396), VVtemp[26]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[60]);                       /*  DESTRUCTURING-CCASE */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LOCATION",1777), VVtemp[29], VVtemp[30]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[61]);                       /*  DESTRUCTURING-ECASE */
  {
   cl_object v1;
   v1 = VVtemp[31];
   goto L54;
L53:;
   {
    cl_object v2name;
    v2name = ecl_car(v1);
    {
     cl_object v3;
     v3 = (cl_env_copy->function=(ECL_SYM("DOCUMENTATION",312)->symbol.gfdef))->cfun.entry(2, VV[39], ECL_SYM("FUNCTION",396)) /*  DOCUMENTATION */;
     (cl_env_copy->function=ECL_CONS_CAR(VV[62]))->cfun.entry(3, v3, v2name, ECL_SYM("FUNCTION",396)) /*  (SETF DOCUMENTATION) */;
    }
   }
   v1 = ecl_cdr(v1);
L54:;
   if (Null(v1)) { goto L62; }
   goto L53;
L62:;
  }
}
