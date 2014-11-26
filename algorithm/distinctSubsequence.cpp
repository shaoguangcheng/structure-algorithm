
#include <iostream>
#include <string>

using namespace std;

int numDistinct(string& S, string & T)
{
	int N = S.size(), M = T.size();

	if(0 == N)
		return 0;

	int **d = new int* [N+1];
	for(int i = 0; i < N+1; ++i)
		d[i] = new int [M+1];

	for(int i = 0; i < N+1; ++i)
		for(int j = 0; j < M+1; ++j)
			d[i][j] = 0;

	for(int i = 1; i < N+1; ++i)
		d[i][0] = 1;

	for(int i = 1; i < N+1; ++i){
		for(int j = 1; j < M+1; ++j){
			if(S[i-1] == T[j-1])
				d[i][j] = d[i-1][j] + d[i-1][j-1];
			else
				d[i][j] = d[i-1][j];
		}
	}

	for(int i = 0; i < N+1; ++i){
		for(int j = 0; j < M+1; ++j)
			cout << d[i][j] << " ";
		cout << endl;	
	}

	int ans = d[N][M];
	for(int i = 0; i < N; ++i)
		delete [] d[i];
	delete [] d;

	return ans;
}

int main()
{
	string s("rabbbit"), t("rabbit");
	cout << numDistinct(s, t) << endl;
	return 0;
}