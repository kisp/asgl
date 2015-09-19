Feature: comb ee and dec

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

    Examples: dec
    | name                                                  |
    | 10-oc8pxvdozslj28z334i                                |
    | 10-uv5c7j9ip8x7mokaz0z                                |
    | 11-2ld84de3g4d4139up243qer3                           |
    | 12-8p3yhgeszi73r6im5mbh65b1uosr                       |
    | 12-9colvrek0qw3txiny5e0r72fhuo3                       |
    | 12-ab1x62m7fz7uvaskqaco25hx2jhg                       |
    | 12-de0ib628dbropkz5lrc2jr186ovb                       |
    | 13-30c7w7l3eytn50yabkywyl1p0pgm0h9qk                  |
    | 13-5dffepipvjarh1xog8qiowskxu7e1i4u                   |
    | 15-2096m09ftcwh7b3t74xugt7ipugzrawwe3hjrq66cank       |
    | 15-2rhiheivfkp6iy9turq9xghq017r237o3cgbiroxqzny       |
    | 16-17m5hdbp2psz4441rpfn9vnyjxrvji7e0o7ib564mca6tsznp0 |
    | 3-ck                                                  |
    | 4-1pl                                                 |
    | 4-pz8                                                 |
    | 5-4jkmd                                               |
    | 5-x7qb                                                |
    | 6-6ae5jzv                                             |
    | 7-3to18aa6ci                                          |
    | 7-bmd6e8o59                                           |
    | 8-3iqnhprr22faz                                       |
    | 9-3b0n41g0a7egi0g0                                    |
    | 9-aaw9fhbctzpyjzxm                                    |




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

    Examples: dec
    | name                                                  |
    | 10-oc8pxvdozslj28z334i                                |
    | 10-uv5c7j9ip8x7mokaz0z                                |
    | 11-2ld84de3g4d4139up243qer3                           |
    | 12-8p3yhgeszi73r6im5mbh65b1uosr                       |
    | 12-9colvrek0qw3txiny5e0r72fhuo3                       |
    | 12-ab1x62m7fz7uvaskqaco25hx2jhg                       |
    | 12-de0ib628dbropkz5lrc2jr186ovb                       |
    | 13-30c7w7l3eytn50yabkywyl1p0pgm0h9qk                  |
    | 13-5dffepipvjarh1xog8qiowskxu7e1i4u                   |
    | 15-2096m09ftcwh7b3t74xugt7ipugzrawwe3hjrq66cank       |
    | 15-2rhiheivfkp6iy9turq9xghq017r237o3cgbiroxqzny       |
    | 16-17m5hdbp2psz4441rpfn9vnyjxrvji7e0o7ib564mca6tsznp0 |
    | 3-ck                                                  |
    | 4-1pl                                                 |
    | 4-pz8                                                 |
    | 5-4jkmd                                               |
    | 5-x7qb                                                |
    | 6-6ae5jzv                                             |
    | 7-3to18aa6ci                                          |
    | 7-bmd6e8o59                                           |
    | 8-3iqnhprr22faz                                       |
    | 9-3b0n41g0a7egi0g0                                    |
    | 9-aaw9fhbctzpyjzxm                                    |

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

    Examples: dec
    | name                                                  |
    | 10-oc8pxvdozslj28z334i                                |
    | 10-uv5c7j9ip8x7mokaz0z                                |
    | 11-2ld84de3g4d4139up243qer3                           |
    | 12-8p3yhgeszi73r6im5mbh65b1uosr                       |
    | 12-9colvrek0qw3txiny5e0r72fhuo3                       |
    | 12-ab1x62m7fz7uvaskqaco25hx2jhg                       |
    | 12-de0ib628dbropkz5lrc2jr186ovb                       |
    | 13-30c7w7l3eytn50yabkywyl1p0pgm0h9qk                  |
    | 13-5dffepipvjarh1xog8qiowskxu7e1i4u                   |
    | 15-2096m09ftcwh7b3t74xugt7ipugzrawwe3hjrq66cank       |
    | 15-2rhiheivfkp6iy9turq9xghq017r237o3cgbiroxqzny       |
    | 16-17m5hdbp2psz4441rpfn9vnyjxrvji7e0o7ib564mca6tsznp0 |
    | 3-ck                                                  |
    | 4-1pl                                                 |
    | 4-pz8                                                 |
    | 5-4jkmd                                               |
    | 5-x7qb                                                |
    | 6-6ae5jzv                                             |
    | 7-3to18aa6ci                                          |
    | 7-bmd6e8o59                                           |
    | 8-3iqnhprr22faz                                       |
    | 9-3b0n41g0a7egi0g0                                    |
    | 9-aaw9fhbctzpyjzxm                                    |

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

    Examples: dec
    | name                                                  |
    | 10-oc8pxvdozslj28z334i                                |
    | 10-uv5c7j9ip8x7mokaz0z                                |
    | 11-2ld84de3g4d4139up243qer3                           |
    | 12-8p3yhgeszi73r6im5mbh65b1uosr                       |
    | 12-9colvrek0qw3txiny5e0r72fhuo3                       |
    | 12-ab1x62m7fz7uvaskqaco25hx2jhg                       |
    | 12-de0ib628dbropkz5lrc2jr186ovb                       |
    | 13-30c7w7l3eytn50yabkywyl1p0pgm0h9qk                  |
    | 13-5dffepipvjarh1xog8qiowskxu7e1i4u                   |
    | 15-2096m09ftcwh7b3t74xugt7ipugzrawwe3hjrq66cank       |
    | 15-2rhiheivfkp6iy9turq9xghq017r237o3cgbiroxqzny       |
    | 16-17m5hdbp2psz4441rpfn9vnyjxrvji7e0o7ib564mca6tsznp0 |
    | 3-ck                                                  |
    | 4-1pl                                                 |
    | 4-pz8                                                 |
    | 5-4jkmd                                               |
    | 5-x7qb                                                |
    | 6-6ae5jzv                                             |
    | 7-3to18aa6ci                                          |
    | 7-bmd6e8o59                                           |
    | 8-3iqnhprr22faz                                       |
    | 9-3b0n41g0a7egi0g0                                    |
    | 9-aaw9fhbctzpyjzxm                                    |
