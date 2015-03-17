#include "Sp.h"

namespace gr1 {

  Sp::Sp(int _n) : l(*this, _n, 0, 1) {
    n = _n;

    Gecode::branch(*this, l, Gecode::INT_VAR_DEGREE_MAX(), Gecode::INT_VAL_MIN());
  }

  Sp::Sp(bool share, Sp& s) : Gecode::Space(share, s) {
    l.update(*this, share, s.l);
  }

  int Sp::getN() {
    return n;
  }

  Gecode::Space* Sp::copy(bool share) {
    return new Sp(share, *this);
  }

  Gecode::BoolVarArray* Sp::getVars(void) {
    return &l;
  }

  void Sp::print(std::ostream& os) const {
    os << l << std::endl;
  }

}
