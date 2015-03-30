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
#include "myfoo.h"

%%{
  machine foo;
  action E { arg_count++; }
  val = [^), ]+;
ws = ('\n' | ' ')+;
arg = 'arg' ws? '(' ws? val ws? ')' ws? '.' %E;
att = 'att' ws? '(' ws? val ws? ',' ws? val ')' ws? '.';
main := ws? (arg | att) (ws (arg | att))* ws? 0 @{ res = 0; };
}%%

%% write data;

int count_args(char *buffer, long size) {
  char *p = buffer;
  char *pe = p + size + 1;
  int cs = 0;
  int res = 1;
  int arg_count = 0;
  %% write init;
  %% write exec;

  if (res)
    FEerror("(count_args) Parsing apx file failed. Invalid format?", 0);

  return arg_count;
}
