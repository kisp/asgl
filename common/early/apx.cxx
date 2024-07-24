/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: common/early/apx.lisp                                 */
#include <ecl/ecl-cmp.h>
#include "common/early/apx.eclh"
/*      function definition for HASH-TABLE2VECTOR                     */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L1hash_table2vector(cl_object v1hash, cl_object v2vector)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4k;
   cl_object v5v;
   v3 = ECL_NIL;
   v4k = ECL_NIL;
   v5v = ECL_NIL;
   {
    cl_object v6;
    v6 = si_hash_table_iterator(v1hash);
L5:;
    {
     cl_object v8;
     cl_object v9;
     cl_object v10;
     value0 = ecl_function_dispatch(cl_env_copy,v6)(0);
     v8 = value0;
     {
      const int v11 = cl_env_copy->nvalues;
      cl_object v12;
      v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
      v9 = v12;
      v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
      v10 = v12;
     }
     if (Null(v8)) { goto L10; }
     v5v = v10;
     v4k = v9;
L10:;
     v3 = v8;
     if ((v3)!=ECL_NIL) { goto L7; }
    }
    goto L6;
L7:;
    {
     cl_object v7;
     v7 = v2vector;
     T0 = v7;
     {
      cl_fixnum v8;
      {
       cl_object v9;
       v9 = v5v;
       if (ecl_unlikely((ecl_fixnum(v9))>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(ecl_fixnum(v9)),(v7)->vector.dim);
       v8 = ecl_fixnum(v9);
      }
      ecl_aset_unsafe(T0,v8,v4k);
     }
    }
    goto L5;
L6:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      local function WITH-APX-READTABLE                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC2with_apx_readtable(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v5;
   }
   if (Null(v4)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_listX(4, ECL_SYM("LET",477), VV[2], VV[3], v3);
   return value0;
  }
 }
}
/*      function definition for READ-APX-FILE                         */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L4read_apx_file(cl_object v1pathname)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  if ((cl_probe_file(v1pathname))!=ECL_NIL) { goto L1; }
  cl_error(2, VV[5], v1pathname);
L1:;
  {
   cl_object v3;                                  /*  BUFFER          */
   cl_object v4;                                  /*  SIZE            */
   T0 = cl_merge_pathnames(1, v1pathname);
   T1 = cl_namestring(T0);
   T2 = si_coerce_to_vector(T1, ECL_SYM("BASE-CHAR",120), ECL_SYM("*",18), ECL_NIL);
   {
    void* v5;
    long v6;
    {
long msize = 99;

v5= slurp_file(T2, &msize);
v6= msize;
}
    cl_env_copy->values[0] = ecl_make_pointer(v5);
    cl_env_copy->values[1] = ecl_make_long(v6);cl_env_copy->nvalues=2;
    value0 = cl_env_copy->values[0];
   }
   v3 = value0;
   v4 = cl_env_copy->values[1];
   {
    cl_fixnum v5arg_count;
    {
     int v6;
     { v6= count_args((char*)ecl_to_pointer(v3), ecl_to_long(v4)); }
     v5arg_count = (cl_fixnum)(v6);
    }
    {
     cl_object v6;
     cl_object v7;
     cl_object v8;
     cl_object v9hash;
     cl_object env1 = env0;
     v6 = si_make_pure_array(ECL_T, ecl_make_fixnum(v5arg_count), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
     T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
     v7 = cl_make_hash_table(2, ECL_SYM("TEST",1321), T0);
     v8 = si_make_pure_array(ECL_T, ecl_make_fixnum(v5arg_count), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
     v9hash = v7;
     env1 = ECL_NIL;
     CLV0 = env1 = CONS(v8,env1);                 /*  GRAPH           */
     {
      cl_object v10;
      v10 = ecl_make_cclosure_va((cl_objectfn)LC3__g31,env1,Cblock);
      T0 = v10;
     }
     { ragel_apx_parse((char*)ecl_to_pointer(v3), ecl_to_long(v4), v9hash, T0); }
     L1hash_table2vector(v9hash, v6);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v9hash;
     cl_env_copy->values[1] = v6;
     cl_env_copy->values[0] = ECL_CONS_CAR(CLV0);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*      closure G31                                                   */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC3__g31(cl_narg narg, cl_object v1from, cl_object v2to, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  GRAPH           */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[9])(3, ECL_CONS_CAR(CLV0), v1from, v2to) /*  ADD-EDGE */;
  return value0;
 }
 }
}

#include "common/early/apx.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclqMFRzztbaOQJM_adf2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/early/apx.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclqMFRzztbaOQJM_adf2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LOCATION",1777), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[0], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[6]);                           /*  HASH-TABLE2VECTOR */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LOCATION",1777), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[1], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[7]);                        /*  WITH-APX-READTABLE */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LOCATION",1777), VVtemp[8], VVtemp[9]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[4], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[10]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[8]);                           /*  READ-APX-FILE   */
}
