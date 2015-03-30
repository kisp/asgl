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

#ifndef MY_FOO_HEADER_
#define MY_FOO_HEADER_
#include "../asgl_config.h"
#include <gecode/int.hh>
#include <gecode/search.hh>
#ifdef HAVE_GECODE_GIST_HH
#include <gecode/gist.hh>
#endif

namespace v1 {
  class Foo : public Gecode::Space
  {
  private:
    int n;

  protected:
    Gecode::BoolVarArray l;

  public:
    Foo(int x);
    Foo(bool share, Foo& s);

    int getN();

    Gecode::Space* copy(bool share);

    Gecode::BoolVarArray* getVars();

    void print(std::ostream&) const;

    void branch__l__int_var_degree_max__int_val_min();
  };
}
#endif
