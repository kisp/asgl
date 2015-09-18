Feature: comb ee

  Scenario Outline: comb testcases EE-GR
    Given apx testcase "<name>"
    When I run `asgl -p EE-GR -fo apx -f "<name>.apx"`
    Then the exit status should be 0
    And the output should be eql to solution "<name>.EE-GR"

    Examples:
    | name                                 |
    | 11-hfjl8s13b99181pjaawixmb           |
    | 3-33                                 |
    | 5-gacfq                              |
    | 9-3406qf98bmoc1y0j                   |
    | 5-12aac                              |
    | 5-d9e0u                              |
    | 10-2bnpb1eolup6jmo8359v              |
    | 10-1luwnm85wjwejj40np2o              |
    | 9-aqtawfbltgadbsaw                   |
    | 13-bqoqit3ffxu3o0w609kslm2lzt12vvps2 |
    | 10-127r681ird483nf0u56u              |
    | 12-7rnyxcmq2hbo0m8xg0itz9q2i2tj      |

  Scenario Outline: comb testcases EE-CO
    Given apx testcase "<name>"
    When I run `asgl -p EE-CO -fo apx -f "<name>.apx"`
    Then the exit status should be 0
    And the output should be eql to solution "<name>.EE-CO"

    Examples:
    | name                                 |
    | 11-hfjl8s13b99181pjaawixmb           |
    | 3-33                                 |
    | 5-gacfq                              |
    | 9-3406qf98bmoc1y0j                   |
    | 5-12aac                              |
    | 5-d9e0u                              |
    | 10-2bnpb1eolup6jmo8359v              |
    | 10-1luwnm85wjwejj40np2o              |
    | 9-aqtawfbltgadbsaw                   |
    | 13-bqoqit3ffxu3o0w609kslm2lzt12vvps2 |
    | 10-127r681ird483nf0u56u              |
    | 12-7rnyxcmq2hbo0m8xg0itz9q2i2tj      |

  Scenario Outline: stmb testcases EE-ST
    Given apx testcase "<name>"
    When I run `asgl -p EE-ST -fo apx -f "<name>.apx"`
    Then the exit status should be 0
    And the output should be eql to solution "<name>.EE-ST"

    Examples:
    | name                                 |
    | 11-hfjl8s13b99181pjaawixmb           |
    | 3-33                                 |
    | 5-gacfq                              |
    | 9-3406qf98bmoc1y0j                   |
    | 5-12aac                              |
    | 5-d9e0u                              |
    | 10-2bnpb1eolup6jmo8359v              |
    | 10-1luwnm85wjwejj40np2o              |
    | 9-aqtawfbltgadbsaw                   |
    | 13-bqoqit3ffxu3o0w609kslm2lzt12vvps2 |
    | 10-127r681ird483nf0u56u              |
    | 12-7rnyxcmq2hbo0m8xg0itz9q2i2tj      |

  Scenario Outline: prmb testcases EE-PR
    Given apx testcase "<name>"
    When I run `asgl -p EE-PR -fo apx -f "<name>.apx"`
    Then the exit status should be 0
    And the output should be eql to solution "<name>.EE-PR"

    Examples:
    | name                                 |
    | 11-hfjl8s13b99181pjaawixmb           |
    | 3-33                                 |
    | 5-gacfq                              |
    | 9-3406qf98bmoc1y0j                   |
    | 5-12aac                              |
    | 5-d9e0u                              |
    | 10-2bnpb1eolup6jmo8359v              |
    | 10-1luwnm85wjwejj40np2o              |
    | 9-aqtawfbltgadbsaw                   |
    | 13-bqoqit3ffxu3o0w609kslm2lzt12vvps2 |
    | 10-127r681ird483nf0u56u              |
    | 12-7rnyxcmq2hbo0m8xg0itz9q2i2tj      |
