#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string query("abcabcdakc");
	string text("bcbdac");

	const int m = query.size();
	const int n = text.size();
	int max= -1;

	int **c = new int* [m+1];
	for(int i=0;i<m+1;i++)
		c[i] = new int [n+1];

	for(int i=0;i<m+1;i++)
		c[i][0] = 0;
	for(int i=0;i<n+1;i++)
		c[0][i] = 0;

	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(query[i-1] == text[j-1])
				c[i][j] = c[i-1][j-1]+1;
			else
				c[i][j] = 0;

			if(c[i][j] > max)
				max = c[i][j]; 
		}

	}

	for(int i=0;i<m+1;i++)
		delete [] c[i];

	delete [] c;	

	cout << max << endl;
	return 0;
}