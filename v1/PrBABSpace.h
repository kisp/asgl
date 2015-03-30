#ifndef MYPrBABSpaceHEADER_
#define MYPrBABSpaceHEADER_
#include "../asgl_config.h"
#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/minimodel.hh>
#include <gecode/set.hh>
#include "Foo.h"
#ifdef HAVE_GECODE_GIST_HH
#include <gecode/gist.hh>
#endif

namespace v1 {
  class PrBABSpace : public Foo
  {
  protected:
    Gecode::IntVar card;
    Gecode::SetVar ext;

  public:
    PrBABSpace(int x);
    PrBABSpace(bool share, PrBABSpace& s);
    Gecode::Space* copy(bool share);
    virtual void constrain(const Gecode::Space& _b);
  };
}
#endif
