#!/bin/sh

sbcl --eval '(asdf:load-system :arnesi)' \
     --eval "(asdf:oos 'arnesi:clean-op :myam)" \
     --eval "(asdf:oos 'arnesi:clean-op :myam-test)" \
     --eval '(asdf:test-system "myam")' \
     --eval '(quit)'
