#!/bin/sh

sbcl --eval "(require 'sb-cover)" \
    --eval '(asdf:load-system :arnesi)' \
    --eval '(asdf:load-system :cl-fad)' \
    --eval "(asdf:oos 'arnesi:clean-op :myam)" \
    --eval "(asdf:oos 'arnesi:clean-op :myam-test)" \
    --eval '(declaim (optimize sb-cover:store-coverage-data))' \
    --eval '(asdf:test-system "myam")' \
    --eval '(cl-fad:delete-directory-and-files "/tmp/report/" :if-does-not-exist :ignore)' \
    --eval '(sb-cover:report "/tmp/report/")' \
    --eval '(quit)'
