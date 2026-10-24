@notref
Feature: error-handling

  As a user of asgl
  I want to get useful information about errors

  Scenario: a mistake in the command line is one line, exit status 2
     When I run `asgl --quux`
     Then the exit status should be 2
     And the stderr should contain "ERROR: unknown option --quux"
     And the stderr should not contain "Unhandled error detected"

  Scenario: Unhandled error detected
     Given a file named "one.apx" with "arg(a).\n"
     When I run `asgl -p EE-GR -f one.apx -eval '(error "boom")'`
     Then the exit status should be 1
     And the output should contain "Unhandled error detected"
     And the output should contain "boom"
