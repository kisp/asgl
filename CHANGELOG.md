# Changelog

All notable changes to ASGL. The format follows
[Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

The command line stays compatible with the ICCMA 2015 interface:
`-p PROBLEM -fo apx -f FILE [-a ARGUMENT]`, `--formats`, `--problems`, the
answers in brackets and `YES`/`NO`, and author and version without
arguments. What is new adds to it.

## [Unreleased]

## [0.2.0] - 2026-10-24

### Added

- `-h` / `--help` prints the usage; `-v` / `--version` prints the version
  and the short commit the build is from: `ASGL version 0.2.0 (1a7da06)`,
  `(1a7da06-dirty)` for a working tree with changes. The commit comes from
  the flake (`self.shortRev`) or from git in a checkout; a build with
  neither prints the version alone.
- The framework is read from the standard input when `-f` is left out or is
  `-`: `echo 'arg(a).arg(b).att(a,b).' | asgl -p EE-PR`.
- Statements of an apx file need no separator between them, so a framework
  fits on one line; whitespace may be space, tab, CR or LF, so files with
  CRLF line ends are read.
- A mistake in the command line or the input is reported in one line on the
  standard error, `ERROR: ...`, with exit status 2 and without a backtrace:
  an unknown option, an option without its value or given twice, no `-p`, a
  problem ASGL does not solve, a format other than apx, a missing file, an
  empty input, input that is not apx, an attack on an argument that no
  `arg(...)` declares, `-a` missing for a DC- or DS- problem, `-a` given for
  another problem, and `-a` naming an argument the framework does not have.
  Unexpected errors keep their backtrace and exit status 1.
- Nix: `flake.nix`, so `nix build github:kisp/asgl` and
  `nix profile install github:kisp/asgl` work; `nix flake check` runs the
  whole test suite (`checks.self-check`, `checks.features`), and
  `nix run .#self-check -- FILE` the unit tests of FILE.
- Tests: `tests/tests-apx-syntax.lisp`, the syntax of apx as both grammars
  read it, to run before and after a change of a grammar;
  `features/command-line.feature`; and
  `features/command-line-suite.feature`, a generated suite of 95 scenarios
  for the command line: every two classes of an invocation together, every
  two classes of the input together in a run that succeeds, and every
  outcome.

### Changed

- An argument declared twice, `arg(a). arg(a).`, is one argument.
- Options are parsed strictly: only those ASGL takes, each once, each with
  its value.
- The copyright years are 2015-2026.
- The version is kept in one place, the file `VERSION`; `default.nix` and
  `asgl.lisp` read it.

### Fixed

- A newline inside `arg(...)`, as in `arg(\na\n).`, crashed the parser
  (index out of range): the two grammars read the name differently.
- An attack on an undeclared argument crashed the same way.
- `arg(a). arg(a).` gave a phantom argument `NIL`: `[[a,NIL]]`.
- A DC- or DS- problem without `-a`, or with `-a` naming an unknown
  argument, crashed with exit status 1.
- A repeated option was silently accepted, the first value winning; `-a`
  with an EE- or SE- problem was silently ignored.
- An empty file failed in `slurp_file`.
- `asgl -h` and any unknown option ended in a backtrace.
- The version, written into `asgl.lisp` by hand in 2015, was
  `v0.1.4-40-g0e7355d`, naming a commit that is not in the repository.

## [0.1.4] - 2015-10-05

The tag v0.1.4. For it and before, see the git history.

[Unreleased]: https://github.com/kisp/asgl/compare/v0.2.0...HEAD
[0.2.0]: https://github.com/kisp/asgl/compare/v0.1.4...v0.2.0
[0.1.4]: https://github.com/kisp/asgl/releases/tag/v0.1.4
