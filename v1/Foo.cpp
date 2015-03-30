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

#include "Foo.h"

namespace v1 {

  Foo::Foo(int _n) : l(*this, _n, 0, 1) {
    n = _n;
  }

  void Foo::branch__l__int_var_degree_max__int_val_min() {
    Gecode::branch(*this, l, Gecode::INT_VAR_DEGREE_MAX(), Gecode::INT_VAL_MIN());
  }

  void Foo::branch__l__int_var_degree_max__int_val_max() {
    Gecode::branch(*this, l, Gecode::INT_VAR_DEGREE_MAX(), Gecode::INT_VAL_MAX());
  }

  Foo::Foo(bool share, Foo& s) : Gecode::Space(share, s) {
    l.update(*this, share, s.l);
  }

  int Foo::getN() {
    return n;
  }

  Gecode::Space* Foo::copy(bool share) {
    return new Foo(share, *this);
  }

  Gecode::BoolVarArray* Foo::getVars(void) {
    return &l;
  }

  void Foo::print(std::ostream& os) const {
    os << l << std::endl;
  }

}
