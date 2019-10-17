// -*- mode: C++; c-file-style: "cc-mode" -*-
//*************************************************************************
// DESCRIPTION: Verilator fuzzing wrapper for verilator_bin
//
// Copyright 2019 by Eric Rippey.  This program is free software; you can
// redistribute it and/or modify it under the terms of either the GNU
// Lesser General Public License Version 3 or the Perl Artistic License
// Version 2.0.
//*************************************************************************

#include <unistd.h>
#include <cstdlib>
#include <cassert>

// The purpose of this script is to make sure that the results folder that
// is generated by running verilator does not change the results of
// subsequent runs.

// This does slow down the execution to some degree but makes the results
// more reliable.

int main(int argc, char **argv, char **envp) {
    auto r = system("rm -rf obj_dir");
    assert(r==0);
    return execve("../../bin/verilator_bin",argv,envp);
}
