#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char ** argv)
{
  int n = atoi(argv[1]);
  int** var;
  int var_temp = 1;
  var = new int*[n+1];
  
  for( int i = 0; i < n+1; i++)
    var[i] = new int[n];

  for( int i = 0; i < n+1; i++)
    for( int j = 0; j < n ; j++)
      {
	var[i][j] = var_temp;
	var_temp++;
      }
  
  for(int i = 0; i < n+1; i++)
    {
      for( int j = 0; j < n; j++)
	cout << var[i][j] << ' ';
      cout << '0' << endl;
      for( int k = 0; k < n; k++)
	{
	  for( int l = 0; l < n; l++)
	    {
	      if( k != l)
		cout << '-' << var[i][k] << ' ' << '-' << var[i][l] << " 0"  << endl;
	    }
	}
    }
 
  for(int i = 0; i < n; i++)
    {
      for( int j = 0; j < n+1; j++)
	{
	  for( int k = 0; k < n+1; k++)
	    {
	      if( j != k)
		cout << '-' << var[j][i] << ' ' << '-' << var[k][i] << " 0"  << endl;
	    }
	}
    } 
  
  
  return 0;
}
