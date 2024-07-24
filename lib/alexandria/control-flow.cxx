/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/control-flow.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/control-flow.eclh"
/*      function definition for EXTRACT-FUNCTION-NAME                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1extract_function_name(cl_object v1spec)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1spec))) { goto L1; }
  {
   cl_object v2;
   v2 = ecl_car(v1spec);
   if (!((v2)==(ECL_SYM("QUOTE",681)))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!((v2)==(ECL_SYM("FUNCTION",398)))) { goto L1; }
   goto L2;
L5:;
  }
L2:;
  value0 = ecl_cadr(v1spec);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v1spec;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for GENERATE-SWITCH-BODY                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3generate_switch_body(cl_narg narg, cl_object v1whole, cl_object v2object, cl_object v3clauses, cl_object v4test, cl_object v5key, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object env0 = ECL_NIL;
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<5)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>6)) FEwrong_num_arguments_anonym();
 {
  va_list args; va_start(args,v5key);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1whole,env0);               /*  WHOLE           */
  CLV1 = env0 = CONS(v4test,env0);                /*  TEST            */
  {
   int i = 5;
   if (i >= narg) {
    CLV2 = env0 = CONS(ECL_NIL,env0);             /*  DEFAULT         */
   } else {
    i++;
    CLV2 = env0 = CONS(va_arg(args,cl_object),env0); /*  DEFAULT      */
   }
  }
  va_end(args);
  {
   cl_object env1 = env0;
   T0 = cl_gensym(1, VV[4]);
   CLV3 = env1 = CONS(T0,env1);                   /*  VALUE           */
   ECL_CONS_CAR(CLV1) = L1extract_function_name(ECL_CONS_CAR(CLV1));
   v5key = L1extract_function_name(v5key);
   if (!(ECL_CONSP(ECL_CONS_CAR(CLV2)))) { goto L5; }
   {
    cl_object v6;
    v6 = ecl_car(ECL_CONS_CAR(CLV2));
    if (!((v6)==(ECL_SYM("ERROR",339)))) { goto L12; }
    goto L9;
    goto L10;
L12:;
    goto L10;
L10:;
    if (!((v6)==(ECL_SYM("CERROR",204)))) { goto L5; }
    goto L6;
L9:;
   }
L6:;
   T0 = ECL_CONS_CAR(CLV2);
   T1 = cl_list(2, ECL_SYM("QUOTE",681), ECL_CONS_CAR(CLV1));
   T2 = cl_list(3, VV[7], ECL_CONS_CAR(CLV3), T1);
   ECL_CONS_CAR(CLV2) = ecl_append(T0,T2);
L5:;
   T0 = cl_list(2, v5key, v2object);
   T1 = cl_list(2, ECL_CONS_CAR(CLV3), T0);
   T2 = ecl_list1(T1);
   {
    cl_object v6;
    {
     cl_object v7;
     v7 = ecl_make_cclosure_va((cl_objectfn)LC2__lambda28,env1,Cblock,1);
     v6 = v7;
    }
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     {
      cl_object v9;
      v9 = v3clauses;
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v8 = v9;
     }
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L24:;
      if (!(ecl_endp(v8))) { goto L26; }
      goto L25;
L26:;
      v7 = ECL_CONS_CAR(v8);
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v8 = v11;
      }
      {
       cl_object v11;
       v11 = v10;
       if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       T4 = v11;
      }
      T5 = ecl_function_dispatch(cl_env_copy,v6)(1, v7);
      v10 = ecl_list1(T5);
      (ECL_CONS_CDR(T4)=v10,T4);
      goto L24;
L25:;
      T3 = ecl_cdr(v9);
      goto L16;
     }
    }
   }
L16:;
   T4 = cl_list(2, ECL_T, ECL_CONS_CAR(CLV2));
   T5 = ecl_list1(T4);
   T6 = ecl_append(T3,T5);
   T7 = CONS(ECL_SYM("COND",249),T6);
   value0 = cl_list(3, ECL_SYM("LET",479), T2, T7);
   return value0;
  }
 }
}
/*      closure LAMBDA28                                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2__lambda28(cl_narg narg, cl_object v1clause, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  VALUE           */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_car(v1clause);
   if (!(ecl_eql(v2,ECL_T))) { goto L7; }
   goto L4;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!((v2)==(ECL_SYM("OTHERWISE",617)))) { goto L1; }
   goto L2;
L4:;
  }
L2:;
  if (Null(ECL_CONS_CAR(CLV2))) { goto L10; }
  cl_error(2, VV[10], ECL_CONS_CAR(CLV0));
L10:;
  T0 = ecl_cdr(v1clause);
  ECL_CONS_CAR(CLV2) = CONS(ECL_SYM("PROGN",673),T0);
  value0 = VV[11];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v2;
   cl_object v3key_form;
   v2 = v1clause;
   if (!(v2==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1clause) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v4;
    v4 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3key_form = v4;
   }
   T0 = cl_list(3, ECL_CONS_CAR(CLV1), ECL_CONS_CAR(CLV3), v3key_form);
   value0 = CONS(T0,v2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*      local function SWITCH                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4switch(cl_object v1, cl_object v2)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6object;
   cl_object v7;
   cl_object v8test;
   cl_object v9;
   cl_object v10key;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v11;
    v11 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v11;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6object = v11;
   }
   v7 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("TEST",1350)) /*  SEARCH-KEYWORD */;
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L17; }
   v8test = ECL_SYM("EQL",336);
   goto L16;
L17:;
   v8test = v7;
L16:;
   v9 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("KEY",1294)) /*  SEARCH-KEYWORD */;
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L21; }
   v10key = ECL_SYM("IDENTITY",428);
   goto L20;
L21:;
   v10key = v9;
L20:;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, v5, VV[13]) /*  CHECK-KEYWORD */;
   value0 = L3generate_switch_body(5, v1, v6object, v3, v8test, v10key);
   return value0;
  }
 }
}
/*      local function ESWITCH                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5eswitch(cl_object v1, cl_object v2)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6object;
   cl_object v7;
   cl_object v8test;
   cl_object v9;
   cl_object v10key;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v11;
    v11 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v11;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6object = v11;
   }
   v7 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("TEST",1350)) /*  SEARCH-KEYWORD */;
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L17; }
   v8test = ECL_SYM("EQL",336);
   goto L16;
L17:;
   v8test = v7;
L16:;
   v9 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("KEY",1294)) /*  SEARCH-KEYWORD */;
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L21; }
   v10key = ECL_SYM("IDENTITY",428);
   goto L20;
L21:;
   v10key = v9;
L20:;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, v5, VV[13]) /*  CHECK-KEYWORD */;
   value0 = L3generate_switch_body(6, v1, v6object, v3, v8test, v10key, VV[15]);
   return value0;
  }
 }
}
/*      local function CSWITCH                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6cswitch(cl_object v1, cl_object v2)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6object;
   cl_object v7;
   cl_object v8test;
   cl_object v9;
   cl_object v10key;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v11;
    v11 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v11;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6object = v11;
   }
   v7 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("TEST",1350)) /*  SEARCH-KEYWORD */;
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L17; }
   v8test = ECL_SYM("EQL",336);
   goto L16;
L17:;
   v8test = v7;
L16:;
   v9 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v5, ECL_SYM("KEY",1294)) /*  SEARCH-KEYWORD */;
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L21; }
   v10key = ECL_SYM("IDENTITY",428);
   goto L20;
L21:;
   v10key = v9;
L20:;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, v5, VV[13]) /*  CHECK-KEYWORD */;
   value0 = L3generate_switch_body(6, v1, v6object, v3, v8test, v10key, VV[17]);
   return value0;
  }
 }
}
/*      local function WHICHEVER                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC10whichever(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3;
 cl_object env0 = ECL_NIL;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2env,env0);                 /*  ENV             */
  {
   cl_object v3;
   cl_object v4possibilities;
   v3 = ecl_cdr(v1);
   v4possibilities = v3;
   {
    cl_object v5;
    {
     cl_object v6;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC7__lambda107,env0,Cblock,1);
     v5 = v6;
    }
    {
     cl_object v6;
     cl_object v7;
     v6 = ECL_NIL;
     {
      cl_object v8;
      v8 = v4possibilities;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L12:;
      if (!(ecl_endp(v7))) { goto L14; }
      goto L13;
L14:;
      v6 = ECL_CONS_CAR(v7);
      {
       cl_object v10;
       v10 = ECL_CONS_CDR(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v7 = v10;
      }
      {
       cl_object v10;
       v10 = v9;
       if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       T0 = v10;
      }
      T1 = ecl_function_dispatch(cl_env_copy,v5)(1, v6);
      v9 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v9,T0);
      goto L12;
L13:;
      v4possibilities = ecl_cdr(v8);
      goto L4;
     }
    }
   }
L4:;
   {
    cl_object v5;
    v5 = ecl_make_cfun((cl_objectfn_fixed)LC8__lambda110,ECL_NIL,Cblock,1);
    T0 = v5;
   }
   if (Null(cl_every(2, T0, v4possibilities))) { goto L30; }
   T0 = CONS(ECL_SYM("VECTOR",900),v4possibilities);
   T1 = cl_list(2, ECL_SYM("LOAD-TIME-VALUE",491), T0);
   {
    cl_fixnum v5;
    v5 = ecl_length(v4possibilities);
    T2 = cl_list(2, ECL_SYM("RANDOM",682), ecl_make_fixnum(v5));
    value0 = cl_list(3, ECL_SYM("SVREF",840), T1, T2);
    return value0;
   }
L30:;
   {
    cl_object v6random_number;
    v6random_number = cl_gensym(1, VV[19]);
    {
     cl_fixnum v7length;
     v7length = ecl_length(v4possibilities);
     T0 = cl_list(2, ECL_SYM("RANDOM",682), ecl_make_fixnum(v7length));
     T1 = cl_list(2, v6random_number, T0);
     T2 = ecl_list1(T1);
     T3 = LC9expand(v4possibilities, ecl_make_fixnum(0), v6random_number);
     value0 = cl_list(3, ECL_SYM("LET",479), T2, T3);
     return value0;
    }
   }
  }
 }
}
/*      closure LAMBDA107                                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC7__lambda107(cl_narg narg, cl_object v1p, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ENV             */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_macroexpand(2, v1p, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*      local function LAMBDA110                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC8__lambda110(cl_object v1p)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_constantp(1, v1p);
  return value0;
 }
}
/*      local function EXPAND                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC9expand(cl_object v1possibilities, cl_object v2position, cl_object v3random_number)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cdr(v1possibilities);
  if (!(T0==ECL_NIL)) { goto L1; }
  value0 = ecl_car(v1possibilities);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_fixnum v4length;
   cl_object v5half;
   cl_object v6second_half;
   cl_object v7first_half;
   v4length = ecl_length(v1possibilities);
   v5half = ecl_truncate2(ecl_make_fixnum(v4length),ecl_make_fixnum(2));
   v6second_half = ecl_nthcdr(ecl_to_size(v5half),v1possibilities);
   T0 = ecl_minus(ecl_make_fixnum(v4length),v5half);
   v7first_half = cl_butlast(2, v1possibilities, T0);
   T0 = ecl_plus(v2position,v5half);
   T1 = cl_list(3, ECL_SYM("<",74), v3random_number, T0);
   T2 = LC9expand(v7first_half, v2position, v3random_number);
   T4 = ecl_plus(v2position,v5half);
   T3 = LC9expand(v6second_half, T4, v3random_number);
   value0 = cl_list(4, ECL_SYM("IF",948), T1, T2, T3);
   return value0;
  }
 }
}
/*      local function XOR                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12xor(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object env0 = ECL_NIL;
 cl_object CLV0, CLV1, CLV2;
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
    cl_object v5;
    cl_object v6;
    cl_object env1 = env0;
    v4 = cl_gensym(1, VV[21]);
    v5 = cl_gensym(1, VV[22]);
    v6 = cl_gensym(1, VV[23]);
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(v4,env1);                  /*  XOR             */
    CLV1 = env1 = CONS(v5,env1);                  /*  TMP             */
    CLV2 = env1 = CONS(v6,env1);                  /*  TRUE            */
    T0 = cl_list(2, ECL_CONS_CAR(CLV1), ECL_CONS_CAR(CLV2));
    {
     cl_object v7;
     {
      cl_object v8;
      v8 = ecl_make_cclosure_va((cl_objectfn)LC11__lambda125,env1,Cblock,1);
      v7 = v8;
     }
     {
      cl_object v8;
      cl_object v9;
      v8 = ECL_NIL;
      {
       cl_object v10;
       v10 = v3;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ecl_list1(ECL_NIL);
       v11 = v10;
L13:;
       if (!(ecl_endp(v9))) { goto L15; }
       goto L14;
L15:;
       v8 = ECL_CONS_CAR(v9);
       {
        cl_object v12;
        v12 = ECL_CONS_CDR(v9);
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        v9 = v12;
       }
       {
        cl_object v12;
        v12 = v11;
        if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        T2 = v12;
       }
       T3 = ecl_function_dispatch(cl_env_copy,v7)(1, v8);
       v11 = ecl_list1(T3);
       (ECL_CONS_CDR(T2)=v11,T2);
       goto L13;
L14:;
       T1 = ecl_cdr(v10);
       goto L5;
      }
     }
    }
L5:;
    T2 = cl_list(3, ECL_SYM("VALUES",897), ECL_CONS_CAR(CLV2), ECL_T);
    T3 = cl_list(3, ECL_SYM("RETURN-FROM",727), ECL_CONS_CAR(CLV0), T2);
    T4 = ecl_list1(T3);
    T5 = ecl_append(T1,T4);
    T6 = cl_listX(3, ECL_SYM("BLOCK",139), ECL_CONS_CAR(CLV0), T5);
    value0 = cl_list(3, ECL_SYM("LET",479), T0, T6);
    return value0;
   }
  }
 }
}
/*      closure LAMBDA125                                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11__lambda125(cl_narg narg, cl_object v1datum, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object CLV0, CLV1, CLV2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TRUE            */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_list(3, ECL_SYM("SETF",752), ECL_CONS_CAR(CLV1), v1datum);
  T1 = cl_list(3, ECL_SYM("RETURN-FROM",727), ECL_CONS_CAR(CLV0), VV[24]);
  T2 = cl_list(3, ECL_SYM("SETF",752), ECL_CONS_CAR(CLV2), ECL_CONS_CAR(CLV1));
  T3 = cl_list(4, ECL_SYM("IF",948), ECL_CONS_CAR(CLV2), T1, T2);
  value0 = cl_list(3, ECL_SYM("IF",948), T0, T3);
  return value0;
 }
 }
}
/*      local function NTH-VALUE-OR                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13nth_value_or(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4nth_value;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4nth_value = v5;
   }
   {
    cl_object v5;
    v5 = cl_gensym(1, VV[26]);
    T0 = cl_list(2, v5, v4nth_value);
    T1 = ecl_list1(T0);
    {
     cl_object v6values;
     v6values = cl_gensym(1, VV[27]);
     T3 = ecl_car(v3);
     T4 = cl_list(2, ECL_SYM("MULTIPLE-VALUE-LIST",576), T3);
     T5 = cl_list(2, v6values, T4);
     T6 = ecl_list1(T5);
     T7 = cl_list(3, ECL_SYM("NTH",604), v5, v6values);
     T8 = cl_list(2, ECL_SYM("VALUES-LIST",898), v6values);
     if (Null(ecl_cdr(v3))) { goto L12; }
     T10 = ecl_cdr(v3);
     T9 = cl_listX(3, VV[25], v5, T10);
     goto L11;
L12:;
     T9 = ECL_NIL;
L11:;
     T10 = cl_list(4, ECL_SYM("IF",948), T7, T8, T9);
     T2 = cl_list(3, ECL_SYM("LET",479), T6, T10);
    }
    value0 = cl_list(3, ECL_SYM("LET",479), T1, T2);
    return value0;
   }
  }
 }
}
/*      local function MULTIPLE-VALUE-PROG2                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14multiple_value_prog2(cl_object v1, cl_object v2)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4first_form;
   cl_object v5second_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4first_form = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   ecl_function_dispatch(cl_env_copy,VV[32])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5second_form = v6;
   }
   T0 = cl_listX(3, ECL_SYM("MULTIPLE-VALUE-PROG1",577), v5second_form, v3);
   value0 = cl_list(3, ECL_SYM("PROGN",673), v4first_form, T0);
   return value0;
  }
 }
}

#include "lib/alexandria/control-flow.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclCnSaUWKBItpDM_zzFycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/control-flow.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclCnSaUWKBItpDM_zzFycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[29]);                          /*  EXTRACT-FUNCTION-NAME */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[4]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LOCATION",1862), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[31]);                          /*  GENERATE-SWITCH-BODY */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[12], ECL_SYM("LOCATION",1862), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[12], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[33]);                       /*  SWITCH          */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[12], ECL_SYM("FUNCTION",398), VVtemp[11]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LOCATION",1862), VVtemp[12], VVtemp[13]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[36]);                       /*  ESWITCH         */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[14], ECL_SYM("FUNCTION",398), VVtemp[14]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LOCATION",1862), VVtemp[15], VVtemp[16]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[37]);                       /*  CSWITCH         */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[16], ECL_SYM("FUNCTION",398), VVtemp[17]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LOCATION",1862), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[20]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[38]);                       /*  WHICHEVER       */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[18], ECL_SYM("FUNCTION",398), VVtemp[21]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LOCATION",1862), VVtemp[22], VVtemp[23]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[24]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[39]);                       /*  XOR             */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[20], ECL_SYM("FUNCTION",398), VVtemp[25]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LOCATION",1862), VVtemp[26], VVtemp[27]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[28]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[40]);                       /*  NTH-VALUE-OR    */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[25], ECL_SYM("FUNCTION",398), VVtemp[29]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[28], ECL_SYM("LOCATION",1862), VVtemp[30], VVtemp[31]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[28], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[32]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[41]);                       /*  MULTIPLE-VALUE-PROG2 */
  ecl_function_dispatch(cl_env_copy,VV[30])(3, VV[28], ECL_SYM("FUNCTION",398), VVtemp[33]) /*  SET-DOCUMENTATION */;
}
