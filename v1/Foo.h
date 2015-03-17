#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/gist.hh>

namespace ks {
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
