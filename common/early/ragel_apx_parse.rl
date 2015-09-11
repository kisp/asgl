// -*- mode:c -*-
// ASGL an abstract argumentation solver in ECL and GECODE.
// Copyright (C) 2015  Kilian Sprotte

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
#include "ragel_apx_parse.h"

%%{
  machine ragel_apx_parse;
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

void ragel_apx_parse(char *buffer, long size, cl_object table, cl_object fn) {
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
    FEerror("(ragel_apx_parse) Parsing apx file failed. Invalid format?", 0);

}
