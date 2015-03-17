@co
Feature: complete

  As a user of asgl
  I want to be able to compute extensions in complete semantics

  Scenario: enumerate all ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg3).
     """
     When I run `asgl -p EE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[[arg1, arg3]]"

  Scenario: enumerate all ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(3).
     att(arg1,arg2).
     att(arg2,3).
     """
     When I run `asgl -p EE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[[arg1, 3]]"

  Scenario: enumerate all ex3
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p EE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[[arg1]]"

  Scenario: enumerate all ex4
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg1).
     att(arg1,arg3).
     att(arg2,arg3).
     arg(arg4).
     arg(arg5).
     att(arg4,arg5).
     att(arg5,arg4).
     """
     When I run `asgl -p EE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to:
     """
     [[],[arg5],[arg2],[arg2,arg5],[arg4],[arg2,arg4],
       [arg1],[arg1,arg5],[arg1,arg4]]
     """

  Scenario: some extension ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg3).
     """
     When I run `asgl -p SE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[arg1, arg3]"

  Scenario: some extension ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p SE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[arg1]"

  Scenario: some extension ex3
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg1).
     att(arg1,arg3).
     att(arg2,arg3).
     arg(arg4).
     arg(arg5).
     att(arg4,arg5).
     att(arg5,arg4).
     """
     When I run `asgl -p SE-CO -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to one of:
     """
     [[],[arg5],[arg2],[arg2,arg5],[arg4],[arg2,arg4],
       [arg1],[arg1,arg5],[arg1,arg4]]
     """

  Scenario: skeptical acceptance ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p DS-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: skeptical acceptance ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     att(arg1,arg1).
     """
     When I run `asgl -p DS-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "NO"

  Scenario: skeptical acceptance ex3
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     att(arg1,arg2).
     att(arg2,arg1).
     """
     When I run `asgl -p DS-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "NO"

  Scenario: credulous acceptance ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p DC-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: credulous acceptance ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     att(arg1,arg1).
     """
     When I run `asgl -p DC-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "NO"

  Scenario: credulous acceptance ex3
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     att(arg1,arg2).
     att(arg2,arg1).
     """
     When I run `asgl -p DC-CO -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"
