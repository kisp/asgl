@notref
Feature: error-handling

  As a user of asgl
  I want to get useful information about errors

  Scenario: Unhandled error detected
     When I run `asgl --quux`
     Then the exit status should be 1
     And the output should contain "Unhandled error detected"
