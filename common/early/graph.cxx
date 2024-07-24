/*      Compiler: ECL 24.5.10                                         */
/*      Date: 2024/7/24 06:55 (yyyy/mm/dd)                            */
/*      Machine: Linux 6.9.7-arch1-1 x86_64                           */
/*      Source: /home/packer/ws/github/kisp/asgl/common/early/graph.lisp */
#include <ecl/ecl-cmp.h>
#include "common/early/graph.eclh"
/*      function definition for %%ORDER                               */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L1__order(cl_object v1graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v1graph) /*  SIMPLE-ARRAY-P */;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v1graph);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  value0 = ecl_make_fixnum(ecl_length(v1graph));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      function definition for %%PARENTS                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L2__parents(cl_object v1graph, cl_object v2node)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v1graph) /*  SIMPLE-ARRAY-P */;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v1graph);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   bool v3;
   v3 = ECL_FIXNUMP(v2node);
   if (ecl_unlikely(!(v3)))
         FEwrong_type_argument(VV[1],v2node);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
  }
  {
   cl_object v3;
   v3 = v1graph;
   T0 = v3;
   {
    cl_fixnum v4;
    {
     cl_fixnum v5;
     v5 = ecl_fixnum(v2node);
     if (ecl_unlikely((v5)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(v5),(v3)->vector.dim);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     v4 = v5;
    }
    value0 = ecl_aref_unsafe(T0,v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      function definition for (SETF %%PARENTS)                      */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L3_setf___parents_(cl_object v1value, cl_object v2graph, cl_object v3node)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v2graph) /*  SIMPLE-ARRAY-P */;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v2graph);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  {
   bool v4;
   v4 = ECL_FIXNUMP(v3node);
   if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(VV[1],v3node);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
  }
  {
   cl_object v4;
   v4 = v2graph;
   T0 = v4;
   {
    cl_fixnum v5;
    {
     cl_fixnum v6;
     v6 = ecl_fixnum(v3node);
     if (ecl_unlikely((v6)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v6),(v4)->vector.dim);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     v5 = v6;
    }
    value0 = ecl_aset_unsafe(T0,v5,v1value);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*      local function DO-%%PARENTS                                   */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC4do___parents(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6node;
   cl_object v7parents;
   cl_object v8return;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v6node = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v7parents = v9;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v8return = v9;
    goto L21;
   }
L22:;
   v8return = ECL_NIL;
L21:;
   if (Null(v5)) { goto L27; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L27:;
   T0 = cl_list(3, v6node, v7parents, v8return);
   T1 = ecl_append(v3,VV[6]);
   value0 = cl_listX(3, ECL_SYM("DOLIST",315), T0, T1);
   return value0;
  }
 }
}
/*      function definition for %%PARENTS-ADD                         */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L5__parents_add(cl_object v1node, cl_object v2parents)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   bool v3;
   v3 = ECL_FIXNUMP(v1node);
   if (ecl_unlikely(!(v3)))
         FEwrong_type_argument(VV[1],v1node);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
  }
  value0 = CONS(v1node,v2parents);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*      local function %%PUSH-PARENTS                                 */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC6__push_parents(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4obj;
   cl_object v5place;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v6;
    v6 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4obj = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L9:;
   {
    cl_object v6;
    v6 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v5place = v6;
   }
   if (Null(v3)) { goto L14; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L14:;
   {
    cl_object v7;                                 /*  DUMMIES         */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  NEWVAL          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",412)->symbol.gfdef))->cfun.entry(2, v5place, v2env) /*  GET-SETF-EXPANSION */;
    {
     v7 = value0;
     v8 = cl_env_copy->values[1];
     v9 = cl_env_copy->values[2];
     v10 = cl_env_copy->values[3];
     v11 = cl_env_copy->values[4];
    }
    {
     cl_object v12g;
     v12g = cl_gensym(0);
     T0 = cl_list(2, v12g, v4obj);
     {
      cl_object v13;
      v13 = (ECL_SYM("LIST",483)->symbol.gfdef);
      {
       cl_object v14;
       cl_object v15;
       v14 = ECL_NIL;
       {
        cl_object v16;
        v16 = v7;
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        v15 = v16;
       }
       {
        cl_object v16;
        cl_object v17;
        v16 = ECL_NIL;
        {
         cl_object v18;
         v18 = v8;
         if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 0;
         v17 = v18;
        }
        {
         cl_object v18;
         cl_object v19;
         v18 = ecl_list1(ECL_NIL);
         v19 = v18;
L30:;
         if (!(v15==ECL_NIL)) { goto L32; }
         goto L31;
L32:;
         v14 = ECL_CONS_CAR(v15);
         {
          cl_object v20;
          v20 = ECL_CONS_CDR(v15);
          if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
          value0 = ECL_NIL;
          cl_env_copy->nvalues = 0;
          v15 = v20;
         }
         if (!(v17==ECL_NIL)) { goto L40; }
         goto L31;
L40:;
         v16 = ECL_CONS_CAR(v17);
         {
          cl_object v20;
          v20 = ECL_CONS_CDR(v17);
          if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
          value0 = ECL_NIL;
          cl_env_copy->nvalues = 0;
          v17 = v20;
         }
         {
          cl_object v20;
          v20 = v19;
          if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
          value0 = ECL_NIL;
          cl_env_copy->nvalues = 0;
          T2 = v20;
         }
         T3 = ecl_function_dispatch(cl_env_copy,v13)(2, v14, v16);
         v19 = ecl_list1(T3);
         (ECL_CONS_CDR(T2)=v19,T2);
         goto L30;
L31:;
         T1 = _ecl_cdr(v18);
         goto L18;
        }
       }
      }
     }
L18:;
     T2 = _ecl_car(v9);
     T3 = cl_list(3, VV[7], v12g, v11);
     T4 = cl_list(2, T2, T3);
     T5 = _ecl_cdr(v9);
     T6 = CONS(T4,T5);
     T7 = ecl_append(T1,T6);
     T8 = CONS(T0,T7);
     value0 = cl_list(3, ECL_SYM("LET*",480), T8, v10);
     return value0;
    }
   }
  }
 }
}
/*      function definition for ORDER                                 */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L7order(cl_object v1graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v2graph;
   {
    cl_object v3;
    v3 = v1graph;
    T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v3) /*  SIMPLE-ARRAY-P */;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v3);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v2graph = v3;
   }
   value0 = ecl_make_fixnum(ecl_length(v2graph));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for SIZE                                  */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L8size(cl_object v1graph)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = (ECL_SYM("+",16)->symbol.gfdef);
  T1 = (ECL_SYM("LENGTH",478)->symbol.gfdef);
  value0 = cl_reduce(4, T0, v1graph, ECL_SYM("KEY",1294), T1);
  return value0;
 }
}
/*      function definition for INDEGREES                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L9indegrees(cl_object v1graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = (ECL_SYM("LENGTH",478)->symbol.gfdef);
  value0 = cl_map(3, ECL_SYM("VECTOR",900), T0, v1graph);
  return value0;
 }
}
/*      local function DO-EDGES                                       */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC10do_edges(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6from;
   cl_object v7to;
   cl_object v8graph;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v6from = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v7to = v9;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L22:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v8graph = v9;
   }
   if (Null(v5)) { goto L27; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L27:;
   T0 = cl_list(2, v6from, v7to);
   T1 = cl_listX(3, ECL_SYM("LAMBDA",454), T0, v3);
   value0 = cl_list(3, VV[14], T1, v8graph);
   return value0;
  }
 }
}
/*      local function DO-PARENTS                                     */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC11do_parents(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6node;
   cl_object v7parents;
   cl_object v8graph;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v6node = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v7parents = v9;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L22:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v8graph = v9;
   }
   if (Null(v5)) { goto L27; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L27:;
   T0 = cl_list(2, v6node, v7parents);
   T1 = cl_listX(3, ECL_SYM("LAMBDA",454), T0, v3);
   value0 = cl_list(3, VV[16], T1, v8graph);
   return value0;
  }
 }
}
/*      local function DO-PARENTS-GRANDPARENTS                        */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC12do_parents_grandparents(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6node;
   cl_object v7parents_grandparents;
   cl_object v8graph;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v6node = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v7parents_grandparents = v9;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L22:;
   {
    cl_object v9;
    v9 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v8graph = v9;
   }
   if (Null(v5)) { goto L27; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L27:;
   T0 = cl_list(2, v6node, v7parents_grandparents);
   T1 = cl_listX(3, ECL_SYM("LAMBDA",454), T0, v3);
   value0 = cl_list(3, VV[18], T1, v8graph);
   return value0;
  }
 }
}
/*      function definition for OUTDEGREES                            */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L14outdegrees(cl_object v1graph)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object env1 = env0;
   {
    cl_object v2;
    v2 = L7order(v1graph);
    T1 = si_make_pure_array(ECL_T, v2, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
    T0 = si_fill_array_with_elt(T1, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
   }
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  VECTOR          */
   {
    cl_object v2;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC13__lambda100,env1,Cblock,2);
    T0 = v2;
   }
   L19map_edges(T0, v1graph);
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      closure LAMBDA100                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC13__lambda100(cl_narg narg, cl_object v1from, cl_object v2to, ...)
{
 cl_object T0, T1;
 cl_object CLV0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  VECTOR          */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3;
   {
    cl_object v4;
    v4 = ECL_CONS_CAR(CLV0);
    T1 = v4;
    {
     cl_fixnum v5;
     {
      cl_object v6;
      v6 = v1from;
      if (ecl_unlikely((ecl_fixnum(v6))>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(ecl_fixnum(v6)),(v4)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v5 = ecl_fixnum(v6);
     }
     T0 = ecl_aref_unsafe(T1,v5);
    }
   }
   v3 = ecl_plus(T0,ecl_make_fixnum(1));
   {
    cl_object v4;
    v4 = ECL_CONS_CAR(CLV0);
    T0 = v4;
    {
     cl_fixnum v5;
     {
      cl_object v6;
      v6 = v1from;
      if (ecl_unlikely((ecl_fixnum(v6))>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(ecl_fixnum(v6)),(v4)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v5 = ecl_fixnum(v6);
     }
     value0 = ecl_aset_unsafe(T0,v5,v3);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
 }
}
/*      function definition for ADD-EDGE                              */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L15add_edge(cl_object v1graph, cl_object v2from, cl_object v3to)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v4;
   {
    cl_object v5;
    cl_fixnum v6node;
    {
     cl_object v7graph;
     cl_fixnum v8node;
     {
      cl_object v9;
      v9 = v1graph;
      T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v9) /*  SIMPLE-ARRAY-P */;
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v9);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v7graph = v9;
     }
     {
      cl_object v9;
      v9 = v3to;
      {
       bool v10;
       v10 = ECL_FIXNUMP(v9);
       if (ecl_unlikely(!(v10)))
         FEwrong_type_argument(VV[1],v9);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
      }
      v8node = ecl_fixnum(v9);
     }
     {
      cl_object v9;
      v9 = v7graph;
      T0 = v9;
      {
       cl_fixnum v10;
       {
        cl_fixnum v11;
        v11 = v8node;
        if (ecl_unlikely((v11)>=(v9)->vector.dim))
           FEwrong_index(ECL_NIL,v9,-1,ecl_make_fixnum(v11),(v9)->vector.dim);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        v10 = v11;
       }
       v5 = ecl_aref_unsafe(T0,v10);
      }
     }
    }
    {
     cl_object v7;
     v7 = v2from;
     {
      bool v8;
      v8 = ECL_FIXNUMP(v7);
      if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(VV[1],v7);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
     }
     v6node = ecl_fixnum(v7);
    }
    v4 = CONS(ecl_make_fixnum(v6node),v5);
   }
   {
    cl_object v5graph;
    cl_fixnum v6node;
    {
     cl_object v7;
     v7 = v1graph;
     T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v7) /*  SIMPLE-ARRAY-P */;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v7);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     v5graph = v7;
    }
    {
     cl_object v7;
     v7 = v3to;
     {
      bool v8;
      v8 = ECL_FIXNUMP(v7);
      if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(VV[1],v7);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
     }
     v6node = ecl_fixnum(v7);
    }
    {
     cl_object v7;
     v7 = v5graph;
     T0 = v7;
     {
      cl_fixnum v8;
      {
       cl_fixnum v9;
       v9 = v6node;
       if (ecl_unlikely((v9)>=(v7)->vector.dim))
           FEwrong_index(ECL_NIL,v7,-1,ecl_make_fixnum(v9),(v7)->vector.dim);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v8 = v9;
      }
      value0 = ecl_aset_unsafe(T0,v8,v4);
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*      function definition for MAKE-GRAPH-FROM-ADJ                   */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L16make_graph_from_adj(cl_object v1adj)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_fixnum v2order;
   cl_object v3graph;
   v2order = ecl_array_dimension(v1adj,0);
   v3graph = si_make_pure_array(ECL_T, ecl_make_fixnum(v2order), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   {
    cl_object v4i;
    v4i = ecl_make_fixnum(0);
    goto L6;
L5:;
    {
     cl_object v5j;
     v5j = ecl_make_fixnum(0);
     goto L11;
L10:;
     {
      cl_object v6;
      v6 = v1adj;
      T1 = v6;
      {
       cl_fixnum v7;
       {
        cl_fixnum v8dim6;
        cl_fixnum v9dim7;
        cl_fixnum v10;
        v8dim6 = (v6)->array.dims[0];
        v9dim7 = (v6)->array.dims[1];
        v10 = 0;
        if (ecl_unlikely((v6)->array.rank != (2)))
            FEwrong_dimensions(v6,2);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        {
         cl_fixnum v11;
         v11 = ecl_fixnum(v4i);
         if (ecl_unlikely((v11)>=(v8dim6)))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v11),v8dim6);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 0;
         v10 = (v10)+(v11);
        }
        v10 = (v10)*(v9dim7);
        {
         cl_fixnum v11;
         v11 = ecl_fixnum(v5j);
         if (ecl_unlikely((v11)>=(v9dim7)))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v11),v9dim7);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 0;
         v10 = (v10)+(v11);
        }
        v7 = v10;
       }
       T0 = ecl_aref_unsafe(T1,v7);
      }
     }
     if (!((ecl_make_fixnum(1))==(T0))) { goto L13; }
     L15add_edge(v3graph, v4i, v5j);
L13:;
     v5j = ecl_one_plus(v5j);
L11:;
     if (!(ecl_lower(v5j,ecl_make_fixnum(v2order)))) { goto L35; }
     goto L10;
L35:;
    }
    v4i = ecl_one_plus(v4i);
L6:;
    if (!(ecl_lower(v4i,ecl_make_fixnum(v2order)))) { goto L39; }
    goto L5;
L39:;
   }
   value0 = v3graph;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MAP-NODES                             */
/*      optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L17map_nodes(cl_object v1fn, cl_object v2graph)
{
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_fixnum v3;
  v3 = ecl_length(v2graph);
  {
   cl_fixnum v4node;
   v4node = 0;
   goto L4;
L3:;
   ecl_function_dispatch(cl_env_copy,v1fn)(1, ecl_make_fixnum(v4node));
   v4node = (v4node)+1;
L4:;
   if (!((v4node)<(v3))) { goto L9; }
   goto L3;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      local function DO-NODES                                       */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC18do_nodes(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6node;
   cl_object v7graph;
   v3 = ECL_CONS_CDR(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L3:;
   {
    cl_object v8;
    v8 = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4 = v8;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L10:;
   {
    cl_object v8;
    v8 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v6node = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[29])(1, v1) /*  DM-TOO-FEW-ARGUMENTS */;
L16:;
   {
    cl_object v8;
    v8 = ECL_CONS_CAR(v5);
    v5 = ECL_CONS_CDR(v5);
    v7graph = v8;
   }
   if (Null(v5)) { goto L21; }
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1) /*  DM-TOO-MANY-ARGUMENTS */;
L21:;
   T0 = ecl_list1(v6node);
   T1 = cl_listX(3, ECL_SYM("LAMBDA",454), T0, v3);
   value0 = cl_list(3, VV[22], T1, v7graph);
   return value0;
  }
 }
}
/*      function definition for MAP-EDGES                             */
/*      optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L19map_edges(cl_object v1fn, cl_object v2graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_fixnum v3;
  v3 = ecl_length(v2graph);
  {
   cl_fixnum v4i;
   v4i = 0;
   goto L4;
L3:;
   {
    cl_object v5;
    {
     cl_object v6;
     v6 = v2graph;
     T0 = v6;
     {
      cl_fixnum v7;
      {
       cl_fixnum v8;
       v8 = v4i;
       if (ecl_unlikely((v8)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v8),(v6)->vector.dim);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v7 = v8;
      }
      v5 = ecl_aref_unsafe(T0,v7);
     }
    }
    goto L15;
L14:;
    {
     cl_object v6j;
     v6j = _ecl_car(v5);
     ecl_function_dispatch(cl_env_copy,v1fn)(2, v6j, ecl_make_fixnum(v4i));
    }
    v5 = _ecl_cdr(v5);
L15:;
    if (Null(v5)) { goto L22; }
    goto L14;
L22:;
   }
   v4i = (v4i)+1;
L4:;
   if (!((v4i)<(v3))) { goto L26; }
   goto L3;
L26:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*      function definition for MAP-PARENTS                           */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L21map_parents(cl_object v1fn, cl_object v2graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1fn,env0);                  /*  FN              */
  CLV1 = env0 = CONS(v2graph,env0);               /*  GRAPH           */
  {
   cl_object v3;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC20__lambda190,env0,Cblock,1);
   T0 = v3;
  }
  value0 = L17map_nodes(T0, ECL_CONS_CAR(CLV1));
  return value0;
 }
}
/*      closure LAMBDA190                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC20__lambda190(cl_narg narg, cl_object v1node, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  GRAPH           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2graph;
   cl_fixnum v3node;
   {
    cl_object v4;
    v4 = ECL_CONS_CAR(CLV1);
    T1 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v4) /*  SIMPLE-ARRAY-P */;
    if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v4);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v2graph = v4;
   }
   {
    cl_object v4;
    v4 = v1node;
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(VV[1],v4);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
    v3node = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = v2graph;
    T1 = v4;
    {
     cl_fixnum v5;
     {
      cl_fixnum v6;
      v6 = v3node;
      if (ecl_unlikely((v6)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v6),(v4)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v5 = v6;
     }
     T0 = ecl_aref_unsafe(T1,v5);
    }
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, v1node, T0);
  return value0;
 }
 }
}
/*      function definition for MAP-PARENTS-GRANDPARENTS              */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object L24map_parents_grandparents(cl_object v1fn, cl_object v2graph)
{
 cl_object T0;
 cl_object env0 = ECL_NIL;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1fn,env0);                  /*  FN              */
  CLV1 = env0 = CONS(v2graph,env0);               /*  GRAPH           */
  {
   cl_object v3;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC23__lambda193,env0,Cblock,2);
   T0 = v3;
  }
  value0 = L21map_parents(T0, ECL_CONS_CAR(CLV1));
  return value0;
 }
}
/*      closure LAMBDA193                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC23__lambda193(cl_narg narg, cl_object v1node, cl_object v2parents, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  GRAPH           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3;
   v3 = (ECL_SYM("CONS",253)->symbol.gfdef);
   {
    cl_object v4;
    cl_object v5;
    v4 = ECL_NIL;
    {
     cl_object v6;
     v6 = v2parents;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
     v5 = v6;
    }
    {
     cl_object v6;
     cl_object v7;
     cl_object v8;
     {
      cl_object v9;
      {
       cl_object v10;
       v10 = ecl_make_cclosure_va((cl_objectfn)LC22__lambda210,env0,Cblock,1);
       v9 = v10;
      }
      {
       cl_object v10;
       cl_object v11;
       v10 = ECL_NIL;
       {
        cl_object v12;
        v12 = v2parents;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 0;
        v11 = v12;
       }
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L15:;
        if (!(v11==ECL_NIL)) { goto L17; }
        goto L16;
L17:;
        v10 = ECL_CONS_CAR(v11);
        {
         cl_object v14;
         v14 = ECL_CONS_CDR(v11);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 0;
         v11 = v14;
        }
        {
         cl_object v14;
         v14 = v13;
         if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 0;
         T1 = v14;
        }
        T2 = ecl_function_dispatch(cl_env_copy,v9)(1, v10);
        v13 = ecl_list1(T2);
        (ECL_CONS_CDR(T1)=v13,T1);
        goto L15;
L16:;
        v6 = _ecl_cdr(v12);
        goto L7;
       }
      }
     }
L7:;
     v7 = ECL_NIL;
     {
      cl_object v9;
      v9 = v6;
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
L39:;
      if (!(v5==ECL_NIL)) { goto L41; }
      goto L40;
L41:;
      v4 = ECL_CONS_CAR(v5);
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v5);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 0;
       v5 = v11;
      }
      if (!(v8==ECL_NIL)) { goto L49; }
      goto L40;
L49:;
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
       T1 = v11;
      }
      T2 = ecl_function_dispatch(cl_env_copy,v3)(2, v4, v7);
      v10 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v10,T1);
      goto L39;
L40:;
      T0 = _ecl_cdr(v9);
      goto L1;
     }
    }
   }
  }
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, v1node, T0);
  return value0;
 }
 }
}
/*      closure LAMBDA210                                             */
/*      optimize speed 3, debug 0, space 0, safety 1                  */
static cl_object LC22__lambda210(cl_narg narg, cl_object v1parent, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  GRAPH           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2graph;
   cl_fixnum v3node;
   {
    cl_object v4;
    v4 = ECL_CONS_CAR(CLV1);
    T0 = ecl_function_dispatch(cl_env_copy,VV[25])(1, v4) /*  SIMPLE-ARRAY-P */;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v4);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    v2graph = v4;
   }
   {
    cl_object v4;
    v4 = v1parent;
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(VV[1],v4);
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 0;
    }
    v3node = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = v2graph;
    T0 = v4;
    {
     cl_fixnum v5;
     {
      cl_fixnum v6;
      v6 = v3node;
      if (ecl_unlikely((v6)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v6),(v4)->vector.dim);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 0;
      v5 = v6;
     }
     value0 = ecl_aref_unsafe(T0,v5);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
 }
}

#include "common/early/graph.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclLTqb7ItxYx5DM_HeDycC71(cl_object flag)
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
 flag->cblock.source = ecl_make_constant_base_string("/home/packer/ws/github/kisp/asgl/common/early/graph.lisp",-1);
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = (const cl_object *)"@EcLtAg:_eclLTqb7ItxYx5DM_HeDycC71@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
  si_select_package(VVtemp[0]);
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[1]) /*  MAPC */;
  si_do_deftype(3, VV[0], VVtemp[2], ECL_SYM("SIMPLE-ARRAY",765));
  si_do_deftype(3, VV[1], VVtemp[3], ECL_SYM("FIXNUM",374));
  (cl_env_copy->function=(ECL_SYM("MAPC",545)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",668), VVtemp[4]) /*  MAPC */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LOCATION",1862), VVtemp[5], VVtemp[6]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[2], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[24]);                          /*  %%ORDER         */
  si_put_sysprop(VV[2], ECL_SYM("INLINE",436), VVtemp[8]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LOCATION",1862), VVtemp[9], VVtemp[10]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[3], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[11]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[26]);                          /*  %%PARENTS       */
  si_put_sysprop(VV[3], ECL_SYM("INLINE",436), VVtemp[12]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VVtemp[13], ECL_SYM("LOCATION",1862), VVtemp[14], VVtemp[15]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VVtemp[13], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[16]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[27]);                          /*  (SETF %%PARENTS) */
  si_put_sysprop(VV[4], ECL_SYM("INLINE",436), VVtemp[17]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LOCATION",1862), VVtemp[18], VVtemp[19]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[5], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[20]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[28]);                       /*  DO-%%PARENTS    */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LOCATION",1862), VVtemp[21], VVtemp[22]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[7], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[23]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[31]);                          /*  %%PARENTS-ADD   */
  si_put_sysprop(VV[7], ECL_SYM("INLINE",436), VVtemp[24]);
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LOCATION",1862), VVtemp[25], VVtemp[26]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[8], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[27]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[32]);                       /*  %%PUSH-PARENTS  */
  si_do_deftype(3, VV[9], VVtemp[28], ECL_SYM("SIMPLE-ARRAY",765));
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[10], ECL_SYM("LOCATION",1862), VVtemp[29], VVtemp[30]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[10], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[33]);                          /*  ORDER           */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LOCATION",1862), VVtemp[31], VVtemp[32]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[11], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[34]);                          /*  SIZE            */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[12], ECL_SYM("LOCATION",1862), VVtemp[33], VVtemp[34]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[12], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[35]);                          /*  INDEGREES       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LOCATION",1862), VVtemp[35], VVtemp[36]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[13], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[37]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[36]);                       /*  DO-EDGES        */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LOCATION",1862), VVtemp[38], VVtemp[39]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[15], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[40]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[37]);                       /*  DO-PARENTS      */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LOCATION",1862), VVtemp[41], VVtemp[42]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[17], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[43]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[38]);                       /*  DO-PARENTS-GRANDPARENTS */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[19], ECL_SYM("LOCATION",1862), VVtemp[44], VVtemp[45]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[19], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[7]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[39]);                          /*  OUTDEGREES      */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LOCATION",1862), VVtemp[46], VVtemp[47]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[20], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[48]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[40]);                          /*  ADD-EDGE        */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[21], ECL_SYM("LOCATION",1862), VVtemp[49], VVtemp[50]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[21], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[51]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[41]);                          /*  MAKE-GRAPH-FROM-ADJ */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[22], ECL_SYM("LOCATION",1862), VVtemp[52], VVtemp[53]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[22], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[54]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[42]);                          /*  MAP-NODES       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[23], ECL_SYM("LOCATION",1862), VVtemp[55], VVtemp[56]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[23], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[57]) /*  ANNOTATE */;
  ecl_cmp_defmacro(VV[43]);                       /*  DO-NODES        */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LOCATION",1862), VVtemp[58], VVtemp[59]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[14], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[54]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[44]);                          /*  MAP-EDGES       */
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LOCATION",1862), VVtemp[60], VVtemp[61]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[16], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[54]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[45]);                          /*  MAP-PARENTS     */
  ecl_function_dispatch(cl_env_copy,VV[46])(3, VV[16], ECL_SYM("FUNCTION",398), VVtemp[62]) /*  SET-DOCUMENTATION */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LOCATION",1862), VVtemp[63], VVtemp[64]) /*  ANNOTATE */;
  ecl_function_dispatch(cl_env_copy,ECL_SYM("ANNOTATE",1856))(4, VV[18], ECL_SYM("LAMBDA-LIST",1000), ECL_NIL, VVtemp[54]) /*  ANNOTATE */;
  ecl_cmp_defun(VV[47]);                          /*  MAP-PARENTS-GRANDPARENTS */
  ecl_function_dispatch(cl_env_copy,VV[46])(3, VV[18], ECL_SYM("FUNCTION",398), VVtemp[65]) /*  SET-DOCUMENTATION */;
}
