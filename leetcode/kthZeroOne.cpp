#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, K;
    int count = 0;

    cin >> count;

    while(count--){
    	cin >> N >> M >> K;

	    char* v = new char [N+M+1];

	    v[N+M] = '\0';

	    for(int i = 0; i < N+M; ++i){
	        if(i < N)
	            v[i] = '0';
	        else
	            v[i] = '1';
	    }

	    for(int i = 1; i < K; ++i)
	        next_permutation(v, v+N+M);

	  	for(int i = 0; i < N+M; ++i)
	    	cout << v[i];
	  	cout << endl;

	  	delete [] v;
	}

  return 0;
}

