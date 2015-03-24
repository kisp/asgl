// -*- mode:c -*-
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
