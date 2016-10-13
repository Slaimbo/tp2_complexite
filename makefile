gen_fnc_graph.exe: exercice_2_3.cpp
	g++ -Wall exercice_2_3.cpp -o gen_fnc_graph.exe

gen_chaussette.exe: exo_1_e_gen_dimacs.cpp
	g++ -Wall exo_1_e_gen_dimacs.cpp -o gen_chaussette.exe
	
clean:
	rm -f *.exe
