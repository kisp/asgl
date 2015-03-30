#include "PrBABSpace.h"

namespace v1 {

  PrBABSpace::PrBABSpace(int _n) : Foo(_n), card(*this, 0, _n), ext(*this, Gecode::IntSet::empty, Gecode::IntSet(0, _n)) {
    cardinality(*this, ext, card);
    channel(*this, l, ext);
    // Gecode::branch(*this, l, Gecode::INT_VAR_DEGREE_MAX(), Gecode::INT_VAL_MAX());
  }

  PrBABSpace::PrBABSpace(bool share, PrBABSpace& s) : Foo(share, s) {
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
}
