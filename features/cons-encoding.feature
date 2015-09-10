Feature: cons encoding

  As a user of asgl
  I want to be able to provide graph input in cons encoding

  Scenario: enumerate all co from cons encoding
     When I run `asgl -p EE-CO -g 3.136`
     Then the exit status should be 0
     And the output should be eql to "[[0, 2]]"

  Scenario Outline: fail on invalid cons
     When I run `asgl -p EE-CO -g <cons>`
     Then the exit status should be 1

  Examples:
  | cons |
  |    3 |
  |   3. |
  |   .0 |
  |  foo |
