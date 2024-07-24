/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: common/early/graph-input.lisp                         */
#include <ecl/ecl-cmp.h>
#include "common/early/graph-input.eclh"
/*      local function G0                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC1__g0(cl_object v1input)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[2])(1, v1input) /*  READ-APX-FILE */;
  return value0;
 }
}
/*      local function G1                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC2__g1(cl_object v1input)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[2])(1, v1input) /*  READ-APX-FILE */;
  return value0;
 }
}
/*      local function G20                                            */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC3__g20(cl_object v1input)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v2items;
   {
    cl_object v3;
    cl_object v4;
    cl_object v5i;
    v3 = ecl_function_dispatch(cl_env_copy,VV[3])(1, v1input) /*  ORDER */;
    {
     cl_object v6;
     v6 = v3;
     T0 = cl_realp(v6);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v6);
     v4 = v6;
    }
    v5i = ecl_make_fixnum(0);
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L9:;
     if (!(ecl_number_compare(v5i,v4)>=0)) { goto L11; }
     goto L10;
L11:;
     {
      cl_object v8;
      v8 = v7;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      T0 = v8;
     }
     v7 = ecl_list1(v5i);
     (ECL_CONS_CDR(T0)=v7,T0);
     v5i = ecl_one_plus(v5i);
     goto L9;
L10:;
     v2items = _ecl_cdr(v6);
     goto L1;
    }
   }
L1:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[3])(1, v1input) /*  ORDER */;
   T1 = cl_make_array(3, T0, ECL_SYM("INITIAL-CONTENTS",1257), v2items);
   {
    cl_object v3hash;
    v3hash = cl_make_hash_table(0);
    {
     cl_object v4;
     v4 = v2items;
     goto L28;
L27:;
     {
      cl_object v5item;
      v5item = ECL_CONS_CAR(v4);
      si_hash_set(v5item, v3hash, v5item);
     }
     v4 = ECL_CONS_CDR(v4);
L28:;
     if (Null(v4)) { goto L35; }
     goto L27;
L35:;
    }
    T2 = v3hash;
   }
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = v1input;
   return cl_env_copy->values[0];
  }
 }
}
/*      local function G104                                           */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC4__g104(cl_object v1input)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v2;
   cl_fixnum v3order;
   v2 = v1input;
   {
    cl_object v4;
    if (!(v2==ECL_NIL)) { goto L4; }
    si_dm_too_few_arguments(v1input);
L4:;
    {
     cl_object v5;
     v5 = ECL_CONS_CAR(v2);
     v2 = ECL_CONS_CDR(v2);
     v4 = v5;
    }
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v3order = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    cl_object v5;
    cl_object v6;
    v4 = ecl_make_integer((v3order)-1);
    T0 = ecl_expt(ecl_make_fixnum(2),ecl_make_fixnum(v3order));
    v5 = ecl_one_minus(T0);
    T0 = si_make_pure_array(ECL_T, ecl_make_fixnum(v3order), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
    v6 = si_fill_array_with_elt(T0, ECL_NIL, ecl_make_fixnum(0), ECL_NIL);
    {
     cl_object v7i;
     v7i = ecl_make_fixnum(0);
     {
      cl_object v8;
      cl_object v9position;
      T0 = ecl_make_integer((v3order)-1);
      v8 = ecl_times(ecl_make_fixnum(v3order),T0);
      {
       cl_object v10;
       v10 = v8;
       T0 = cl_realp(v10);
       if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v10);
       v9position = v10;
      }
      {
       cl_object v10row;
       v10row = ECL_NIL;
       if (!(ecl_number_compare(v7i,ecl_make_fixnum(v3order))>=0)) { goto L22; }
       goto L21;
L22:;
L20:;
       {
        cl_object v11;
        cl_object v12;
        {
         cl_object v13;
         v13 = ecl_make_fixnum(v3order);
         {
          cl_object v14;
          v14 = ecl_make_fixnum(0);
          if (!(ECL_FIXNUMP(v13)||ECL_BIGNUMP(v13))) { goto L32; }
          v14 = v13;
          T0 = ecl_make_bool(ecl_number_compare(v14,ecl_make_fixnum(0))>=0);
          goto L29;
L32:;
          T0 = ECL_NIL;
          goto L29;
         }
L29:;
         if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v13);
         v11 = v13;
        }
        {
         cl_object v13;
         v13 = v9position;
         {
          cl_object v14;
          v14 = ecl_make_fixnum(0);
          if (!(ECL_FIXNUMP(v13)||ECL_BIGNUMP(v13))) { goto L42; }
          v14 = v13;
          T0 = ecl_make_bool(ecl_number_compare(v14,ecl_make_fixnum(0))>=0);
          goto L39;
L42:;
          T0 = ECL_NIL;
          goto L39;
         }
L39:;
         if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v13);
         v12 = v13;
        }
        T0 = cl_ash(ecl_make_fixnum(-1), v11);
        T1 = ecl_boole(ECL_BOOLXOR,(T0),ecl_make_fixnum(-1));
        T2 = ecl_negate(v12);
        T3 = cl_ash(v2, T2);
        v10row = ecl_boole(ECL_BOOLAND,(T1),(T3));
       }
       {
        cl_object v11;
        v11 = ecl_make_bool(ecl_zerop(v10row));
        if (Null(v11)) { goto L48; }
        goto L46;
L48:;
        if (!(ecl_eql(v10row,v5))) { goto L50; }
        {
         cl_fixnum v12j;
         v12j = 0;
         goto L54;
L53:;
         {
          cl_object v13;
          cl_object v14;
          v13 = ecl_minus(v4,ecl_make_fixnum(v12j));
          {
          cl_object v15;
          v15 = v6;
          T1 = v15;
          {
          cl_fixnum v16;
          {
          cl_object v17;
          v17 = v13;
          if (ecl_unlikely((ecl_fixnum(v17))>=(v15)->vector.dim))
           FEwrong_index(ECL_NIL,v15,-1,ecl_make_fixnum(ecl_fixnum(v17)),(v15)->vector.dim);
          v16 = ecl_fixnum(v17);
          }
          T0 = ecl_aref_unsafe(T1,v16);
          }
          }
          v14 = CONS(v7i,T0);
          {
          cl_object v15;
          v15 = v6;
          T0 = v15;
          {
          cl_fixnum v16;
          {
          cl_object v17;
          v17 = v13;
          if (ecl_unlikely((ecl_fixnum(v17))>=(v15)->vector.dim))
           FEwrong_index(ECL_NIL,v15,-1,ecl_make_fixnum(ecl_fixnum(v17)),(v15)->vector.dim);
          v16 = ecl_fixnum(v17);
          }
          ecl_aset_unsafe(T0,v16,v14);
          }
          }
         }
         v12j = (v12j)+1;
L54:;
         if (!((v12j)<(v3order))) { goto L72; }
         goto L53;
L72:;
         goto L46;
        }
L50:;
        {
         cl_fixnum v13j;
         v13j = 0;
         goto L76;
L75:;
         if (Null(cl_logbitp(ecl_make_fixnum(v13j), v10row))) { goto L78; }
         {
          cl_object v14;
          cl_object v15;
          v14 = ecl_minus(v4,ecl_make_fixnum(v13j));
          {
          cl_object v16;
          v16 = v6;
          T1 = v16;
          {
          cl_fixnum v17;
          {
          cl_object v18;
          v18 = v14;
          if (ecl_unlikely((ecl_fixnum(v18))>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(ecl_fixnum(v18)),(v16)->vector.dim);
          v17 = ecl_fixnum(v18);
          }
          T0 = ecl_aref_unsafe(T1,v17);
          }
          }
          v15 = CONS(v7i,T0);
          {
          cl_object v16;
          v16 = v6;
          T0 = v16;
          {
          cl_fixnum v17;
          {
          cl_object v18;
          v18 = v14;
          if (ecl_unlikely((ecl_fixnum(v18))>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(ecl_fixnum(v18)),(v16)->vector.dim);
          v17 = ecl_fixnum(v18);
          }
          ecl_aset_unsafe(T0,v17,v15);
          }
          }
         }
L78:;
         v13j = (v13j)+1;
L76:;
         if (!((v13j)<(v3order))) { goto L95; }
         goto L75;
L95:;
        }
       }
L46:;
       v7i = ecl_one_plus(v7i);
       if (!(ecl_number_compare(v7i,ecl_make_fixnum(v3order))>=0)) { goto L99; }
       goto L21;
L99:;
       v9position = ecl_minus(v9position,ecl_make_fixnum(v3order));
       goto L20;
L21:;
      }
     }
    }
    value0 = ecl_function_dispatch(cl_env_copy,VV[0])(1, v6) /*  READ-GRAPH-INPUT */;
    return value0;
   }
  }
 }
}

#include "common/early/graph-input.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclkTNz1HtborJCM_WNf2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/early/graph-input.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclkTNz1HtborJCM_WNf2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[0], VV[1], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[4]) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__g0,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  clos_install_method(6, VV[0], ECL_NIL, VVtemp[7], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g1,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  clos_install_method(6, VV[0], ECL_NIL, VVtemp[10], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[11], VVtemp[12]) /*  ANNOTATE */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g20,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  clos_install_method(6, VV[0], ECL_NIL, VVtemp[13], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g104,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  clos_install_method(6, VV[0], ECL_NIL, VVtemp[16], VVtemp[4], T0, ECL_T);
 }
}
