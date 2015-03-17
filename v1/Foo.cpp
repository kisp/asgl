#include "Foo.h"

namespace ks {

  Foo::Foo(int _n) : l(*this, _n, 0, 1) {
    n = _n;

    Gecode::branch(*this, l, Gecode::INT_VAR_DEGREE_MAX(), Gecode::INT_VAL_MIN());
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
