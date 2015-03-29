#include "PrBABSpace.h"

namespace v1 {

  PrBABSpace::PrBABSpace(int _n) : Foo(_n), card(*this, 0, _n) {
    rel(*this, sum(l) == card);
  }

  PrBABSpace::PrBABSpace(bool share, PrBABSpace& s) : Foo(share, s) {
    card.update(*this, share, s.card);
  }

  Gecode::Space* PrBABSpace::copy(bool share) {
    return new PrBABSpace(share, *this);
  }

  void PrBABSpace::constrain(const Gecode::Space& _b) {
    const PrBABSpace& b = static_cast<const PrBABSpace&>(_b);
    rel(*this, card > b.card);
  }
}
