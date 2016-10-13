#!/bin/bash

nb_sommets_max=$1

nb_sommets=$(( $RANDOM % $nb_sommets_max + 2 ))
nb_aretes_max=$(( ( ($nb_sommets*$nb_sommets) - $nb_sommets ) / 2 ))
nb_aretes=$(( $RANDOM % $nb_aretes_max + 1 ))

#echo "nb_sommets_max : $nb_sommets_max "
#echo "nb_sommets : $nb_sommets "
#echo
#echo "nb_aretes_max  : $nb_aretes_max  "
#echo "nb_aretes  : $nb_aretes  "
#echo
#echo "Generation du graph ..."


i=0

for(( i = 0; i < $nb_aretes; i++ ))
do
	s1="$(( $RANDOM % $nb_sommets + 1 ))"
	s2="$(( $RANDOM % $nb_sommets + 1 ))"

	test1=`echo $res | grep -c "$s1 $s2"`
	test2=`echo $res | grep -c "$s2 $s1"`
	test=$(( $test1 + $test2 ))

	if (( $s1 != $s2 && $test == 0 ))
	then
		res="$res|$s1 $s2"
	else
		let i--
	fi
done

res="$nb_sommets $nb_aretes $res"
echo `echo $res | tr '|' ' '`
