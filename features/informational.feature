@notref
Feature: informational

  As a user of asgl
  I want to be able to query useful information about the solver

  Scenario: print information
     When I run `asgl`
     Then the exit status should be 0
     And the output should contain "Kilian Sprotte"
     And the output should contain "ASGL"
     And the output should contain "version 0.0.4"

  Scenario: print formats
     When I run `asgl --formats`
     Then the exit status should be 0
     And the output should be a set of strings
     And the output should be eql to "[apx]"

  Scenario: print problems
     When I run `asgl --problems`
     Then the exit status should be 0
     And the output should be a set of strings
     And the output should be eql to:
     """
     [DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST,
     EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]
     """
