@gr
Feature: syntax

  As a user of asgl
  I want to be able to parse apx reliably
  So that edge cases regarding syntax are treated correctly

  Scenario: normal
    Given a file named "g.apx" with:
    """
    arg(arg1).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: normal2
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg2).
    att(arg1,arg2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 1
    Given a file named "g.apx" with:
    """

    arg(arg1).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 2
    Given a file named "g.apx" with:
    """
    arg(arg1).

    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 3
    Given a file named "g.apx" with:
    """
    arg(arg1).

    arg(arg2).
    att(arg1,arg2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 4
    Given a file named "g.apx" with:
    """
    arg(arg1).


    arg(arg2).
    att(arg1,arg2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 5
    Given a file named "g.apx" with:
    """


    arg(arg1).
    arg(arg2).
    att(arg1,arg2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 6
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg2).
    att(arg1,arg2).

    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line 7
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg2).
    att(arg1,arg2).



    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: no trailing newline
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg2).
    att(arg1,arg2).
    """
    # cause of aruba not really needed
    And I run `perl -pie 'chomp if eof' "g.apx" &>/dev/null`
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: empty line with spaces
    Given a file named "g.apx" with "arg(arg1).\n   \narg(arg2).\natt(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in line 1
    Given a file named "g.apx" with "arg(arg1).  \narg(arg2). \natt(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in line 2
    Given a file named "g.apx" with "arg(arg1).\n arg(arg2).\n  att(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 1
    Given a file named "g.apx" with "arg (arg1).\narg  (arg2).\natt(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 2
    Given a file named "g.apx" with "arg(arg1) .\narg(arg2)  .\natt(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 3
    Given a file named "g.apx" with "arg( arg1).\narg(arg2).\natt(  arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 4
    Given a file named "g.apx" with "arg(arg1 ).\narg(arg2  ).\natt(arg1,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 5
    Given a file named "g.apx" with "arg(arg1).\narg(arg2).\natt(arg1 ,arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 6
    Given a file named "g.apx" with "arg(arg1).\narg(arg2).\natt(arg1, arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: spaces in expression 7
    Given a file named "g.apx" with "arg(arg1).\narg(arg2).\natt(arg1,  arg2).\n"
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: special characters 1
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg_2).
    att(arg1,arg_2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: special characters 2
    Given a file named "g.apx" with:
    """
    arg(arg1).
    arg(arg!2).
    att(arg1,arg!2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[arg1]]"

  Scenario: special characters 3
    Given a file named "g.apx" with:
    """
    arg(!arg1).
    arg(arg!2).
    att(!arg1,arg!2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[!arg1]]"

  Scenario: special characters 4
    Given a file named "g.apx" with:
    """
    arg($arg1).
    arg(arg2).
    att($arg1,arg2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[$arg1]]"

  Scenario: special characters 5
    Given a file named "g.apx" with:
    """
    arg(1.1).
    arg(2.2).
    att(1.1,2.2).
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[[1.1]]"

  Scenario: special characters 6
    Given a file named "g.apx" with:
    """
    arg('a').
    arg('b').
    att('a','b').
    """
    When I run `asgl -p EE-GR -fo apx -f "g.apx"`
    Then the exit status should be 0
    And the output should be eql to "[['a']]"
