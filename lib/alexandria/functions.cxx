/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/functions.lisp                         */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/functions.eclh"
/*      function definition for ENSURE-FUNCTION                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1ensure_function(cl_object v1function_designator)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_functionp(v1function_designator))) { goto L1; }
  value0 = v1function_designator;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = cl_fdefinition(v1function_designator);
  return value0;
 }
}
/*      local function ENSURE-FUNCTIONF/1                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3ensure_functionf_1(cl_object v1, cl_object v2si__env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4si___reference;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  VALS            */
    cl_object v8;                                 /*  STORES          */
    cl_object v9;                                 /*  SETTER          */
    cl_object v10;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    v6 = value0;
    v7 = cl_env_copy->values[1];
    v8 = cl_env_copy->values[2];
    v9 = cl_env_copy->values[3];
    v10 = cl_env_copy->values[4];
    {
     cl_object v11si__all_vars;
     {
      cl_object v12;
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC2__g5,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = ECL_NIL;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L13; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, VV[0], v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[2],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L13:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L22;
L21:;
      {
       cl_object v15;
       v15 = ecl_cdr(v12si__d);
       {
        cl_object v16;
        v16 = ecl_cdr(v13si__v);
        T0 = ecl_car(v12si__d);
        T1 = ecl_car(v13si__v);
        T2 = cl_list(2, T0, T1);
        v14si__let_list = CONS(T2,v14si__let_list);
        v13si__v = v16;
        v12si__d = v15;
       }
      }
L22:;
      if (v12si__d==ECL_NIL) { goto L28; }
      goto L21;
L28:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L33; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L33; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, VV[0], v10, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L32;
L33:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, VV[0], v10, T3);
L32:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[2],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G5                                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2__g5(cl_object v1si__v)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  value0 = cl_list(2, T0, v1si__v);
  return value0;
 }
}
/*      local function ENSURE-FUNCTIONF                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5ensure_functionf(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4;
    {
     cl_object v5;
     v5 = ecl_make_cfun((cl_objectfn_fixed)LC4__g22,ECL_NIL,Cblock,1);
     v4 = v5;
    }
    {
     cl_object v5;
     cl_object v6;
     v5 = ECL_NIL;
     {
      cl_object v7;
      v7 = v3;
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v6 = v7;
     }
     {
      cl_object v7;
      cl_object v8;
      v7 = ecl_list1(ECL_NIL);
      v8 = v7;
L10:;
      if (!(ecl_endp(v6))) { goto L12; }
      goto L11;
L12:;
      v5 = _ecl_car(v6);
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
       T1 = v9;
      }
      T2 = ecl_function_dispatch(cl_env_copy,v4)(1, v5);
      v8 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v8,T1);
      goto L10;
L11:;
      T0 = ecl_cdr(v7);
      goto L2;
     }
    }
   }
L2:;
   value0 = CONS(ECL_SYM("PROGN",671),T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function G22                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4__g22(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(2, VV[1], v1x);
  return value0;
 }
}
/*      function definition for DISJOIN                               */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object L8disjoin(cl_narg narg, cl_object v1predicate, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2more_predicates;
  ecl_va_list args; ecl_va_start(args,v1predicate,narg,1);
  v2more_predicates = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   cl_object v4;
   cl_object env1 = env0;
   if (Null(cl_functionp(v1predicate))) { goto L2; }
   v3 = v1predicate;
   goto L1;
L2:;
   v3 = cl_fdefinition(v1predicate);
L1:;
   {
    cl_object v5;
    v5 = (VV[0]->symbol.gfdef);
    {
     cl_object v6;
     cl_object v7;
     v6 = ECL_NIL;
     {
      cl_object v8;
      v8 = v2more_predicates;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L12:;
      if (!(v7==ECL_NIL)) { goto L14; }
      goto L13;
L14:;
      v6 = ECL_CONS_CAR(v7);
      {
       cl_object v10;
       v10 = ECL_CONS_CDR(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v7 = v10;
      }
      {
       cl_object v10;
       v10 = v9;
       if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
       T0 = v10;
      }
      T1 = ecl_function_dispatch(cl_env_copy,v5)(1, v6);
      v9 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v9,T0);
      goto L12;
L13:;
      v4 = _ecl_cdr(v8);
      goto L4;
     }
    }
   }
L4:;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(v3,env1);                   /*  PREDICATE       */
   CLV1 = env1 = CONS(v4,env1);                   /*  MORE-PREDICATES */
   {
    cl_object v5;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC7__g35,env1,Cblock);
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      closure G35                                                   */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC7__g35(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  MORE-PREDICATES */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1arguments = cl_grab_rest_args(args);
  CLV2 = env0 = CONS(v1arguments,env0);           /*  ARGUMENTS       */
  ecl_va_end(args);
  value0 = cl_apply(2, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV2));
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v2;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC6__g36,env0,Cblock);
   T0 = v2;
  }
  value0 = cl_some(2, T0, ECL_CONS_CAR(CLV1));
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      closure G36                                                   */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC6__g36(cl_narg narg, cl_object v1p, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  ARGUMENTS       */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_functionp(v1p);
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("FUNCTION",396),v1p);
  value0 = cl_apply(2, v1p, ECL_CONS_CAR(CLV2));
  return value0;
 }
 }
}
/*      function definition for CONJOIN                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L10conjoin(cl_narg narg, cl_object v1predicate, ...)
{
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2more_predicates;
  ecl_va_list args; ecl_va_start(args,v1predicate,narg,1);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1predicate,env0);           /*  PREDICATE       */
  v2more_predicates = cl_grab_rest_args(args);
  CLV1 = env0 = CONS(v2more_predicates,env0);     /*  MORE-PREDICATES */
  ecl_va_end(args);
  if (!(ECL_CONS_CAR(CLV1)==ECL_NIL)) { goto L1; }
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC9__g37,env0,Cblock);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G37                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC9__g37(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  MORE-PREDICATES */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(cl_apply(2, ECL_CONS_CAR(CLV0), v1arguments))) { goto L2; }
  {
   cl_object v2;
   cl_object v3;
   cl_object v4tail;
   cl_object v5head;
   v2 = ecl_cdr(ECL_CONS_CAR(CLV1));
   v3 = ecl_car(ECL_CONS_CAR(CLV1));
   v4tail = v2;
   v5head = v3;
   goto L10;
L9:;
   if ((cl_apply(2, v5head, v1arguments))!=ECL_NIL) { goto L12; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   {
    cl_object v6;
    v6 = ecl_cdr(v4tail);
    v5head = ecl_car(v4tail);
    v4tail = v6;
   }
L10:;
   if (Null(v4tail)) { goto L17; }
   goto L9;
L17:;
   value0 = cl_apply(2, v5head, v1arguments);
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      function definition for COMPOSE                               */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object L13compose(cl_narg narg, cl_object v1function, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2more_functions;
  ecl_va_list args; ecl_va_start(args,v1function,narg,1);
  v2more_functions = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   v3 = ecl_make_cfun((cl_objectfn_fixed)LC12__g42,ECL_NIL,Cblock,2);
   T0 = v3;
  }
  value0 = cl_reduce(4, T0, v2more_functions, VV[7], v1function);
  return value0;
 }
}
/*      local function G42                                            */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC12__g42(cl_object v1f, cl_object v2g)
{
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object env1 = env0;
   if (Null(cl_functionp(v1f))) { goto L2; }
   v3 = v1f;
   goto L1;
L2:;
   v3 = cl_fdefinition(v1f);
L1:;
   if (Null(cl_functionp(v2g))) { goto L5; }
   v4 = v2g;
   goto L4;
L5:;
   v4 = cl_fdefinition(v2g);
L4:;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(v3,env1);                   /*  F               */
   CLV1 = env1 = CONS(v4,env1);                   /*  G               */
   {
    cl_object v5;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC11__g47,env1,Cblock);
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      closure G47                                                   */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC11__g47(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  G               */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = cl_apply(2, ECL_CONS_CAR(CLV1), v1arguments);
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, T0);
  return value0;
 }
 }
}
/*      local function COMPOSE                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC15compose(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4function;
   T0 = ecl_car(v1);
   if (!((T0)==(ECL_SYM("FUNCALL",394)))) { goto L2; }
   T0 = ecl_caadr(v1);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L2; }
   v3 = ecl_cddr(v1);
   goto L1;
L2:;
   v3 = ecl_cdr(v1);
L1:;
   if (!(v3==ECL_NIL)) { goto L6; }
   si_dm_too_few_arguments(v1);
L6:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4function = v5;
   }
   {
    cl_object v5args;
    cl_object v6funs;
    v5args = CONS(v4function,v3);
    {
     cl_fixnum v7;
     v7 = ecl_length(v5args);
     v6funs = ecl_function_dispatch(cl_env_copy,VV[28])(2, ecl_make_fixnum(v7), VV[9]) /*  MAKE-GENSYM-LIST */;
    }
    {
     cl_object v7f;
     cl_object v8;
     v7f = ECL_NIL;
     {
      cl_object v9;
      v9 = v6funs;
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v8 = v9;
     }
     {
      cl_object v9arg;
      cl_object v10;
      v9arg = ECL_NIL;
      v10 = v5args;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L22:;
       if (!(ecl_endp(v8))) { goto L24; }
       goto L23;
L24:;
       v7f = _ecl_car(v8);
       {
        cl_object v13;
        v13 = _ecl_cdr(v8);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v8 = v13;
       }
       if (!(ecl_endp(v10))) { goto L32; }
       goto L23;
L32:;
       v9arg = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       {
        cl_object v13;
        v13 = v12;
        if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
        T1 = v13;
       }
       T2 = cl_list(2, VV[0], v9arg);
       T3 = cl_list(2, v7f, T2);
       v12 = ecl_list1(T3);
       (ECL_CONS_CDR(T1)=v12,T1);
       goto L22;
L23:;
       T0 = ecl_cdr(v11);
       goto L13;
      }
     }
    }
L13:;
    T1 = LC14compose_1(v6funs);
    T2 = cl_list(4, ECL_SYM("LAMBDA",452), VV[11], VV[12], T1);
    value0 = cl_list(4, ECL_SYM("LET",477), T0, VV[10], T2);
    return value0;
   }
  }
 }
}
/*      local function COMPOSE-1                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14compose_1(cl_object v1funs)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_cdr(v1funs))) { goto L1; }
  T0 = ecl_car(v1funs);
  T2 = ecl_cdr(v1funs);
  T1 = LC14compose_1(T2);
  value0 = cl_list(3, ECL_SYM("FUNCALL",394), T0, T1);
  return value0;
L1:;
  T0 = ecl_car(v1funs);
  value0 = cl_list(3, ECL_SYM("APPLY",89), T0, VV[8]);
  return value0;
 }
}
/*      function definition for MULTIPLE-VALUE-COMPOSE                */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object L18multiple_value_compose(cl_narg narg, cl_object v1function, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2more_functions;
  ecl_va_list args; ecl_va_start(args,v1function,narg,1);
  v2more_functions = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   v3 = ecl_make_cfun((cl_objectfn_fixed)LC17__g60,ECL_NIL,Cblock,2);
   T0 = v3;
  }
  value0 = cl_reduce(4, T0, v2more_functions, VV[7], v1function);
  return value0;
 }
}
/*      local function G60                                            */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC17__g60(cl_object v1f, cl_object v2g)
{
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object env1 = env0;
   if (Null(cl_functionp(v1f))) { goto L2; }
   v3 = v1f;
   goto L1;
L2:;
   v3 = cl_fdefinition(v1f);
L1:;
   if (Null(cl_functionp(v2g))) { goto L5; }
   v4 = v2g;
   goto L4;
L5:;
   v4 = cl_fdefinition(v2g);
L4:;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(v3,env1);                   /*  F               */
   CLV1 = env1 = CONS(v4,env1);                   /*  G               */
   {
    cl_object v5;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC16__g65,env1,Cblock);
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      closure G65                                                   */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC16__g65(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  G               */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    {
     cl_object v3;
     v3 = ECL_CONS_CAR(CLV0);
     cl_env_copy->values[0] = cl_apply(2, ECL_CONS_CAR(CLV1), v1arguments);
     ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,v3);
     value0 = cl_env_copy->values[0];
    }
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
 }
 }
}
/*      local function MULTIPLE-VALUE-COMPOSE                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC20multiple_value_compose(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4function;
   T0 = ecl_car(v1);
   if (!((T0)==(ECL_SYM("FUNCALL",394)))) { goto L2; }
   T0 = ecl_caadr(v1);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L2; }
   v3 = ecl_cddr(v1);
   goto L1;
L2:;
   v3 = ecl_cdr(v1);
L1:;
   if (!(v3==ECL_NIL)) { goto L6; }
   si_dm_too_few_arguments(v1);
L6:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4function = v5;
   }
   {
    cl_object v5args;
    cl_object v6funs;
    v5args = CONS(v4function,v3);
    {
     cl_fixnum v7;
     v7 = ecl_length(v5args);
     v6funs = ecl_function_dispatch(cl_env_copy,VV[28])(2, ecl_make_fixnum(v7), VV[14]) /*  MAKE-GENSYM-LIST */;
    }
    {
     cl_object v7;
     v7 = (ECL_SYM("LIST",481)->symbol.gfdef);
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v6funs;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ECL_NIL;
       v11 = v5args;
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L23:;
        if (!(ecl_endp(v9))) { goto L25; }
        goto L24;
L25:;
        v8 = _ecl_car(v9);
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        if (!(ecl_endp(v11))) { goto L33; }
        goto L24;
L33:;
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
        goto L23;
L24:;
        T0 = ecl_cdr(v12);
        goto L13;
       }
      }
     }
    }
L13:;
    T1 = LC19compose_1(v6funs);
    T2 = cl_list(4, ECL_SYM("LAMBDA",452), VV[11], VV[12], T1);
    value0 = cl_list(4, ECL_SYM("LET",477), T0, VV[10], T2);
    return value0;
   }
  }
 }
}
/*      local function COMPOSE-1                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19compose_1(cl_object v1funs)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_cdr(v1funs))) { goto L1; }
  T0 = ecl_car(v1funs);
  T2 = ecl_cdr(v1funs);
  T1 = LC19compose_1(T2);
  value0 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-CALL",573), T0, T1);
  return value0;
L1:;
  T0 = ecl_car(v1funs);
  value0 = cl_list(3, ECL_SYM("APPLY",89), T0, VV[8]);
  return value0;
 }
}
/*      function definition for CURRY                                 */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object L22curry(cl_narg narg, cl_object v1function, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1function,narg,1);
  v2arguments = cl_grab_rest_args(args);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2arguments,env0);           /*  ARGUMENTS       */
  ecl_va_end(args);
  {
   cl_object env1 = env0;
   if (Null(cl_functionp(v1function))) { goto L2; }
   T0 = v1function;
   goto L1;
L2:;
   T0 = cl_fdefinition(v1function);
L1:;
   CLV1 = env1 = CONS(T0,env1);                   /*  FN              */
   {
    cl_object v3;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC21__g84,env1,Cblock);
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      closure G84                                                   */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC21__g84(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  FN              */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1more;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1more = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    {
     cl_object v3;
     v3 = ECL_CONS_CAR(CLV1);
     cl_env_copy->values[0] = cl_values_list(ECL_CONS_CAR(CLV0));
     ecl_stack_frame_push_values(v2);
     cl_env_copy->values[0] = cl_values_list(v1more);
     ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,v3);
     value0 = cl_env_copy->values[0];
    }
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
 }
 }
}
/*      local function CURRY                                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC23curry(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4function;
   T0 = ecl_car(v1);
   if (!((T0)==(ECL_SYM("FUNCALL",394)))) { goto L2; }
   T0 = ecl_caadr(v1);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L2; }
   v3 = ecl_cddr(v1);
   goto L1;
L2:;
   v3 = ecl_cdr(v1);
L1:;
   if (!(v3==ECL_NIL)) { goto L6; }
   si_dm_too_few_arguments(v1);
L6:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4function = v5;
   }
   {
    cl_object v5;
    cl_object v6;
    {
     cl_fixnum v7;
     v7 = ecl_length(v3);
     v5 = ecl_function_dispatch(cl_env_copy,VV[28])(2, ecl_make_fixnum(v7), VV[16]) /*  MAKE-GENSYM-LIST */;
    }
    v6 = cl_gensym(1, VV[17]);
    T0 = cl_list(2, VV[0], v4function);
    T1 = cl_list(2, v6, T0);
    {
     cl_object v7;
     v7 = (ECL_SYM("LIST",481)->symbol.gfdef);
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
        v12 = v3;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v11 = v12;
       }
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L25:;
        if (!(ecl_endp(v9))) { goto L27; }
        goto L26;
L27:;
        v8 = _ecl_car(v9);
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        if (!(ecl_endp(v11))) { goto L35; }
        goto L26;
L35:;
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
         T3 = v14;
        }
        T4 = ecl_function_dispatch(cl_env_copy,v7)(2, v8, v10);
        v13 = ecl_list1(T4);
        (ECL_CONS_CDR(T3)=v13,T3);
        goto L25;
L26:;
        T2 = ecl_cdr(v12);
        goto L13;
       }
      }
     }
    }
L13:;
    T3 = CONS(T1,T2);
    T4 = ecl_append(v5,VV[19]);
    T5 = cl_listX(3, ECL_SYM("APPLY",89), v6, T4);
    T6 = cl_list(3, ECL_SYM("LAMBDA",452), VV[18], T5);
    value0 = cl_list(4, ECL_SYM("LET",477), T3, VV[10], T6);
    return value0;
   }
  }
 }
}
/*      function definition for RCURRY                                */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object L25rcurry(cl_narg narg, cl_object v1function, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1function,narg,1);
  v2arguments = cl_grab_rest_args(args);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2arguments,env0);           /*  ARGUMENTS       */
  ecl_va_end(args);
  {
   cl_object env1 = env0;
   if (Null(cl_functionp(v1function))) { goto L2; }
   T0 = v1function;
   goto L1;
L2:;
   T0 = cl_fdefinition(v1function);
L1:;
   CLV1 = env1 = CONS(T0,env1);                   /*  FN              */
   {
    cl_object v3;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC24__g105,env1,Cblock);
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      closure G105                                                  */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC24__g105(cl_narg narg, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  FN              */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1more;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1more = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    {
     cl_object v3;
     v3 = ECL_CONS_CAR(CLV1);
     cl_env_copy->values[0] = cl_values_list(v1more);
     ecl_stack_frame_push_values(v2);
     cl_env_copy->values[0] = cl_values_list(ECL_CONS_CAR(CLV0));
     ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,v3);
     value0 = cl_env_copy->values[0];
    }
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
 }
 }
}
/*      local function NAMED-LAMBDA                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC26named_lambda(cl_object v1, cl_object v2)
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
   cl_object v5lambda_list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5lambda_list = v6;
   }
   T0 = cl_listX(3, v4name, v5lambda_list, v3);
   T1 = ecl_list1(T0);
   T2 = cl_list(2, ECL_SYM("FUNCTION",396), v4name);
   value0 = cl_list(3, ECL_SYM("LABELS",451), T1, T2);
   return value0;
  }
 }
}

#include "lib/alexandria/functions.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclNfUD6Zhj9JNJM_UCh2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/functions.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclNfUD6Zhj9JNJM_UCh2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[2]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[3], VVtemp[4]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[5]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[22]);                          /*  ENSURE-FUNCTION */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[6]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[7], VVtemp[8]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[9]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[23]);                       /*  ENSURE-FUNCTIONF/1 */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[10], VVtemp[11]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[12]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[24]);                       /*  ENSURE-FUNCTIONF */
  si_set_documentation(3, VV[3], ECL_SYM("FUNCTION",396), VVtemp[13]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[25]);                          /*  DISJOIN         */
  si_set_documentation(3, VV[4], ECL_SYM("FUNCTION",396), VVtemp[17]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LOCATION",1777), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[26]);                          /*  CONJOIN         */
  si_set_documentation(3, VV[5], ECL_SYM("FUNCTION",396), VVtemp[20]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[21], VVtemp[22]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[23]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[27]);                          /*  COMPOSE         */
  si_set_documentation(3, VV[6], ECL_SYM("FUNCTION",396), VVtemp[24]);
 {
  cl_object T0;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC15compose,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[6], ECL_SYM("COMPILER-MACRO",238), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[25], VVtemp[26]) /*  ANNOTATE */;
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[23]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[29]);                          /*  MULTIPLE-VALUE-COMPOSE */
  si_set_documentation(3, VV[13], ECL_SYM("FUNCTION",396), VVtemp[29]);
 {
  cl_object T0;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC20multiple_value_compose,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[13], ECL_SYM("COMPILER-MACRO",238), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LOCATION",1777), VVtemp[30], VVtemp[31]) /*  ANNOTATE */;
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LOCATION",1777), VVtemp[32], VVtemp[33]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[34]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[30]);                          /*  CURRY           */
  si_set_documentation(3, VV[15], ECL_SYM("FUNCTION",396), VVtemp[35]);
 {
  cl_object T0;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC23curry,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[15], ECL_SYM("COMPILER-MACRO",238), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LOCATION",1777), VVtemp[36], VVtemp[37]) /*  ANNOTATE */;
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[20], ECL_SYM("LOCATION",1777), VVtemp[38], VVtemp[39]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[20], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[34]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[31]);                          /*  RCURRY          */
  si_set_documentation(3, VV[20], ECL_SYM("FUNCTION",396), VVtemp[40]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[21], ECL_SYM("LOCATION",1777), VVtemp[41], VVtemp[42]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[21], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[43]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[32]);                       /*  NAMED-LAMBDA    */
  si_set_documentation(3, VV[21], ECL_SYM("FUNCTION",396), VVtemp[44]);
}
