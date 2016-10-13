#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char ** argv)
{
	int nb_som = atoi(argv[1]); //nombre de sommets
	int nb_arr = atoi(argv[2]); //nombre d'aretes
	int* arr = new int[2*nb_arr];
	for(int i = 0; i < 2*nb_arr; i++)
		arr[i] = atoi(argv[i+3]);

	int** var;
  	int var_temp = 1;

  	var = new int*[nb_som];
  
  	for( int i = 0; i < nb_som; i++)
    		var[i] = new int[3];

  	for( int i = 0; i < nb_som; i++)
    		for( int j = 0; j < 3 ; j++)
      		{
			var[i][j] = var_temp;
			var_temp++;
      		}
  
	cout << "p cnf " << nb_som * 3 << ' ' << 4 * nb_som + 3 * nb_arr << endl;

	for(int i = 0; i < nb_som; i++)
	{
		cout << '-' << var[i][1] << " -" << var[i][0] << " 0" << endl;
		cout << '-' << var[i][2] << " -" << var[i][0] << " 0" << endl;
		cout << '-' << var[i][2] << " -" << var[i][1] << " 0" << endl;
		cout << var[i][0] << ' ' << var[i][1] << ' ' << var[i][2] << " 0" << endl;
	}

	for(int i = 0; i < nb_arr * 2; i += 2)
	{
		cout << '-' << var[arr[i] - 1][0] << " -" << var[arr[i+1] - 1][0] << " 0" << endl;
  		cout << '-' << var[arr[i] - 1][1] << " -" << var[arr[i+1] - 1][1] << " 0" << endl;
  		cout << '-' << var[arr[i] - 1][2] << " -" << var[arr[i+1] - 1][2] << " 0" << endl;
	}

  	return 0;
}
