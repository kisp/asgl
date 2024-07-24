/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/symbols.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/symbols.eclh"
/*      function definition for ENSURE-SYMBOL                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L1ensure_symbol(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2package;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2package = ecl_symbol_value(ECL_SYM("*PACKAGE*",45));
   } else {
    i++;
    v2package = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = cl_string(v1name);
  value0 = cl_intern(2, T0, v2package);
  return value0;
 }
}
/*      function definition for MAYBE-INTERN                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L2maybe_intern(cl_object v1name, cl_object v2package)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2package)) { goto L2; }
  if (!((ECL_T)==(v2package))) { goto L5; }
  T0 = ecl_symbol_value(ECL_SYM("*PACKAGE*",45));
  goto L4;
L5:;
  T0 = v2package;
L4:;
  value0 = cl_intern(2, v1name, T0);
  goto L1;
L2:;
  value0 = cl_make_symbol(v1name);
L1:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for FORMAT-SYMBOL                         */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L3format_symbol(cl_narg narg, cl_object v1package, cl_object v2control, ...)
{
 cl_object T0, T1, T2;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3arguments;
  ecl_va_list args; ecl_va_start(args,v2control,narg,2);
  v3arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v4;
   v4 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1798));
   {
    cl_object v6, v7; cl_index v5;
    v6 = ECL_CONS_CAR(v4);
    v7 = ECL_CONS_CDR(v4);
    v5 = ecl_progv(cl_env_copy, v6, v7);
    T1 = (ECL_SYM("FORMAT",389)->symbol.gfdef);
    T2 = cl_string(v2control);
    T0 = cl_apply(4, T1, ECL_NIL, T2, v3arguments);
    ecl_bds_unwind(cl_env_copy,v5);
   }
  }
  value0 = L2maybe_intern(T0, v1package);
  return value0;
 }
}
/*      function definition for MAKE-KEYWORD                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L4make_keyword(cl_object v1name)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1name);
  value0 = cl_intern(2, T0, VV[4]);
  return value0;
 }
}
/*      function definition for MAKE-GENSYM                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L5make_gensym(cl_object v1name)
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
   v2 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v1name)||ECL_BIGNUMP(v1name))) { goto L2; }
   v2 = v1name;
   if (!(ecl_greatereq(v2,ecl_make_fixnum(0)))) { goto L2; }
  }
  T0 = v1name;
  goto L1;
L2:;
  T0 = cl_string(v1name);
L1:;
  value0 = cl_gensym(1, T0);
  return value0;
 }
}
/*      function definition for MAKE-GENSYM-LIST                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L6make_gensym_list(cl_narg narg, cl_object v1length, ...)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2x;
  va_list args; va_start(args,v1length);
  {
   int i = 1;
   if (i >= narg) {
    v2x = VV[7];
   } else {
    i++;
    v2x = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3g;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v2x)||ECL_BIGNUMP(v2x))) { goto L3; }
    v4 = v2x;
    if (!(ecl_greatereq(v4,ecl_make_fixnum(0)))) { goto L3; }
   }
   v3g = v2x;
   goto L2;
L3:;
   v3g = cl_string(v2x);
L2:;
   {
    cl_object v4;
    {
     cl_object v5;
     v5 = v1length;
     T0 = cl_realp(v5);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",705),v5);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     v4 = v5;
    }
    {
     cl_object v5;
     cl_object v6;
     v5 = ecl_list1(ECL_NIL);
     v6 = v5;
L14:;
     v4 = ecl_minus(v4,ecl_make_fixnum(1));
     T0 = v4;
     if (!(ecl_minusp(T0))) { goto L16; }
     goto L15;
L16:;
     {
      cl_object v7;
      v7 = v6;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      T0 = v7;
     }
     T1 = cl_gensym(1, v3g);
     v6 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v6,T0);
     goto L14;
L15:;
     value0 = ecl_cdr(v5);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      function definition for SYMBOLICATE                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L8symbolicate(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1things;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1things = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2length;
   cl_object v3name;
   T0 = (ECL_SYM("+",16)->symbol.gfdef);
   {
    cl_object v4;
    v4 = ecl_make_cfun((cl_objectfn_fixed)LC7__lambda15,ECL_NIL,Cblock,1);
    T1 = v4;
   }
   v2length = cl_reduce(4, T0, v1things, ECL_SYM("KEY",1294), T1);
   v3name = si_make_pure_array(ECL_SYM("CHARACTER",224), v2length, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   {
    cl_object v4index;
    v4index = ecl_make_fixnum(0);
    {
     cl_object v5;
     v5 = v1things;
     goto L9;
L8:;
     {
      cl_object v6thing;
      v6thing = ecl_car(v5);
      {
       cl_object v7x;
       cl_fixnum v8len;
       v7x = cl_string(v6thing);
       v8len = ecl_length(v7x);
       cl_replace(4, v3name, v7x, ECL_SYM("START1",1345), v4index);
       v4index = ecl_plus(v4index,ecl_make_fixnum(v8len));
      }
     }
     v5 = ecl_cdr(v5);
L9:;
     if (Null(v5)) { goto L20; }
     goto L8;
L20:;
     value0 = cl_intern(1, v3name);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*      local function LAMBDA15                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC7__lambda15(cl_object v1x)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1x);
  value0 = ecl_make_fixnum(ecl_length(T0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lib/alexandria/symbols.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecljVTgFlYFBNMEM_qiFycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/symbols.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_ecljVTgFlYFBNMEM_qiFycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[1]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LOCATION",1862), VVtemp[2], VVtemp[3]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[0], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[4]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[9]);                           /*  ENSURE-SYMBOL   */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[0], ECL_SYM("FUNCTION",398), VVtemp[5]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[0], ECL_SYM("INLINE",436), VVtemp[6]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[1], ECL_SYM("LOCATION",1862), VVtemp[7], VVtemp[8]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[1], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[9]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[11]);                          /*  MAYBE-INTERN    */
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[10]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LOCATION",1862), VVtemp[11], VVtemp[12]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[13]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[12]);                          /*  FORMAT-SYMBOL   */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[2], ECL_SYM("FUNCTION",398), VVtemp[14]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[2], ECL_SYM("INLINE",436), VVtemp[15]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LOCATION",1862), VVtemp[16], VVtemp[17]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[18]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[13]);                          /*  MAKE-KEYWORD    */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[3], ECL_SYM("FUNCTION",398), VVtemp[19]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LOCATION",1862), VVtemp[20], VVtemp[21]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[18]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[14]);                          /*  MAKE-GENSYM     */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[5], ECL_SYM("FUNCTION",398), VVtemp[22]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LOCATION",1862), VVtemp[23], VVtemp[24]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[25]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[15]);                          /*  MAKE-GENSYM-LIST */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[6], ECL_SYM("FUNCTION",398), VVtemp[26]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[27], VVtemp[28]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[29]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[16]);                          /*  SYMBOLICATE     */
  ecl_function_dispatch(cl_env_copy,VV[10])(3, VV[8], ECL_SYM("FUNCTION",398), VVtemp[30]) /*  SET-DOCUMENTATION */;
}
