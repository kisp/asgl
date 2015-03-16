Feature: preferred

  As a user of asgl
  I want to be able to compute extensions in preferred semantics

  Scenario: enumerate all ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg3).
     """
     When I run `asgl -p EE-PR -fo apx -f "g.apx"`
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
     When I run `asgl -p EE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[[arg1, 3]]"

  Scenario: enumerate all ex3
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p EE-PR -fo apx -f "g.apx"`
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
     When I run `asgl -p EE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to:
     """
     [[arg2,arg5], [arg2,arg4], [arg1,arg5], [arg1,arg4]]
     """

  Scenario: enumerate all ex5
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p EE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[[3,1,7,9],[3,1,7,8]]"

  Scenario: some extension ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg3).
     """
     When I run `asgl -p SE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "[arg1, arg3]"

  Scenario: some extension ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p SE-PR -fo apx -f "g.apx"`
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
     When I run `asgl -p SE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to one of:
     """
     [[arg2,arg5], [arg2,arg4], [arg1,arg5], [arg1,arg4]]
     """

  Scenario: some extension ex4
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p SE-PR -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to one of:
     """
     [[3,1,7,9],[3,1,7,8]]
     """

  Scenario: skeptical acceptance ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: skeptical acceptance ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     att(arg1,arg1).
     """
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a arg1`
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
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "NO"

  Scenario: skeptical acceptance ex4
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a 3`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: skeptical acceptance ex5
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a 9`
     Then the exit status should be 0
     And the output should be eql to "NO"

  Scenario: credulous acceptance ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     """
     When I run `asgl -p DC-PR -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: credulous acceptance ex2
     Given a file named "g.apx" with:
     """
     arg(arg1).
     att(arg1,arg1).
     """
     When I run `asgl -p DC-PR -fo apx -f "g.apx" -a arg1`
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
     When I run `asgl -p DC-PR -fo apx -f "g.apx" -a arg1`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: credulous acceptance ex4
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p DC-PR -fo apx -f "g.apx" -a 3`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: credulous acceptance ex5
     Given a file named "g.apx" with:
     """
     arg(1).
     arg(2).
     arg(3).
     att(1,2).
     att(2,3).
     arg(4).
     arg(5).
     att(3,4).
     att(4,5).
     att(5,3).
     arg(6).
     att(1,6).
     arg(7).
     att(6,7).
     att(7,5).
     arg(8).
     arg(9).
     att(8,9).
     att(9,8).
     """
     When I run `asgl -p DC-PR -fo apx -f "g.apx" -a 9`
     Then the exit status should be 0
     And the output should be eql to "YES"
