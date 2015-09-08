@pr
Feature: preferred new

  As a user of asgl
  I want to be able to compute extensions in preferred semantics

  Scenario: new skeptical acceptance ex1 part a
     Given a file named "g.apx" with:
     """
     arg(0).
     arg(1).
     arg(2).
     arg(3).
     arg(4).
     arg(5).
     arg(6).
     att(0,3).
     att(3,0).
     att(3,3).
     att(2,3).
     att(2,4).
     att(4,2).
     att(6,2).
     att(6,5).
     att(5,6).
     """
     When I run `asgl -p DS-PR -fo apx -f "g.apx" -a 0`
     Then the exit status should be 0
     And the output should be eql to "YES"

  Scenario: new skeptical acceptance ex1 part b
     Given a file named "g.apx" with:
     """
     arg(0).
     arg(1).
     arg(2).
     arg(3).
     arg(4).
     arg(5).
     arg(6).
     att(0,3).
     att(3,0).
     att(3,3).
     att(2,3).
     att(2,4).
     att(4,2).
     att(6,2).
     att(6,5).
     att(5,6).
     """
     When I run `asgl -p DS-CO -fo apx -f "g.apx" -a 0`
     Then the exit status should be 0
     And the output should be eql to "NO"
