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

#include "PrBABSpace.h"

namespace v1 {

  PrBABSpace::PrBABSpace(int _n) : BoolSpace(_n), card(*this, 0, _n), ext(*this, Gecode::IntSet::empty, Gecode::IntSet(0, _n)) {
    cardinality(*this, ext, card);
    channel(*this, l, ext);
  }

  PrBABSpace::PrBABSpace(bool share, PrBABSpace& s) : BoolSpace(share, s) {
    card.update(*this, share, s.card);
    ext.update(*this, share, s.ext);
  }

  Gecode::Space* PrBABSpace::copy(bool share) {
    return new PrBABSpace(share, *this);
  }

  void PrBABSpace::constrain(const Gecode::Space& _b) {
    const PrBABSpace& b = static_cast<const PrBABSpace&>(_b);
    rel(*this, card > b.card);
    rel(*this, ext >= b.ext);
    // rel(*this, ext != b.ext);
  }

  void PrBABSpace::constrain_not_subset(const PrBABSpace& b) {
    rel(*this, (ext - b.ext) != Gecode::IntSet::empty);
  }
}
