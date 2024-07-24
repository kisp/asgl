/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/lib/alexandria/types.lisp */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/types.eclh"
/*      local function LAMBDA2                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1__lambda2(cl_object v1)
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
   cl_object v3length;
   v2 = v1;
   if (Null(v2)) { goto L3; }
   {
    cl_object v4;
    v4 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3length = v4;
    goto L2;
   }
L3:;
   v3length = ecl_make_fixnum(2305843009213693950);
L2:;
   if (Null(v2)) { goto L8; }
   ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L8:;
   T0 = ecl_list1(v3length);
   value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(0), T0);
   return value0;
  }
 }
}
/*      local function LAMBDA6                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2__lambda6(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3length;
   v2 = v1;
   if (Null(v2)) { goto L3; }
   {
    cl_object v4;
    v4 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3length = v4;
    goto L2;
   }
L3:;
   v3length = ecl_make_fixnum(2305843009213693950);
L2:;
   if (Null(v2)) { goto L8; }
   ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L8:;
   value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(0), v3length);
   return value0;
  }
 }
}
/*      local function LAMBDA37                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3__lambda37(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(-2305843009213693952), ecl_make_fixnum(-1));
  return value0;
 }
}
/*      local function LAMBDA40                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4__lambda40(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(-2305843009213693952), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function LAMBDA43                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5__lambda43(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(0), ecl_make_fixnum(2305843009213693951));
  return value0;
 }
}
/*      local function LAMBDA46                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6__lambda46(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(1), ecl_make_fixnum(2305843009213693951));
  return value0;
 }
}
/*      function definition for NEGATIVE-FIXNUM-P                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7negative_fixnum_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-FIXNUM-P                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L8non_positive_fixnum_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-FIXNUM-P                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L9non_negative_fixnum_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-FIXNUM-P                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L10positive_fixnum_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA49                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11__lambda49(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ECL_SYM("*",20), ecl_make_fixnum(-1));
  return value0;
 }
}
/*      local function LAMBDA52                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12__lambda52(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ECL_SYM("*",20), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function LAMBDA55                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13__lambda55(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(0), ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA58                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14__lambda58(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",439), ecl_make_fixnum(1), ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-INTEGER-P                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L15negative_integer_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-INTEGER-P                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L16non_positive_integer_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-INTEGER-P                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L17non_negative_integer_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-INTEGER-P                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L18positive_integer_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA61                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19__lambda61(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",689), ECL_SYM("*",20), VV[19]);
  return value0;
 }
}
/*      local function LAMBDA64                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC20__lambda64(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",689), ECL_SYM("*",20), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function LAMBDA67                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC21__lambda67(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",689), ecl_make_fixnum(0), ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA70                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC22__lambda70(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",689), VV[19], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-RATIONAL-P                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L23negative_rational_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-RATIONAL-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L24non_positive_rational_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-RATIONAL-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L25non_negative_rational_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-RATIONAL-P                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L26positive_rational_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA73                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC27__lambda73(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",705), ECL_SYM("*",20), VV[19]);
  return value0;
 }
}
/*      local function LAMBDA76                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC28__lambda76(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",705), ECL_SYM("*",20), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function LAMBDA79                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC29__lambda79(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",705), ecl_make_fixnum(0), ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA82                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC30__lambda82(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",705), VV[19], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-REAL-P                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L31negative_real_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-REAL-P                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L32non_positive_real_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-REAL-P                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L33non_negative_real_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-REAL-P                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L34positive_real_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(ecl_make_fixnum(0),v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA85                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC35__lambda85(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",376), ECL_SYM("*",20), VV[36]);
  return value0;
 }
}
/*      local function LAMBDA88                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC36__lambda88(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",376), ECL_SYM("*",20), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function LAMBDA91                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC37__lambda91(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",376), cl_core.singlefloat_zero, ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA94                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC38__lambda94(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",376), VV[36], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-FLOAT-P                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L39negative_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-FLOAT-P                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L40non_positive_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-FLOAT-P                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L41non_negative_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-FLOAT-P                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L42positive_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA97                                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC43__lambda97(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",758), ECL_SYM("*",20), VV[36]);
  return value0;
 }
}
/*      local function LAMBDA100                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC44__lambda100(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",758), ECL_SYM("*",20), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function LAMBDA103                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC45__lambda103(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",758), cl_core.singlefloat_zero, ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA106                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC46__lambda106(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",758), VV[36], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-SHORT-FLOAT-P                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L47negative_short_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-SHORT-FLOAT-P            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L48non_positive_short_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-SHORT-FLOAT-P            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L49non_negative_short_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-SHORT-FLOAT-P                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L50positive_short_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA109                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC51__lambda109(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",780), ECL_SYM("*",20), VV[36]);
  return value0;
 }
}
/*      local function LAMBDA112                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC52__lambda112(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",780), ECL_SYM("*",20), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function LAMBDA115                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC53__lambda115(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",780), cl_core.singlefloat_zero, ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA118                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC54__lambda118(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",780), VV[36], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-SINGLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L55negative_single_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-SINGLE-FLOAT-P           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L56non_positive_single_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,cl_core.singlefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-SINGLE-FLOAT-P           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L57non_negative_single_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-SINGLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L58positive_single_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(cl_core.singlefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA121                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC59__lambda121(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",317), ECL_SYM("*",20), VV[61]);
  return value0;
 }
}
/*      local function LAMBDA124                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC60__lambda124(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",317), ECL_SYM("*",20), cl_core.doublefloat_zero);
  return value0;
 }
}
/*      local function LAMBDA127                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC61__lambda127(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",317), cl_core.doublefloat_zero, ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA130                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC62__lambda130(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",317), VV[61], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-DOUBLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L63negative_double_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,cl_core.doublefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-DOUBLE-FLOAT-P           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L64non_positive_double_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,cl_core.doublefloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-DOUBLE-FLOAT-P           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L65non_negative_double_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(cl_core.doublefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-DOUBLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L66positive_double_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(cl_core.doublefloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function LAMBDA133                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC67__lambda133(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",510), ECL_SYM("*",20), VV[70]);
  return value0;
 }
}
/*      local function LAMBDA136                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC68__lambda136(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",510), ECL_SYM("*",20), cl_core.longfloat_zero);
  return value0;
 }
}
/*      local function LAMBDA139                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC69__lambda139(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",510), cl_core.longfloat_zero, ECL_SYM("*",20));
  return value0;
 }
}
/*      local function LAMBDA142                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC70__lambda142(cl_object v1)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",510), VV[70], ECL_SYM("*",20));
  return value0;
 }
}
/*      function definition for NEGATIVE-LONG-FLOAT-P                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L71negative_long_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(v1n,cl_core.longfloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-POSITIVE-LONG-FLOAT-P             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L72non_positive_long_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(v1n,cl_core.longfloat_zero));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for NON-NEGATIVE-LONG-FLOAT-P             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L73non_negative_long_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lowereq(cl_core.longfloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for POSITIVE-LONG-FLOAT-P                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L74positive_long_float_p(cl_object v1n)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_lower(cl_core.longfloat_zero,v1n));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for OF-TYPE                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L76of_type(cl_object v1type)
{
 cl_object env0 = ECL_NIL;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1type,env0);                /*  TYPE            */
  {
   cl_object v2;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC75__lambda143,env0,Cblock,1);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure LAMBDA143                                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC75__lambda143(cl_narg narg, cl_object v1thing, ...)
{
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  TYPE            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_typep(2, v1thing, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*      local function LAMBDA146                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC77__lambda146(cl_object v1, cl_object v2env)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4type;
   T0 = ecl_car(v1);
   if (!((T0)==(ECL_SYM("FUNCALL",396)))) { goto L2; }
   T0 = ecl_caadr(v1);
   if (!((T0)==(ECL_SYM("FUNCTION",398)))) { goto L2; }
   v3 = ecl_cddr(v1);
   goto L1;
L2:;
   v3 = ecl_cdr(v1);
L1:;
   if (!(v3==ECL_NIL)) { goto L6; }
   ecl_function_dispatch(cl_env_copy,VV[122])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L6:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4type = v5;
   }
   if (Null(v3)) { goto L11; }
   ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L11:;
   if (Null(cl_constantp(2, v4type, v2env))) { goto L13; }
   {
    cl_object v5thing;
    v5thing = cl_gensym(1, VV[79]);
    T0 = ecl_list1(v5thing);
    T1 = cl_list(3, ECL_SYM("TYPEP",877), v5thing, v4type);
    value0 = cl_list(3, ECL_SYM("LAMBDA",454), T0, T1);
    return value0;
   }
L13:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for TYPE=                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L78type_(cl_object v1type1, cl_object v2type2)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  SUB             */
   cl_object v5;                                  /*  OK              */
   value0 = cl_subtypep(2, v1type1, v2type2);
   {
    v4 = value0;
    v5 = cl_env_copy->values[1];
   }
   if (Null(v5)) { goto L2; }
   if (Null(v4)) { goto L2; }
   value0 = cl_subtypep(2, v2type2, v1type1);
   return value0;
L2:;
   if (Null(v5)) { goto L5; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
L5:;
   {
    cl_object v7;                                 /*  OK              */
    value0 = cl_subtypep(2, v2type2, v1type1);
    {
     v7 = cl_env_copy->values[1];
    }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v7;
    cl_env_copy->values[0] = ECL_NIL;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*      local function COERCEF                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC80coercef(cl_object v1, cl_object v2si__env)
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
   cl_object v5type_spec;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[122])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   ecl_function_dispatch(cl_env_copy,VV[122])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type_spec = v6;
   }
   if (Null(v3)) { goto L14; }
   ecl_function_dispatch(cl_env_copy,VV[84])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L14:;
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",412)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    {
     v7 = value0;
     v8 = cl_env_copy->values[1];
     v9 = cl_env_copy->values[2];
     v10 = cl_env_copy->values[3];
     v11 = cl_env_copy->values[4];
    }
    {
     cl_object v12si__all_vars;
     {
      cl_object v13;
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC79__lambda154,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5type_spec,ECL_NIL);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L19; }
     T0 = (ECL_SYM("CAR",182)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("COERCE",233), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",373)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[82],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",276), T6);
     T8 = cl_list(4, ECL_SYM("LET*",480), v12si__all_vars, T7, v10);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L19:;
     {
      cl_object v13si__d;
      cl_object v14si__v;
      cl_object v15si__let_list;
      v13si__d = v7;
      v14si__v = v8;
      v15si__let_list = ECL_NIL;
      goto L28;
L27:;
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
L28:;
      if (v13si__d==ECL_NIL) { goto L34; }
      goto L27;
L34:;
      T0 = ecl_car(v9);
      T1 = (ECL_SYM("CAR",182)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = cl_listX(3, ECL_SYM("COERCE",233), v11, T2);
      T4 = cl_list(2, T0, T3);
      T5 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T4,T5);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",373)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",547)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[82],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",276), T4);
      value0 = cl_list(4, ECL_SYM("LET*",480), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function LAMBDA154                                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC79__lambda154(cl_object v1si__v)
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

#include "lib/alexandria/types.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclYKIWc8zWYNLAM_M2HycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/types.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclYKIWc8zWYNLAM_M2HycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
 {
  cl_object T0;
  cl_object volatile env0 = ECL_NIL;
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[0], ECL_SYM("TYPE",871), VVtemp[1]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__lambda2,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[0], VVtemp[2], T0);
 }
 {
  cl_object T0;
  cl_object volatile env0 = ECL_NIL;
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[1], ECL_SYM("TYPE",871), VVtemp[3]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__lambda6,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[1], VVtemp[4], T0);
 }
 {
  cl_object T0;
  cl_object volatile env0 = ECL_NIL;
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[2], ECL_SYM("TYPE",871), VVtemp[5]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__lambda37,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[2], VVtemp[6], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[3], ECL_SYM("TYPE",871), VVtemp[7]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__lambda40,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[3], VVtemp[8], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[4], ECL_SYM("TYPE",871), VVtemp[9]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__lambda43,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[4], VVtemp[10], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[5], ECL_SYM("TYPE",871), VVtemp[11]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__lambda46,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[5], VVtemp[12], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[13]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LOCATION",1862), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[6], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[85]);                          /*  NEGATIVE-FIXNUM-P */
  si_put_sysprop(VV[6], ECL_SYM("INLINE",436), VVtemp[17]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LOCATION",1862), VVtemp[18], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[86]);                          /*  NON-POSITIVE-FIXNUM-P */
  si_put_sysprop(VV[7], ECL_SYM("INLINE",436), VVtemp[19]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[20], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[87]);                          /*  NON-NEGATIVE-FIXNUM-P */
  si_put_sysprop(VV[8], ECL_SYM("INLINE",436), VVtemp[21]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[9], ECL_SYM("LOCATION",1862), VVtemp[22], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[9], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[88]);                          /*  POSITIVE-FIXNUM-P */
  si_put_sysprop(VV[9], ECL_SYM("INLINE",436), VVtemp[23]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[10], ECL_SYM("TYPE",871), VVtemp[24]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC11__lambda49,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[10], VVtemp[25], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[11], ECL_SYM("TYPE",871), VVtemp[26]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__lambda52,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[11], VVtemp[27], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[12], ECL_SYM("TYPE",871), VVtemp[28]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC13__lambda55,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[12], VVtemp[29], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[13], ECL_SYM("TYPE",871), VVtemp[30]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__lambda58,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[13], VVtemp[31], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[32]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LOCATION",1862), VVtemp[33], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[89]);                          /*  NEGATIVE-INTEGER-P */
  si_put_sysprop(VV[14], ECL_SYM("INLINE",436), VVtemp[34]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LOCATION",1862), VVtemp[35], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[90]);                          /*  NON-POSITIVE-INTEGER-P */
  si_put_sysprop(VV[15], ECL_SYM("INLINE",436), VVtemp[36]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LOCATION",1862), VVtemp[37], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[91]);                          /*  NON-NEGATIVE-INTEGER-P */
  si_put_sysprop(VV[16], ECL_SYM("INLINE",436), VVtemp[38]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LOCATION",1862), VVtemp[39], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[92]);                          /*  POSITIVE-INTEGER-P */
  si_put_sysprop(VV[17], ECL_SYM("INLINE",436), VVtemp[40]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[18], ECL_SYM("TYPE",871), VVtemp[41]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC19__lambda61,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[18], VVtemp[42], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[20], ECL_SYM("TYPE",871), VVtemp[41]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC20__lambda64,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[20], VVtemp[43], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[21], ECL_SYM("TYPE",871), VVtemp[44]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC21__lambda67,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[21], VVtemp[45], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[22], ECL_SYM("TYPE",871), VVtemp[44]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__lambda70,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[22], VVtemp[46], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[47]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[23], ECL_SYM("LOCATION",1862), VVtemp[48], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[23], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[93]);                          /*  NEGATIVE-RATIONAL-P */
  si_put_sysprop(VV[23], ECL_SYM("INLINE",436), VVtemp[49]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[24], ECL_SYM("LOCATION",1862), VVtemp[50], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[24], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[94]);                          /*  NON-POSITIVE-RATIONAL-P */
  si_put_sysprop(VV[24], ECL_SYM("INLINE",436), VVtemp[51]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LOCATION",1862), VVtemp[52], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[25], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[95]);                          /*  NON-NEGATIVE-RATIONAL-P */
  si_put_sysprop(VV[25], ECL_SYM("INLINE",436), VVtemp[53]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[26], ECL_SYM("LOCATION",1862), VVtemp[54], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[26], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[96]);                          /*  POSITIVE-RATIONAL-P */
  si_put_sysprop(VV[26], ECL_SYM("INLINE",436), VVtemp[55]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[27], ECL_SYM("TYPE",871), VVtemp[56]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__lambda73,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[27], VVtemp[57], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[28], ECL_SYM("TYPE",871), VVtemp[56]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__lambda76,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[28], VVtemp[58], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[29], ECL_SYM("TYPE",871), VVtemp[59]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__lambda79,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[29], VVtemp[60], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[30], ECL_SYM("TYPE",871), VVtemp[59]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__lambda82,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[30], VVtemp[61], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[62]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[31], ECL_SYM("LOCATION",1862), VVtemp[63], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[31], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[97]);                          /*  NEGATIVE-REAL-P */
  si_put_sysprop(VV[31], ECL_SYM("INLINE",436), VVtemp[64]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[32], ECL_SYM("LOCATION",1862), VVtemp[65], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[32], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[98]);                          /*  NON-POSITIVE-REAL-P */
  si_put_sysprop(VV[32], ECL_SYM("INLINE",436), VVtemp[66]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[33], ECL_SYM("LOCATION",1862), VVtemp[67], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[33], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[99]);                          /*  NON-NEGATIVE-REAL-P */
  si_put_sysprop(VV[33], ECL_SYM("INLINE",436), VVtemp[68]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[34], ECL_SYM("LOCATION",1862), VVtemp[69], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[34], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[100]);                         /*  POSITIVE-REAL-P */
  si_put_sysprop(VV[34], ECL_SYM("INLINE",436), VVtemp[70]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[35], ECL_SYM("TYPE",871), VVtemp[71]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__lambda85,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[35], VVtemp[72], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[37], ECL_SYM("TYPE",871), VVtemp[71]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__lambda88,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[37], VVtemp[73], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[38], ECL_SYM("TYPE",871), VVtemp[74]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__lambda91,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[38], VVtemp[75], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[39], ECL_SYM("TYPE",871), VVtemp[74]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__lambda94,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[39], VVtemp[76], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[77]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[40], ECL_SYM("LOCATION",1862), VVtemp[78], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[40], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[101]);                         /*  NEGATIVE-FLOAT-P */
  si_put_sysprop(VV[40], ECL_SYM("INLINE",436), VVtemp[79]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[41], ECL_SYM("LOCATION",1862), VVtemp[80], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[41], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[102]);                         /*  NON-POSITIVE-FLOAT-P */
  si_put_sysprop(VV[41], ECL_SYM("INLINE",436), VVtemp[81]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[42], ECL_SYM("LOCATION",1862), VVtemp[82], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[42], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[103]);                         /*  NON-NEGATIVE-FLOAT-P */
  si_put_sysprop(VV[42], ECL_SYM("INLINE",436), VVtemp[83]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[43], ECL_SYM("LOCATION",1862), VVtemp[84], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[43], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[104]);                         /*  POSITIVE-FLOAT-P */
  si_put_sysprop(VV[43], ECL_SYM("INLINE",436), VVtemp[85]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[44], ECL_SYM("TYPE",871), VVtemp[86]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC43__lambda97,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[44], VVtemp[87], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[45], ECL_SYM("TYPE",871), VVtemp[86]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC44__lambda100,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[45], VVtemp[88], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[46], ECL_SYM("TYPE",871), VVtemp[89]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC45__lambda103,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[46], VVtemp[90], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[47], ECL_SYM("TYPE",871), VVtemp[89]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC46__lambda106,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[47], VVtemp[91], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[92]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[48], ECL_SYM("LOCATION",1862), VVtemp[93], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[48], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[105]);                         /*  NEGATIVE-SHORT-FLOAT-P */
  si_put_sysprop(VV[48], ECL_SYM("INLINE",436), VVtemp[94]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[49], ECL_SYM("LOCATION",1862), VVtemp[95], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[49], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[106]);                         /*  NON-POSITIVE-SHORT-FLOAT-P */
  si_put_sysprop(VV[49], ECL_SYM("INLINE",436), VVtemp[96]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[50], ECL_SYM("LOCATION",1862), VVtemp[97], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[50], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[107]);                         /*  NON-NEGATIVE-SHORT-FLOAT-P */
  si_put_sysprop(VV[50], ECL_SYM("INLINE",436), VVtemp[98]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[51], ECL_SYM("LOCATION",1862), VVtemp[99], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[51], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[108]);                         /*  POSITIVE-SHORT-FLOAT-P */
  si_put_sysprop(VV[51], ECL_SYM("INLINE",436), VVtemp[100]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[52], ECL_SYM("TYPE",871), VVtemp[101]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC51__lambda109,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[52], VVtemp[102], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[53], ECL_SYM("TYPE",871), VVtemp[101]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__lambda112,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[53], VVtemp[103], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[54], ECL_SYM("TYPE",871), VVtemp[104]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__lambda115,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[54], VVtemp[105], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[55], ECL_SYM("TYPE",871), VVtemp[104]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC54__lambda118,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[55], VVtemp[106], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[107]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[56], ECL_SYM("LOCATION",1862), VVtemp[108], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[56], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[109]);                         /*  NEGATIVE-SINGLE-FLOAT-P */
  si_put_sysprop(VV[56], ECL_SYM("INLINE",436), VVtemp[109]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[57], ECL_SYM("LOCATION",1862), VVtemp[110], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[57], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[110]);                         /*  NON-POSITIVE-SINGLE-FLOAT-P */
  si_put_sysprop(VV[57], ECL_SYM("INLINE",436), VVtemp[111]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[58], ECL_SYM("LOCATION",1862), VVtemp[112], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[58], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[111]);                         /*  NON-NEGATIVE-SINGLE-FLOAT-P */
  si_put_sysprop(VV[58], ECL_SYM("INLINE",436), VVtemp[113]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[59], ECL_SYM("LOCATION",1862), VVtemp[114], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[59], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[112]);                         /*  POSITIVE-SINGLE-FLOAT-P */
  si_put_sysprop(VV[59], ECL_SYM("INLINE",436), VVtemp[115]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[60], ECL_SYM("TYPE",871), VVtemp[116]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC59__lambda121,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[60], VVtemp[117], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[62], ECL_SYM("TYPE",871), VVtemp[116]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC60__lambda124,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[62], VVtemp[118], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[63], ECL_SYM("TYPE",871), VVtemp[119]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC61__lambda127,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[63], VVtemp[120], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[64], ECL_SYM("TYPE",871), VVtemp[119]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC62__lambda130,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[64], VVtemp[121], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[122]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[65], ECL_SYM("LOCATION",1862), VVtemp[123], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[65], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[113]);                         /*  NEGATIVE-DOUBLE-FLOAT-P */
  si_put_sysprop(VV[65], ECL_SYM("INLINE",436), VVtemp[124]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[66], ECL_SYM("LOCATION",1862), VVtemp[125], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[66], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[114]);                         /*  NON-POSITIVE-DOUBLE-FLOAT-P */
  si_put_sysprop(VV[66], ECL_SYM("INLINE",436), VVtemp[126]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[67], ECL_SYM("LOCATION",1862), VVtemp[127], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[67], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[115]);                         /*  NON-NEGATIVE-DOUBLE-FLOAT-P */
  si_put_sysprop(VV[67], ECL_SYM("INLINE",436), VVtemp[128]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[68], ECL_SYM("LOCATION",1862), VVtemp[129], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[68], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[116]);                         /*  POSITIVE-DOUBLE-FLOAT-P */
  si_put_sysprop(VV[68], ECL_SYM("INLINE",436), VVtemp[130]);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[69], ECL_SYM("TYPE",871), VVtemp[131]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC67__lambda133,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[69], VVtemp[132], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[71], ECL_SYM("TYPE",871), VVtemp[131]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC68__lambda136,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[71], VVtemp[133], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[72], ECL_SYM("TYPE",871), VVtemp[134]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC69__lambda139,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[72], VVtemp[135], T0);
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[73], ECL_SYM("TYPE",871), VVtemp[134]) /*  SET-DOCUMENTATION */;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC70__lambda142,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[73], VVtemp[136], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[137]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[74], ECL_SYM("LOCATION",1862), VVtemp[138], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[74], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[117]);                         /*  NEGATIVE-LONG-FLOAT-P */
  si_put_sysprop(VV[74], ECL_SYM("INLINE",436), VVtemp[139]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[75], ECL_SYM("LOCATION",1862), VVtemp[140], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[75], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[118]);                         /*  NON-POSITIVE-LONG-FLOAT-P */
  si_put_sysprop(VV[75], ECL_SYM("INLINE",436), VVtemp[141]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[76], ECL_SYM("LOCATION",1862), VVtemp[142], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[76], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[119]);                         /*  NON-NEGATIVE-LONG-FLOAT-P */
  si_put_sysprop(VV[76], ECL_SYM("INLINE",436), VVtemp[143]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[77], ECL_SYM("LOCATION",1862), VVtemp[144], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[77], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[120]);                         /*  POSITIVE-LONG-FLOAT-P */
  si_put_sysprop(VV[77], ECL_SYM("INLINE",436), VVtemp[145]);
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[78], ECL_SYM("LOCATION",1862), VVtemp[146], VVtemp[147]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[78], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[148]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[121]);                         /*  OF-TYPE         */
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[78], ECL_SYM("FUNCTION",398), VVtemp[149]) /*  SET-DOCUMENTATION */;
 {
  cl_object T0;
  cl_object volatile env0 = ECL_NIL;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC77__lambda146,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[78], ECL_SYM("COMPILER-MACRO",240), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[78], ECL_SYM("LOCATION",1862), VVtemp[150], VVtemp[151]) /*  ANNOTATE */;
 }
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[152]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[80], ECL_SYM("LOCATION",1862), VVtemp[153], VVtemp[154]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[80], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[155]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[123]);                         /*  TYPE=           */
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[80], ECL_SYM("FUNCTION",398), VVtemp[156]) /*  SET-DOCUMENTATION */;
  si_put_sysprop(VV[80], ECL_SYM("INLINE",436), VVtemp[157]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[81], ECL_SYM("LOCATION",1862), VVtemp[158], VVtemp[159]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[81], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[160]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[124]);                      /*  COERCEF         */
  ecl_function_dispatch(cl_env_copy,VV[83])(3, VV[81], ECL_SYM("FUNCTION",398), VVtemp[161]) /*  SET-DOCUMENTATION */;
}
