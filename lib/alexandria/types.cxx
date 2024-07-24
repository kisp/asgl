/*      Compiler: ECL 16.1.2                                          */
/*      Date: 2024/7/24 08:12 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: lib/alexandria/types.lisp                             */
#include <ecl/ecl-cmp.h>
#include "lib/alexandria/types.eclh"
/*      local function ARRAY-INDEX                                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC1array_index(cl_object v1)
{
 cl_object T0;
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
   si_dm_too_many_arguments(v1);
L8:;
   T0 = ecl_list1(v3length);
   value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), T0);
   return value0;
  }
 }
}
/*      local function ARRAY-LENGTH                                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC2array_length(cl_object v1)
{
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
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), v3length);
   return value0;
  }
 }
}
/*      local function NEGATIVE-FIXNUM                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC3negative_fixnum(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(-2305843009213693952), ecl_make_fixnum(-1));
  return value0;
 }
}
/*      local function NON-POSITIVE-FIXNUM                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC4non_positive_fixnum(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(-2305843009213693952), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function NON-NEGATIVE-FIXNUM                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC5non_negative_fixnum(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), ecl_make_fixnum(2305843009213693951));
  return value0;
 }
}
/*      local function POSITIVE-FIXNUM                                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC6positive_fixnum(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(1), ecl_make_fixnum(2305843009213693951));
  return value0;
 }
}
/*      function definition for NEGATIVE-FIXNUM-P                     */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L7negative_fixnum_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-INTEGER                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC11negative_integer(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ECL_SYM("*",18), ecl_make_fixnum(-1));
  return value0;
 }
}
/*      local function NON-POSITIVE-INTEGER                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC12non_positive_integer(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ECL_SYM("*",18), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function NON-NEGATIVE-INTEGER                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC13non_negative_integer(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-INTEGER                               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC14positive_integer(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(1), ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-INTEGER-P                    */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L15negative_integer_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-RATIONAL                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC19negative_rational(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",687), ECL_SYM("*",18), VV[19]);
  return value0;
 }
}
/*      local function NON-POSITIVE-RATIONAL                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC20non_positive_rational(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",687), ECL_SYM("*",18), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function NON-NEGATIVE-RATIONAL                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC21non_negative_rational(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",687), ecl_make_fixnum(0), ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-RATIONAL                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC22positive_rational(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("RATIONAL",687), VV[19], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-RATIONAL-P                   */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L23negative_rational_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-REAL                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC27negative_real(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",703), ECL_SYM("*",18), VV[19]);
  return value0;
 }
}
/*      local function NON-POSITIVE-REAL                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC28non_positive_real(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",703), ECL_SYM("*",18), ecl_make_fixnum(0));
  return value0;
 }
}
/*      local function NON-NEGATIVE-REAL                              */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC29non_negative_real(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",703), ecl_make_fixnum(0), ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-REAL                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC30positive_real(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("REAL",703), VV[19], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-REAL-P                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L31negative_real_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,ecl_make_fixnum(0))<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(ecl_make_fixnum(0),v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-FLOAT                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC35negative_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",374), ECL_SYM("*",18), VV[36]);
  return value0;
 }
}
/*      local function NON-POSITIVE-FLOAT                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC36non_positive_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",374), ECL_SYM("*",18), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function NON-NEGATIVE-FLOAT                             */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC37non_negative_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",374), cl_core.singlefloat_zero, ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-FLOAT                                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC38positive_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("FLOAT",374), VV[36], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-FLOAT-P                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L39negative_float_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-SHORT-FLOAT                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC43negative_short_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",756), ECL_SYM("*",18), VV[36]);
  return value0;
 }
}
/*      local function NON-POSITIVE-SHORT-FLOAT                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC44non_positive_short_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",756), ECL_SYM("*",18), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function NON-NEGATIVE-SHORT-FLOAT                       */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC45non_negative_short_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",756), cl_core.singlefloat_zero, ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-SHORT-FLOAT                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC46positive_short_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SHORT-FLOAT",756), VV[36], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-SHORT-FLOAT-P                */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L47negative_short_float_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-SINGLE-FLOAT                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC51negative_single_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",778), ECL_SYM("*",18), VV[36]);
  return value0;
 }
}
/*      local function NON-POSITIVE-SINGLE-FLOAT                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC52non_positive_single_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",778), ECL_SYM("*",18), cl_core.singlefloat_zero);
  return value0;
 }
}
/*      local function NON-NEGATIVE-SINGLE-FLOAT                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC53non_negative_single_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",778), cl_core.singlefloat_zero, ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-SINGLE-FLOAT                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC54positive_single_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("SINGLE-FLOAT",778), VV[36], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-SINGLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L55negative_single_float_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.singlefloat_zero)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SINGLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.singlefloat_zero,v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-DOUBLE-FLOAT                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC59negative_double_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",315), ECL_SYM("*",18), VV[61]);
  return value0;
 }
}
/*      local function NON-POSITIVE-DOUBLE-FLOAT                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC60non_positive_double_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",315), ECL_SYM("*",18), cl_core.doublefloat_zero);
  return value0;
 }
}
/*      local function NON-NEGATIVE-DOUBLE-FLOAT                      */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC61non_negative_double_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",315), cl_core.doublefloat_zero, ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-DOUBLE-FLOAT                          */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC62positive_double_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("DOUBLE-FLOAT",315), VV[61], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-DOUBLE-FLOAT-P               */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L63negative_double_float_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.doublefloat_zero)<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.doublefloat_zero)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.doublefloat_zero,v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_DOUBLE_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.doublefloat_zero,v1n)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function NEGATIVE-LONG-FLOAT                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC67negative_long_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",508), ECL_SYM("*",18), VV[70]);
  return value0;
 }
}
/*      local function NON-POSITIVE-LONG-FLOAT                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC68non_positive_long_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",508), ECL_SYM("*",18), cl_core.longfloat_zero);
  return value0;
 }
}
/*      local function NON-NEGATIVE-LONG-FLOAT                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC69non_negative_long_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",508), cl_core.longfloat_zero, ECL_SYM("*",18));
  return value0;
 }
}
/*      local function POSITIVE-LONG-FLOAT                            */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC70positive_long_float(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1)) { goto L1; }
  si_dm_too_many_arguments(v1);
L1:;
  value0 = cl_list(3, ECL_SYM("LONG-FLOAT",508), VV[70], ECL_SYM("*",18));
  return value0;
 }
}
/*      function definition for NEGATIVE-LONG-FLOAT-P                 */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L71negative_long_float_p(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.longfloat_zero)<0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(v1n,cl_core.longfloat_zero)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.longfloat_zero,v1n)<=0);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LONG_FLOAT_P(v1n))) { goto L2; }
  value0 = ecl_make_bool(ecl_number_compare(cl_core.longfloat_zero,v1n)<0);
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
 cl_object env0;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1type,env0);                /*  TYPE            */
  {
   cl_object v2;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC75__g105,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure G105                                                  */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC75__g105(cl_narg narg, cl_object v1thing, ...)
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
/*      local function OF-TYPE                                        */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC77of_type(cl_object v1, cl_object v2env)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4type;
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
    v4type = v5;
   }
   if (Null(v3)) { goto L11; }
   si_dm_too_many_arguments(v1);
L11:;
   if (Null(cl_constantp(2, v4type, v2env))) { goto L13; }
   {
    cl_object v5thing;
    v5thing = cl_gensym(1, VV[79]);
    T0 = ecl_list1(v5thing);
    T1 = cl_list(3, ECL_SYM("TYPEP",875), v5thing, v4type);
    value0 = cl_list(3, ECL_SYM("LAMBDA",452), T0, T1);
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
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  SUB             */
   cl_object v5;                                  /*  OK              */
   value0 = cl_subtypep(2, v1type1, v2type2);
   v4 = value0;
   v5 = cl_env_copy->values[1];
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
    v7 = cl_env_copy->values[1];
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
    v5type_spec = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
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
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC79__g115,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5type_spec,ECL_NIL);
     v12si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L19; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("COERCE",231), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[82],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v12si__all_vars, T7, v10);
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
      if (!(ECL_LISTP(v4si___reference))) { goto L39; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L39; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(4, ECL_SYM("COERCE",231), v11, v5type_spec, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L38;
L39:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("COERCE",231), v11, T3);
L38:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12si__all_vars,v15si__let_list);
      v15si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[82],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*      local function G115                                           */
/*      optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object LC79__g115(cl_object v1si__v)
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

#include "lib/alexandria/types.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclYKIWc8zWYNLAM_kSh2dC71(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("/home/packer/ws/github/kisp/asgl/lib/alexandria/types.lisp");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclYKIWc8zWYNLAM_kSh2dC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
 {
  cl_object T0;
  si_set_documentation(3, VV[0], ECL_SYM("TYPE",869), VVtemp[1]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC1array_index,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[0], VVtemp[2], T0);
 }
 {
  cl_object T0;
  si_set_documentation(3, VV[1], ECL_SYM("TYPE",869), VVtemp[3]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC2array_length,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[1], VVtemp[4], T0);
 }
 {
  cl_object T0;
  si_set_documentation(3, VV[2], ECL_SYM("TYPE",869), VVtemp[5]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC3negative_fixnum,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[2], VVtemp[6], T0);
  si_set_documentation(3, VV[3], ECL_SYM("TYPE",869), VVtemp[7]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC4non_positive_fixnum,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[3], VVtemp[8], T0);
  si_set_documentation(3, VV[4], ECL_SYM("TYPE",869), VVtemp[9]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC5non_negative_fixnum,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[4], VVtemp[10], T0);
  si_set_documentation(3, VV[5], ECL_SYM("TYPE",869), VVtemp[11]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC6positive_fixnum,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[5], VVtemp[12], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[13]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LOCATION",1777), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[6], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[83]);                          /*  NEGATIVE-FIXNUM-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LOCATION",1777), VVtemp[17], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[7], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[84]);                          /*  NON-POSITIVE-FIXNUM-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LOCATION",1777), VVtemp[18], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[8], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[85]);                          /*  NON-NEGATIVE-FIXNUM-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LOCATION",1777), VVtemp[19], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[9], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[86]);                          /*  POSITIVE-FIXNUM-P */
  si_set_documentation(3, VV[10], ECL_SYM("TYPE",869), VVtemp[20]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC11negative_integer,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[10], VVtemp[21], T0);
  si_set_documentation(3, VV[11], ECL_SYM("TYPE",869), VVtemp[22]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC12non_positive_integer,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[11], VVtemp[23], T0);
  si_set_documentation(3, VV[12], ECL_SYM("TYPE",869), VVtemp[24]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC13non_negative_integer,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[12], VVtemp[25], T0);
  si_set_documentation(3, VV[13], ECL_SYM("TYPE",869), VVtemp[26]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC14positive_integer,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[13], VVtemp[27], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[28]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[14], ECL_SYM("LOCATION",1777), VVtemp[29], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[14], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[87]);                          /*  NEGATIVE-INTEGER-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LOCATION",1777), VVtemp[30], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[15], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[88]);                          /*  NON-POSITIVE-INTEGER-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[16], ECL_SYM("LOCATION",1777), VVtemp[31], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[16], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[89]);                          /*  NON-NEGATIVE-INTEGER-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[17], ECL_SYM("LOCATION",1777), VVtemp[32], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[17], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[90]);                          /*  POSITIVE-INTEGER-P */
  si_set_documentation(3, VV[18], ECL_SYM("TYPE",869), VVtemp[33]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC19negative_rational,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[18], VVtemp[34], T0);
  si_set_documentation(3, VV[20], ECL_SYM("TYPE",869), VVtemp[33]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC20non_positive_rational,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[20], VVtemp[35], T0);
  si_set_documentation(3, VV[21], ECL_SYM("TYPE",869), VVtemp[36]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC21non_negative_rational,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[21], VVtemp[37], T0);
  si_set_documentation(3, VV[22], ECL_SYM("TYPE",869), VVtemp[36]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC22positive_rational,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[22], VVtemp[38], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[39]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LOCATION",1777), VVtemp[40], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[23], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[91]);                          /*  NEGATIVE-RATIONAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LOCATION",1777), VVtemp[41], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[24], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[92]);                          /*  NON-POSITIVE-RATIONAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LOCATION",1777), VVtemp[42], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[25], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[93]);                          /*  NON-NEGATIVE-RATIONAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LOCATION",1777), VVtemp[43], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[26], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[94]);                          /*  POSITIVE-RATIONAL-P */
  si_set_documentation(3, VV[27], ECL_SYM("TYPE",869), VVtemp[44]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC27negative_real,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[27], VVtemp[45], T0);
  si_set_documentation(3, VV[28], ECL_SYM("TYPE",869), VVtemp[44]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC28non_positive_real,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[28], VVtemp[46], T0);
  si_set_documentation(3, VV[29], ECL_SYM("TYPE",869), VVtemp[47]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC29non_negative_real,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[29], VVtemp[48], T0);
  si_set_documentation(3, VV[30], ECL_SYM("TYPE",869), VVtemp[47]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC30positive_real,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[30], VVtemp[49], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[50]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[31], ECL_SYM("LOCATION",1777), VVtemp[51], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[31], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[95]);                          /*  NEGATIVE-REAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[32], ECL_SYM("LOCATION",1777), VVtemp[52], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[32], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[96]);                          /*  NON-POSITIVE-REAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[33], ECL_SYM("LOCATION",1777), VVtemp[53], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[33], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[97]);                          /*  NON-NEGATIVE-REAL-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[34], ECL_SYM("LOCATION",1777), VVtemp[54], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[34], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[98]);                          /*  POSITIVE-REAL-P */
  si_set_documentation(3, VV[35], ECL_SYM("TYPE",869), VVtemp[55]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC35negative_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[35], VVtemp[56], T0);
  si_set_documentation(3, VV[37], ECL_SYM("TYPE",869), VVtemp[55]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC36non_positive_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[37], VVtemp[57], T0);
  si_set_documentation(3, VV[38], ECL_SYM("TYPE",869), VVtemp[58]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC37non_negative_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[38], VVtemp[59], T0);
  si_set_documentation(3, VV[39], ECL_SYM("TYPE",869), VVtemp[58]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC38positive_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[39], VVtemp[60], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[61]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LOCATION",1777), VVtemp[62], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[40], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[99]);                          /*  NEGATIVE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LOCATION",1777), VVtemp[63], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[41], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[100]);                         /*  NON-POSITIVE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[42], ECL_SYM("LOCATION",1777), VVtemp[64], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[42], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[101]);                         /*  NON-NEGATIVE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[43], ECL_SYM("LOCATION",1777), VVtemp[65], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[43], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[102]);                         /*  POSITIVE-FLOAT-P */
  si_set_documentation(3, VV[44], ECL_SYM("TYPE",869), VVtemp[66]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC43negative_short_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[44], VVtemp[67], T0);
  si_set_documentation(3, VV[45], ECL_SYM("TYPE",869), VVtemp[66]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC44non_positive_short_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[45], VVtemp[68], T0);
  si_set_documentation(3, VV[46], ECL_SYM("TYPE",869), VVtemp[69]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC45non_negative_short_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[46], VVtemp[70], T0);
  si_set_documentation(3, VV[47], ECL_SYM("TYPE",869), VVtemp[69]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC46positive_short_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[47], VVtemp[71], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[72]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[48], ECL_SYM("LOCATION",1777), VVtemp[73], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[48], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[103]);                         /*  NEGATIVE-SHORT-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[49], ECL_SYM("LOCATION",1777), VVtemp[74], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[49], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[104]);                         /*  NON-POSITIVE-SHORT-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[50], ECL_SYM("LOCATION",1777), VVtemp[75], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[50], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[105]);                         /*  NON-NEGATIVE-SHORT-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[51], ECL_SYM("LOCATION",1777), VVtemp[76], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[51], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[106]);                         /*  POSITIVE-SHORT-FLOAT-P */
  si_set_documentation(3, VV[52], ECL_SYM("TYPE",869), VVtemp[77]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC51negative_single_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[52], VVtemp[78], T0);
  si_set_documentation(3, VV[53], ECL_SYM("TYPE",869), VVtemp[77]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC52non_positive_single_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[53], VVtemp[79], T0);
  si_set_documentation(3, VV[54], ECL_SYM("TYPE",869), VVtemp[80]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC53non_negative_single_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[54], VVtemp[81], T0);
  si_set_documentation(3, VV[55], ECL_SYM("TYPE",869), VVtemp[80]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC54positive_single_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[55], VVtemp[82], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[83]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[56], ECL_SYM("LOCATION",1777), VVtemp[84], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[56], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[107]);                         /*  NEGATIVE-SINGLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[57], ECL_SYM("LOCATION",1777), VVtemp[85], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[57], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[108]);                         /*  NON-POSITIVE-SINGLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[58], ECL_SYM("LOCATION",1777), VVtemp[86], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[58], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[109]);                         /*  NON-NEGATIVE-SINGLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[59], ECL_SYM("LOCATION",1777), VVtemp[87], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[59], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[110]);                         /*  POSITIVE-SINGLE-FLOAT-P */
  si_set_documentation(3, VV[60], ECL_SYM("TYPE",869), VVtemp[88]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC59negative_double_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[60], VVtemp[89], T0);
  si_set_documentation(3, VV[62], ECL_SYM("TYPE",869), VVtemp[88]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC60non_positive_double_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[62], VVtemp[90], T0);
  si_set_documentation(3, VV[63], ECL_SYM("TYPE",869), VVtemp[91]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC61non_negative_double_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[63], VVtemp[92], T0);
  si_set_documentation(3, VV[64], ECL_SYM("TYPE",869), VVtemp[91]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC62positive_double_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[64], VVtemp[93], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[94]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[65], ECL_SYM("LOCATION",1777), VVtemp[95], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[65], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[111]);                         /*  NEGATIVE-DOUBLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[66], ECL_SYM("LOCATION",1777), VVtemp[96], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[66], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[112]);                         /*  NON-POSITIVE-DOUBLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[67], ECL_SYM("LOCATION",1777), VVtemp[97], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[67], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[113]);                         /*  NON-NEGATIVE-DOUBLE-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[68], ECL_SYM("LOCATION",1777), VVtemp[98], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[68], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[114]);                         /*  POSITIVE-DOUBLE-FLOAT-P */
  si_set_documentation(3, VV[69], ECL_SYM("TYPE",869), VVtemp[99]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC67negative_long_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[69], VVtemp[100], T0);
  si_set_documentation(3, VV[71], ECL_SYM("TYPE",869), VVtemp[99]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC68non_positive_long_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[71], VVtemp[101], T0);
  si_set_documentation(3, VV[72], ECL_SYM("TYPE",869), VVtemp[102]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC69non_negative_long_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[72], VVtemp[103], T0);
  si_set_documentation(3, VV[73], ECL_SYM("TYPE",869), VVtemp[102]);
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC70positive_long_float,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  si_do_deftype(3, VV[73], VVtemp[104], T0);
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[105]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[74], ECL_SYM("LOCATION",1777), VVtemp[106], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[74], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[115]);                         /*  NEGATIVE-LONG-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[75], ECL_SYM("LOCATION",1777), VVtemp[107], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[75], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[116]);                         /*  NON-POSITIVE-LONG-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[76], ECL_SYM("LOCATION",1777), VVtemp[108], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[76], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[117]);                         /*  NON-NEGATIVE-LONG-FLOAT-P */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[77], ECL_SYM("LOCATION",1777), VVtemp[109], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[77], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[118]);                         /*  POSITIVE-LONG-FLOAT-P */
 }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[78], ECL_SYM("LOCATION",1777), VVtemp[110], VVtemp[111]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[78], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[112]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[119]);                         /*  OF-TYPE         */
  si_set_documentation(3, VV[78], ECL_SYM("FUNCTION",396), VVtemp[113]);
 {
  cl_object T0;
  {
   cl_object volatile v1;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC77of_type,ECL_NIL,Cblock,2);
   T0 = v1;
  }
  si_put_sysprop(VV[78], ECL_SYM("COMPILER-MACRO",238), T0);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[78], ECL_SYM("LOCATION",1777), VVtemp[114], VVtemp[115]) /*  ANNOTATE */;
 }
  (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[116]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[80], ECL_SYM("LOCATION",1777), VVtemp[117], VVtemp[118]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[80], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[119]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[120]);                         /*  TYPE=           */
  si_set_documentation(3, VV[80], ECL_SYM("FUNCTION",396), VVtemp[120]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[81], ECL_SYM("LOCATION",1777), VVtemp[121], VVtemp[122]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1771))(4, VV[81], ECL_SYM("LAMBDA-LIST",998), ECL_NIL, VVtemp[123]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[121]);                      /*  COERCEF         */
  si_set_documentation(3, VV[81], ECL_SYM("FUNCTION",396), VVtemp[124]);
}
