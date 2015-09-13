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

#ifndef MYPrBABSpaceHEADER_
#define MYPrBABSpaceHEADER_
#include "../asgl_config.h"
#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/minimodel.hh>
#include <gecode/set.hh>
#include "BoolSpace.h"
#ifdef HAVE_GECODE_GIST_HH
#include <gecode/gist.hh>
#endif

class PrBABSpace : public BoolSpace
{
 protected:
  Gecode::IntVar card;
  Gecode::SetVar ext;

 public:
  PrBABSpace(int x);
  PrBABSpace(bool share, PrBABSpace& s);
  Gecode::Space* copy(bool share);
  virtual void constrain(const Gecode::Space& _b);
  void constrain_not_subset(const PrBABSpace& b);
};
#endif
