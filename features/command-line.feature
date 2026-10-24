@notref
Feature: command line

  As a user of asgl, and of other solvers with the same command line
  I want help, input from a pipe, and one clear line for each mistake

  Scenario: -h prints the usage
     When I run `asgl -h`
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl -p PROBLEM"
     And the stdout should contain "-f FILE"

  Scenario: --help prints the usage
     When I run `asgl --help`
     Then the exit status should be 0
     And the stdout should contain "Usage: asgl -p PROBLEM"

  Scenario: the framework from the standard input, without -f
     When I run `asgl -p EE-CO` interactively
     And I type "arg(5)."
     And I close the stdin stream
     Then the exit status should be 0
     And the output should be eql to "[[5]]"

  Scenario: the framework from the standard input, with -f -
     When I run `asgl -p EE-PR -f -` interactively
     And I type "arg(a)."
     And I type "arg(b)."
     And I type "att(a,b)."
     And I close the stdin stream
     Then the exit status should be 0
     And the output should be eql to "[[a]]"

  Scenario: the same answer from a file and from the standard input
     Given a file named "chain.apx" with "arg(a).\narg(b).\narg(c).\natt(a,b).\natt(b,c).\n"
     When I run `asgl -p EE-GR -f chain.apx`
     Then the exit status should be 0
     And the output should be eql to "[[a,c]]"

  Scenario: an unsupported problem is named, and where to look
     When I run `asgl -p EE-CF -f -` interactively
     And I type "arg(5)."
     And I close the stdin stream
     Then the exit status should be 2
     And the stderr should contain "ERROR: unsupported problem EE-CF; asgl --problems lists those it solves"
     And the stderr should not contain "Backtrace"

  Scenario: an unknown option
     When I run `asgl --quux`
     Then the exit status should be 2
     And the stderr should contain "ERROR: unknown option --quux"
     And the stderr should contain "asgl -h shows the usage"

  Scenario: an option without its value
     When I run `asgl -p`
     Then the exit status should be 2
     And the stderr should contain "ERROR: -p needs a value"

  Scenario: no problem given
     Given a file named "one.apx" with "arg(a).\n"
     When I run `asgl -f one.apx`
     Then the exit status should be 2
     And the stderr should contain "ERROR: -p PROBLEM is required"

  Scenario: an unsupported format
     Given a file named "one.apx" with "arg(a).\n"
     When I run `asgl -p EE-GR -fo tgf -f one.apx`
     Then the exit status should be 2
     And the stderr should contain "ERROR: unsupported format tgf"

  Scenario: a file that is not there
     When I run `asgl -p EE-GR -f nope.apx`
     Then the exit status should be 2
     And the stderr should contain "ERROR: no such file: nope.apx"

  Scenario: an empty standard input
     When I run `asgl -p EE-CO` interactively
     And I close the stdin stream
     Then the exit status should be 2
     And the stderr should contain "ERROR: the standard input is empty"

  Scenario: input that is not apx
     Given a file named "bad.apx" with "arg(a.\n"
     When I run `asgl -p EE-GR -f bad.apx`
     Then the exit status should be 2
     And the stderr should contain "ERROR: bad.apx is not a framework in apx format"
     And the stderr should not contain "Backtrace"
