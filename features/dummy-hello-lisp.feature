Feature: hello lisp

  Scenario: hello
     When I run `hello-lisp`
     Then the exit status should be 0
     And the output should contain "complete-all of #2A((0 1 0) (0 0 1) (0 0 0)) is ((0 2))"
