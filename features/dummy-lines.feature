Feature: lines

  As a user of asgl
  I want to be able to count lines of input files

  Scenario: count lines ex1
     Given a file named "g.apx" with:
     """
     arg(arg1).
     arg(arg2).
     arg(arg3).
     att(arg1,arg2).
     att(arg2,arg3).
     """
     When I run `asgl -p lines -fo apx -f "g.apx"`
     Then the exit status should be 0
     And the output should be eql to "5"
