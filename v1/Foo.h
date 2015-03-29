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
  };
}
#endif
