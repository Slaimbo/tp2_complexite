#!/bin/bash

if [ "$1" = "-r" ]
then
	g=`./gen_graph.bash $2`
else
	g=$1
fi

make gen_fnc_graph.exe > videordure.ord
echo $g
./gen_fnc_graph.exe $g > graph_cnf.cnf
minisat graph_cnf.cnf graph.output > videordure.ord

test=`cat graph.output | grep -Eo "(SAT)|(UNSAT)"`

if [ $test = "UNSAT" ]
then
	echo "Ce Graph n'est pas trois coloriables."

else
	echo "Ce Graph est trois coloriables."
	res=`cat graph.output | tr ' ' '\n' | grep -Ev "(\-)|SAT|(^0)" `

	cpt=1
	for line in $res
	do
		echo "Sommet numero $cpt de couleur $(( ($line - 1)%3 + 1))"
		(( cpt=$cpt+1 ))
	done
fi
