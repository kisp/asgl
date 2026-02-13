desc "Clean the repository and build using Nix"
task :build do
  puts "Running 'git clean -fxd'..."
  system("git clean -fxd") or abort("git clean failed!")

  puts "Running 'nix-build'..."
  system("nix-build") or abort("nix-build failed!")

  puts "Build completed successfully!"
  system("./result/bin/asgl") or abort("asgl failed!")
end
