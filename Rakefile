desc "Clean the repository and build using Nix"
task :build do
  puts "Running 'git clean -fxd'..."
  system("git clean -fxd") or abort("git clean failed!")

  puts "Running 'nix-build'..."
  system("nix-build") or abort("nix-build failed!")

  puts "Build completed successfully!"
  system("./result/bin/asgl") or abort("asgl failed!")
end

desc "Run the internal self-check"
task :check do
  system("ASGL_HOME=$(pwd) ./result/bin/asgl --check") or abort("asgl --check failed!")
end

desc "Run the cucumber feature tests (very fast)"
task :test_very_fast do
  system("ln -sf ../result/bin/asgl bin/asgl") or abort("ln -s failed!")
  system("cucumber features/informational.feature") or abort("cucumber failed!")
end

desc "Run the cucumber feature tests"
task :test do
  system("ln -sf ../result/bin/asgl bin/asgl") or abort("ln -s failed!")

  system("rm -rf data/iccma15_testcases && tar xf data/iccma15_testcases.tar.xz")
  system("rm -rf data/real-ee-gr-solutions && tar -C data -xf data/real-ee-gr-solutions.tar.xz")
  system("rm -rf data/iccma15_solutions && tar xf data/iccma15_solutions.tar.xz && bash support/fixes.sh")

  system("cucumber") or abort("cucumber failed!")
end
