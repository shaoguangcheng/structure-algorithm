#include <stdio.h>
#include <time.h>
#include <algorithm>

void printArray(int *a, int n)
{
	for(int i = 0;i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void mySwap(int& x, int& y)
{
    if(x != y){
		x ^= y;
		y ^= x;
		x ^= y;
    }
}

void myReverse(int* array, int start,int end)
{
    if(start >= end)
       return;

	const int tmp = end + start;
	const int t = tmp/2;
	for(int i = start; i <= t; ++i)
		mySwap(array[i], array[tmp-i]);
}

void nextPermutation(int* array, int n)
{
	int i = n-2, j = n-1;
	int p;

	while(array[i] >= array[j]){
		--i;
		if(i < 0)
			return;
		--j;
	}

	for(p = j; p < n; ++p){
		if(array[p] <= array[i])
			break;
	}

	mySwap(array[i], array[p-1]);

	myReverse(array, j, n-1);
}

int fun(int n)
{
	if(1 == n)
		return 1;
	return n*fun(n-1);
}

void allPermutation_1(int* array, int n)
{
	const int N = fun(n);

	for(int i = 1; i < N; ++i){
		nextPermutation(array, n);
	}	
}

void allPermutation_2(int* array, int n)
{
	const int N = fun(n);

	for(int i = 1; i < N; ++i){
		std::next_permutation(array, array+n);
	}	
}

void allPermutation_3(int* array, int index, int n)
{
	if(index == n){
		printArray(array, n);
		return;
	}
		
	for(int i = index; i < n; ++i){
		mySwap(array[index], array[i]);
		allPermutation_3(array, index+1, n);
		mySwap(array[index], array[i]);
	}
}

void allPermutation_4(int* array, int index, int n)
{
	if(index < n);
		printArray(array, n);

	for(int i = index; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			mySwap(array[i], array[j]);
			allPermutation_4(array, i+1, n);
			mySwap(array[i], array[j]);
		}
	}
}

int main(void)
{
	const int N = 3;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 13, 14, 15};

	clock_t start = clock();
	allPermutation_1(array, N);
	clock_t end = clock();
	printf("dictionary sequence method: %ld\n", end - start);

	std::sort(array, array+N);

	start = clock();
	allPermutation_2(array, N);;
	end = clock();
	printf("STL method: %ld\n", end - start);

	std::sort(array, array+N);

	start = clock();
	allPermutation_3(array, 0, N);
	end = clock();
	printf("Recursive method 1: %ld\n", end - start);

	std::sort(array, array+N);

	start = clock();
	allPermutation_4(array, 0, N);
	end = clock();
	printf("Recursive method 2: %ld\n", end - start);

	return 0;
}