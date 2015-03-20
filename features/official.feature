Feature: official

  @gr
  Scenario Outline: official testcases EE-GR
    Given official testcase "<name>"
    When I run `asgl -p EE-GR -fo apx -f "<name>.apx"`
    Then the exit status should be 0
    And the output should be eql to solution "<name>.EE-GR"

    Examples:
    | name                        |
    | 109649__200__11_12_65__35   |
    | 116134__200__18_19_87__57   |
    | 119290__200__21_22_51__46   |
    | 120200__300__11_12_33__98   |
    | 120355__300__9_9_17__90     |
    | 120534__300__8_8_15__62     |
    | 120572__300__8_9_15__71     |
    | 121196__300__20_20_24__31   |
    | 122029__300__9_9_18__0      |
    | 122574__400__10_11_36__3    |
    | 122581__300__8_8_11__76     |
    | 122639__300__13_13_18__9    |
    | 122981__300__12_12_24__47   |
    | 123848__400__9_11_33__51    |
    | 124293__300__9_9_17__24     |
    | 124850__300__7_7_11__38     |
    | 126235__300__15_15_23__61   |
    | 126695__300__12_12_54__79   |
    | 127258__300__12_12_22__37   |
    | 127686__300__2_2_4__30      |
    | 128045__300__8_8_11__38     |
    | 130138__300__13_14_55__2    |
    | 130999__300__2_2_3__71      |
    | 131734__300__7_7_14__88     |
    | 132179__300__10_10_15__24   |
    | 132701__300__10_11_16__26   |
    | 132920__400__12_17_40__77   |
    | 132981__300__10_10_19__14   |
    | 134006__300__16_17_24__97   |
    | 135068__300__11_11_16__84   |
    | 136011__300__12_12_21__24   |
    | 136131__300__8_10_31__20    |
    | 139361__400__14_14_37__40   |
    | 139477__300__10_10_18__32   |
    | 139987__300__8_12_57__96    |
    | 143673__300__4_4_5__98      |
    | 143978__300__5_5_8__58      |
    | 144063__300__13_13_24__29   |
    | 145703__300__11_12_17__95   |
    | 145796__300__14_14_18__74   |
    | 146780__400__14_15_41__8    |
    | 147966__300__8_8_14__81     |
    | 148782__300__2_2_3__65      |
    | 149598__400__3_3_40__5      |
    | 150857__400__3_11_34__79    |
    | 152085__300__12_12_26__22   |
    | 153752__300__3_3_4__58      |
    | 153904__300__12_13_36__72   |
    | 156312__300__10_11_63__84   |
    | 158223__300__15_15_29__19   |
    | 158386__300__12_14_63__76   |
    | 159357__400__7_14_44__41    |
    | 159643__300__15_15_21__14   |
    | 159944__300__4_6_9__72      |
    | 159956__300__8_9_19__10     |
    | 160116__400__8_10_33__99    |
    | 162036__300__11_11_30__49   |
    | 162515__300__7_10_66__85    |
    | 164313__300__9_11_64__85    |
    | 164327__400__9_9_44__77     |
    | 166553__200__10_10_103__63  |
    | 168618__400__15_15_40__0    |
    | 169156__300__6_6_8__31      |
    | 170593__400__15_21_39__30   |
    | 174098__300__14_14_67__2    |
    | 180108__300__8_8_11__63     |
    | 180143__400__12_12_44__40   |
    | 184426__300__9_13_69__53    |
    | 186964__300__11_11_17__16   |
    | 1897134__400__31_31_158__97 |
    | 192127__300__17_17_35__25   |
    | 208150__400__19_19_52__0    |
    | 217012__300__11_13_20__18   |
    | 218889__400__10_10_40__92   |
    | 225196__300__3_3_8__1       |
    | 225561__300__18_19_27__29   |
    | 243916__300__18_18_29__63   |
    | 245700__300__10_13_42__41   |
    | 282961__300__19_19_36__77   |
    | 295835__300__23_23_63__88   |
    | 299083__400__2_10_63__30    |
    | 299968__300__14_15_27__75   |
    | 329663__300__7_7_10__89     |
    | 358242__400__17_17_67__23   |
    | 429816__400__4_16_74__73    |
    | 509887__400__19_28_85__22   |
    | 567666__300__26_26_122__27  |
    | 5786688__400__32_32_257__47 |
    | 600053__300__15_27_127__59  |
    | 665218__400__23_23_95__53   |
    | rdm1000_0                   |
    | rdm1000_1                   |
    | rdm1000_2                   |
    | rdm1000_3                   |
    | rdm1000_4                   |
    | rdm1000_5                   |
    | rdm200_0                    |
    | rdm200_10                   |
    | rdm200_11                   |
    | rdm200_12                   |
    | rdm200_13                   |
    | rdm200_14                   |
    | rdm200_15                   |
    | rdm200_1                    |
    | rdm200_20                   |
    | rdm200_21                   |
    | rdm200_22                   |
    | rdm200_23                   |
    | rdm200_24                   |
    | rdm200_25                   |
    | rdm200_2                    |
    | rdm200_30                   |
    | rdm200_31                   |
    | rdm200_32                   |
    | rdm200_33                   |
    | rdm200_34                   |
    | rdm200_35                   |
    | rdm200_3                    |
    | rdm200_4                    |
    | rdm200_5                    |
    | rdm20_0                     |
    | rdm20_10                    |
    | rdm20_11                    |
    | rdm20_12                    |
    | rdm20_13                    |
    | rdm20_14                    |
    | rdm20_15                    |
    | rdm20_1                     |
    | rdm20_20                    |
    | rdm20_21                    |
    | rdm20_22                    |
    | rdm20_23                    |
    | rdm20_24                    |
    | rdm20_25                    |
    | rdm20_2                     |
    | rdm20_30                    |
    | rdm20_31                    |
    | rdm20_32                    |
    | rdm20_33                    |
    | rdm20_34                    |
    | rdm20_35                    |
    | rdm20_3                     |
    | rdm20_4                     |
    | rdm20_5                     |
    | rdm20_6                     |
    | rdm50_0                     |
    | rdm50_10                    |
    | rdm50_11                    |
    | rdm50_12                    |
    | rdm50_13                    |
    | rdm50_14                    |
    | rdm50_15                    |
    | rdm50_1                     |
    | rdm50_20                    |
    | rdm50_21                    |
    | rdm50_22                    |
    | rdm50_23                    |
    | rdm50_24                    |
    | rdm50_25                    |
    | rdm50_2                     |
    | rdm50_30                    |
    | rdm50_31                    |
    | rdm50_32                    |
    | rdm50_33                    |
    | rdm50_34                    |
    | rdm50_35                    |
    | rdm50_3                     |
    | rdm50_4                     |
    | rdm50_5                     |
    | real_0                      |
    | real_10                     |
    | real_11                     |
    | real_12                     |
    | real_13                     |
    | real_14                     |
    | real_15                     |
    | real_16                     |
    | real_17                     |
    | real_18                     |
    | real_19                     |
    | real_1                      |
    | real_2                      |
    | real_3                      |
    | real_4                      |
    | real_5                      |
    | real_6                      |
    | real_7                      |
    | real_8                      |
    | real_9                      |
