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

#include "IntSpace.h"

IntSpace::IntSpace(int _n, int _from, int _to) : l(*this, _n, _from, _to) {
  n = _n;
}

IntSpace::IntSpace(bool share, IntSpace& s) : Gecode::Space(share, s) {
  l.update(*this, share, s.l);
}

Gecode::Space* IntSpace::copy(bool share) {
  return new IntSpace(share, *this);
}

Gecode::IntVarArray* IntSpace::getVars(void) {
  return &l;
}

void IntSpace::print(std::ostream& os) const {
  os << l << std::endl;
}
