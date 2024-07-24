/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/lists.lisp                             */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/lists.eclh"
/*      function definition for SAFE-ENDP                             */
/*      optimize speed 3, debug 0, space 0, safety 3                  */
static cl_object L1safe_endp(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ecl_endp(v1x));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for ALIST-PLIST                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2alist_plist(cl_object v1alist)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2plist;
   v2plist = ECL_NIL;
   {
    cl_object v3;
    v3 = v1alist;
    goto L6;
L5:;
    {
     cl_object v4pair;
     v4pair = ecl_car(v3);
     T0 = ecl_car(v4pair);
     v2plist = CONS(T0,v2plist);
     T0 = ecl_cdr(v4pair);
     v2plist = CONS(T0,v2plist);
    }
    v3 = ecl_cdr(v3);
L6:;
    if (Null(v3)) { goto L16; }
    goto L5;
L16:;
   }
   value0 = cl_nreverse(v2plist);
   return value0;
  }
 }
}
/*      function definition for PLIST-ALIST                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3plist_alist(cl_object v1plist)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2alist;
   v2alist = ECL_NIL;
   {
    cl_object v3tail;
    v3tail = v1plist;
    goto L5;
L4:;
    T0 = ecl_car(v3tail);
    T1 = ecl_cadr(v3tail);
    T2 = CONS(T0,T1);
    v2alist = CONS(T2,v2alist);
    v3tail = ecl_cddr(v3tail);
L5:;
    if (ecl_endp(v3tail)) { goto L11; }
    goto L4;
L11:;
    value0 = cl_nreverse(v2alist);
    return value0;
   }
  }
 }
}
/*      function definition for RACONS                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4racons(cl_object v1key, cl_object v2value, cl_object v3ralist)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_acons(v2value, v1key, v3ralist);
  return value0;
 }
}
/*      function definition for ASSOC-VALUE                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5assoc_value(cl_narg narg, cl_object v1alist, cl_object v2key, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  ecl_va_list args; ecl_va_start(args,v2key,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L5assoc_valuekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v3test = ECL_SYM("EQL",334);
   } else {
    v3test = keyvars[0];
   }
  }
  {
   cl_object v4entry;
   {
    cl_object v5;
    v5 = v1alist;
    goto L6;
L5:;
    {
     cl_object v6;
     cl_object v7;
     {
      cl_object v8;
      v8 = v5;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      v6 = v8;
     }
     v7 = ECL_CONS_CAR(v6);
     if (Null(v7)) { goto L8; }
     {
      cl_object v8;
      {
       cl_object v9;
       v9 = v7;
       if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
       T0 = v9;
      }
      v8 = ECL_CONS_CAR(T0);
      if (Null(ecl_function_dispatch(cl_env_copy,v3test)(2, v2key, v8))) { goto L8; }
      v4entry = v7;
      goto L2;
     }
    }
L8:;
    v5 = ECL_CONS_CDR(v5);
L6:;
    if (v5==ECL_NIL) { goto L21; }
    goto L5;
L21:;
    v4entry = ECL_NIL;
   }
L2:;
   T0 = ecl_cdr(v4entry);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4entry;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*      local function ASSOC-VALUE                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6assoc_value(cl_narg narg, cl_object v1env, cl_object v2place, cl_object v3key, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4test;
  ecl_va_list args; ecl_va_start(args,v3key,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC6assoc_valuekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v4test = VV[5];
   } else {
    v4test = keyvars[0];
   }
  }
  {
   cl_object v6;                                  /*  TEMPORARY-VARIABLES */
   cl_object v7;                                  /*  INITFORMS       */
   cl_object v8;                                  /*  NEWVALS         */
   cl_object v9;                                  /*  SETTER          */
   cl_object v10;                                 /*  GETTER          */
   value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v2place, v1env) /*  GET-SETF-EXPANSION */;
   v6 = value0;
   v7 = cl_env_copy->values[1];
   v8 = cl_env_copy->values[2];
   v9 = cl_env_copy->values[3];
   v10 = cl_env_copy->values[4];
   if (Null(ecl_cdr(v8))) { goto L3; }
   cl_error(2, VV[6], VV[4]);
L3:;
   {
    cl_object v11;
    cl_object v12;
    cl_object v13;
    cl_object v14;
    cl_object v15;
    v11 = cl_gensym(1, VV[7]);
    v12 = cl_gensym(1, VV[8]);
    v13 = cl_gensym(1, VV[9]);
    v14 = cl_gensym(1, VV[10]);
    v15 = cl_gensym(1, VV[11]);
    T0 = cl_list(4, v14, v12, v13, v15);
    T1 = ecl_append(v6,T0);
    T2 = cl_list(5, ECL_SYM("ASSOC",114), v12, v14, ECL_SYM("TEST",1321), v13);
    T3 = cl_list(4, v10, v3key, v4test, T2);
    T4 = ecl_append(v7,T3);
    T5 = ecl_list1(v11);
    T6 = cl_list(2, ECL_SYM("CDR",198), v15);
    T7 = cl_list(3, ECL_SYM("SETF",750), T6, v11);
    T8 = cl_list(2, v15, T7);
    T9 = ecl_car(v8);
    T10 = cl_list(4, ECL_SYM("ACONS",79), v3key, v11, v14);
    T11 = cl_list(3, ECL_SYM("SETF",750), T9, T10);
    T12 = cl_list(5, ECL_SYM("LET",477), v8, T11, v9, v11);
    T13 = cl_list(2, ECL_T, T12);
    T14 = cl_list(3, ECL_SYM("COND",247), T8, T13);
    T15 = cl_list(2, ECL_SYM("CDR",198), v15);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T15;
    cl_env_copy->values[3] = T14;
    cl_env_copy->values[2] = T5;
    cl_env_copy->values[1] = T4;
    cl_env_copy->values[0] = T1;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for RASSOC-VALUE                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7rassoc_value(cl_narg narg, cl_object v1alist, cl_object v2key, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  ecl_va_list args; ecl_va_start(args,v2key,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L7rassoc_valuekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v3test = ECL_SYM("EQL",334);
   } else {
    v3test = keyvars[0];
   }
  }
  {
   cl_object v4entry;
   v4entry = cl_rassoc(4, v2key, v1alist, ECL_SYM("TEST",1321), v3test);
   T0 = ecl_car(v4entry);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4entry;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*      local function RASSOC-VALUE                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC8rassoc_value(cl_narg narg, cl_object v1env, cl_object v2place, cl_object v3key, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4test;
  ecl_va_list args; ecl_va_start(args,v3key,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC8rassoc_valuekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v4test = VV[5];
   } else {
    v4test = keyvars[0];
   }
  }
  {
   cl_object v6;                                  /*  TEMPORARY-VARIABLES */
   cl_object v7;                                  /*  INITFORMS       */
   cl_object v8;                                  /*  NEWVALS         */
   cl_object v9;                                  /*  SETTER          */
   cl_object v10;                                 /*  GETTER          */
   value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v2place, v1env) /*  GET-SETF-EXPANSION */;
   v6 = value0;
   v7 = cl_env_copy->values[1];
   v8 = cl_env_copy->values[2];
   v9 = cl_env_copy->values[3];
   v10 = cl_env_copy->values[4];
   if (Null(ecl_cdr(v8))) { goto L3; }
   cl_error(2, VV[6], VV[12]);
L3:;
   {
    cl_object v11;
    cl_object v12;
    cl_object v13;
    cl_object v14;
    cl_object v15;
    v11 = cl_gensym(1, VV[7]);
    v12 = cl_gensym(1, VV[8]);
    v13 = cl_gensym(1, VV[9]);
    v14 = cl_gensym(1, VV[10]);
    v15 = cl_gensym(1, VV[11]);
    T0 = cl_list(4, v14, v12, v13, v15);
    T1 = ecl_append(v6,T0);
    T2 = cl_list(5, ECL_SYM("RASSOC",683), v12, v14, ECL_SYM("TEST",1321), v13);
    T3 = cl_list(4, v10, v3key, v4test, T2);
    T4 = ecl_append(v7,T3);
    T5 = ecl_list1(v11);
    T6 = cl_list(2, ECL_SYM("CAR",180), v15);
    T7 = cl_list(3, ECL_SYM("SETF",750), T6, v11);
    T8 = cl_list(2, v15, T7);
    T9 = ecl_car(v8);
    T10 = cl_list(4, VV[3], v3key, v11, v14);
    T11 = cl_list(3, ECL_SYM("SETF",750), T9, T10);
    T12 = cl_list(5, ECL_SYM("LET",477), v8, T11, v9, v11);
    T13 = cl_list(2, ECL_T, T12);
    T14 = cl_list(3, ECL_SYM("COND",247), T8, T13);
    T15 = cl_list(2, ECL_SYM("CAR",180), v15);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T15;
    cl_env_copy->values[3] = T14;
    cl_env_copy->values[2] = T5;
    cl_env_copy->values[1] = T4;
    cl_env_copy->values[0] = T1;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      function definition for MALFORMED-PLIST                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9malformed_plist(cl_object v1plist)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(2, VV[14], v1plist);
  return value0;
 }
}
/*      local function DOPLIST                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC10doplist(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6key;
   cl_object v7val;
   cl_object v8plist;
   cl_object v9values;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v10;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6key = v10;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7val = v10;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   si_dm_too_few_arguments(v1);
L22:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8plist = v10;
   }
   if (Null(v5)) { goto L28; }
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v9values = v10;
    goto L27;
   }
L28:;
   v9values = ECL_NIL;
L27:;
   if (Null(v5)) { goto L33; }
   si_dm_too_many_arguments(v1);
L33:;
   {
    cl_object v11;                                /*  FORMS           */
    cl_object v12;                                /*  DECLARATIONS    */
    value0 = ecl_function_dispatch(cl_env_copy,VV[62])(1, v3) /*  PARSE-BODY */;
    v11 = value0;
    {
     const int v13 = cl_env_copy->nvalues;
     cl_object v14;
     v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
     v12 = v14;
    }
    {
     cl_object v13;
     cl_object v14;
     cl_object v15;
     v13 = cl_gensym(1, VV[16]);
     v14 = cl_gensym(1, VV[17]);
     v15 = cl_gensym(1, VV[18]);
     T0 = cl_list(2, v6key, v7val);
     T1 = cl_list(3, ECL_SYM("IGNORABLE",427), v6key, v7val);
     T2 = cl_list(2, ECL_SYM("DECLARE",274), T1);
     T3 = cl_list(2, ECL_SYM("RETURN",724), v9values);
     T4 = cl_list(4, ECL_SYM("LET",477), T0, T2, T3);
     T5 = cl_list(3, v15, ECL_NIL, T4);
     T6 = ecl_list1(T5);
     T7 = cl_list(2, v13, v8plist);
     T8 = cl_list(2, ECL_SYM("POP",643), v13);
     T9 = ecl_list1(v15);
     T10 = cl_list(4, ECL_SYM("IF",946), v13, T8, T9);
     T11 = cl_list(2, v6key, T10);
     T12 = cl_list(2, ECL_SYM("POP",643), v13);
     T13 = cl_list(2, ECL_SYM("QUOTE",679), v8plist);
     T14 = cl_list(2, VV[13], T13);
     T15 = cl_list(4, ECL_SYM("IF",946), v13, T12, T14);
     T16 = cl_list(2, v7val, T15);
     T17 = cl_list(3, T7, T11, T16);
     T18 = cl_list(3, ECL_SYM("IGNORABLE",427), v6key, v7val);
     T19 = cl_list(2, ECL_SYM("DECLARE",274), T18);
     T20 = cl_list(2, ECL_SYM("POP",643), v13);
     T21 = ecl_list1(v15);
     T22 = cl_list(4, ECL_SYM("IF",946), v13, T20, T21);
     T23 = cl_list(2, ECL_SYM("POP",643), v13);
     T24 = cl_list(2, ECL_SYM("QUOTE",679), v8plist);
     T25 = cl_list(2, VV[13], T24);
     T26 = cl_list(4, ECL_SYM("IF",946), v13, T23, T25);
     T27 = cl_list(5, ECL_SYM("SETF",750), v6key, T22, v7val, T26);
     T28 = cl_list(2, ECL_SYM("GO",414), v14);
     T29 = cl_list(2, T27, T28);
     T30 = ecl_append(v11,T29);
     T31 = cl_listX(3, ECL_SYM("TAGBODY",850), v14, T30);
     T32 = ecl_list1(T31);
     T33 = ecl_append(v12,T32);
     T34 = cl_listX(4, ECL_SYM("LET*",478), T17, T19, T33);
     T35 = cl_list(3, ECL_SYM("FLET",373), T6, T34);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), ECL_NIL, T35);
     return value0;
    }
   }
  }
 }
}
/*      local function APPENDF                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12appendf(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC11__g54,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("APPEND",88), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
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
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, ECL_SYM("APPEND",88), v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("APPEND",88), v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G54                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11__g54(cl_object v1si__v)
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
/*      local function NCONCF                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14nconcf(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC13__g65,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("NCONC",581), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
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
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, ECL_SYM("NCONC",581), v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("NCONC",581), v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G65                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13__g65(cl_object v1si__v)
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
/*      local function UNIONF                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC16unionf(cl_object v1, cl_object v2si__env)
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
   cl_object v5list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5list = v6;
   }
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    {
     cl_object v12si__all_vars;
     {
      cl_object v13;
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC15__g77,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5list,v3);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L17; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("UNION",882), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v12si__all_vars, T7, v10);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L17:;
     {
      cl_object v13si__d;
      cl_object v14si__v;
      cl_object v15si__let_list;
      v13si__d = v7;
      v14si__v = v8;
      v15si__let_list = ECL_NIL;
      goto L26;
L25:;
      {
       cl_object v16;
       v16 = ecl_cdr(v13si__d);
       {
        cl_object v17;
        v17 = ecl_cdr(v14si__v);
        T0 = ecl_car(v13si__d);
        T1 = ecl_car(v14si__v);
        T2 = cl_list(2, T0, T1);
        v15si__let_list = CONS(T2,v15si__let_list);
        v14si__v = v17;
        v13si__d = v16;
       }
      }
L26:;
      if (v13si__d==ECL_NIL) { goto L32; }
      goto L25;
L32:;
      T0 = ecl_car(v9);
      if (!(ECL_LISTP(v4si___reference))) { goto L37; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L37; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(4, ECL_SYM("UNION",882), v11, v5list, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L36;
L37:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("UNION",882), v11, T3);
L36:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G77                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC15__g77(cl_object v1si__v)
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
/*      local function NUNIONF                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC18nunionf(cl_object v1, cl_object v2si__env)
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
   cl_object v5list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5list = v6;
   }
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    {
     cl_object v12si__all_vars;
     {
      cl_object v13;
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC17__g89,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5list,v3);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L17; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("NUNION",609), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v12si__all_vars, T7, v10);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L17:;
     {
      cl_object v13si__d;
      cl_object v14si__v;
      cl_object v15si__let_list;
      v13si__d = v7;
      v14si__v = v8;
      v15si__let_list = ECL_NIL;
      goto L26;
L25:;
      {
       cl_object v16;
       v16 = ecl_cdr(v13si__d);
       {
        cl_object v17;
        v17 = ecl_cdr(v14si__v);
        T0 = ecl_car(v13si__d);
        T1 = ecl_car(v14si__v);
        T2 = cl_list(2, T0, T1);
        v15si__let_list = CONS(T2,v15si__let_list);
        v14si__v = v17;
        v13si__d = v16;
       }
      }
L26:;
      if (v13si__d==ECL_NIL) { goto L32; }
      goto L25;
L32:;
      T0 = ecl_car(v9);
      if (!(ECL_LISTP(v4si___reference))) { goto L37; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L37; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(4, ECL_SYM("NUNION",609), v11, v5list, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L36;
L37:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("NUNION",609), v11, T3);
L36:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G89                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC17__g89(cl_object v1si__v)
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
/*      local function REVERSEF                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC20reversef(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC19__g100,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = ECL_NIL;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L13; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("REVERSE",727), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
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
      T3 = cl_listX(3, ECL_SYM("REVERSE",727), v10, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L32;
L33:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("REVERSE",727), v10, T3);
L32:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G100                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19__g100(cl_object v1si__v)
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
/*      local function NREVERSEF                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC22nreversef(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC21__g111,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = ECL_NIL;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L13; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("NREVERSE",589), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
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
      T3 = cl_listX(3, ECL_SYM("NREVERSE",589), v10, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L32;
L33:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("NREVERSE",589), v10, T3);
L32:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G111                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC21__g111(cl_object v1si__v)
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
/*      function definition for CIRCULAR-LIST                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L23circular_list(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1elements;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1elements = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2cycle;
   v2cycle = cl_copy_list(v1elements);
   value0 = ecl_nconc(v2cycle,v2cycle);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for CIRCULAR-LIST-P                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L24circular_list_p(cl_object v1object)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1object))) { goto L2; }
  {
   cl_object v2;
   cl_object v3fast;
   cl_object v4slow;
   T0 = ecl_car(v1object);
   T1 = ecl_cdr(v1object);
   v2 = CONS(T0,T1);
   v3fast = v1object;
   v4slow = v2;
   goto L9;
L8:;
   if (!(ECL_CONSP(v3fast))) { goto L14; }
   T0 = ecl_cdr(v3fast);
   if (ECL_LISTP(T0)) { goto L11; }
   goto L12;
L14:;
   goto L12;
L12:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   if (!((v3fast)==(v4slow))) { goto L16; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   v3fast = ecl_cddr(v3fast);
   v4slow = ecl_cdr(v4slow);
L9:;
   goto L8;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for CIRCULAR-TREE-P                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L26circular_tree_p(cl_object volatile v1object)
{
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object volatile value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   lex0[0] = ECL_NEW_FRAME_ID(cl_env_copy);       /*  CIRCULAR-TREE-P */
   if (ecl_frs_push(cl_env_copy,lex0[0])!=0) {
   value0 = cl_env_copy->values[0];
   ecl_frs_pop(cl_env_copy);
   return value0;
   } else {
   value0 = LC25circularp(lex0, v1object, ECL_NIL);
   ecl_frs_pop(cl_env_copy);
   return value0;}
  }
 }
}
/*      local function CIRCULARP                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC25circularp(volatile cl_object *lex0, cl_object v1object, cl_object v2seen)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1object))) { goto L2; }
  {
   cl_object v3;
   cl_object v4fast;
   cl_object v5slow;
   T0 = ecl_car(v1object);
   T1 = ecl_cdr(v1object);
   v3 = CONS(T0,T1);
   v4fast = v3;
   v5slow = v1object;
   goto L9;
L8:;
   if ((v4fast)==(v5slow)) { goto L13; }
   if (Null(ecl_memql(v5slow,v2seen))) { goto L11; }
   goto L12;
L13:;
L12:;
   cl_env_copy->values[0] = ECL_T;
   cl_env_copy->nvalues = 1;
   cl_return_from(lex0[0],ECL_NIL);
L11:;
   if (!(ECL_CONSP(v4fast))) { goto L18; }
   T0 = ecl_cdr(v5slow);
   if (ECL_CONSP(T0)) { goto L16; }
   goto L17;
L18:;
L17:;
   {
    cl_object v6tail;
    v6tail = v1object;
    goto L23;
L22:;
    {
     cl_object v7elt;
     v7elt = ecl_car(v6tail);
     T0 = CONS(v1object,v2seen);
     LC25circularp(lex0, v7elt, T0);
    }
    v6tail = ecl_cdr(v6tail);
L23:;
    if (!(ECL_CONSP(v6tail))) { goto L29; }
    goto L22;
L29:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L16:;
   v4fast = ecl_cddr(v4fast);
   v5slow = ecl_cdr(v5slow);
L9:;
   goto L8;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for PROPER-LIST-P                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L27proper_list_p(cl_object v1object)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1object)!=ECL_NIL) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_CONSP(v1object))) { goto L3; }
  {
   cl_object v2;
   cl_object v3fast;
   cl_object v4slow;
   T0 = ecl_car(v1object);
   T1 = ecl_cdr(v1object);
   v2 = CONS(T0,T1);
   v3fast = v1object;
   v4slow = v2;
   goto L10;
L9:;
   if (!(ECL_LISTP(v3fast))) { goto L15; }
   T0 = ecl_cdr(v3fast);
   if (ECL_CONSP(T0)) { goto L12; }
   goto L13;
L15:;
   goto L13;
L13:;
   if (!(ECL_LISTP(v3fast))) { goto L18; }
   T0 = ecl_cdr(v3fast);
   value0 = Null(T0)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L18:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   if (!((v3fast)==(v4slow))) { goto L20; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L20:;
   v3fast = ecl_cddr(v3fast);
   v4slow = ecl_cdr(v4slow);
L10:;
   goto L9;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function PROPER-LIST                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC28proper_list(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = VV[31];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for CIRCULAR-LIST-ERROR                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L29circular_list_error(cl_object v1list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v1list, ECL_SYM("EXPECTED-TYPE",1235), VV[33]);
  return value0;
 }
}
/*      function definition for PROPER-LIST-LENGTH                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L30proper_list_length(cl_object v1list)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3last;
   cl_object v4fast;
   cl_object v5slow;
   cl_fixnum v6n;
   T0 = ecl_car(v1list);
   T1 = ecl_cdr(v1list);
   v2 = CONS(T0,T1);
   v3last = v1list;
   v4fast = v1list;
   v5slow = v2;
   v6n = 1;
   goto L8;
L7:;
   if (!(ecl_endp(v4fast))) { goto L10; }
   value0 = ecl_make_integer((v6n)-1);
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   {
    cl_object v7;
    v7 = ecl_cdr(v4fast);
    if (!(ecl_endp(v7))) { goto L12; }
   }
   value0 = ecl_make_fixnum(v6n);
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   if (!((v4fast)==(v5slow))) { goto L15; }
   L29circular_list_error(v1list);
L15:;
   v3last = v4fast;
   v4fast = ecl_cddr(v4fast);
   v5slow = ecl_cdr(v5slow);
   {
    cl_object v7;
    v7 = ecl_plus(ecl_make_fixnum(v6n),ecl_make_fixnum(2));
    {
     bool v8;
     v8 = ECL_FIXNUMP(v7);
     if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v7);
    }
    v6n = ecl_fixnum(v7);
   }
L8:;
   goto L7;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for LASTCAR                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L31lastcar(cl_object v1list)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3last;
   cl_object v4fast;
   cl_object v5slow;
   T0 = ecl_car(v1list);
   T1 = ecl_cdr(v1list);
   v2 = CONS(T0,T1);
   v3last = v1list;
   v4fast = v1list;
   v5slow = v2;
   goto L7;
L6:;
   if (!(ecl_endp(v4fast))) { goto L9; }
   value0 = ecl_cadr(v3last);
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   {
    cl_object v6;
    v6 = ecl_cdr(v4fast);
    if (!(ecl_endp(v6))) { goto L11; }
   }
   value0 = ecl_car(v4fast);
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   if (!((v4fast)==(v5slow))) { goto L14; }
   L29circular_list_error(v1list);
L14:;
   v3last = v4fast;
   v4fast = ecl_cddr(v4fast);
   v5slow = ecl_cdr(v5slow);
L7:;
   goto L6;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for (SETF LASTCAR)                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L32_setf_lastcar_(cl_object v1object, cl_object v2list)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4last;
   cl_object v5fast;
   cl_object v6slow;
   T0 = ecl_car(v2list);
   T1 = ecl_cdr(v2list);
   v3 = CONS(T0,T1);
   v4last = v2list;
   v5fast = v2list;
   v6slow = v3;
   goto L7;
L6:;
   if (!(ecl_endp(v5fast))) { goto L9; }
   {
    cl_object v7;
    v7 = v1object;
    {
     cl_object v8;
     v8 = ecl_cdr(v4last);
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
    }
    (ECL_CONS_CAR(T0)=v7,T0);
    value0 = v7;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L9:;
   {
    cl_object v7;
    v7 = ecl_cdr(v5fast);
    if (!(ecl_endp(v7))) { goto L16; }
   }
   {
    cl_object v7;
    v7 = v1object;
    {
     cl_object v8;
     v8 = v5fast;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
    }
    (ECL_CONS_CAR(T0)=v7,T0);
    value0 = v7;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L16:;
   if (!((v5fast)==(v6slow))) { goto L24; }
   L29circular_list_error(v2list);
L24:;
   v4last = v5fast;
   v5fast = ecl_cddr(v5fast);
   v6slow = ecl_cdr(v6slow);
L7:;
   goto L6;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MAKE-CIRCULAR-LIST                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L33make_circular_list(cl_narg narg, cl_object v1length, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initial_element;
  ecl_va_list args; ecl_va_start(args,v1length,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L33make_circular_listkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2initial_element = keyvars[0];
  }
  {
   cl_object v3cycle;
   v3cycle = cl_make_list(3, v1length, ECL_SYM("INITIAL-ELEMENT",1256), v2initial_element);
   value0 = ecl_nconc(v3cycle,v3cycle);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function CIRCULAR-LIST                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC34circular_list(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = VV[38];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for ENSURE-CAR                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L35ensure_car(cl_object v1thing)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1thing))) { goto L1; }
  value0 = ecl_car(v1thing);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v1thing;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for ENSURE-CONS                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L36ensure_cons(cl_object v1cons)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1cons))) { goto L1; }
  value0 = v1cons;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = CONS(v1cons,ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for ENSURE-LIST                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L37ensure_list(cl_object v1list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1list))) { goto L1; }
  value0 = v1list;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ecl_list1(v1list);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for REMOVE-FROM-PLIST                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L38remove_from_plist(cl_narg narg, cl_object v1plist, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1plist,narg,1);
  v2keys = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   cl_object v4key;
   cl_object v5rest;
   {
    cl_object v6;
    v6 = v1plist;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v3 = v6;
   }
   v4key = ECL_NIL;
   v5rest = ECL_NIL;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L8:;
    if (!(ECL_ATOM(v3))) { goto L10; }
    goto L9;
L10:;
    {
     cl_object v8;
     v8 = v3;
     v4key = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v5rest = v8;
    }
    {
     cl_object v8;
     v8 = ecl_cddr(v3);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v3 = v8;
    }
    goto L25;
L24:;
    si_assert_failure(5, ECL_SYM("REST",719), ECL_NIL, ECL_NIL, VV[43], v1plist);
L25:;
    if ((v5rest)!=ECL_NIL) { goto L28; }
    goto L24;
L28:;
    if ((si_memq(v4key,v2keys))!=ECL_NIL) { goto L30; }
    {
     cl_object v8;
     v8 = v7;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
    }
    v7 = ecl_list1(v4key);
    (ECL_CONS_CDR(T0)=v7,T0);
    {
     cl_object v8;
     v8 = v7;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
    }
    T1 = ecl_car(v5rest);
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
L30:;
    goto L8;
L9:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      function definition for DELETE-FROM-PLIST                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L39delete_from_plist(cl_narg narg, cl_object v1plist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1plist,narg,1);
  v2keys = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3head;
   v3head = v1plist;
   {
    cl_object v4tail;
    v4tail = ECL_NIL;
    {
     cl_object v5;
     cl_object v6key;
     cl_object v7rest;
     {
      cl_object v8;
      v8 = v1plist;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     v6key = ECL_NIL;
     v7rest = ECL_NIL;
L8:;
     if (!(ECL_ATOM(v5))) { goto L10; }
     goto L9;
L10:;
     {
      cl_object v8;
      v8 = v5;
      v6key = ecl_car(v8);
      v8 = ecl_cdr(v8);
      v7rest = v8;
     }
     {
      cl_object v8;
      v8 = ecl_cddr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     goto L26;
L25:;
     si_assert_failure(5, ECL_SYM("REST",719), ECL_NIL, ECL_NIL, VV[43], v1plist);
L26:;
     if ((v7rest)!=ECL_NIL) { goto L29; }
     goto L25;
L29:;
     if (Null(si_memq(v6key,v2keys))) { goto L31; }
     {
      cl_object v8next;
      v8next = ecl_cdr(v7rest);
      if (Null(v4tail)) { goto L34; }
      {
       cl_object v9;
       v9 = v8next;
       {
        cl_object v10;
        v10 = v4tail;
        if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
        T0 = v10;
       }
       (ECL_CONS_CDR(T0)=v9,T0);
       goto L23;
      }
L34:;
      v3head = v8next;
      goto L23;
     }
L31:;
     v4tail = v7rest;
L23:;
     goto L8;
L9:;
     value0 = v3head;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      local function REMOVE-FROM-PLISTF                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC41remove_from_plistf(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC40__g187,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, VV[42], v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
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
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, VV[42], v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, VV[42], v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G187                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC40__g187(cl_object v1si__v)
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
/*      local function DELETE-FROM-PLISTF                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC43delete_from_plistf(cl_object v1, cl_object v2si__env)
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
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC42__g198,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, VV[44], v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[20],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
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
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, VV[44], v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, VV[44], v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[20],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G198                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC42__g198(cl_object v1si__v)
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
/*      function definition for SANS                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L44sans(cl_narg narg, cl_object v1plist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1plist,narg,1);
  v2keys = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_fdefinition(VV[42]);
  value0 = cl_apply(3, T0, v1plist, v2keys);
  return value0;
 }
}
/*      function definition for MAPPEND                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L45mappend(cl_narg narg, cl_object v1function, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2lists;
  ecl_va_list args; ecl_va_start(args,v1function,narg,1);
  v2lists = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   cl_object v4results;
   cl_object v5;
   T0 = (ECL_SYM("MAPCAR",545)->symbol.gfdef);
   v3 = cl_apply(3, T0, v1function, v2lists);
   v4results = ECL_NIL;
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L7:;
    if (!(ecl_endp(v5))) { goto L9; }
    goto L8;
L9:;
    v4results = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    {
     cl_object v8;
     v8 = cl_copy_list(v4results);
     {
      cl_object v9;
      v9 = v7;
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T0 = v9;
     }
     (ECL_CONS_CDR(T0)=v8,T0);
     if (Null(v8)) { goto L17; }
    }
    T0 = ecl_cdr(v7);
    v7 = ecl_last(T0,1);
L17:;
    goto L7;
L8:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      function definition for SETP                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L46setp(cl_narg narg, cl_object v1object, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v1object,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L46setpkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2test = (ECL_SYM("EQL",334)->symbol.gfdef);
   } else {
    v2test = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v3key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   } else {
    v3key = keyvars[1];
   }
  }
  if (!(ECL_LISTP(v1object))) { goto L4; }
  {
   cl_object v4seen;
   v4seen = ECL_NIL;
   {
    cl_object v5;
    v5 = v1object;
    goto L10;
L9:;
    {
     cl_object v6elt;
     v6elt = ecl_car(v5);
     {
      cl_object v7key;
      v7key = ecl_function_dispatch(cl_env_copy,v3key)(1, v6elt);
      {
       cl_object v8;
       v8 = v4seen;
       goto L21;
L20:;
       {
        cl_object v9;
        cl_object v10;
        {
         cl_object v11;
         v11 = v8;
         if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
         v9 = v11;
        }
        v10 = ECL_CONS_CAR(v9);
        if (Null(ecl_function_dispatch(cl_env_copy,v2test)(2, v7key, v10))) { goto L23; }
        if (Null(v9)) { goto L16; }
        goto L17;
       }
L23:;
       v8 = ECL_CONS_CDR(v8);
L21:;
       if (v8==ECL_NIL) { goto L31; }
       goto L20;
L31:;
       goto L16;
      }
L17:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
L16:;
      v4seen = CONS(v7key,v4seen);
     }
    }
    v5 = ecl_cdr(v5);
L10:;
    if (Null(v5)) { goto L36; }
    goto L9;
L36:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for SET-EQUAL                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L47set_equal(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4key;
  cl_object v5keyp;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L47set_equalkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3test = (ECL_SYM("EQL",334)->symbol.gfdef);
   } else {
    v3test = keyvars[0];
   }
   v4key = keyvars[1];
   v5keyp = keyvars[3];
  }
  {
   cl_object v6;
   cl_object v7;
   if (Null(v5keyp)) { goto L3; }
   {
    cl_object v8;
    cl_object v9;
    v8 = ECL_NIL;
    {
     cl_object v10;
     v10 = v1list1;
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    {
     cl_object v10;
     cl_object v11;
     v10 = ecl_list1(ECL_NIL);
     v11 = v10;
L11:;
     if (!(ecl_endp(v9))) { goto L13; }
     goto L12;
L13:;
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
     T1 = ecl_function_dispatch(cl_env_copy,v4key)(1, v8);
     v11 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v11,T0);
     goto L11;
L12:;
     v6 = ecl_cdr(v10);
     goto L2;
    }
   }
L3:;
   v6 = v1list1;
L2:;
   if (Null(v5keyp)) { goto L30; }
   {
    cl_object v8;
    cl_object v9;
    v8 = ECL_NIL;
    {
     cl_object v10;
     v10 = v2list2;
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    {
     cl_object v10;
     cl_object v11;
     v10 = ecl_list1(ECL_NIL);
     v11 = v10;
L38:;
     if (!(ecl_endp(v9))) { goto L40; }
     goto L39;
L40:;
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
     T1 = ecl_function_dispatch(cl_env_copy,v4key)(1, v8);
     v11 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v11,T0);
     goto L38;
L39:;
     v7 = ecl_cdr(v10);
     goto L29;
    }
   }
L30:;
   v7 = v2list2;
L29:;
   {
    cl_object v8;
    v8 = v6;
    goto L62;
L61:;
    {
     cl_object v9elt;
     v9elt = ecl_car(v8);
     {
      cl_object v10;
      v10 = v7;
      goto L73;
L72:;
      {
       cl_object v11;
       cl_object v12;
       {
        cl_object v13;
        v13 = v10;
        if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
        v11 = v13;
       }
       v12 = ECL_CONS_CAR(v11);
       if (Null(ecl_function_dispatch(cl_env_copy,v3test)(2, v9elt, v12))) { goto L75; }
       value0 = v11;
       goto L69;
      }
L75:;
      v10 = ECL_CONS_CDR(v10);
L73:;
      if (v10==ECL_NIL) { goto L83; }
      goto L72;
L83:;
      value0 = ECL_NIL;
     }
L69:;
     if ((value0)!=ECL_NIL) { goto L68; }
     goto L57;
L68:;
     goto L66;
L66:;
    }
    v8 = ecl_cdr(v8);
L62:;
    if (Null(v8)) { goto L87; }
    goto L61;
L87:;
   }
   {
    cl_object v8;
    v8 = v7;
    goto L92;
L91:;
    {
     cl_object v9elt;
     v9elt = ecl_car(v8);
     {
      cl_object v10;
      v10 = v6;
      goto L103;
L102:;
      {
       cl_object v11;
       cl_object v12;
       {
        cl_object v13;
        v13 = v10;
        if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
        v11 = v13;
       }
       v12 = ECL_CONS_CAR(v11);
       if (Null(ecl_function_dispatch(cl_env_copy,v3test)(2, v9elt, v12))) { goto L105; }
       value0 = v11;
       goto L99;
      }
L105:;
      v10 = ECL_CONS_CDR(v10);
L103:;
      if (v10==ECL_NIL) { goto L113; }
      goto L102;
L113:;
      value0 = ECL_NIL;
     }
L99:;
     if ((value0)!=ECL_NIL) { goto L98; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L98:;
     goto L96;
L96:;
    }
    v8 = ecl_cdr(v8);
L92:;
    if (Null(v8)) { goto L117; }
    goto L91;
L117:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L57:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MAP-PRODUCT                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L51map_product(cl_narg narg, cl_object v1function, cl_object v2list, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3more_lists;
  ecl_va_list args; ecl_va_start(args,v2list,narg,2);
  v3more_lists = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_function_dispatch(cl_env_copy,VV[93])(1, v1function) /*  ENSURE-FUNCTION */;
  T1 = CONS(v2list,v3more_lists);
  value0 = LC50_map_product(T0, T1);
  return value0;
 }
}
/*      local function %MAP-PRODUCT                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC50_map_product(cl_object v1f, cl_object v2lists)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1f,env0);                   /*  F               */
  {
   cl_object v3;
   cl_object v4;
   cl_object env1 = env0;
   v3 = ecl_cdr(v2lists);
   v4 = ecl_car(v2lists);
   CLV1 = env1 = CONS(v3,env1);                   /*  MORE            */
   if ((ECL_CONS_CAR(CLV1))!=ECL_NIL) { goto L3; }
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
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
L11:;
     if (!(ecl_endp(v6))) { goto L13; }
     goto L12;
L13:;
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
      T0 = v9;
     }
     T1 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, v5);
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
     goto L11;
L12:;
     value0 = ecl_cdr(v7);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L3:;
   {
    cl_object v9;
    v9 = ecl_make_cclosure_va((cl_objectfn)LC49__g270,env1,Cblock);
    T0 = v9;
   }
   value0 = L45mappend(2, T0, v4);
   return value0;
  }
 }
}
/*      closure G270                                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC49__g270(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  MORE            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   cl_object env1 = env0;
   v2 = ecl_function_dispatch(cl_env_copy,VV[93])(1, ECL_CONS_CAR(CLV0)) /*  ENSURE-FUNCTION */;
   CLV2 = env1 = CONS(v2,env1);
   CLV3 = env1 = CONS(v1x,env1);
   {
    cl_object v3;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC48__g275,env1,Cblock);
    T0 = v3;
   }
  }
  value0 = LC50_map_product(T0, ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*      closure G275                                                  */
/*      optimize speed 3, debug 1, space 0, safety 1                  */
static cl_object LC48__g275(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1more;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1more = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_apply(3, ECL_CONS_CAR(CLV2), ECL_CONS_CAR(CLV3), v1more);
  return value0;
 }
 }
}
/*      function definition for FLATTEN                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L53flatten(cl_object v1tree)
{
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  lex0[0] = ECL_NIL;                              /*  LIST            */
  LC52traverse(lex0, v1tree);
  value0 = cl_nreverse(lex0[0]);
  return value0;
 }
}
/*      local function TRAVERSE                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC52traverse(volatile cl_object *lex0, cl_object v1subtree)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1subtree)) { goto L1; }
  if (!(ECL_CONSP(v1subtree))) { goto L3; }
  T0 = ecl_car(v1subtree);
  LC52traverse(lex0, T0);
  v1subtree = ecl_cdr(v1subtree);
  goto TTL;
L3:;
  lex0[0] = CONS(v1subtree,lex0[0]);
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lib/alexandria/lists.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecli7UuzzMOVz39M_hCh2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/lists.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecli7UuzzMOVz39M_hCh2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[53]);                          /*  SAFE-ENDP       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[54]);                          /*  ALIST-PLIST     */
  si_set_documentation(3, VV[1], ECL_SYM("FUNCTION",396), VVtemp[8]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[9], VVtemp[10]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[11]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[55]);                          /*  PLIST-ALIST     */
  si_set_documentation(3, VV[2], ECL_SYM("FUNCTION",396), VVtemp[12]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[13]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[56]);                          /*  RACONS          */
 {
  cl_object T0;
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[17]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[20]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[57]);                          /*  ASSOC-VALUE     */
  si_set_documentation(3, VV[4], ECL_SYM("FUNCTION",396), VVtemp[21]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun_va((cl_objectfn)LC6assoc_value,ECL_NIL,Cblock);
   T0 = v1;
  }
  si_do_define_setf_method(VV[4], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[22]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[12], ECL_SYM("LOCATION",1777), VVtemp[23], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[12], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[20]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[58]);                          /*  RASSOC-VALUE    */
  si_set_documentation(3, VV[12], ECL_SYM("FUNCTION",396), VVtemp[24]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun_va((cl_objectfn)LC8rassoc_value,ECL_NIL,Cblock);
   T0 = v1;
  }
  si_do_define_setf_method(VV[12], T0);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LOCATION",1777), VVtemp[25], VVtemp[26]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[11]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[60]);                          /*  MALFORMED-PLIST */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[29]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[61]);                       /*  DOPLIST         */
  si_set_documentation(3, VV[15], ECL_SYM("FUNCTION",396), VVtemp[30]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[19], ECL_SYM("LOCATION",1777), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[19], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[33]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[63]);                       /*  APPENDF         */
  si_set_documentation(3, VV[19], ECL_SYM("FUNCTION",396), VVtemp[34]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[21], ECL_SYM("LOCATION",1777), VVtemp[35], VVtemp[36]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[21], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[33]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[64]);                       /*  NCONCF          */
  si_set_documentation(3, VV[21], ECL_SYM("FUNCTION",396), VVtemp[37]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LOCATION",1777), VVtemp[38], VVtemp[39]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[65]);                       /*  UNIONF          */
  si_set_documentation(3, VV[22], ECL_SYM("FUNCTION",396), VVtemp[41]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LOCATION",1777), VVtemp[42], VVtemp[43]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[66]);                       /*  NUNIONF         */
  si_set_documentation(3, VV[23], ECL_SYM("FUNCTION",396), VVtemp[44]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LOCATION",1777), VVtemp[45], VVtemp[46]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[47]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[67]);                       /*  REVERSEF        */
  si_set_documentation(3, VV[24], ECL_SYM("FUNCTION",396), VVtemp[48]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LOCATION",1777), VVtemp[49], VVtemp[50]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[47]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[68]);                       /*  NREVERSEF       */
  si_set_documentation(3, VV[25], ECL_SYM("FUNCTION",396), VVtemp[51]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LOCATION",1777), VVtemp[52], VVtemp[53]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[54]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[69]);                          /*  CIRCULAR-LIST   */
  si_set_documentation(3, VV[26], ECL_SYM("FUNCTION",396), VVtemp[55]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LOCATION",1777), VVtemp[56], VVtemp[57]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[58]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[70]);                          /*  CIRCULAR-LIST-P */
  si_set_documentation(3, VV[27], ECL_SYM("FUNCTION",396), VVtemp[59]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[28], ECL_SYM("LOCATION",1777), VVtemp[60], VVtemp[61]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[28], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[58]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[71]);                          /*  CIRCULAR-TREE-P */
  si_set_documentation(3, VV[28], ECL_SYM("FUNCTION",396), VVtemp[62]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[29], ECL_SYM("LOCATION",1777), VVtemp[63], VVtemp[64]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[29], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[58]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[72]);                          /*  PROPER-LIST-P   */
  si_set_documentation(3, VV[29], ECL_SYM("FUNCTION",396), VVtemp[65]);
 {
  cl_object T0;
  si_set_documentation(3, VV[30], ECL_SYM("TYPE",869), VVtemp[66]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC28proper_list,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[30], VVtemp[67], T0);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[32], ECL_SYM("LOCATION",1777), VVtemp[68], VVtemp[69]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[32], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[70]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[73]);                          /*  CIRCULAR-LIST-ERROR */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[34], ECL_SYM("LOCATION",1777), VVtemp[71], VVtemp[72]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[34], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[70]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[74]);                          /*  PROPER-LIST-LENGTH */
  si_set_documentation(3, VV[34], ECL_SYM("FUNCTION",396), VVtemp[73]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LOCATION",1777), VVtemp[74], VVtemp[72]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[70]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[75]);                          /*  LASTCAR         */
  si_set_documentation(3, VV[35], ECL_SYM("FUNCTION",396), VVtemp[75]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[76], ECL_SYM("LOCATION",1777), VVtemp[77], VVtemp[72]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[76], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[78]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[76]);                          /*  (SETF LASTCAR)  */
  si_set_documentation(3, VV[36], ECL_SYM("FUNCTION",396), VVtemp[79]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[37], ECL_SYM("LOCATION",1777), VVtemp[80], VVtemp[81]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[37], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[82]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[77]);                          /*  MAKE-CIRCULAR-LIST */
  si_set_documentation(3, VV[37], ECL_SYM("FUNCTION",396), VVtemp[83]);
 {
  cl_object T0;
  si_set_documentation(3, VV[26], ECL_SYM("TYPE",869), VVtemp[84]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC34circular_list,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[26], VVtemp[85], T0);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LOCATION",1777), VVtemp[86], VVtemp[87]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[88]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[79]);                          /*  ENSURE-CAR      */
  si_set_documentation(3, VV[39], ECL_SYM("FUNCTION",396), VVtemp[89]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LOCATION",1777), VVtemp[90], VVtemp[91]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[92]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[80]);                          /*  ENSURE-CONS     */
  si_set_documentation(3, VV[40], ECL_SYM("FUNCTION",396), VVtemp[93]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LOCATION",1777), VVtemp[94], VVtemp[95]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[70]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[81]);                          /*  ENSURE-LIST     */
  si_set_documentation(3, VV[41], ECL_SYM("FUNCTION",396), VVtemp[96]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[42], ECL_SYM("LOCATION",1777), VVtemp[97], VVtemp[98]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[42], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[99]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[82]);                          /*  REMOVE-FROM-PLIST */
  si_set_documentation(3, VV[42], ECL_SYM("FUNCTION",396), VVtemp[100]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[44], ECL_SYM("LOCATION",1777), VVtemp[101], VVtemp[102]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[44], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[99]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[83]);                          /*  DELETE-FROM-PLIST */
  si_set_documentation(3, VV[44], ECL_SYM("FUNCTION",396), VVtemp[103]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[45], ECL_SYM("LOCATION",1777), VVtemp[104], VVtemp[105]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[45], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[106]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[84]);                       /*  REMOVE-FROM-PLISTF */
  si_set_documentation(3, VV[45], ECL_SYM("FUNCTION",396), VVtemp[107]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[46], ECL_SYM("LOCATION",1777), VVtemp[108], VVtemp[109]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[46], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[106]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[85]);                       /*  DELETE-FROM-PLISTF */
  si_set_documentation(3, VV[46], ECL_SYM("FUNCTION",396), VVtemp[110]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[111]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[47], ECL_SYM("LOCATION",1777), VVtemp[112], VVtemp[113]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[47], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[99]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[86]);                          /*  SANS            */
  si_set_documentation(3, VV[47], ECL_SYM("FUNCTION",396), VVtemp[114]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[48], ECL_SYM("LOCATION",1777), VVtemp[115], VVtemp[116]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[48], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[117]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[87]);                          /*  MAPPEND         */
  si_set_documentation(3, VV[48], ECL_SYM("FUNCTION",396), VVtemp[118]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[49], ECL_SYM("LOCATION",1777), VVtemp[119], VVtemp[120]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[49], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[121]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[88]);                          /*  SETP            */
  si_set_documentation(3, VV[49], ECL_SYM("FUNCTION",396), VVtemp[122]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[50], ECL_SYM("LOCATION",1777), VVtemp[123], VVtemp[124]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[50], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[125]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[91]);                          /*  SET-EQUAL       */
  si_set_documentation(3, VV[50], ECL_SYM("FUNCTION",396), VVtemp[126]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[51], ECL_SYM("LOCATION",1777), VVtemp[127], VVtemp[128]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[51], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[129]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[92]);                          /*  MAP-PRODUCT     */
  si_set_documentation(3, VV[51], ECL_SYM("FUNCTION",396), VVtemp[130]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[52], ECL_SYM("LOCATION",1777), VVtemp[131], VVtemp[132]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[52], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[133]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[94]);                          /*  FLATTEN         */
  si_set_documentation(3, VV[52], ECL_SYM("FUNCTION",396), VVtemp[134]);
}
