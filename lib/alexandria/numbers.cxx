/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/numbers.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/numbers.eclh"
/*      function definition for CLAMP                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1clamp(cl_object v1number, cl_object v2min, cl_object v3max)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_lower(v1number,v2min))) { goto L1; }
  value0 = v2min;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_greater(v1number,v3max))) { goto L3; }
  value0 = v3max;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = v1number;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for GAUSSIAN-RANDOM                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4gaussian_random(cl_narg narg, ...)
{
 cl_object T0, T1;
 volatile cl_object lex0[2];
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    lex0[0] = ECL_NIL;                            /*  MIN             */
   } else {
    i++;
    lex0[0] = va_arg(args,cl_object);             /*  MIN             */
   }
   if (i >= narg) {
    lex0[1] = ECL_NIL;                            /*  MAX             */
   } else {
    i++;
    lex0[1] = va_arg(args,cl_object);             /*  MAX             */
   }
  }
  va_end(args);
  {
   cl_object v2;                                  /*  G1              */
   cl_object v3;                                  /*  G2              */
   value0 = LC2gauss();
   {
    const int v4 = cl_env_copy->nvalues;
    v2 = value0;
    cl_object v5;
    v5 = (v4<=1)? ECL_NIL : cl_env_copy->values[1];
    v3 = v5;
   }
   T0 = LC3guard(lex0, v2);
   T1 = LC3guard(lex0, v3);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*      local function GUARD                                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3guard(volatile cl_object *lex0, cl_object v1x)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = lex0[0];
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = v1x;
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  value0 = lex0[1];
  if ((value0)!=ECL_NIL) { goto L9; }
  T1 = v1x;
  goto L7;
L9:;
  T1 = value0;
  goto L7;
L7:;
  if ((cl_LE(3, T0, v1x, T1))!=ECL_NIL) { goto L1; }
L11:;
  {
   cl_object v3;                                  /*  X1              */
   cl_object v4;                                  /*  X2              */
   value0 = LC2gauss();
   {
    const int v5 = cl_env_copy->nvalues;
    v3 = value0;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   value0 = lex0[0];
   if ((value0)!=ECL_NIL) { goto L19; }
   T0 = v3;
   goto L17;
L19:;
   T0 = value0;
   goto L17;
L17:;
   value0 = lex0[1];
   if ((value0)!=ECL_NIL) { goto L23; }
   T1 = v3;
   goto L21;
L23:;
   T1 = value0;
   goto L21;
L21:;
   if (Null(cl_LE(3, T0, v3, T1))) { goto L15; }
   v1x = v3;
   goto L12;
L15:;
   value0 = lex0[0];
   if ((value0)!=ECL_NIL) { goto L31; }
   T0 = v4;
   goto L29;
L31:;
   T0 = value0;
   goto L29;
L29:;
   value0 = lex0[1];
   if ((value0)!=ECL_NIL) { goto L35; }
   T1 = v4;
   goto L33;
L35:;
   T1 = value0;
   goto L33;
L33:;
   if (Null(cl_LE(3, T0, v4, T1))) { goto L27; }
   v1x = v4;
   goto L12;
L27:;
   goto L11;
  }
L12:;
L1:;
  value0 = v1x;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function GAUSS                                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2gauss()
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1x1;
   v1x1 = ECL_NIL;
   {
    cl_object v2x2;
    v2x2 = ECL_NIL;
    {
     cl_object v3w;
     v3w = ECL_NIL;
L4:;
     T0 = cl_random(1, VV[2]);
     v1x1 = ecl_minus(T0,VV[3]);
     T0 = cl_random(1, VV[2]);
     v2x2 = ecl_minus(T0,VV[3]);
     T0 = ecl_expt(v1x1,ecl_make_fixnum(2));
     T1 = ecl_expt(v2x2,ecl_make_fixnum(2));
     v3w = ecl_plus(T0,T1);
     if (!(ecl_lower(v3w,VV[3]))) { goto L11; }
     {
      cl_object v4v;
      T0 = cl_log(1, v3w);
      T1 = ecl_times(VV[4],T0);
      T2 = ecl_divide(T1,v3w);
      v4v = ecl_sqrt(T2);
      T0 = ecl_times(v1x1,v4v);
      T1 = ecl_times(v2x2,v4v);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = T1;
      cl_env_copy->values[0] = T0;
      return cl_env_copy->values[0];
     }
L11:;
     goto L4;
    }
   }
  }
 }
}
/*      function definition for IOTA                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5iota(cl_narg narg, cl_object v1n, ...)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2start;
  cl_object v3step;
  ecl_va_list args; ecl_va_start(args,v1n,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L5iotakeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2start = ecl_make_fixnum(0);
   } else {
    v2start = keyvars[0];
    {
     bool v4;
     v4 = ecl_numberp(v2start);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("NUMBER",608),v2start);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
   }
   if (Null(keyvars[3])) {
    v3step = ecl_make_fixnum(1);
   } else {
    v3step = keyvars[1];
    {
     bool v4;
     v4 = ecl_numberp(v3step);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("NUMBER",608),v3step);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
   }
  }
  {
   cl_object v4;
   v4 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L9; }
   v4 = v1n;
   T0 = ecl_make_bool(ecl_greatereq(v4,ecl_make_fixnum(0)));
   goto L6;
L9:;
   T0 = ECL_NIL;
   goto L6;
  }
L6:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[6],v1n);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_object v4;
   cl_object v5i;
   v4 = v1n;
   v5i = ECL_NIL;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
    v4 = ecl_minus(v4,ecl_make_fixnum(1));
    T0 = v4;
    if (!(ecl_minusp(T0))) { goto L19; }
    goto L18;
L19:;
    T0 = ecl_plus(v2start,v3step);
    v5i = ecl_minus(T0,v3step);
L17:;
    {
     cl_object v8;
     v8 = v7;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     T0 = v8;
    }
    v7 = ecl_list1(v5i);
    (ECL_CONS_CDR(T0)=v7,T0);
    v4 = ecl_minus(v4,ecl_make_fixnum(1));
    T0 = v4;
    if (!(ecl_minusp(T0))) { goto L30; }
    goto L18;
L30:;
    v5i = ecl_plus(v5i,v3step);
    goto L17;
L18:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      function definition for MAP-IOTA                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L6map_iota(cl_narg narg, cl_object v1function, cl_object v2n, ...)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4step;
  ecl_va_list args; ecl_va_start(args,v2n,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L6map_iotakeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
    {
     bool v5;
     v5 = ecl_numberp(v3start);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("NUMBER",608),v3start);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
   }
   if (Null(keyvars[3])) {
    v4step = ecl_make_fixnum(1);
   } else {
    v4step = keyvars[1];
    {
     bool v5;
     v5 = ecl_numberp(v4step);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("NUMBER",608),v4step);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
   }
  }
  {
   cl_object v5;
   v5 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v2n)||ECL_BIGNUMP(v2n))) { goto L9; }
   v5 = v2n;
   T0 = ecl_make_bool(ecl_greatereq(v5,ecl_make_fixnum(0)));
   goto L6;
L9:;
   T0 = ECL_NIL;
   goto L6;
  }
L6:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[6],v2n);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_object v5;
   cl_object v6i;
   v5 = v2n;
   v6i = ECL_NIL;
   v5 = ecl_minus(v5,ecl_make_fixnum(1));
   T0 = v5;
   if (!(ecl_minusp(T0))) { goto L18; }
   goto L17;
L18:;
   T0 = ecl_minus(v4step,v4step);
   v6i = ecl_plus(v3start,T0);
L16:;
   ecl_function_dispatch(cl_env_copy,v1function)(1, v6i);
   v5 = ecl_minus(v5,ecl_make_fixnum(1));
   T0 = v5;
   if (!(ecl_minusp(T0))) { goto L25; }
   goto L17;
L25:;
   v6i = ecl_plus(v6i,v4step);
   goto L16;
L17:;
  }
  value0 = v2n;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for LERP                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7lerp(cl_object v1v, cl_object v2a, cl_object v3b)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_minus(v3b,v2a);
  T1 = ecl_times(v1v,T0);
  value0 = ecl_plus(v2a,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for MEAN                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L8mean(cl_object v1sample)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("+",16)->symbol.gfdef);
  T1 = cl_reduce(2, T0, v1sample);
  {
   cl_fixnum v2;
   v2 = ecl_length(v1sample);
   value0 = ecl_divide(T1,ecl_make_fixnum(v2));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MEDIAN                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9median(cl_object v1sample)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2vector;
   cl_fixnum v3length;
   cl_object v4middle;
   T0 = ecl_function_dispatch(cl_env_copy,VV[43])(2, ECL_SYM("VECTOR",900), v1sample) /*  COPY-SEQUENCE */;
   T1 = (ECL_SYM("<",74)->symbol.gfdef);
   v2vector = cl_sort(2, T0, T1);
   v3length = ecl_length(v2vector);
   v4middle = ecl_truncate2(ecl_make_fixnum(v3length),ecl_make_fixnum(2));
   if (!(ecl_oddp(ecl_make_fixnum(v3length)))) { goto L5; }
   {
    cl_object v5;
    v5 = v2vector;
    T0 = v5;
    {
     cl_fixnum v6;
     {
      cl_object v7;
      v7 = v4middle;
      if (ecl_unlikely((ecl_fixnum(v7))>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(ecl_fixnum(v7)),(v5)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v6 = ecl_fixnum(v7);
     }
     value0 = ecl_aref_unsafe(T0,v6);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L5:;
   {
    cl_object v7;
    v7 = v2vector;
    T1 = v7;
    {
     cl_fixnum v8;
     {
      cl_object v9;
      v9 = v4middle;
      if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v8 = ecl_fixnum(v9);
     }
     T0 = ecl_aref_unsafe(T1,v8);
    }
   }
   {
    cl_object v7;
    v7 = v2vector;
    T2 = v7;
    {
     cl_fixnum v8;
     {
      cl_object v9;
      v9 = ecl_one_minus(v4middle);
      if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v8 = ecl_fixnum(v9);
     }
     T1 = ecl_aref_unsafe(T2,v8);
    }
   }
   T2 = ecl_plus(T0,T1);
   value0 = ecl_divide(T2,ecl_make_fixnum(2));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for VARIANCE                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L11variance(cl_narg narg, cl_object v1sample, ...)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2biased;
  ecl_va_list args; ecl_va_start(args,v1sample,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L11variancekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2biased = ECL_T;
   } else {
    v2biased = keyvars[0];
   }
  }
  {
   cl_object env1 = env0;
   T1 = (ECL_SYM("+",16)->symbol.gfdef);
   T2 = cl_reduce(2, T1, v1sample);
   {
    cl_fixnum v3;
    v3 = ecl_length(v1sample);
    T0 = ecl_divide(T2,ecl_make_fixnum(v3));
   }
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  MEAN            */
   {
    cl_object v3;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC10__lambda32,env1,Cblock,2);
    T0 = v3;
   }
   T1 = cl_reduce(4, T0, v1sample, VV[12], ecl_make_fixnum(0));
   {
    cl_fixnum v3;
    v3 = ecl_length(v1sample);
    {
     cl_fixnum v4;
     if (Null(v2biased)) { goto L6; }
     v4 = 0;
     goto L5;
L6:;
     v4 = 1;
L5:;
     T2 = ecl_minus(ecl_make_fixnum(v3),ecl_make_fixnum(v4));
     value0 = ecl_divide(T1,T2);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      closure LAMBDA32                                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC10__lambda32(cl_narg narg, cl_object v1a, cl_object v2b, ...)
{
 cl_object T0, T1;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  MEAN            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_minus(v2b,ECL_CONS_CAR(CLV0));
  T1 = ecl_expt(T0,ecl_make_fixnum(2));
  value0 = ecl_plus(v1a,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      function definition for STANDARD-DEVIATION                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L13standard_deviation(cl_narg narg, cl_object v1sample, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object env0 = ECL_NIL;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2biased;
  ecl_va_list args; ecl_va_start(args,v1sample,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L13standard_deviationkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2biased = ECL_T;
   } else {
    v2biased = keyvars[0];
   }
  }
  {
   cl_object v3;
   cl_object v4;
   cl_object v5biased;
   v3 = cl_list(2, VV[14], v2biased);
   v4 = ecl_function_dispatch(cl_env_copy,VV[46])(2, v3, VV[14]) /*  SEARCH-KEYWORD */;
   if (!((v4)==(ECL_SYM("MISSING-KEYWORD",2037)))) { goto L6; }
   v5biased = ECL_T;
   goto L5;
L6:;
   v5biased = v4;
L5:;
   ecl_function_dispatch(cl_env_copy,VV[47])(2, v3, VV[15]) /*  CHECK-KEYWORD */;
   {
    cl_object env1 = env0;
    T2 = (ECL_SYM("+",16)->symbol.gfdef);
    T3 = cl_reduce(2, T2, v1sample);
    {
     cl_fixnum v6;
     v6 = ecl_length(v1sample);
     T1 = ecl_divide(T3,ecl_make_fixnum(v6));
    }
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(T1,env1);                  /*  MEAN            */
    {
     cl_object v6;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC12__lambda40,env1,Cblock,2);
     T1 = v6;
    }
    T2 = cl_reduce(4, T1, v1sample, VV[12], ecl_make_fixnum(0));
    {
     cl_fixnum v6;
     v6 = ecl_length(v1sample);
     {
      cl_fixnum v7;
      if (Null(v5biased)) { goto L15; }
      v7 = 0;
      goto L14;
L15:;
      v7 = 1;
L14:;
      T3 = ecl_minus(ecl_make_fixnum(v6),ecl_make_fixnum(v7));
      T0 = ecl_divide(T2,T3);
     }
    }
   }
  }
  value0 = ecl_sqrt(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      closure LAMBDA40                                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12__lambda40(cl_narg narg, cl_object v1a, cl_object v2b, ...)
{
 cl_object T0, T1;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  MEAN            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_minus(v2b,ECL_CONS_CAR(CLV0));
  T1 = ecl_expt(T0,ecl_make_fixnum(2));
  value0 = ecl_plus(v1a,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      local function MAXF                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC15maxf(cl_object v1, cl_object v2si__env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 cl_object env0 = ECL_NIL;
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
   ecl_function_dispatch(cl_env_copy,VV[49])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
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
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",412)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    {
     v6 = value0;
     v7 = cl_env_copy->values[1];
     v8 = cl_env_copy->values[2];
     v9 = cl_env_copy->values[3];
     v10 = cl_env_copy->values[4];
    }
    {
     cl_object v11si__all_vars;
     {
      cl_object v12;
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC14__lambda46,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",182)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("MAX",553), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",373)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[17],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",276), T6);
     T8 = cl_list(4, ECL_SYM("LET*",480), v11si__all_vars, T7, v9);
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
      T1 = (ECL_SYM("CAR",182)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = cl_listX(3, ECL_SYM("MAX",553), v10, T2);
      T4 = cl_list(2, T0, T3);
      T5 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T4,T5);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",373)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[17],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",276), T4);
      value0 = cl_list(4, ECL_SYM("LET*",480), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function LAMBDA46                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14__lambda46(cl_object v1si__v)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
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
/*      local function MINF                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC17minf(cl_object v1, cl_object v2si__env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 cl_object env0 = ECL_NIL;
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
   ecl_function_dispatch(cl_env_copy,VV[49])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
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
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",412)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    {
     v6 = value0;
     v7 = cl_env_copy->values[1];
     v8 = cl_env_copy->values[2];
     v9 = cl_env_copy->values[3];
     v10 = cl_env_copy->values[4];
    }
    {
     cl_object v11si__all_vars;
     {
      cl_object v12;
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC16__lambda57,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",182)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("MIN",559), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",373)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[17],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",276), T6);
     T8 = cl_list(4, ECL_SYM("LET*",480), v11si__all_vars, T7, v9);
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
      T1 = (ECL_SYM("CAR",182)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = cl_listX(3, ECL_SYM("MIN",559), v10, T2);
      T4 = cl_list(2, T0, T3);
      T5 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T4,T5);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",373)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[17],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",276), T4);
      value0 = cl_list(4, ECL_SYM("LET*",480), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function LAMBDA57                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC16__lambda57(cl_object v1si__v)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
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
/*      function definition for %MULTIPLY-RANGE                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L21_multiply_range(cl_object v1i, cl_object v2j)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1i))) { goto L1; }
  if (!(ECL_FIXNUMP(v2j))) { goto L1; }
  value0 = LC18bisect(v1i, v2j);
  return value0;
L1:;
  value0 = LC19bisect_big(v1i, v2j);
  return value0;
 }
}
/*      local function MULTIPLY-RANGE                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC20multiply_range(cl_object v1j, cl_object v2k)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3;
   v3 = 0;
   if (!(ECL_FIXNUMP(v1j))) { goto L5; }
   v3 = ecl_fixnum(v1j);
   if (!((v3)<=(2305843009213693951))) { goto L10; }
   T0 = ecl_make_bool((v3)>=(1));
   goto L2;
L10:;
   T0 = ECL_NIL;
   goto L2;
L5:;
   T0 = ECL_NIL;
   goto L2;
  }
L2:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[22],v1j);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_fixnum v3;
   v3 = 0;
   if (!(ECL_FIXNUMP(v2k))) { goto L16; }
   v3 = ecl_fixnum(v2k);
   if (!((v3)<=(2305843009213693951))) { goto L21; }
   T0 = ecl_make_bool((v3)>=(1));
   goto L13;
L21:;
   T0 = ECL_NIL;
   goto L13;
L16:;
   T0 = ECL_NIL;
   goto L13;
  }
L13:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[22],v2k);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_object v3;
   cl_object v4f;
   cl_fixnum v5m;
   v3 = ecl_make_integer((ecl_to_fixnum(v2k))-1);
   v4f = v2k;
   {
    cl_object v6;
    v6 = v3;
    {
     cl_fixnum v7;
     v7 = 0;
     if (!(ECL_FIXNUMP(v6))) { goto L31; }
     v7 = ecl_fixnum(v6);
     if (!((v7)<(2305843009213693951))) { goto L36; }
     T0 = ecl_make_bool((v7)>=(0));
     goto L28;
L36:;
     T0 = ECL_NIL;
     goto L28;
L31:;
     T0 = ECL_NIL;
     goto L28;
    }
L28:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[24],v6);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v5m = ecl_fixnum(v6);
   }
   goto L40;
L39:;
   {
    cl_object v6;
    v6 = ecl_times(v4f,ecl_make_fixnum(v5m));
    {
     cl_object v7;
     v7 = ecl_make_fixnum(0);
     v7 = v6;
     T0 = ecl_make_bool(ecl_greatereq(v7,ecl_make_fixnum(0)));
     goto L46;
     T0 = ECL_NIL;
     goto L46;
    }
L46:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",887),v6);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v4f = v6;
   }
   {
    cl_object v6;
    v6 = ecl_make_integer((v5m)-1);
    {
     cl_fixnum v7;
     v7 = 0;
     if (!(ECL_FIXNUMP(v6))) { goto L59; }
     v7 = ecl_fixnum(v6);
     if (!((v7)<(2305843009213693951))) { goto L64; }
     T0 = ecl_make_bool((v7)>=(0));
     goto L56;
L64:;
     T0 = ECL_NIL;
     goto L56;
L59:;
     T0 = ECL_NIL;
     goto L56;
    }
L56:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[24],v6);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v5m = ecl_fixnum(v6);
   }
L40:;
   if ((v5m)<(ecl_to_fixnum(v1j))) { goto L66; }
   goto L39;
L66:;
   value0 = v4f;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function BISECT-BIG                                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19bisect_big(cl_object v1j, cl_object v2k)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v1j)||ECL_BIGNUMP(v1j))) { goto L5; }
   v3 = v1j;
   T0 = ecl_make_bool(ecl_greatereq(v3,ecl_make_fixnum(1)));
   goto L2;
L5:;
   T0 = ECL_NIL;
   goto L2;
  }
L2:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[23],v1j);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v2k)||ECL_BIGNUMP(v2k))) { goto L13; }
   v3 = v2k;
   T0 = ecl_make_bool(ecl_greatereq(v3,ecl_make_fixnum(1)));
   goto L10;
L13:;
   T0 = ECL_NIL;
   goto L10;
  }
L10:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[23],v2k);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  if (!(ecl_number_equalp(v1j,v2k))) { goto L17; }
  value0 = v1j;
  cl_env_copy->nvalues = 1;
  return value0;
L17:;
  {
   cl_object v3middle;
   T0 = ecl_minus(v2k,v1j);
   T1 = ecl_truncate2(T0,ecl_make_fixnum(2));
   v3middle = ecl_plus(v1j,T1);
   if (!(ecl_lowereq(v3middle,ecl_make_fixnum(2305843009213693951)))) { goto L21; }
   T0 = LC18bisect(v1j, v3middle);
   goto L20;
L21:;
   T0 = LC19bisect_big(v1j, v3middle);
L20:;
   T2 = ecl_plus(v3middle,ecl_make_fixnum(1));
   T1 = LC19bisect_big(T2, v2k);
   value0 = ecl_times(T0,T1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function BISECT                                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC18bisect(cl_object v1j, cl_object v2k)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3;
   v3 = 0;
   if (!(ECL_FIXNUMP(v1j))) { goto L5; }
   v3 = ecl_fixnum(v1j);
   if (!((v3)<=(2305843009213693951))) { goto L10; }
   T0 = ecl_make_bool((v3)>=(1));
   goto L2;
L10:;
   T0 = ECL_NIL;
   goto L2;
L5:;
   T0 = ECL_NIL;
   goto L2;
  }
L2:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[22],v1j);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   cl_fixnum v3;
   v3 = 0;
   if (!(ECL_FIXNUMP(v2k))) { goto L16; }
   v3 = ecl_fixnum(v2k);
   if (!((v3)<=(2305843009213693951))) { goto L21; }
   T0 = ecl_make_bool((v3)>=(1));
   goto L13;
L21:;
   T0 = ECL_NIL;
   goto L13;
L16:;
   T0 = ECL_NIL;
   goto L13;
  }
L13:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[22],v2k);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  T0 = ecl_minus(v2k,v1j);
  if (!(ecl_lower(T0,ecl_make_fixnum(8)))) { goto L23; }
  value0 = LC20multiply_range(v1j, v2k);
  return value0;
L23:;
  {
   cl_object v3middle;
   T0 = ecl_minus(v2k,v1j);
   T1 = ecl_truncate2(T0,ecl_make_fixnum(2));
   v3middle = ecl_plus(v1j,T1);
   T0 = LC18bisect(v1j, v3middle);
   T2 = ecl_plus(v3middle,ecl_make_fixnum(1));
   T1 = LC18bisect(T2, v2k);
   value0 = ecl_times(T0,T1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for %FACTORIAL                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L22_factorial(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_lower(v1n,ecl_make_fixnum(2)))) { goto L1; }
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = L21_multiply_range(ecl_make_fixnum(1), v1n);
  return value0;
 }
}
/*      function definition for FACTORIAL                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L23factorial(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1n;
   {
    cl_object v3;
    v3 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v2)||ECL_BIGNUMP(v2))) { goto L7; }
    v3 = v2;
    if (ecl_greatereq(v3,ecl_make_fixnum(0))) { goto L3; }
    goto L4;
L7:;
    goto L4;
   }
L4:;
   v1n = si_do_check_type(v2, VV[6], ECL_NIL, VV[27]);
L3:;
  }
  value0 = L22_factorial(v1n);
  return value0;
 }
}
/*      function definition for BINOMIAL-COEFFICIENT                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L24binomial_coefficient(cl_object v1n, cl_object v2k)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v1n;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v3)||ECL_BIGNUMP(v3))) { goto L7; }
    v4 = v3;
    if (ecl_greatereq(v4,ecl_make_fixnum(0))) { goto L3; }
    goto L4;
L7:;
    goto L4;
   }
L4:;
   v1n = si_do_check_type(v3, VV[6], ECL_NIL, VV[27]);
L3:;
  }
  {
   cl_object v3;
   v3 = v2k;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v3)||ECL_BIGNUMP(v3))) { goto L18; }
    v4 = v3;
    if (ecl_greatereq(v4,ecl_make_fixnum(0))) { goto L14; }
    goto L15;
L18:;
    goto L15;
   }
L15:;
   v2k = si_do_check_type(v3, VV[6], ECL_NIL, VV[29]);
L14:;
  }
  goto L25;
L24:;
  si_assert_failure(1, VV[30]);
L25:;
  if (ecl_greatereq(v1n,v2k)) { goto L28; }
  goto L24;
L28:;
  if (ecl_zerop(v2k)) { goto L32; }
  if (!(ecl_number_equalp(v1n,v2k))) { goto L30; }
  goto L31;
L32:;
L31:;
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L30:;
  {
   cl_object v3n_k;
   v3n_k = ecl_minus(v1n,v2k);
   if (!(ecl_lower(v2k,v3n_k))) { goto L35; }
   {
    cl_object v4;
    v4 = v3n_k;
    {
     cl_object v5;
     v5 = v2k;
     v2k = v4;
     v3n_k = v5;
    }
   }
L35:;
   if (!(ecl_number_equalp(ecl_make_fixnum(1),v3n_k))) { goto L43; }
   value0 = v1n;
   cl_env_copy->nvalues = 1;
   return value0;
L43:;
   T0 = ecl_plus(v2k,ecl_make_fixnum(1));
   T1 = L21_multiply_range(T0, v1n);
   T2 = L22_factorial(v3n_k);
   value0 = ecl_divide(T1,T2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for SUBFACTORIAL                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L25subfactorial(cl_object v1n)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1n;
   {
    cl_object v3;
    v3 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v2)||ECL_BIGNUMP(v2))) { goto L7; }
    v3 = v2;
    if (ecl_greatereq(v3,ecl_make_fixnum(0))) { goto L3; }
    goto L4;
L7:;
    goto L4;
   }
L4:;
   v1n = si_do_check_type(v2, VV[6], ECL_NIL, VV[27]);
L3:;
  }
  if (!(ecl_zerop(v1n))) { goto L12; }
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  {
   cl_object v2x;
   cl_object v3a;
   cl_object v4b;
   v2x = ecl_make_fixnum(1);
   v3a = ecl_make_fixnum(0);
   v4b = ecl_make_fixnum(1);
   goto L19;
L18:;
   {
    cl_object v5;
    v5 = ecl_one_plus(v2x);
    {
     cl_object v6;
     T0 = ecl_plus(v3a,v4b);
     v6 = ecl_times(v2x,T0);
     v4b = v3a;
     v3a = v6;
     v2x = v5;
    }
   }
L19:;
   if (ecl_number_equalp(v1n,v2x)) { goto L25; }
   goto L18;
L25:;
   value0 = v3a;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for COUNT-PERMUTATIONS                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L26count_permutations(cl_narg narg, cl_object v1n, ...)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2k;
  va_list args; va_start(args,v1n);
  {
   int i = 1;
   if (i >= narg) {
    v2k = v1n;
   } else {
    i++;
    v2k = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3;
   v3 = v1n;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v3)||ECL_BIGNUMP(v3))) { goto L8; }
    v4 = v3;
    if (ecl_greatereq(v4,ecl_make_fixnum(0))) { goto L4; }
    goto L5;
L8:;
    goto L5;
   }
L5:;
   v1n = si_do_check_type(v3, VV[6], ECL_NIL, VV[27]);
L4:;
  }
  {
   cl_object v3;
   v3 = v2k;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v3)||ECL_BIGNUMP(v3))) { goto L19; }
    v4 = v3;
    if (ecl_greatereq(v4,ecl_make_fixnum(0))) { goto L15; }
    goto L16;
L19:;
    goto L16;
   }
L16:;
   v2k = si_do_check_type(v3, VV[6], ECL_NIL, VV[29]);
L15:;
  }
  goto L26;
L25:;
  si_assert_failure(1, VV[30]);
L26:;
  if (ecl_greatereq(v1n,v2k)) { goto L29; }
  goto L25;
L29:;
  T0 = ecl_minus(v1n,v2k);
  T1 = ecl_one_plus(T0);
  value0 = L21_multiply_range(T1, v1n);
  return value0;
 }
}

#include "lib/alexandria/numbers.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclGV3xc4hVq7NJM_aLIycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/numbers.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclGV3xc4hVq7NJM_aLIycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[33]);                          /*  CLAMP           */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[5]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[0], ECL_SYM("INLINE",436), VVtemp[6]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[1], ECL_SYM("LOCATION",1862), VVtemp[7], VVtemp[8]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[1], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[9]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[35]);                          /*  GAUSSIAN-RANDOM */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[1], ECL_SYM("FUNCTION",398), VVtemp[10]) /*  SET-DOCUMENTATION */;
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[11]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LOCATION",1862), VVtemp[12], VVtemp[13]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[14]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[36]);                          /*  IOTA            */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[5], ECL_SYM("FUNCTION",398), VVtemp[15]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[5], ECL_SYM("INLINE",436), VVtemp[16]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[17]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LOCATION",1862), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[20]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[39]);                          /*  MAP-IOTA        */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[7], ECL_SYM("FUNCTION",398), VVtemp[21]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[7], ECL_SYM("INLINE",436), VVtemp[22]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[23]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[24], VVtemp[25]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[26]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[40]);                          /*  LERP            */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[8], ECL_SYM("FUNCTION",398), VVtemp[27]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[8], ECL_SYM("INLINE",436), VVtemp[28]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[29]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[9], ECL_SYM("LOCATION",1862), VVtemp[30], VVtemp[31]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[9], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[32]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[41]);                          /*  MEAN            */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[9], ECL_SYM("FUNCTION",398), VVtemp[33]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[9], ECL_SYM("INLINE",436), VVtemp[34]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[35]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[10], ECL_SYM("LOCATION",1862), VVtemp[36], VVtemp[37]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[10], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[32]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[42]);                          /*  MEDIAN          */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[10], ECL_SYM("FUNCTION",398), VVtemp[38]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[10], ECL_SYM("INLINE",436), VVtemp[39]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[40]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LOCATION",1862), VVtemp[41], VVtemp[42]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[43]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[44]);                          /*  VARIANCE        */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[11], ECL_SYM("FUNCTION",398), VVtemp[44]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[11], ECL_SYM("INLINE",436), VVtemp[45]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[46]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LOCATION",1862), VVtemp[47], VVtemp[48]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[43]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[45]);                          /*  STANDARD-DEVIATION */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[13], ECL_SYM("FUNCTION",398), VVtemp[49]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[13], ECL_SYM("INLINE",436), VVtemp[50]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LOCATION",1862), VVtemp[51], VVtemp[52]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[53]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[48]);                       /*  MAXF            */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[16], ECL_SYM("FUNCTION",398), VVtemp[54]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LOCATION",1862), VVtemp[55], VVtemp[56]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[53]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[50]);                       /*  MINF            */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[18], ECL_SYM("FUNCTION",398), VVtemp[57]) /*  SET-DOCUMENTATION */;
  si_Xmake_constant(VV[19], ecl_make_fixnum(8));
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[19], ECL_SYM("LOCATION",1862), VVtemp[58], VVtemp[59]) /*  ANNOTATE */;
  si_Xmake_constant(VV[20], ecl_make_fixnum(13));
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LOCATION",1862), VVtemp[60], VVtemp[61]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[21], ECL_SYM("LOCATION",1862), VVtemp[62], VVtemp[63]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[21], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[64]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[51]);                          /*  %MULTIPLY-RANGE */
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[65]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LOCATION",1862), VVtemp[66], VVtemp[67]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[68]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[52]);                          /*  %FACTORIAL      */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[26], ECL_SYM("LOCATION",1862), VVtemp[69], VVtemp[70]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[26], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[68]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[53]);                          /*  FACTORIAL       */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[26], ECL_SYM("FUNCTION",398), VVtemp[71]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[26], ECL_SYM("INLINE",436), VVtemp[72]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[28], ECL_SYM("LOCATION",1862), VVtemp[73], VVtemp[74]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[28], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[75]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[54]);                          /*  BINOMIAL-COEFFICIENT */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[28], ECL_SYM("FUNCTION",398), VVtemp[76]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[31], ECL_SYM("LOCATION",1862), VVtemp[77], VVtemp[78]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[31], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[68]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[55]);                          /*  SUBFACTORIAL    */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[31], ECL_SYM("FUNCTION",398), VVtemp[79]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[32], ECL_SYM("LOCATION",1862), VVtemp[80], VVtemp[81]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[32], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[82]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[56]);                          /*  COUNT-PERMUTATIONS */
  ecl_function_dispatch(cl_env_copy,VV[34])(3, VV[32], ECL_SYM("FUNCTION",398), VVtemp[83]) /*  SET-DOCUMENTATION */;
}
