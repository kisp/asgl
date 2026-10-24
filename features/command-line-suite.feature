@notref
Feature: the command line, a designed suite

  Generated, one scenario per test case, from a table of test cases
  designed by a classification tree of an invocation: every two classes
  together, and every outcome. The table is kept outside this repository;
  change it and generate this file again rather than editing it.

  Every case reads the same framework, a <-> b, a -> c, c -> d -> e -> c,
  whose four semantics all give different answers.

  Scenario: case 1: request=solve problem=given task=ee semantics=co query=none format=omitted source=file text=lines order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p EE-CO -f af.apx` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 2: request=solve problem=given task=ee semantics=pr query=a format=apx source=stdin text=one-line order=reversed extra=unknown-option
     When I run `asgl -a a -fo apx -p EE-PR --quux` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 3: request=solve problem=given task=ee semantics=gr query=b format=other source=dash text=crlf-tabs order=iccma extra=dangling-option
     When I run `asgl -p EE-GR -fo tgf -f - -a b -fo` with the input "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 4: request=solve problem=given task=ee semantics=st query=c format=omitted source=missing-file text=lines order=reversed extra=repeated-option
     When I run `asgl -a c -f missing.apx -p EE-ST -fo apx -fo apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 5: request=solve problem=given task=se semantics=co query=undeclared format=apx source=dash text=duplicate order=iccma extra=repeated-option
     When I run `asgl -p SE-CO -fo apx -f - -a z -fo apx -fo apx` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 6: request=solve problem=given task=se semantics=pr query=none format=other source=file text=empty order=reversed extra=dangling-option
     Given a file named "af.apx" with ""
     When I run `asgl -f af.apx -fo tgf -p SE-PR -fo` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 7: request=solve problem=given task=se semantics=gr query=a format=omitted source=stdin text=not-apx order=reversed extra=none
     When I run `asgl -a a -p SE-GR` with the input "arg(a).\natt(a b).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-a is only for DC- and DS- problems"
     And the stderr should not contain "Backtrace"

  Scenario: case 8: request=solve problem=given task=se semantics=st query=b format=apx source=file text=undeclared-attack order=iccma extra=unknown-option
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p SE-ST -fo apx -f af.apx -a b --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 9: request=solve problem=given task=dc semantics=co query=a format=other source=missing-file text=lines order=iccma extra=unknown-option
     When I run `asgl -p DC-CO -fo tgf -f missing.apx -a a --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 10: request=solve problem=given task=dc semantics=pr query=b format=omitted source=dash text=duplicate order=reversed extra=none
     When I run `asgl -a b -f - -p DC-PR` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 0
     And the output should be eql to "YES"
     And the stderr should not contain anything

  Scenario: case 11: request=solve problem=given task=dc semantics=gr query=none format=apx source=file text=one-line order=iccma extra=repeated-option
     Given a file named "af.apx" with "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     When I run `asgl -p DC-GR -fo apx -f af.apx -fo apx -fo apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 12: request=solve problem=given task=dc semantics=st query=undeclared format=other source=stdin text=crlf-tabs order=reversed extra=dangling-option
     When I run `asgl -a z -fo tgf -p DC-ST -fo` with the input "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 13: request=solve problem=given task=ds semantics=co query=b format=omitted source=stdin text=empty order=iccma extra=repeated-option
     When I run `asgl -p DS-CO -a b -fo apx -fo apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 14: request=solve problem=given task=ds semantics=pr query=c format=apx source=file text=crlf-tabs order=reversed extra=none
     Given a file named "af.apx" with "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     When I run `asgl -a c -f af.apx -fo apx -p DS-PR` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 15: request=solve problem=given task=ds semantics=gr query=undeclared format=omitted source=missing-file text=lines order=iccma extra=unknown-option
     When I run `asgl -p DS-GR -f missing.apx -a z --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 16: request=solve problem=given task=ds semantics=st query=none format=other source=dash text=not-apx order=iccma extra=unknown-option
     When I run `asgl -p DS-ST -fo tgf -f - --quux` with the input "arg(a).\natt(a b).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 17: request=solve problem=given task=ee semantics=st query=undeclared format=apx source=file text=empty order=iccma extra=none
     Given a file named "af.apx" with ""
     When I run `asgl -p EE-ST -fo apx -f af.apx -a z` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-a is only for DC- and DS- problems"
     And the stderr should not contain "Backtrace"

  Scenario: case 18: request=solve problem=given task=se semantics=co query=c format=other source=dash text=one-line order=reversed extra=dangling-option
     When I run `asgl -a c -f - -fo tgf -p SE-CO -fo` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 19: request=solve problem=given task=dc semantics=gr query=c format=omitted source=stdin text=empty order=iccma extra=unknown-option
     When I run `asgl -p DC-GR -a c --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 20: request=solve problem=given task=ds semantics=st query=a format=other source=file text=duplicate order=iccma extra=dangling-option
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DS-ST -fo tgf -f af.apx -a a -fo` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 21: request=solve problem=given task=se semantics=pr query=b format=apx source=missing-file text=lines order=iccma extra=dangling-option
     When I run `asgl -p SE-PR -fo apx -f missing.apx -a b -fo` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 22: request=solve problem=given task=ee semantics=gr query=none format=apx source=stdin text=duplicate order=iccma extra=none
     When I run `asgl -p EE-GR -fo apx` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 0
     And the output should be eql to "[[]]"
     And the stderr should not contain anything

  Scenario: case 23: request=solve problem=given task=ee semantics=co query=b format=apx source=file text=not-apx order=iccma extra=dangling-option
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -p EE-CO -fo apx -f af.apx -a b -fo` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 24: request=solve problem=given task=ee semantics=co query=none format=omitted source=stdin text=undeclared-attack order=reversed extra=dangling-option
     When I run `asgl -p EE-CO -fo` with the input "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 25: request=solve problem=given task=se semantics=co query=none format=omitted source=stdin text=crlf-tabs order=reversed extra=none
     When I run `asgl -p SE-CO` with the input "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     Then the exit status should be 0
     And the output should be one extension of "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 26: request=solve problem=given task=dc semantics=pr query=undeclared format=other source=file text=not-apx order=iccma extra=repeated-option
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -p DC-PR -fo tgf -f af.apx -a z -fo apx -fo apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 27: request=solve problem=given task=dc semantics=pr query=a format=other source=dash text=undeclared-attack order=iccma extra=repeated-option
     When I run `asgl -p DC-PR -fo tgf -f - -a a -fo apx -fo apx` with the input "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 28: request=solve problem=given task=ds semantics=st query=b format=omitted source=stdin text=one-line order=iccma extra=none
     When I run `asgl -p DS-ST -a b` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 29: request=solve problem=given task=ds semantics=gr query=c format=other source=file text=undeclared-attack order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DS-GR -fo tgf -f af.apx -a c` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported format tgf"
     And the stderr should not contain "Backtrace"

  Scenario: case 30: request=solve problem=unsupported query=none format=omitted source=missing-file text=lines order=iccma extra=none
     When I run `asgl -p EE-CF -f missing.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 31: request=solve problem=unsupported query=a format=apx source=file text=crlf-tabs order=reversed extra=unknown-option
     Given a file named "af.apx" with "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     When I run `asgl -a a -f af.apx -fo apx -p EE-CF --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 32: request=solve problem=unsupported query=b format=other source=stdin text=one-line order=iccma extra=dangling-option
     When I run `asgl -p EE-CF -fo tgf -a b -fo` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 33: request=solve problem=unsupported query=c format=omitted source=dash text=duplicate order=iccma extra=repeated-option
     When I run `asgl -p EE-CF -f - -a c -fo apx -fo apx` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 34: request=solve problem=unsupported query=undeclared format=omitted source=file text=undeclared-attack order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p EE-CF -f af.apx -a z` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 35: request=solve problem=malformed query=a format=apx source=dash text=empty order=reversed extra=unknown-option
     When I run `asgl -a a -f - -fo apx -p EE --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 36: request=solve problem=malformed query=b format=other source=stdin text=one-line order=iccma extra=dangling-option
     When I run `asgl -p EE -fo tgf -a b -fo` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 37: request=solve problem=malformed query=c format=omitted source=file text=not-apx order=iccma extra=repeated-option
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -p EE -f af.apx -a c -fo apx -fo apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 38: request=solve problem=malformed query=undeclared format=omitted source=missing-file text=lines order=iccma extra=none
     When I run `asgl -p EE -f missing.apx -a z` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 39: request=solve problem=missing query=a format=apx source=stdin text=one-line order=reversed extra=unknown-option
     When I run `asgl -a a -fo apx --quux` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 40: request=solve problem=missing query=b format=other source=dash text=crlf-tabs order=iccma extra=repeated-option
     When I run `asgl -fo tgf -f - -a b -fo apx -fo apx` with the input "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo is given twice"
     And the stderr should not contain "Backtrace"

  Scenario: case 41: request=solve problem=missing query=c format=omitted source=missing-file text=lines order=iccma extra=dangling-option
     When I run `asgl -f missing.apx -a c -fo` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-fo needs a value"
     And the stderr should not contain "Backtrace"

  Scenario: case 42: request=solve problem=missing query=undeclared format=omitted source=file text=duplicate order=iccma extra=unknown-option
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -f af.apx -a z --quux` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unknown option --quux"
     And the stderr should not contain "Backtrace"

  Scenario: case 43: request=solve problem=unsupported query=none format=omitted source=file text=empty order=iccma extra=none
     Given a file named "af.apx" with ""
     When I run `asgl -p EE-CF -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 44: request=solve problem=unsupported query=none format=omitted source=file text=not-apx order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -p EE-CF -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 45: request=solve problem=malformed query=none format=omitted source=file text=crlf-tabs order=iccma extra=none
     Given a file named "af.apx" with "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     When I run `asgl -p EE -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 46: request=solve problem=malformed query=none format=omitted source=file text=duplicate order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p EE -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 47: request=solve problem=malformed query=none format=omitted source=file text=undeclared-attack order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p EE -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "unsupported problem"
     And the stderr should not contain "Backtrace"

  Scenario: case 48: request=solve problem=missing query=none format=omitted source=file text=empty order=iccma extra=none
     Given a file named "af.apx" with ""
     When I run `asgl -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-p PROBLEM is required"
     And the stderr should not contain "Backtrace"

  Scenario: case 49: request=solve problem=missing query=none format=omitted source=file text=not-apx order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-p PROBLEM is required"
     And the stderr should not contain "Backtrace"

  Scenario: case 50: request=solve problem=missing query=none format=omitted source=file text=undeclared-attack order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -f af.apx` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "-p PROBLEM is required"
     And the stderr should not contain "Backtrace"

  Scenario: case 51: request=solve problem=given task=dc semantics=co query=undeclared format=omitted source=file text=one-line order=iccma extra=none
     Given a file named "af.apx" with "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     When I run `asgl -p DC-CO -f af.apx -a z` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "z is not an argument of the framework"
     And the stderr should not contain "Backtrace"

  Scenario: case 52: request=solve problem=given task=dc semantics=co query=a format=apx source=stdin text=lines order=reversed extra=none
     When I run `asgl -a a -fo apx -p DC-CO` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 0
     And the output should be eql to "YES"
     And the stderr should not contain anything

  Scenario: case 53: request=solve problem=given task=se semantics=co query=none format=apx source=dash text=lines order=iccma extra=none
     When I run `asgl -p SE-CO -fo apx -f -` with the input "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     Then the exit status should be 0
     And the output should be one extension of "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 54: request=help help-flag=short extra=none
     When I run `asgl -h` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 55: request=help help-flag=short extra=unknown-option
     When I run `asgl -h --quux` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 56: request=help help-flag=short extra=dangling-option
     When I run `asgl -h -fo` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 57: request=help help-flag=short extra=repeated-option
     When I run `asgl -h -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 58: request=help help-flag=long extra=none
     When I run `asgl --help` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 59: request=help help-flag=long extra=unknown-option
     When I run `asgl --help --quux` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 60: request=help help-flag=long extra=dangling-option
     When I run `asgl --help -fo` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 61: request=help help-flag=long extra=repeated-option
     When I run `asgl --help -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl "
     And the stderr should not contain anything

  Scenario: case 62: request=version version-flag=short extra=none
     When I run `asgl -v` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 63: request=version version-flag=short extra=unknown-option
     When I run `asgl -v --quux` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 64: request=version version-flag=short extra=dangling-option
     When I run `asgl -v -fo` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 65: request=version version-flag=short extra=repeated-option
     When I run `asgl -v -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 66: request=version version-flag=long extra=none
     When I run `asgl --version` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 67: request=version version-flag=long extra=unknown-option
     When I run `asgl --version --quux` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 68: request=version version-flag=long extra=dangling-option
     When I run `asgl --version -fo` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 69: request=version version-flag=long extra=repeated-option
     When I run `asgl --version -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the stdout should contain "ASGL version "
     And the stderr should not contain anything

  Scenario: case 70: request=solve problem=given task=se semantics=co query=none format=apx source=file text=one-line order=reversed extra=none
     Given a file named "af.apx" with "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     When I run `asgl -f af.apx -fo apx -p SE-CO` with the input ""
     Then the exit status should be 0
     And the output should be one extension of "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 71: request=solve problem=given task=dc semantics=co query=c format=omitted source=file text=duplicate order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DC-CO -f af.apx -a c` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 72: request=solve problem=given task=ee semantics=co query=none format=omitted source=dash text=one-line order=reversed extra=none
     When I run `asgl -f - -p EE-CO` with the input "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     Then the exit status should be 0
     And the output should be eql to "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 73: request=solve problem=given task=ds semantics=co query=a format=omitted source=dash text=crlf-tabs order=iccma extra=none
     When I run `asgl -p DS-CO -f - -a a` with the input "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 74: request=solve problem=given task=ds semantics=gr query=a format=omitted source=file text=lines order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DS-GR -f af.apx -a a` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 75: request=solve problem=given task=dc semantics=pr query=c format=omitted source=file text=one-line order=iccma extra=none
     Given a file named "af.apx" with "arg(a).arg(b).arg(c).arg(d).arg(e).att(a,b).att(b,a).att(a,c).att(c,d).att(d,e).att(e,c)."
     When I run `asgl -p DC-PR -f af.apx -a c` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 76: request=solve problem=given task=ee semantics=co query=none format=omitted source=file text=crlf-tabs order=reversed extra=none
     Given a file named "af.apx" with "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     When I run `asgl -f af.apx -p EE-CO` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 77: request=solve problem=given task=dc semantics=gr query=a format=omitted source=file text=crlf-tabs order=iccma extra=none
     Given a file named "af.apx" with "\targ(a).\r\n\targ(b).\r\n\targ(c).\r\n\targ(d).\r\n\targ(e).\r\n\tatt(a,\tb).\r\n\tatt(b,\ta).\r\n\tatt(a,\tc).\r\n\tatt(c,\td).\r\n\tatt(d,\te).\r\n\tatt(e,\tc).\r\n"
     When I run `asgl -p DC-GR -f af.apx -a a` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 78: request=solve problem=given task=se semantics=co query=none format=omitted source=file text=duplicate order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p SE-CO -f af.apx` with the input ""
     Then the exit status should be 0
     And the output should be one extension of "[[],[b],[a,d]]"
     And the stderr should not contain anything

  Scenario: case 79: request=solve problem=given task=ds semantics=st query=a format=omitted source=file text=duplicate order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\narg(c).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DS-ST -f af.apx -a a` with the input ""
     Then the exit status should be 0
     And the output should be eql to "YES"
     And the stderr should not contain anything

  Scenario: case 80: request=solve problem=given task=dc semantics=st query=a format=omitted source=file text=lines order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DC-ST -f af.apx -a a` with the input ""
     Then the exit status should be 0
     And the output should be eql to "YES"
     And the stderr should not contain anything

  Scenario: case 81: request=solve problem=given task=dc semantics=st query=b format=omitted source=file text=lines order=iccma extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -p DC-ST -f af.apx -a b` with the input ""
     Then the exit status should be 0
     And the output should be eql to "NO"
     And the stderr should not contain anything

  Scenario: case 82: request=problems extra=none
     When I run `asgl --problems` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"
     And the stderr should not contain anything

  Scenario: case 83: request=problems extra=unknown-option
     When I run `asgl --problems --quux` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"
     And the stderr should not contain anything

  Scenario: case 84: request=problems extra=dangling-option
     When I run `asgl --problems -fo` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"
     And the stderr should not contain anything

  Scenario: case 85: request=problems extra=repeated-option
     When I run `asgl --problems -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"
     And the stderr should not contain anything

  Scenario: case 86: request=formats extra=none
     When I run `asgl --formats` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[apx]"
     And the stderr should not contain anything

  Scenario: case 87: request=formats extra=unknown-option
     When I run `asgl --formats --quux` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[apx]"
     And the stderr should not contain anything

  Scenario: case 88: request=formats extra=dangling-option
     When I run `asgl --formats -fo` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[apx]"
     And the stderr should not contain anything

  Scenario: case 89: request=formats extra=repeated-option
     When I run `asgl --formats -fo apx -fo apx` with the input ""
     Then the exit status should be 0
     And the output should be eql to "[apx]"
     And the stderr should not contain anything

  Scenario: case 90: request=banner extra=none
     When I run `asgl` with the input ""
     Then the exit status should be 0
     And the stdout should contain "Kilian Sprotte"
     And the stderr should not contain anything

  Scenario: case 91: request=solve problem=given task=ds semantics=co query=none format=omitted source=file text=lines order=reversed extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\narg(e).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -f af.apx -p DS-CO` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "needs -a ARGUMENT"
     And the stderr should not contain "Backtrace"

  Scenario: case 92: request=solve problem=given task=ee semantics=co query=none format=omitted source=missing-file text=lines order=reversed extra=none
     When I run `asgl -f missing.apx -p EE-CO` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "no such file: missing.apx"
     And the stderr should not contain "Backtrace"

  Scenario: case 93: request=solve problem=given task=ee semantics=co query=none format=omitted source=file text=empty order=reversed extra=none
     Given a file named "af.apx" with ""
     When I run `asgl -f af.apx -p EE-CO` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "is empty"
     And the stderr should not contain "Backtrace"

  Scenario: case 94: request=solve problem=given task=ee semantics=co query=none format=omitted source=file text=not-apx order=reversed extra=none
     Given a file named "af.apx" with "arg(a).\natt(a b).\n"
     When I run `asgl -f af.apx -p EE-CO` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "is not a framework in apx format"
     And the stderr should not contain "Backtrace"

  Scenario: case 95: request=solve problem=given task=ee semantics=co query=none format=omitted source=file text=undeclared-attack order=reversed extra=none
     Given a file named "af.apx" with "arg(a).\narg(b).\narg(c).\narg(d).\natt(a,b).\natt(b,a).\natt(a,c).\natt(c,d).\natt(d,e).\natt(e,c).\n"
     When I run `asgl -f af.apx -p EE-CO` with the input ""
     Then the exit status should be 2
     And the stdout should not contain anything
     And the stderr should contain "ERROR: "
     And the stderr should contain "an attack names e, which no arg(...) declares"
     And the stderr should not contain "Backtrace"
