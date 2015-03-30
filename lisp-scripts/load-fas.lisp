(load "common/asgl-config/asgl-config.fas")
(load "common/early/early.fas")
(load "lib/alexandria/alexandria.fas")
(load "lib/arnesi-list-match/arnesi-list-match.fas")
(load "lib/myam/myam.fas")
(let ((lib-dir "/nix/store/n8s5yghc01vvs9lmlkkn1k0mg6g7zyb8-gecode-4.3.3/lib/"))
  (dolist (lib '("libgecodesearch.so.40"
                 "libgecodeint.so.40"
                 "libgecodeset.so.40"
                 "libgecodeminimodel.so.40"
                 "libgecodekernel.so.40"
                 "libgecodesupport.so.40"
                 "libgecodegist.so.40"))
    (ffi:load-foreign-library (merge-pathnames lib lib-dir))))
(load "v1/v1.fas")
