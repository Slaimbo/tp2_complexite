#!/bin/bash

rm -f test.cnf
make gen_chaussette.exe

let a="$1 * ($1 + 1)"
echo -n "p cnf $a " >> test.cnf
echo `./gen_chaussette.exe $1 | wc -l` >> test.cnf
./gen_chaussette.exe $1 >> test.cnf
minisat test.cnf
