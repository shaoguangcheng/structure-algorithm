#include <vector>
#include <iostream>

using namespace std;

void help(vector<int> v, int l, int r, int k, int t, int& n)
{
	int N = r - l + 1;
	if(k == 1){
		for(int i = l; i <= r; ++i){
			if(v[i] == t){
				++n;
				break;
			}
		}

	return;
	}

	for(int i = l; i <= r; ++i){
		help(v, i+1, r, k-1, t-v[i], n);
	}
}

int main()
{
	int array[4] = {1,2,3,4};
	int n = 0;


	vector<int> v(array, array+4);

	help(v, 0, v.size()-1, 2, 5, n);
	cout << n << endl;

	return 0;
}