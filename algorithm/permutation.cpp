#include <stdio.h>
#include <time.h>

#include <vector>

using namespace std;

static int nTimes = 0;

void mySwap(int* x, int* y)
{
	if(x != y){
		int t = *x;
		*x = *y;
		*y = t;
	}
}

void permutation1(vector<int>& v, int index)
{
	if(index == v.size()){
	/*	for(int i = 0; i < v.size(); ++i){
			printf("%d ", v[i]);
		}
		printf("\n"); */
		return;
	}

	nTimes++;

	for(int i = index; i < v.size(); ++i){
		mySwap(&v[index], &v[i]);
		permutation1(v, index+1);
		mySwap(&v[index], &v[i]);
	}
}

void permutation2(std::vector<int>& v, int index) // better method
{
	/*
	if(index < v.size()){
		for(int i = 0; i < v.size(); ++i){
			printf("%d ", v[i]);
		}
		printf("\n");	
	}
	else
		return;
	*/

	if(index >= v.size())
		return;

	nTimes++;

	for(int i = index; i < v.size(); ++i){
		for(int j = i+1; j < v.size(); ++j){
			mySwap(&v[i], &v[j]);
			permutation2(v, i+1);
			mySwap(&v[i], &v[j]);
		}
	}
}

//////////////////////////////////////////////////
bool isSelect(std::vector<int> v, int i, int j)
{
	for(int k = i; k < j; ++k)
		if(v[j] == v[k])
			return false;

	return true;
}

void selectK(std::vector<int> v, int index, std::vector<int>& result, int k)
{
	if(0 == k){
		for(int i = 0; i < result.size(); ++i){
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}

/*	if(0 == k){
		nTimes++;
		return;
	}
*/
	const int n = v.size();

	for(int i = index; i <= n-k; ++i){
		if(isSelect(v, index, i)){
			result.push_back(v[i]);
			selectK(v, i+1, result, k-1);
			result.pop_back();
		}
	}
}

void selectK(std::vector<int> v, int k)
{
	std::vector<int> result;

	selectK(v, 0, result, k);
}

////////////////////////////////////////////////
void arange(std::vector<int> v)
{
	const int n = v.size();
	for(int i = 1; i <= n; ++i)
		selectK(v, i);
}

int main()
{
	int array[] = {1,2,2,3};
	std::vector<int> v(array, array+4);

	clock_t start = clock();
//	permutation2(v, 0);
//	selectK(v, 2);
	arange(v);
	clock_t end = clock();

	printf("nTimes = %d, time consumed = %ld\n", nTimes, end - start);

	return 0;
}