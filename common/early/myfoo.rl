// -*- mode:c -*-
#include <stdlib.h>
#include "myfoo.h"

%%{
  machine foo;
  action S { sss = fpc; }
  action E {
    mys = ecl_make_constant_base_string(sss, fpc - sss);
    entry = ecl_gethash_safe(mys,table,ECL_NIL);
    if (entry == ECL_NIL) {
      ecl_sethash(mys, table, index);
      index = ecl_plus(index, ecl_make_fixnum(1));
    }
  }

  action ATT_START {
    att_val_a = ECL_NIL;
    att_val_b = ECL_NIL;
  }

  action ATT_VAL_A {
    mys = ecl_make_constant_base_string(sss, fpc - sss);
    entry = ecl_gethash_safe(mys, table, ECL_NIL);
    if (entry == ECL_NIL) {
      ecl_sethash(mys, table, index);
      entry = index;
      index = ecl_plus(index, ecl_make_fixnum(1));
    }
    att_val_a = entry;
  }

  action ATT_VAL_B {
    mys = ecl_make_constant_base_string(sss, fpc - sss);
    entry = ecl_gethash_safe(mys, table, ECL_NIL);
    if (entry == ECL_NIL) {
      ecl_sethash(mys, table, index);
      entry = index;
      index = ecl_plus(index, ecl_make_fixnum(1));
    }
    att_val_b = entry;
  }

  action ATT_END {
    ecl_function_dispatch(cl_env_copy,fn)(2, att_val_a, att_val_b);
  }

  val = [^), ]+;
ws = ('\n' | ' ')+;
arg = 'arg' ws? '(' ws? (val >S %E) ws? ')' ws? '.';
att = (('att' %ATT_START) ws? '(' ws? (val >S %ATT_VAL_A) ws? ',' ws? (val >S %ATT_VAL_B) ')' ws? '.') %ATT_END;
main := ws? (arg | att) (ws (arg | att | ws))* ws? 0 @{ res = 0; };
}%%

%% write data;

void myfoo(char *buffer, long size, cl_object table, cl_object fn) {
  char *p = buffer;
  char *pe = p + size + 1;
  int cs = 0;
  int res = 1;
  char *sss;
  cl_object mys;
  cl_object index = ecl_make_fixnum(0);
  cl_object entry;

  cl_object att_val_a = ECL_NIL;
  cl_object att_val_b = ECL_NIL;

  const cl_env_ptr cl_env_copy = ecl_process_env();

  %% write init;
  %% write exec;

  if (res)
    FEerror("(myfoo) Parsing apx file failed. Invalid format?", 0);

}
