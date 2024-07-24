/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/hash-tables.lisp                       */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/hash-tables.eclh"
/*      function definition for COPY-HASH-TABLE                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2copy_hash_table(cl_narg narg, cl_object v1table, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  cl_object v3size;
  cl_object v4rehash_size;
  cl_object v5rehash_threshold;
  ecl_va_list args; ecl_va_start(args,v1table,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L2copy_hash_tablekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   env0 = ECL_NIL;
   CLV0 = env0 = CONS(keyvars[0],env0);           /*  KEY             */
   v2test = keyvars[1];
   v3size = keyvars[2];
   v4rehash_size = keyvars[3];
   v5rehash_threshold = keyvars[4];
  }
  value0 = ECL_CONS_CAR(CLV0);
  if ((value0)!=ECL_NIL) { goto L4; }
  ECL_CONS_CAR(CLV0) = ECL_SYM("IDENTITY",426);
  goto L2;
L4:;
  ECL_CONS_CAR(CLV0) = value0;
  goto L2;
L2:;
  value0 = v2test;
  if ((value0)!=ECL_NIL) { goto L9; }
  v2test = cl_hash_table_test(v1table);
  goto L7;
L9:;
  v2test = value0;
  goto L7;
L7:;
  value0 = v3size;
  if ((value0)!=ECL_NIL) { goto L14; }
  v3size = cl_hash_table_size(v1table);
  goto L12;
L14:;
  v3size = value0;
  goto L12;
L12:;
  value0 = v4rehash_size;
  if ((value0)!=ECL_NIL) { goto L19; }
  v4rehash_size = cl_hash_table_rehash_size(v1table);
  goto L17;
L19:;
  v4rehash_size = value0;
  goto L17;
L17:;
  value0 = v5rehash_threshold;
  if ((value0)!=ECL_NIL) { goto L24; }
  v5rehash_threshold = cl_hash_table_rehash_threshold(v1table);
  goto L22;
L24:;
  v5rehash_threshold = value0;
  goto L22;
L22:;
  {
   cl_object env1 = env0;
   T0 = cl_make_hash_table(8, ECL_SYM("TEST",1321), v2test, ECL_SYM("SIZE",1313), v3size, ECL_SYM("REHASH-SIZE",1302), v4rehash_size, ECL_SYM("REHASH-THRESHOLD",1303), v5rehash_threshold);
   CLV1 = env1 = CONS(T0,env1);                   /*  COPY            */
   {
    cl_object v6;
    v6 = ecl_make_cclosure_va((cl_objectfn)LC1__g5,env1,Cblock);
    T0 = v6;
   }
   cl_maphash(T0, v1table);
   value0 = ECL_CONS_CAR(CLV1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G5                                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1__g5(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  COPY            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, v2v);
  value0 = si_hash_set(v1k, ECL_CONS_CAR(CLV1), T0);
  return value0;
 }
 }
}
/*      function definition for MAPHASH-KEYS                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4maphash_keys(cl_object v1function, cl_object v2table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1function,env0);            /*  FUNCTION        */
  {
   cl_object v3;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC3__g9,env0,Cblock);
   T0 = v3;
  }
  value0 = cl_maphash(T0, v2table);
  return value0;
 }
}
/*      closure G9                                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3__g9(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FUNCTION        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, v1k);
  return value0;
 }
 }
}
/*      function definition for MAPHASH-VALUES                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L6maphash_values(cl_object v1function, cl_object v2table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1function,env0);            /*  FUNCTION        */
  {
   cl_object v3;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC5__g10,env0,Cblock);
   T0 = v3;
  }
  value0 = cl_maphash(T0, v2table);
  return value0;
 }
}
/*      closure G10                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5__g10(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FUNCTION        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, v2v);
  return value0;
 }
 }
}
/*      function definition for HASH-TABLE-KEYS                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9hash_table_keys(cl_object v1table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  KEYS            */
   {
    cl_object v2;
    cl_object env2 = env1;
    {
     cl_object v3;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC7__g13,env2,Cblock);
     v2 = v3;
    }
    CLV1 = env2 = CONS(v2,env2);                  /*  FUNCTION        */
    {
     cl_object v3;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC8__g15,env2,Cblock);
     T0 = v3;
    }
    cl_maphash(T0, v1table);
   }
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G13                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC7__g13(cl_narg narg, cl_object v1k, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  KEYS            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1k,ECL_CONS_CAR(CLV0));
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      closure G15                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC8__g15(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  FUNCTION        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV1))(1, v1k);
  return value0;
 }
 }
}
/*      function definition for HASH-TABLE-VALUES                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L12hash_table_values(cl_object v1table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  VALUES          */
   {
    cl_object v2;
    cl_object env2 = env1;
    {
     cl_object v3;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC10__g18,env2,Cblock);
     v2 = v3;
    }
    CLV1 = env2 = CONS(v2,env2);                  /*  FUNCTION        */
    {
     cl_object v3;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC11__g20,env2,Cblock);
     T0 = v3;
    }
    cl_maphash(T0, v1table);
   }
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G18                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC10__g18(cl_narg narg, cl_object v1v, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  VALUES          */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1v,ECL_CONS_CAR(CLV0));
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      closure G20                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11__g20(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  FUNCTION        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV1))(1, v2v);
  return value0;
 }
 }
}
/*      function definition for HASH-TABLE-ALIST                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L14hash_table_alist(cl_object v1table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  ALIST           */
   {
    cl_object v2;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC13__g21,env1,Cblock);
    T0 = v2;
   }
   cl_maphash(T0, v1table);
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G21                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13__g21(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object T0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ALIST           */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = CONS(v1k,v2v);
  ECL_CONS_CAR(CLV0) = CONS(T0,ECL_CONS_CAR(CLV0));
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      function definition for HASH-TABLE-PLIST                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L16hash_table_plist(cl_object v1table)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  PLIST           */
   {
    cl_object v2;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC15__g23,env1,Cblock);
    T0 = v2;
   }
   cl_maphash(T0, v1table);
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G23                                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC15__g23(cl_narg narg, cl_object v1k, cl_object v2v, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  PLIST           */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = cl_listX(3, v1k, v2v, ECL_CONS_CAR(CLV0));
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*      function definition for ALIST-HASH-TABLE                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L17alist_hash_table(cl_narg narg, cl_object v1alist, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2hash_table_initargs;
  ecl_va_list args; ecl_va_start(args,v1alist,narg,1);
  v2hash_table_initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3table;
   T0 = (ECL_SYM("MAKE-HASH-TABLE",528)->symbol.gfdef);
   v3table = cl_apply(2, T0, v2hash_table_initargs);
   {
    cl_object v4;
    v4 = v1alist;
    goto L7;
L6:;
    {
     cl_object v5cons;
     v5cons = ecl_car(v4);
     T0 = ecl_car(v5cons);
     T1 = ecl_cdr(v5cons);
     si_hash_set(T0, v3table, T1);
    }
    v4 = ecl_cdr(v4);
L7:;
    if (Null(v4)) { goto L14; }
    goto L6;
L14:;
   }
   value0 = v3table;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for PLIST-HASH-TABLE                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L18plist_hash_table(cl_narg narg, cl_object v1plist, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2hash_table_initargs;
  ecl_va_list args; ecl_va_start(args,v1plist,narg,1);
  v2hash_table_initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3table;
   T0 = (ECL_SYM("MAKE-HASH-TABLE",528)->symbol.gfdef);
   v3table = cl_apply(2, T0, v2hash_table_initargs);
   {
    cl_object v4tail;
    v4tail = v1plist;
    goto L7;
L6:;
    T0 = ecl_car(v4tail);
    T1 = ecl_cadr(v4tail);
    si_hash_set(T0, v3table, T1);
    v4tail = ecl_cddr(v4tail);
L7:;
    if (Null(v4tail)) { goto L12; }
    goto L6;
L12:;
   }
   value0 = v3table;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function ENSURE-GETHASH                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19ensure_gethash(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4key;
   cl_object v5hash_table;
   cl_object v6default;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4key = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5hash_table = v7;
   }
   if (Null(v3)) { goto L15; }
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6default = v7;
    goto L14;
   }
L15:;
   v6default = ECL_NIL;
L14:;
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   T0 = cl_list(3, ECL_SYM("GETHASH",413), v4key, v5hash_table);
   T1 = cl_list(3, ECL_SYM("GETHASH",413), v4key, v5hash_table);
   T2 = cl_list(3, ECL_SYM("SETF",750), T1, v6default);
   T3 = cl_list(3, ECL_SYM("VALUES",895), T2, ECL_NIL);
   T4 = cl_list(4, ECL_SYM("IF",946), VV[11], VV[12], T3);
   value0 = cl_list(4, ECL_SYM("MULTIPLE-VALUE-BIND",572), VV[10], T0, T4);
   return value0;
  }
 }
}

#include "lib/alexandria/hash-tables.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl7ZmCSEYoe0NCM_yPg2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/hash-tables.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecl7ZmCSEYoe0NCM_yPg2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[1], VVtemp[2]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[3]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[13]);                          /*  COPY-HASH-TABLE */
  si_set_documentation(3, VV[0], ECL_SYM("FUNCTION",396), VVtemp[4]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[5]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[6], VVtemp[7]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[8]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[19]);                          /*  MAPHASH-KEYS    */
  si_set_documentation(3, VV[1], ECL_SYM("FUNCTION",396), VVtemp[9]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[10]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LOCATION",1777), VVtemp[11], VVtemp[12]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[2], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[8]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[20]);                          /*  MAPHASH-VALUES  */
  si_set_documentation(3, VV[2], ECL_SYM("FUNCTION",396), VVtemp[13]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[3], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[21]);                          /*  HASH-TABLE-KEYS */
  si_set_documentation(3, VV[3], ECL_SYM("FUNCTION",396), VVtemp[17]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[22]);                          /*  HASH-TABLE-VALUES */
  si_set_documentation(3, VV[4], ECL_SYM("FUNCTION",396), VVtemp[20]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LOCATION",1777), VVtemp[21], VVtemp[22]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[5], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[23]);                          /*  HASH-TABLE-ALIST */
  si_set_documentation(3, VV[5], ECL_SYM("FUNCTION",396), VVtemp[23]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[24], VVtemp[25]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[24]);                          /*  HASH-TABLE-PLIST */
  si_set_documentation(3, VV[6], ECL_SYM("FUNCTION",396), VVtemp[26]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LOCATION",1777), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[29]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[25]);                          /*  ALIST-HASH-TABLE */
  si_set_documentation(3, VV[7], ECL_SYM("FUNCTION",396), VVtemp[30]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[33]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[26]);                          /*  PLIST-HASH-TABLE */
  si_set_documentation(3, VV[8], ECL_SYM("FUNCTION",396), VVtemp[34]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LOCATION",1777), VVtemp[35], VVtemp[36]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[37]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[27]);                       /*  ENSURE-GETHASH  */
  si_set_documentation(3, VV[9], ECL_SYM("FUNCTION",396), VVtemp[38]);
}
