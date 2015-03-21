#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/gist.hh>

namespace gr1 {
  class Sp : public Gecode::Space
  {
  private:
    int n;

  protected:
    Gecode::BoolVarArray l;

  public:
    Sp(int x);
    Sp(bool share, Sp& s);

    int getN();

    Gecode::Space* copy(bool share);

    Gecode::BoolVarArray* getVars();

    void print(std::ostream&) const;
  };
}

