#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& v, int k, int start, int end)
{
	int i = start + 1, j = start + 1, pivot = v[start];

	int tmp;
	for(; i <= end; ++i){
		if(v[i] > pivot){
			tmp = v[i];
			v[i] = v[j];
			v[j++] = tmp;
		}
	}

	v[start] = v[j-1];
	v[j-1] = pivot;
	if(k == j)
		return v[j-1];
	if(k > j)
		return partition(v, k, j, end);
	else
		return partition(v, k, start, j-2); 
}

int getKNumber(vector<int>& v, int k)
{
	int N = v.size();
	if(N < k)
		throw logic_error("error");

	return partition(v, k, 0, N-1);
}

int main()
{
	int array[10] = {2,3,4,2,18,9,4,32,3,21};
	vector<int> v(array, array+10);
	cout << getKNumber(v,6) << endl;
	for(int i = 0; i < 10; ++i)
		cout << v[i] << " ";
	return 0;
}