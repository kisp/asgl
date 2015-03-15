Feature: formats

  As a user of asgl
  I want to be able to see the formats supported

  Scenario: print formats
     When I run `asgl --formats`
     Then the exit status should be 0
     And the output should be a set of strings
     And the output should be eql to "[apx, tgf]"
