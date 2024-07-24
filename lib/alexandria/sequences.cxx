/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/sequences.lisp                         */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/sequences.eclh"
/*      function definition for SEQUENCE-OF-LENGTH-P                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1sequence_of_length_p(cl_object v1sequence, cl_object v2length)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3;
   v3 = 0;
   if (!(ECL_FIXNUMP(v2length))) { goto L5; }
   v3 = ecl_fixnum(v2length);
   if (!((v3)<(2305843009213693950))) { goto L10; }
   T0 = ecl_make_bool((v3)>=(0));
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
         FEwrong_type_argument(VV[1],v2length);
  if (!(v1sequence==ECL_NIL)) { goto L12; }
  value0 = ecl_make_bool((ecl_to_fixnum(v2length))==0);
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  if (!(ECL_CONSP(v1sequence))) { goto L14; }
  {
   cl_object v3n;
   v3n = ecl_make_integer((ecl_to_fixnum(v2length))-1);
   if (ecl_minusp(v3n)) { goto L17; }
   {
    cl_object v4tail;
    v4tail = ecl_nthcdr(ecl_to_size(v3n),v1sequence);
    if (Null(v4tail)) { goto L21; }
    T0 = ecl_cdr(v4tail);
    value0 = ecl_make_bool(T0==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
L21:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L14:;
  if (!(ECL_VECTORP(v1sequence))) { goto L23; }
  {
   cl_fixnum v5;
   v5 = ecl_length(v1sequence);
   value0 = ecl_make_bool((ecl_to_fixnum(v2length))==(v5));
   cl_env_copy->nvalues = 1;
   return value0;
  }
L23:;
  if (ECL_CONSP(v1sequence)) { goto L27; }
  if (v1sequence==ECL_NIL) { goto L27; }
  if (!(ECL_VECTORP(v1sequence))) { goto L25; }
  goto L26;
L27:;
L26:;
  {
   cl_fixnum v6;
   v6 = ecl_length(v1sequence);
   value0 = ecl_make_bool((ecl_to_fixnum(v2length))==(v6));
   cl_env_copy->nvalues = 1;
   return value0;
  }
L25:;
  value0 = si_etypecase_error(v1sequence, VV[2]);
  return value0;
 }
}
/*      function definition for ROTATE-TAIL-TO-HEAD                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2rotate_tail_to_head(cl_object v1sequence, cl_object v2n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v2n)||ECL_BIGNUMP(v2n))) { goto L5; }
   v3 = v2n;
   T0 = ecl_make_bool(ecl_number_compare(v3,ecl_make_fixnum(1))>=0);
   goto L2;
L5:;
   T0 = ECL_NIL;
   goto L2;
  }
L2:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v2n);
  if (!(ECL_LISTP(v1sequence))) { goto L9; }
  {
   cl_object v3m;
   T0 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1sequence) /*  PROPER-LIST-LENGTH */;
   v3m = (ecl_floor2(v2n,T0),cl_env_copy->values[1]);
   T0 = ecl_cdr(v1sequence);
   if (!(T0==ECL_NIL)) { goto L12; }
   value0 = v1sequence;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   {
    cl_object v4tail;
    cl_object v5last;
    T0 = ecl_plus(v3m,ecl_make_fixnum(1));
    v4tail = cl_last(2, v1sequence, T0);
    v5last = ecl_cdr(v4tail);
    {
     cl_object v6;
     v6 = ECL_NIL;
     {
      cl_object v7;
      v7 = v4tail;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
     }
     (ECL_CONS_CDR(T0)=v6,T0);
    }
    value0 = ecl_nconc(v5last,v1sequence);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L9:;
  {
   cl_fixnum v6len;
   cl_object v7m;
   cl_object v8tail;
   v6len = ecl_length(v1sequence);
   v7m = (ecl_floor2(v2n,ecl_make_fixnum(v6len)),cl_env_copy->values[1]);
   T0 = ecl_minus(ecl_make_fixnum(v6len),v7m);
   v8tail = cl_subseq(2, v1sequence, T0);
   cl_replace(6, v1sequence, v1sequence, ECL_SYM("START1",1316), v7m, ECL_SYM("START2",1317), ecl_make_fixnum(0));
   cl_replace(2, v1sequence, v8tail);
   value0 = v1sequence;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ROTATE-HEAD-TO-TAIL                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3rotate_head_to_tail(cl_object v1sequence, cl_object v2n)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v2n)||ECL_BIGNUMP(v2n))) { goto L5; }
   v3 = v2n;
   T0 = ecl_make_bool(ecl_number_compare(v3,ecl_make_fixnum(1))>=0);
   goto L2;
L5:;
   T0 = ECL_NIL;
   goto L2;
  }
L2:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v2n);
  if (!(ECL_LISTP(v1sequence))) { goto L9; }
  {
   cl_object v3m;
   T0 = ecl_one_minus(v2n);
   T1 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1sequence) /*  PROPER-LIST-LENGTH */;
   v3m = (ecl_floor2(T0,T1),cl_env_copy->values[1]);
   T0 = ecl_cdr(v1sequence);
   if (!(T0==ECL_NIL)) { goto L12; }
   value0 = v1sequence;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   {
    cl_object v4headtail;
    cl_object v5tail;
    v4headtail = ecl_nthcdr(ecl_to_size(v3m),v1sequence);
    v5tail = ecl_cdr(v4headtail);
    {
     cl_object v6;
     v6 = ECL_NIL;
     {
      cl_object v7;
      v7 = v4headtail;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
     }
     (ECL_CONS_CDR(T0)=v6,T0);
    }
    value0 = ecl_nconc(v5tail,v1sequence);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L9:;
  {
   cl_fixnum v6len;
   cl_object v7m;
   cl_object v8head;
   v6len = ecl_length(v1sequence);
   v7m = (ecl_floor2(v2n,ecl_make_fixnum(v6len)),cl_env_copy->values[1]);
   v8head = cl_subseq(3, v1sequence, ecl_make_fixnum(0), v7m);
   cl_replace(6, v1sequence, v1sequence, ECL_SYM("START1",1316), ecl_make_fixnum(0), ECL_SYM("START2",1317), v7m);
   T0 = ecl_minus(ecl_make_fixnum(v6len),v7m);
   cl_replace(4, v1sequence, v8head, ECL_SYM("START1",1316), T0);
   value0 = v1sequence;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for ROTATE                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4rotate(cl_narg narg, cl_object v1sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2n;
  va_list args; va_start(args,v1sequence);
  {
   int i = 1;
   if (i >= narg) {
    v2n = ecl_make_fixnum(1);
   } else {
    i++;
    v2n = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_plusp(v2n))) { goto L2; }
  value0 = L2rotate_tail_to_head(v1sequence, v2n);
  return value0;
L2:;
  if (!(ecl_minusp(v2n))) { goto L4; }
  T0 = ecl_negate(v2n);
  value0 = L3rotate_head_to_tail(v1sequence, T0);
  return value0;
L4:;
  value0 = v1sequence;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for SHUFFLE                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5shuffle(cl_narg narg, cl_object v1sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2start;
  cl_object v3end;
  ecl_va_list args; ecl_va_start(args,v1sequence,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L5shufflekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2start = ecl_make_fixnum(0);
   } else {
    v2start = keyvars[0];
   }
   v3end = keyvars[1];
  }
  {
   bool v4;
   v4 = ECL_FIXNUMP(v2start);
   if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v2start);
  }
  value0 = ecl_make_bool(ECL_FIXNUMP(v3end));
  if ((value0)!=ECL_NIL) { goto L6; }
  T0 = ecl_make_bool(v3end==ECL_NIL);
  goto L4;
L6:;
  T0 = value0;
  goto L4;
L4:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[8],v3end);
  if (!(ECL_LISTP(v1sequence))) { goto L9; }
  {
   cl_object v4end;
   cl_object v5n;
   value0 = v3end;
   if ((value0)!=ECL_NIL) { goto L13; }
   v4end = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1sequence) /*  PROPER-LIST-LENGTH */;
   goto L11;
L13:;
   v4end = value0;
   goto L11;
L11:;
   v5n = ecl_minus(v4end,v2start);
   {
    cl_object v6tail;
    v6tail = ecl_nthcdr(ecl_to_fixnum(v2start),v1sequence);
    goto L19;
L18:;
    {
     cl_object v7;
     T0 = cl_random(1, v5n);
     v7 = ecl_nthcdr(ecl_to_size(T0),v6tail);
     {
      cl_object v8;
      v8 = ecl_car(v7);
      {
       cl_object v9;
       v9 = ecl_car(v6tail);
       {
        cl_object v10;
        v10 = v6tail;
        if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
        T0 = v10;
       }
       (ECL_CONS_CAR(T0)=v8,T0);
       {
        cl_object v10;
        v10 = v7;
        if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
        T0 = v10;
       }
       (ECL_CONS_CAR(T0)=v9,T0);
      }
     }
    }
    v5n = ecl_minus(v5n,ecl_make_fixnum(1));
    v6tail = ecl_cdr(v6tail);
L19:;
    if (ecl_zerop(v5n)) { goto L39; }
    goto L18;
L39:;
    goto L8;
   }
  }
L9:;
  if (!(ECL_VECTORP(v1sequence))) { goto L41; }
  {
   cl_object v7end;
   value0 = v3end;
   if ((value0)!=ECL_NIL) { goto L45; }
   v7end = ecl_make_fixnum(ecl_length(v1sequence));
   goto L43;
L45:;
   v7end = value0;
   goto L43;
L43:;
   {
    cl_object v8i;
    cl_object v9;
    v8i = v2start;
    {
     cl_object v10;
     v10 = v7end;
     T0 = cl_realp(v10);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v10);
     v9 = v10;
    }
L51:;
    if (!(ecl_number_compare(v8i,v9)>=0)) { goto L53; }
    goto L52;
L53:;
    {
     cl_object v10;
     T0 = ecl_minus(v7end,v8i);
     T1 = cl_random(1, T0);
     v10 = ecl_plus(v8i,T1);
     {
      cl_object v11;
      {
       cl_object v12;
       v12 = v1sequence;
       T0 = v12;
       {
        cl_fixnum v13;
        {
         cl_object v14;
         v14 = v10;
         if (ecl_unlikely((ecl_fixnum(v14))>=(v12)->vector.dim))
           FEwrong_index(ECL_NIL,v12,-1,ecl_make_fixnum(ecl_fixnum(v14)),(v12)->vector.dim);
         v13 = ecl_fixnum(v14);
        }
        v11 = ecl_aref_unsafe(T0,v13);
       }
      }
      {
       cl_object v12;
       {
        cl_object v13;
        v13 = v1sequence;
        T0 = v13;
        {
         cl_fixnum v14;
         {
          cl_object v15;
          v15 = v8i;
          if (ecl_unlikely((ecl_fixnum(v15))>=(v13)->vector.dim))
           FEwrong_index(ECL_NIL,v13,-1,ecl_make_fixnum(ecl_fixnum(v15)),(v13)->vector.dim);
          v14 = ecl_fixnum(v15);
         }
         v12 = ecl_aref_unsafe(T0,v14);
        }
       }
       {
        cl_object v13;
        v13 = v1sequence;
        T0 = v13;
        {
         cl_fixnum v14;
         {
          cl_object v15;
          v15 = v8i;
          if (ecl_unlikely((ecl_fixnum(v15))>=(v13)->vector.dim))
           FEwrong_index(ECL_NIL,v13,-1,ecl_make_fixnum(ecl_fixnum(v15)),(v13)->vector.dim);
          v14 = ecl_fixnum(v15);
         }
         ecl_aset_unsafe(T0,v14,v11);
        }
       }
       {
        cl_object v13;
        v13 = v1sequence;
        T0 = v13;
        {
         cl_fixnum v14;
         {
          cl_object v15;
          v15 = v10;
          if (ecl_unlikely((ecl_fixnum(v15))>=(v13)->vector.dim))
           FEwrong_index(ECL_NIL,v13,-1,ecl_make_fixnum(ecl_fixnum(v15)),(v13)->vector.dim);
          v14 = ecl_fixnum(v15);
         }
         ecl_aset_unsafe(T0,v14,v12);
        }
       }
      }
     }
    }
    v8i = ecl_one_plus(v8i);
    goto L51;
L52:;
    goto L8;
   }
  }
L41:;
  if (ECL_CONSP(v1sequence)) { goto L86; }
  if (v1sequence==ECL_NIL) { goto L86; }
  if (!(ECL_VECTORP(v1sequence))) { goto L84; }
  goto L85;
L86:;
L85:;
  {
   cl_object v10end;
   value0 = v3end;
   if ((value0)!=ECL_NIL) { goto L91; }
   v10end = ecl_make_fixnum(ecl_length(v1sequence));
   goto L89;
L91:;
   v10end = value0;
   goto L89;
L89:;
   {
    cl_object v11;
    cl_object v12i;
    v11 = ecl_minus(v10end,ecl_make_fixnum(1));
    {
     cl_object v13;
     v13 = v11;
     T0 = cl_realp(v13);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v13);
     v12i = v13;
    }
L97:;
    if (!(ecl_number_compare(v12i,v2start)<0)) { goto L99; }
    goto L98;
L99:;
    {
     cl_object v13;
     T0 = ecl_minus(v10end,v12i);
     T1 = cl_random(1, T0);
     v13 = ecl_plus(v12i,T1);
     {
      cl_object v14;
      v14 = ecl_elt(v1sequence,ecl_fixnum(v13));
      {
       cl_object v15;
       v15 = ecl_elt(v1sequence,ecl_fixnum(v12i));
       ecl_elt_set(v1sequence,ecl_to_size(v12i),v14);
       ecl_elt_set(v1sequence,ecl_to_size(v13),v15);
      }
     }
    }
    v12i = ecl_one_minus(v12i);
    goto L97;
L98:;
    goto L8;
   }
  }
L84:;
  si_etypecase_error(v1sequence, VV[9]);
L8:;
  value0 = v1sequence;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for RANDOM-ELT                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L6random_elt(cl_narg narg, cl_object v1sequence, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2start;
  cl_object v3end;
  ecl_va_list args; ecl_va_start(args,v1sequence,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L6random_eltkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2start = ecl_make_fixnum(0);
   } else {
    v2start = keyvars[0];
   }
   v3end = keyvars[1];
  }
  if (ecl_unlikely(!(ECL_LISTP(v1sequence) || ECL_VECTORP(v1sequence))))
           FEtype_error_sequence(v1sequence);
  {
   bool v4;
   v4 = ECL_FIXNUMP(v2start);
   if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v2start);
  }
  value0 = ecl_make_bool(ECL_FIXNUMP(v3end));
  if ((value0)!=ECL_NIL) { goto L7; }
  T0 = ecl_make_bool(v3end==ECL_NIL);
  goto L5;
L7:;
  T0 = value0;
  goto L5;
L5:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[8],v3end);
  {
   cl_object v4size;
   cl_object v5end2;
   if (!(ECL_LISTP(v1sequence))) { goto L10; }
   v4size = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1sequence) /*  PROPER-LIST-LENGTH */;
   goto L9;
L10:;
   v4size = ecl_make_fixnum(ecl_length(v1sequence));
L9:;
   value0 = v3end;
   if ((value0)!=ECL_NIL) { goto L14; }
   v5end2 = v4size;
   goto L12;
L14:;
   v5end2 = value0;
   goto L12;
L12:;
   if (!(ecl_zerop(v4size))) { goto L16; }
   value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v1sequence, ECL_SYM("EXPECTED-TYPE",1235), VV[11]);
   return value0;
L16:;
   if (!((0)<=(ecl_to_fixnum(v2start)))) { goto L21; }
   if (!(ecl_number_compare(v2start,v5end2)<0)) { goto L21; }
   if (ecl_number_compare(v5end2,v4size)<=0) { goto L18; }
   goto L19;
L21:;
   goto L19;
L19:;
   T0 = CONS(v2start,v3end);
   T1 = ecl_list1(v5end2);
   T2 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), T1);
   T3 = ecl_list1(v2start);
   T4 = cl_list(3, ECL_SYM("INTEGER",437), T3, v4size);
   T5 = cl_list(3, ECL_SYM("OR",614), ECL_SYM("NULL",605), T4);
   T6 = cl_list(3, ECL_SYM("CONS",251), T2, T5);
   T7 = cl_list(3, v2start, v3end, v4size);
   value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1217), T0, ECL_SYM("EXPECTED-TYPE",1235), T6, ECL_SYM("FORMAT-CONTROL",1243), VV[12], ECL_SYM("FORMAT-ARGUMENTS",1242), T7);
   return value0;
L18:;
   {
    cl_object v6index;
    T0 = ecl_minus(v5end2,v2start);
    T1 = cl_random(1, T0);
    v6index = ecl_plus(v2start,T1);
    value0 = ecl_elt(v1sequence,ecl_fixnum(v6index));
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      function definition for REMOVE/SWAPPED-ARGUMENTS              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7remove_swapped_arguments(cl_narg narg, cl_object v1sequence, cl_object v2item, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3keyword_arguments;
  ecl_va_list args; ecl_va_start(args,v2item,narg,2);
  v3keyword_arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("REMOVE",710)->symbol.gfdef);
  value0 = cl_apply(4, T0, v2item, v1sequence, v3keyword_arguments);
  return value0;
 }
}
/*      local function REMOVEF                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC9removef(cl_object v1, cl_object v2si__env)
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
   cl_object v5item;
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
    v5item = v6;
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
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC8__g62,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5item,v3);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L17; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, VV[13], v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[15],T5);
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
      T3 = cl_listX(4, VV[13], v11, v5item, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L36;
L37:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, VV[13], v11, T3);
L36:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[15],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G62                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC8__g62(cl_object v1si__v)
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
/*      function definition for DELETE/SWAPPED-ARGUMENTS              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L10delete_swapped_arguments(cl_narg narg, cl_object v1sequence, cl_object v2item, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3keyword_arguments;
  ecl_va_list args; ecl_va_start(args,v2item,narg,2);
  v3keyword_arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("DELETE",291)->symbol.gfdef);
  value0 = cl_apply(4, T0, v2item, v1sequence, v3keyword_arguments);
  return value0;
 }
}
/*      local function DELETEF                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12deletef(cl_object v1, cl_object v2si__env)
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
   cl_object v5item;
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
    v5item = v6;
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
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC11__g74,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5item,v3);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L17; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, VV[16], v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[15],T5);
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
      T3 = cl_listX(4, VV[16], v11, v5item, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L36;
L37:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, VV[16], v11, T3);
L36:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[15],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G74                                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11__g74(cl_object v1si__v)
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
/*      local function PROPER-SEQUENCE                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13proper_sequence(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = VV[19];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for EMPTYP                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L14emptyp(cl_object v1sequence)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1sequence))) { goto L1; }
  value0 = ecl_make_bool(v1sequence==ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (ECL_CONSP(v1sequence)) { goto L5; }
  if (v1sequence==ECL_NIL) { goto L5; }
  if (!(ECL_VECTORP(v1sequence))) { goto L3; }
  goto L4;
L5:;
L4:;
  {
   cl_fixnum v2;
   v2 = ecl_length(v1sequence);
   value0 = ecl_make_bool((v2)==0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  value0 = si_etypecase_error(v1sequence, VV[21]);
  return value0;
 }
}
/*      function definition for LENGTH=                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L15length_(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1sequences;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1sequences = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((ecl_cdr(v1sequences))!=ECL_NIL) { goto L1; }
  cl_error(1, VV[23]);
L1:;
  {
   cl_object v2first;
   cl_fixnum v3current;
   {
    cl_object v4;
    v4 = v1sequences;
    {
     cl_object v5;
     v5 = v4;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    }
    if (Null(v4)) { goto L9; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1sequences = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L9:;
    v2first = v4;
   }
   {
    cl_object v4;
    if (!(ECL_FIXNUMP(v2first)||ECL_BIGNUMP(v2first))) { goto L17; }
    v4 = v2first;
    goto L16;
L17:;
    v4 = ecl_make_fixnum(ecl_length(v2first));
L16:;
    {
     cl_fixnum v5;
     v5 = 0;
     if (!(ECL_FIXNUMP(v4))) { goto L23; }
     v5 = ecl_fixnum(v4);
     if (!((v5)<(2305843009213693950))) { goto L28; }
     T0 = ecl_make_bool((v5)>=(0));
     goto L20;
L28:;
     T0 = ECL_NIL;
     goto L20;
L23:;
     T0 = ECL_NIL;
     goto L20;
    }
L20:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[1],v4);
    v3current = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = v1sequences;
    goto L33;
L32:;
    {
     cl_object v5el;
     v5el = ecl_car(v4);
     if (!(ECL_FIXNUMP(v5el)||ECL_BIGNUMP(v5el))) { goto L38; }
     if (ecl_number_equalp(v5el,ecl_make_fixnum(v3current))) { goto L37; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L38:;
     if ((L1sequence_of_length_p(v5el, ecl_make_fixnum(v3current)))!=ECL_NIL) { goto L37; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L37:;
    }
    v4 = ecl_cdr(v4);
L33:;
    if (Null(v4)) { goto L44; }
    goto L32;
L44:;
   }
  }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LENGTH=                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC16length_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4length;
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
    v4length = v5;
   }
   {
    cl_fixnum v5;
    v5 = ecl_length(v3);
    if (!((v5)==0)) { goto L11; }
   }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   {
    cl_object v5optimizedp;
    v5optimizedp = ecl_make_bool(ECL_FIXNUMP(v4length)||ECL_BIGNUMP(v4length));
    {
     cl_object v6;
     cl_object v7;
     v6 = cl_gensym(1, VV[24]);
     v7 = cl_gensym(1, VV[25]);
     T0 = ecl_list1(v6);
     if ((v5optimizedp)!=ECL_NIL) { goto L17; }
     T2 = cl_list(2, v7, v4length);
     T1 = ecl_list1(T2);
     goto L16;
L17:;
     T1 = ECL_NIL;
L16:;
     T2 = CONS(T0,T1);
     if ((v5optimizedp)!=ECL_NIL) { goto L20; }
     T4 = cl_list(2, ECL_SYM("INTEGERP",440), v7);
     T5 = cl_list(2, ECL_SYM("LENGTH",476), v7);
     T6 = cl_list(3, ECL_SYM("SETF",750), v7, T5);
     T7 = cl_list(3, ECL_SYM("UNLESS",883), T4, T6);
     T3 = ecl_list1(T7);
     goto L19;
L20:;
     T3 = ECL_NIL;
L19:;
     {
      cl_object v8sequence;
      cl_object v9;
      v8sequence = ECL_NIL;
      {
       cl_object v10;
       v10 = v3;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ecl_list1(ECL_NIL);
       v11 = v10;
L29:;
       if (!(ecl_endp(v9))) { goto L31; }
       goto L30;
L31:;
       v8sequence = _ecl_car(v9);
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
        T5 = v12;
       }
       T6 = cl_list(3, ECL_SYM("SETF",750), v6, v8sequence);
       T7 = cl_list(2, ECL_SYM("INTEGERP",440), v6);
       if (Null(v5optimizedp)) { goto L45; }
       T8 = v4length;
       goto L44;
L45:;
       T8 = v7;
L44:;
       T9 = cl_list(3, ECL_SYM("=",74), v6, T8);
       if (Null(v5optimizedp)) { goto L48; }
       T10 = v4length;
       goto L47;
L48:;
       T10 = v7;
L47:;
       T11 = cl_list(3, VV[0], v6, T10);
       T12 = cl_list(4, ECL_SYM("IF",946), T7, T9, T11);
       T13 = cl_list(3, ECL_SYM("PROGN",671), T6, T12);
       v11 = ecl_list1(T13);
       (ECL_CONS_CDR(T5)=v11,T5);
       goto L29;
L30:;
       T4 = ecl_cdr(v10);
       goto L22;
      }
     }
L22:;
     T5 = CONS(ECL_SYM("AND",87),T4);
     T6 = ecl_list1(T5);
     T7 = ecl_append(T3,T6);
     T8 = cl_listX(3, ECL_SYM("LET",477), T2, T7);
     value0 = cl_list(3, ECL_SYM("LOCALLY",490), VV[26], T8);
     return value0;
    }
   }
  }
 }
}
/*      function definition for COPY-SEQUENCE                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L17copy_sequence(cl_object v1type, cl_object v2sequence)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_typep(2, v2sequence, v1type))) { goto L1; }
  value0 = ecl_copy_seq(v2sequence);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = cl_coerce(v2sequence, v1type);
  return value0;
 }
}
/*      function definition for FIRST-ELT                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L18first_elt(cl_object v1sequence)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1sequence))) { goto L1; }
  value0 = ecl_car(v1sequence);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_VECTORP(v1sequence))) { goto L3; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1sequence);
   if (!((v2)>0)) { goto L3; }
  }
  value0 = ecl_elt(v1sequence,0);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v1sequence, ECL_SYM("EXPECTED-TYPE",1235), VV[11]);
  return value0;
 }
}
/*      function definition for (SETF FIRST-ELT)                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L19_setf_first_elt_(cl_object v1object, cl_object v2sequence)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v2sequence))) { goto L1; }
  {
   cl_object v3;
   v3 = v1object;
   {
    cl_object v4;
    v4 = v2sequence;
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T0 = v4;
   }
   (ECL_CONS_CAR(T0)=v3,T0);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_VECTORP(v2sequence))) { goto L8; }
  {
   cl_fixnum v4;
   v4 = ecl_length(v2sequence);
   if (!((v4)>0)) { goto L8; }
  }
  value0 = ecl_elt_set(v2sequence,0,v1object);
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v2sequence, ECL_SYM("EXPECTED-TYPE",1235), VV[11]);
  return value0;
 }
}
/*      function definition for LAST-ELT                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L20last_elt(cl_object v1sequence)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2len;
   v2len = ecl_make_fixnum(0);
   if (!(ECL_CONSP(v1sequence))) { goto L2; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[65])(1, v1sequence) /*  LASTCAR */;
   return value0;
L2:;
   if (!(ECL_VECTORP(v1sequence))) { goto L4; }
   v2len = ecl_make_fixnum(ecl_length(v1sequence));
   if (!((ecl_to_fixnum(v2len))>0)) { goto L4; }
   T0 = ecl_one_minus(v2len);
   value0 = ecl_elt(v1sequence,ecl_fixnum(T0));
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v1sequence, ECL_SYM("EXPECTED-TYPE",1235), VV[31]);
   return value0;
  }
 }
}
/*      function definition for (SETF LAST-ELT)                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L21_setf_last_elt_(cl_object v1object, cl_object v2sequence)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3len;
   v3len = ecl_make_fixnum(0);
   if (!(ECL_CONSP(v2sequence))) { goto L2; }
   value0 = (cl_env_copy->function=ecl_fdefinition(VV[67]))->cfun.entry(2, v1object, v2sequence) /*  (SETF LASTCAR) */;
   return value0;
L2:;
   if (!(ECL_VECTORP(v2sequence))) { goto L4; }
   v3len = ecl_make_fixnum(ecl_length(v2sequence));
   if (!((ecl_to_fixnum(v3len))>0)) { goto L4; }
   T0 = ecl_one_minus(v3len);
   value0 = ecl_elt_set(v2sequence,ecl_to_size(T0),v1object);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1217), v2sequence, ECL_SYM("EXPECTED-TYPE",1235), VV[31]);
   return value0;
  }
 }
}
/*      function definition for STARTS-WITH-SUBSEQ                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L22starts_with_subseq(cl_narg narg, cl_object v1prefix, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  cl_object v4return_suffix;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L22starts_with_subseqkeys,keyvars,(cl_object*)&v3args,TRUE);
   ecl_va_end(args);
   v4return_suffix = keyvars[0];
  }
  v3args = ecl_function_dispatch(cl_env_copy,VV[69])(2, v3args, VV[34]) /*  REMOVE-FROM-PLIST */;
  {
   cl_fixnum v5;
   cl_fixnum v6;
   v5 = ecl_length(v2sequence);
   v6 = ecl_length(v1prefix);
   if (!((v6)<=(v5))) { goto L5; }
   {
    cl_object v7mismatch;
    T0 = (ECL_SYM("MISMATCH",559)->symbol.gfdef);
    v7mismatch = cl_apply(4, T0, v1prefix, v2sequence, v3args);
    if (Null(v7mismatch)) { goto L9; }
    if (!(ecl_number_compare(v7mismatch,ecl_make_fixnum(v6))<0)) { goto L11; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    return cl_env_copy->values[0];
L11:;
    if (Null(v4return_suffix)) { goto L14; }
    T1 = cl_array_element_type(v2sequence);
    T2 = ecl_minus(ecl_make_fixnum(v5),v7mismatch);
    T0 = si_make_pure_array(T1, T2, ECL_NIL, ECL_NIL, v2sequence, ecl_make_fixnum(v6));
    goto L13;
L14:;
    T0 = ECL_NIL;
L13:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = ECL_T;
    return cl_env_copy->values[0];
L9:;
    if (Null(v4return_suffix)) { goto L17; }
    T1 = cl_array_element_type(v2sequence);
    T0 = si_make_vector(T1, ecl_make_fixnum(0), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
    goto L16;
L17:;
    T0 = ECL_NIL;
L16:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = ECL_T;
    return cl_env_copy->values[0];
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*      function definition for ENDS-WITH-SUBSEQ                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L23ends_with_subseq(cl_narg narg, cl_object v1suffix, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L23ends_with_subseqkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v3test = (ECL_SYM("EQL",334)->symbol.gfdef);
   } else {
    v3test = keyvars[0];
   }
  }
  {
   cl_fixnum v4;
   cl_fixnum v5;
   v4 = ecl_length(v2sequence);
   v5 = ecl_length(v1suffix);
   if (!((v4)<(v5))) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v6;
    cl_object v7sequence_index;
    cl_object v8;
    v6 = ecl_minus(ecl_make_fixnum(v4),ecl_make_fixnum(v5));
    {
     cl_object v9;
     v9 = v6;
     T0 = cl_realp(v9);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v9);
     v7sequence_index = v9;
    }
    v8 = ecl_make_fixnum(v4);
    {
     cl_object v9suffix_index;
     cl_object v10;
     v9suffix_index = ecl_make_fixnum(0);
     v10 = ecl_make_fixnum(v5);
     if (!(ecl_number_compare(v7sequence_index,v8)>=0)) { goto L15; }
     goto L14;
L15:;
L13:;
     if (!(ecl_number_compare(v9suffix_index,v10)>=0)) { goto L17; }
     goto L14;
L17:;
     T0 = ecl_elt(v2sequence,ecl_fixnum(v7sequence_index));
     T1 = ecl_elt(v1suffix,ecl_fixnum(v9suffix_index));
     if ((ecl_function_dispatch(cl_env_copy,v3test)(2, T0, T1))!=ECL_NIL) { goto L19; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L19:;
     v7sequence_index = ecl_one_plus(v7sequence_index);
     if (!(ecl_number_compare(v7sequence_index,v8)>=0)) { goto L23; }
     goto L14;
L23:;
     v9suffix_index = ecl_one_plus(v9suffix_index);
     goto L13;
L14:;
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      function definition for STARTS-WITH                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L24starts_with(cl_narg narg, cl_object v1object, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L24starts_withkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3test = (ECL_SYM("EQL",334)->symbol.gfdef);
   } else {
    v3test = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v4key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   } else {
    v4key = keyvars[1];
   }
  }
  if (!(ECL_CONSP(v2sequence))) { goto L5; }
  T1 = ecl_car(v2sequence);
  goto L4;
L5:;
  if (ECL_CONSP(v2sequence)) { goto L9; }
  if (v2sequence==ECL_NIL) { goto L9; }
  if (!(ECL_VECTORP(v2sequence))) { goto L7; }
  goto L8;
L9:;
L8:;
  {
   cl_fixnum v5;
   v5 = ecl_length(v2sequence);
   if (!((v5)>0)) { goto L12; }
  }
  T1 = ecl_elt(v2sequence,0);
  goto L4;
L12:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  T0 = ecl_function_dispatch(cl_env_copy,v4key)(1, T1);
  value0 = ecl_function_dispatch(cl_env_copy,v3test)(2, T0, v1object);
  return value0;
 }
}
/*      function definition for ENDS-WITH                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L25ends_with(cl_narg narg, cl_object v1object, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L25ends_withkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3test = (ECL_SYM("EQL",334)->symbol.gfdef);
   } else {
    v3test = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v4key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   } else {
    v4key = keyvars[1];
   }
  }
  if (!(ECL_CONSP(v2sequence))) { goto L5; }
  T1 = ecl_function_dispatch(cl_env_copy,VV[65])(1, v2sequence) /*  LASTCAR */;
  goto L4;
L5:;
  if (ECL_CONSP(v2sequence)) { goto L9; }
  if (v2sequence==ECL_NIL) { goto L9; }
  if (!(ECL_VECTORP(v2sequence))) { goto L7; }
  goto L8;
L9:;
L8:;
  {
   cl_fixnum v5len;
   v5len = ecl_length(v2sequence);
   if (!((v5len)>0)) { goto L13; }
   T2 = ecl_make_integer((v5len)-1);
   T1 = ecl_elt(v2sequence,ecl_fixnum(T2));
   goto L4;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L7:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  T0 = ecl_function_dispatch(cl_env_copy,v4key)(1, T1);
  value0 = ecl_function_dispatch(cl_env_copy,v3test)(2, T0, v1object);
  return value0;
 }
}
/*      function definition for MAP-COMBINATIONS                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L30map_combinations(cl_narg narg, cl_object v1function, cl_object v2sequence, ...)
{
 cl_object T0;
 volatile cl_object lex0[5];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5length;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  lex0[0] = v2sequence;                           /*  SEQUENCE        */
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L30map_combinationskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[4])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5length = keyvars[2];
   if (Null(keyvars[7])) {
    lex0[1] = ECL_T;                              /*  COPY            */
   } else {
    lex0[1] = keyvars[3];                         /*  COPY            */
   }
  }
  {
   cl_object v6size;
   cl_object v7length;
   value0 = v4end;
   if ((value0)!=ECL_NIL) { goto L5; }
   T0 = ecl_make_fixnum(ecl_length(lex0[0]));
   goto L3;
L5:;
   T0 = value0;
   goto L3;
L3:;
   lex0[2] = T0;                                  /*  END             */
   v6size = ecl_minus(lex0[2],v3start);
   value0 = v5length;
   if ((value0)!=ECL_NIL) { goto L10; }
   v7length = v6size;
   goto L8;
L10:;
   v7length = value0;
   goto L8;
L8:;
   T0 = cl_subseq(3, lex0[0], ecl_make_fixnum(0), v7length);
   lex0[3] = T0;                                  /*  COMBINATION     */
   T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v1function) /*  ENSURE-FUNCTION */;
   lex0[4] = T0;                                  /*  FUNCTION        */
   if (!(ecl_number_equalp(v7length,v6size))) { goto L12; }
   ecl_function_dispatch(cl_env_copy,lex0[4])(1, lex0[3]);
   goto L2;
L12:;
   if (!(ECL_LISTP(lex0[0]))) { goto L14; }
   T0 = ecl_nthcdr(ecl_to_size(v3start),lex0[0]);
   LC27combine_list(lex0, lex0[3], T0);
   goto L2;
L14:;
   if (!(ECL_VECTORP(lex0[0]))) { goto L16; }
   LC28combine(lex0, v7length, v3start);
   goto L2;
L16:;
   if (ECL_CONSP(lex0[0])) { goto L20; }
   if (lex0[0]==ECL_NIL) { goto L20; }
   if (!(ECL_VECTORP(lex0[0]))) { goto L18; }
   goto L19;
L20:;
L19:;
   LC29combine(lex0, v7length, v3start);
   goto L2;
L18:;
   si_etypecase_error(lex0[0], VV[9]);
  }
L2:;
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function CALL                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC26call(volatile cl_object *lex0)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(lex0[1])) { goto L2; }
  T0 = ecl_copy_seq(lex0[3]);
  goto L1;
L2:;
  T0 = lex0[3];
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,lex0[4])(1, T0);
  return value0;
 }
}
/*      local function COMBINE-LIST                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC27combine_list(volatile cl_object *lex0, cl_object v1c_tail, cl_object v2o_tail)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1c_tail)!=ECL_NIL) { goto L1; }
  value0 = LC26call(lex0);
  return value0;
L1:;
  {
   cl_object v3tail;
   v3tail = v2o_tail;
   goto L6;
L5:;
   {
    cl_object v4;
    v4 = ecl_car(v3tail);
    {
     cl_object v5;
     v5 = v1c_tail;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     T0 = v5;
    }
    (ECL_CONS_CAR(T0)=v4,T0);
   }
   T0 = ecl_cdr(v1c_tail);
   T1 = ecl_cdr(v3tail);
   LC27combine_list(lex0, T0, T1);
   v3tail = ecl_cdr(v3tail);
L6:;
   if (Null(v3tail)) { goto L17; }
   goto L5;
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function COMBINE                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC28combine(volatile cl_object *lex0, cl_object v1count, cl_object v2start)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v1count))) { goto L1; }
  value0 = LC26call(lex0);
  return value0;
L1:;
  {
   cl_object v3i;
   cl_object v4;
   {
    cl_object v5;
    v5 = v2start;
    T0 = cl_realp(v5);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v5);
    v3i = v5;
   }
   {
    cl_object v5;
    v5 = lex0[2];
    T0 = cl_realp(v5);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v5);
    v4 = v5;
   }
L9:;
   if (!(ecl_number_compare(v3i,v4)>=0)) { goto L11; }
   goto L10;
L11:;
   {
    cl_object v5j;
    v5j = ecl_minus(v1count,ecl_make_fixnum(1));
    {
     cl_object v6;
     v6 = lex0[3];
     T0 = v6;
     {
      cl_fixnum v7;
      {
       cl_object v8;
       v8 = v5j;
       if (ecl_unlikely((ecl_fixnum(v8))>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(ecl_fixnum(v8)),(v6)->vector.dim);
       v7 = ecl_fixnum(v8);
      }
      T1 = ecl_aref_unsafe(lex0[0],ecl_fixnum(v3i));
      ecl_aset_unsafe(T0,v7,T1);
     }
    }
    T0 = ecl_plus(v3i,ecl_make_fixnum(1));
    LC28combine(lex0, v5j, T0);
   }
   v3i = ecl_one_plus(v3i);
   goto L9;
L10:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function COMBINE                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC29combine(volatile cl_object *lex0, cl_object v1count, cl_object v2start)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v1count))) { goto L1; }
  value0 = LC26call(lex0);
  return value0;
L1:;
  {
   cl_object v3i;
   cl_object v4;
   {
    cl_object v5;
    v5 = v2start;
    T0 = cl_realp(v5);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v5);
    v3i = v5;
   }
   {
    cl_object v5;
    v5 = lex0[2];
    T0 = cl_realp(v5);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v5);
    v4 = v5;
   }
L9:;
   if (!(ecl_number_compare(v3i,v4)>=0)) { goto L11; }
   goto L10;
L11:;
   {
    cl_object v5j;
    v5j = ecl_minus(v1count,ecl_make_fixnum(1));
    T0 = ecl_elt(lex0[0],ecl_fixnum(v3i));
    ecl_elt_set(lex0[3],ecl_to_size(v5j),T0);
    T0 = ecl_plus(v3i,ecl_make_fixnum(1));
    LC29combine(lex0, v5j, T0);
   }
   v3i = ecl_one_plus(v3i);
   goto L9;
L10:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MAP-PERMUTATIONS                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L34map_permutations(cl_narg narg, cl_object v1function, cl_object v2sequence, ...)
{
 cl_object T0;
 cl_object env0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5length;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1function,env0);            /*  FUNCTION        */
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L34map_permutationskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[4])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5length = keyvars[2];
   if (Null(keyvars[7])) {
    CLV1 = env0 = CONS(ECL_T,env0);               /*  COPY            */
   } else {
    CLV1 = env0 = CONS(keyvars[3],env0);          /*  COPY            */
   }
  }
  {
   cl_object v6end;
   cl_object v7size;
   cl_object env1 = env0;
   value0 = v4end;
   if ((value0)!=ECL_NIL) { goto L4; }
   v6end = ecl_make_fixnum(ecl_length(v2sequence));
   goto L2;
L4:;
   v6end = value0;
   goto L2;
L2:;
   v7size = ecl_minus(v6end,v3start);
   value0 = v5length;
   if ((value0)!=ECL_NIL) { goto L9; }
   T0 = v7size;
   goto L7;
L9:;
   T0 = value0;
   goto L7;
L7:;
   CLV2 = env1 = CONS(T0,env1);                   /*  LENGTH          */
   if (!(ecl_number_equalp(ECL_CONS_CAR(CLV2),v7size))) { goto L11; }
   T0 = cl_subseq(3, v2sequence, v3start, v6end);
   value0 = (aux_closure.env=env1,cl_env_copy->function=(cl_object)&aux_closure,LC32permute_sequence(1, T0));
   return value0;
L11:;
   {
    cl_object env2 = env1;
    T0 = cl_subseq(3, v2sequence, ecl_make_fixnum(0), ECL_CONS_CAR(CLV2));
    CLV3 = env2 = CONS(T0,env2);                  /*  PERMUTATION     */
    {
     cl_object v8;
     v8 = ecl_make_cclosure_va((cl_objectfn)LC33permute_combination,env2,Cblock);
     value0 = L30map_combinations(10, v8, v2sequence, ECL_SYM("START",1315), v3start, ECL_SYM("END",1228), v6end, ECL_SYM("LENGTH",1268), ECL_CONS_CAR(CLV2), VV[40], ECL_NIL);
     return value0;
    }
   }
  }
 }
}
/*      closure PERMUTE-SEQUENCE                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC32permute_sequence(cl_narg narg, cl_object v1seq, ...)
{
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  LENGTH          */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC31permute(2, v1seq, ECL_CONS_CAR(CLV2)));
  return value0;
 }
 }
}
/*      closure PERMUTE                                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC31permute(cl_narg narg, cl_object v1seq, cl_object v2n, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;
 CLV1 = _ecl_cdr(CLV2);                           /*  COPY            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3n_1;
   v3n_1 = ecl_minus(v2n,ecl_make_fixnum(1));
   if (!(ecl_zerop(v3n_1))) { goto L2; }
   if (Null(ECL_CONS_CAR(CLV1))) { goto L5; }
   T0 = ecl_copy_seq(v1seq);
   goto L4;
L5:;
   T0 = v1seq;
L4:;
   value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, T0);
   return value0;
L2:;
   {
    cl_object v4i;
    cl_object v5;
    v4i = ecl_make_fixnum(0);
    {
     cl_object v6;
     v6 = v3n_1;
     T0 = cl_realp(v6);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v6);
     v5 = v6;
    }
L11:;
    if (!(ecl_number_compare(v4i,v5)>0)) { goto L13; }
    goto L12;
L13:;
    (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC31permute(2, v1seq, v3n_1));
    if (!(ecl_evenp(v3n_1))) { goto L17; }
    {
     cl_object v6;
     v6 = ecl_elt(v1seq,ecl_fixnum(v3n_1));
     {
      cl_object v7;
      v7 = ecl_elt(v1seq,0);
      ecl_elt_set(v1seq,0,v6);
      ecl_elt_set(v1seq,ecl_to_size(v3n_1),v7);
     }
    }
    goto L15;
L17:;
    {
     cl_object v6;
     v6 = ecl_elt(v1seq,ecl_fixnum(v3n_1));
     {
      cl_object v7;
      v7 = ecl_elt(v1seq,ecl_fixnum(v4i));
      ecl_elt_set(v1seq,ecl_to_size(v4i),v6);
      ecl_elt_set(v1seq,ecl_to_size(v3n_1),v7);
     }
    }
L15:;
    v4i = ecl_one_plus(v4i);
    goto L11;
L12:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
 }
}
/*      closure PERMUTE-COMBINATION                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC33permute_combination(cl_narg narg, cl_object v1combination, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2, CLV3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  PERMUTATION     */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_replace(2, ECL_CONS_CAR(CLV3), v1combination);
  value0 = (aux_closure.env=ecl_nthcdr(1,env0),cl_env_copy->function=(cl_object)&aux_closure,LC32permute_sequence(1, T0));
  return value0;
 }
 }
}
/*      function definition for MAP-DERANGEMENTS                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L36map_derangements(cl_narg narg, cl_object v1function, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 volatile cl_object lex0[7];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3end;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  lex0[0] = v1function;                           /*  FUNCTION        */
  lex0[1] = v2sequence;                           /*  SEQUENCE        */
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L36map_derangementskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    lex0[2] = ecl_make_fixnum(0);                 /*  START           */
   } else {
    lex0[2] = keyvars[0];                         /*  START           */
   }
   v3end = keyvars[1];
   if (Null(keyvars[5])) {
    lex0[3] = ECL_T;                              /*  COPY            */
   } else {
    lex0[3] = keyvars[2];                         /*  COPY            */
   }
  }
  {
   cl_object v4end;
   value0 = v3end;
   if ((value0)!=ECL_NIL) { goto L3; }
   v4end = ecl_make_fixnum(ecl_length(lex0[1]));
   goto L1;
L3:;
   v4end = value0;
   goto L1;
L1:;
   T0 = ecl_minus(v4end,lex0[2]);
   lex0[4] = T0;                                  /*  SIZE            */
   T0 = cl_subseq(3, lex0[1], ecl_make_fixnum(0), lex0[4]);
   lex0[5] = T0;                                  /*  DERANGEMENT     */
   T0 = si_make_pure_array(ECL_SYM("BIT",123), lex0[4], ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   T1 = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
   lex0[6] = T1;                                  /*  MASK            */
   LC35derange(lex0, lex0[2], lex0[4]);
   value0 = lex0[1];
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function DERANGE                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC35derange(volatile cl_object *lex0, cl_object v1place, cl_object v2n)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v2n))) { goto L1; }
  if (Null(lex0[3])) { goto L4; }
  T0 = ecl_copy_seq(lex0[5]);
  goto L3;
L4:;
  T0 = lex0[5];
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,lex0[0])(1, T0);
  return value0;
L1:;
  {
   cl_object v3i;
   cl_object v4;
   v3i = ecl_make_fixnum(0);
   {
    cl_object v5;
    v5 = lex0[4];
    T0 = cl_realp(v5);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v5);
    v4 = v5;
   }
L10:;
   if (!(ecl_number_compare(v3i,v4)>=0)) { goto L12; }
   goto L11;
L12:;
   T0 = ecl_plus(v3i,lex0[2]);
   if (ecl_number_equalp(v1place,T0)) { goto L14; }
   T0 = cl_bit(2, lex0[6], v3i);
   if (!((ecl_to_fixnum(T0))==0)) { goto L14; }
   T0 = ecl_elt(lex0[1],ecl_fixnum(v1place));
   ecl_elt_set(lex0[5],ecl_to_size(v3i),T0);
   {
    cl_object v5;
    v5 = lex0[6];
    T0 = v5;
    {
     cl_fixnum v6;
     {
      cl_object v7;
      v7 = v3i;
      if (ecl_unlikely((ecl_fixnum(v7))>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(ecl_fixnum(v7)),(v5)->vector.dim);
      v6 = ecl_fixnum(v7);
     }
     ecl_aset_unsafe(T0,v6,ecl_make_fixnum(1));
    }
   }
   T0 = ecl_one_plus(v1place);
   T1 = ecl_one_minus(v2n);
   LC35derange(lex0, T0, T1);
   {
    cl_object v5;
    v5 = lex0[6];
    T0 = v5;
    {
     cl_fixnum v6;
     {
      cl_object v7;
      v7 = v3i;
      if (ecl_unlikely((ecl_fixnum(v7))>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(ecl_fixnum(v7)),(v5)->vector.dim);
      v6 = ecl_fixnum(v7);
     }
     ecl_aset_unsafe(T0,v6,ecl_make_fixnum(0));
    }
   }
L14:;
   v3i = ecl_one_plus(v3i);
   goto L10;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function G181                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC38__g181()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g182,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function G182                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC37__g182(cl_object v1condition, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, v2stream, VV[43], VV[44]);
  return value0;
 }
}
/*      function definition for EXTREMUM                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L41extremum(cl_narg narg, cl_object v1sequence, cl_object v2predicate, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  cl_object v4start;
  cl_object v5end;
  ecl_va_list args; ecl_va_start(args,v2predicate,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L41extremumkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
   if (Null(keyvars[4])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
  }
  {
   cl_object v6real_end;
   cl_object env1 = env0;
   T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v2predicate) /*  ENSURE-FUNCTION */;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  PRED-FUN        */
   if (Null(v3key)) { goto L3; }
   if ((v3key)==(ECL_SYM("IDENTITY",426))) { goto L3; }
   T1 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   if ((v3key)==(T1)) { goto L3; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v3key) /*  ENSURE-FUNCTION */;
   goto L2;
L3:;
   T0 = ECL_NIL;
L2:;
   CLV1 = env1 = CONS(T0,env1);                   /*  KEY-FUN         */
   value0 = v5end;
   if ((value0)!=ECL_NIL) { goto L10; }
   v6real_end = ecl_make_fixnum(ecl_length(v1sequence));
   goto L8;
L10:;
   v6real_end = value0;
   goto L8;
L8:;
   if (!(ecl_number_compare(v6real_end,v4start)>0)) { goto L12; }
   if (Null(ECL_CONS_CAR(CLV1))) { goto L14; }
   {
    cl_object v7;
    v7 = ecl_make_cclosure_va((cl_objectfn)LC39reduce_keys,env1,Cblock);
    value0 = cl_reduce(6, v7, v1sequence, ECL_SYM("START",1315), v4start, ECL_SYM("END",1228), v6real_end);
    return value0;
   }
L14:;
   {
    cl_object v8;
    v8 = ecl_make_cclosure_va((cl_objectfn)LC40reduce_elts,env1,Cblock);
    value0 = cl_reduce(6, v8, v1sequence, ECL_SYM("START",1315), v4start, ECL_SYM("END",1228), v6real_end);
    return value0;
   }
L12:;
   if (!(ecl_number_equalp(v6real_end,v4start))) { goto L16; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   {
    cl_fixnum v9;
    v9 = ecl_length(v1sequence);
    value0 = cl_error(6, VV[45], ecl_make_fixnum(v9), ECL_SYM("START",1315), v4start, ECL_SYM("END",1228), v5end);
    return value0;
   }
  }
 }
}
/*      closure REDUCE-KEYS                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC39reduce_keys(cl_narg narg, cl_object v1a, cl_object v2b, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  KEY-FUN         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV1))(1, v1a);
  T1 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV1))(1, v2b);
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, T0, T1))) { goto L1; }
  value0 = v1a;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v2b;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      closure REDUCE-ELTS                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC40reduce_elts(cl_narg narg, cl_object v1a, cl_object v2b, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);                           /*  PRED-FUN        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, v1a, v2b))) { goto L1; }
  value0 = v1a;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v2b;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}

#include "lib/alexandria/sequences.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4y48pVyvO59HM_R0i2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/sequences.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecl4y48pVyvO59HM_R0i2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[46]);                          /*  SEQUENCE-OF-LENGTH-P */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[5]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[6], VVtemp[7]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[8]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[47]);                          /*  ROTATE-TAIL-TO-HEAD */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LOCATION",1777), VVtemp[9], VVtemp[10]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[8]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[49]);                          /*  ROTATE-HEAD-TO-TAIL */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[11], VVtemp[12]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[13]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[50]);                          /*  ROTATE          */
  si_set_documentation(3, VV[6], ECL_SYM("FUNCTION",396), VVtemp[14]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LOCATION",1777), VVtemp[15], VVtemp[16]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[17]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[51]);                          /*  SHUFFLE         */
  si_set_documentation(3, VV[7], ECL_SYM("FUNCTION",396), VVtemp[18]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[10], ECL_SYM("LOCATION",1777), VVtemp[19], VVtemp[20]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[10], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[17]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[54]);                          /*  RANDOM-ELT      */
  si_set_documentation(3, VV[10], ECL_SYM("FUNCTION",396), VVtemp[21]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[22]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LOCATION",1777), VVtemp[23], VVtemp[24]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[13], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[55]);                          /*  REMOVE/SWAPPED-ARGUMENTS */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[14], ECL_SYM("LOCATION",1777), VVtemp[26], VVtemp[27]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[14], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[28]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[56]);                       /*  REMOVEF         */
  si_set_documentation(3, VV[14], ECL_SYM("FUNCTION",396), VVtemp[29]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[30]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[16], ECL_SYM("LOCATION",1777), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[16], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[57]);                          /*  DELETE/SWAPPED-ARGUMENTS */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[17], ECL_SYM("LOCATION",1777), VVtemp[33], VVtemp[34]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[17], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[28]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[58]);                       /*  DELETEF         */
  si_set_documentation(3, VV[17], ECL_SYM("FUNCTION",396), VVtemp[35]);
 {
  cl_object T0;
  si_set_documentation(3, VV[18], ECL_SYM("TYPE",869), VVtemp[36]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC13proper_sequence,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[18], VVtemp[37], T0);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[20], ECL_SYM("LOCATION",1777), VVtemp[38], VVtemp[39]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[20], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[59]);                          /*  EMPTYP          */
  si_set_documentation(3, VV[20], ECL_SYM("FUNCTION",396), VVtemp[41]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LOCATION",1777), VVtemp[42], VVtemp[43]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[44]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[60]);                          /*  LENGTH=         */
  si_set_documentation(3, VV[22], ECL_SYM("FUNCTION",396), VVtemp[45]);
 {
  cl_object T0;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC16length_,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[22], ECL_SYM("COMPILER-MACRO",238), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[22], ECL_SYM("LOCATION",1777), VVtemp[46], VVtemp[47]) /*  ANNOTATE */;
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LOCATION",1777), VVtemp[48], VVtemp[49]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[27], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[50]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[61]);                          /*  COPY-SEQUENCE   */
  si_set_documentation(3, VV[27], ECL_SYM("FUNCTION",396), VVtemp[51]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[28], ECL_SYM("LOCATION",1777), VVtemp[52], VVtemp[53]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[28], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[62]);                          /*  FIRST-ELT       */
  si_set_documentation(3, VV[28], ECL_SYM("FUNCTION",396), VVtemp[54]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[55], ECL_SYM("LOCATION",1777), VVtemp[56], VVtemp[57]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[55], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[58]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[63]);                          /*  (SETF FIRST-ELT) */
  si_set_documentation(3, VV[29], ECL_SYM("FUNCTION",396), VVtemp[59]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[30], ECL_SYM("LOCATION",1777), VVtemp[60], VVtemp[61]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[30], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[64]);                          /*  LAST-ELT        */
  si_set_documentation(3, VV[30], ECL_SYM("FUNCTION",396), VVtemp[62]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[63], ECL_SYM("LOCATION",1777), VVtemp[64], VVtemp[65]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VVtemp[63], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[58]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[66]);                          /*  (SETF LAST-ELT) */
  si_set_documentation(3, VV[32], ECL_SYM("FUNCTION",396), VVtemp[66]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[33], ECL_SYM("LOCATION",1777), VVtemp[67], VVtemp[68]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[33], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[69]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[68]);                          /*  STARTS-WITH-SUBSEQ */
  si_set_documentation(3, VV[33], ECL_SYM("FUNCTION",396), VVtemp[70]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LOCATION",1777), VVtemp[71], VVtemp[72]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[35], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[73]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[70]);                          /*  ENDS-WITH-SUBSEQ */
  si_set_documentation(3, VV[35], ECL_SYM("FUNCTION",396), VVtemp[74]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[36], ECL_SYM("LOCATION",1777), VVtemp[75], VVtemp[76]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[36], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[77]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[72]);                          /*  STARTS-WITH     */
  si_set_documentation(3, VV[36], ECL_SYM("FUNCTION",396), VVtemp[78]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[37], ECL_SYM("LOCATION",1777), VVtemp[79], VVtemp[80]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[37], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[77]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[75]);                          /*  ENDS-WITH       */
  si_set_documentation(3, VV[37], ECL_SYM("FUNCTION",396), VVtemp[81]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[38], ECL_SYM("LOCATION",1777), VVtemp[82], VVtemp[83]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[38], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[84]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[76]);                          /*  MAP-COMBINATIONS */
  si_set_documentation(3, VV[38], ECL_SYM("FUNCTION",396), VVtemp[85]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LOCATION",1777), VVtemp[86], VVtemp[87]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[39], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[84]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[82]);                          /*  MAP-PERMUTATIONS */
  si_set_documentation(3, VV[39], ECL_SYM("FUNCTION",396), VVtemp[88]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LOCATION",1777), VVtemp[89], VVtemp[90]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[91]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[83]);                          /*  MAP-DERANGEMENTS */
  si_set_documentation(3, VV[41], ECL_SYM("FUNCTION",396), VVtemp[92]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[93]) /*  MAPC */;
 {
  cl_object T0, T1, T2;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[42], ECL_SYM("LOCATION",1777), VVtemp[94], VVtemp[95]) /*  ANNOTATE */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__g181,ECL_NIL,Cblock,0);
   T0 = v1;
  }
  T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[97]);
  T2 = ecl_list1(T1);
  clos_load_defclass(VV[42], VVtemp[96], T2, ECL_NIL);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[44], ECL_SYM("LOCATION",1777), VVtemp[98], VVtemp[99]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[44], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[100]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[87]);                          /*  EXTREMUM        */
  si_set_documentation(3, VV[44], ECL_SYM("FUNCTION",396), VVtemp[101]);
}
