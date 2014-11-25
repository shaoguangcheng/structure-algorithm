/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <iostream>
#include <string>

using namespace std;

#define MIN(x,y) ((x) > (y) ? (y) : (x))

int editDistance(const string& s1, const string& s2)
{
	const int N = s1.size(), M = s2.size();

	if(0 == N)
		return M;
	if(0 == M)
		return N;

	int **distance = new int* [N+1];
	if(distance == NULL)
		throw logic_error("error");
	for(int i = 0; i < N+1; ++i){
		distance[i] = new int [M+1];
		if(distance[i] == NULL)
			throw logic_error("error");
	}

	for(int i = 1; i < N+1; ++i)
		distance[i][0] = i;
	for(int j = 0; j < M+1; ++j)
		distance[0][j] = j;

	distance[0][0] = 0;

	for(int i = 1; i < N+1; ++i){
		for(int j = 1; j < M+1; ++j){
			distance[i][j] = MIN(distance[i-1][j]+1, distance[i][j-1]+1); // deletion and insertion
			if(s1[i-1] == s2[j-1]) // substition
				distance[i][j] = MIN(distance[i][j], distance[i-1][j-1]);
			else
				distance[i][j] = MIN(distance[i][j], distance[i-1][j-1]+1);
		}
	}

	int ans = distance[N][M];
	
	for(int i = 0; i < N+1; ++i)
		delete [] distance[i];
	delete [] distance;
	return ans;
}

int main()
{
	string s1("bc"), s2("abc");
	cout << editDistance(s1, s2) << endl;
	return 0;
}