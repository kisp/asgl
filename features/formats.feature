Feature: formats

  As a user of asgl
  I want to be able to see the formats supported

  Scenario: print formats
     When I run `asgl --formats`
     Then the exit status should be 0
     And the output should contain "[apx, tgf]"
