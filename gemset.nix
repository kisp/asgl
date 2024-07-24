{
  aruba = {
    dependencies = ["childprocess" "cucumber" "rspec-expectations"];
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "0hlq03shd7cl72n7nark8dm5gdrsjpcqkxd2qrkcjzd35nkqqlbw";
      type = "gem";
    };
    version = "0.6.2";
  };
  builder = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "14fii7ab8qszrvsvhz6z2z3i4dw0h41a62fjr2h1j8m41vbrmyv2";
      type = "gem";
    };
    version = "3.2.2";
  };
  childprocess = {
    dependencies = ["ffi"];
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "0cxzh17vjlmpqfcas4815x50dc1gzfwgbs51zzpd4chrl6ak4n4v";
      type = "gem";
    };
    version = "0.5.5";
  };
  cucumber = {
    dependencies = ["builder" "diff-lcs" "gherkin" "multi_json" "multi_test"];
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "170a0yclrc1i9m5wjgwzga3ipb5mbapiha8jcg0g2gjnmzvd77nr";
      type = "gem";
    };
    version = "1.3.19";
  };
  diff-lcs = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "1vf9civd41bnqi6brr5d9jifdw73j9khc6fkhfl1f8r9cpkdvlx1";
      type = "gem";
    };
    version = "1.2.5";
  };
  ffi = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "0ph098bv92rn5wl6rn2hwb4ng24v4187sz8pa0bpi9jfh50im879";
      type = "gem";
    };
    version = "1.9.8";
  };
  gherkin = {
    dependencies = ["multi_json"];
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "1mxfgw15pii1jmq00xxbyp77v71mh3bp99ndgwzfwkxvbcisha25";
      type = "gem";
    };
    version = "2.12.2";
  };
  multi_json = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "1mg3hp17ch8bkf3ndj40s50yjs0vrqbfh3aq5r02jkpjkh23wgxl";
      type = "gem";
    };
    version = "1.11.0";
  };
  multi_test = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "1sx356q81plr67hg16jfwz9hcqvnk03bd9n75pmdw8pfxjfy1yxd";
      type = "gem";
    };
    version = "0.1.2";
  };
  rspec-expectations = {
    dependencies = ["diff-lcs" "rspec-support"];
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "08ba5hprb3kf849yylkxm9dd9lfazh7gapiqxy5lapwqxbqpa3ky";
      type = "gem";
    };
    version = "3.2.0";
  };
  rspec-support = {
    groups = ["default"];
    platforms = [];
    source = {
      remotes = ["https://rubygems.org"];
      sha256 = "194zry5195ls2hni7r9824vqb5d3qfg4jb15fgj8glfy0rvw3zxl";
      type = "gem";
    };
    version = "3.2.2";
  };
}
