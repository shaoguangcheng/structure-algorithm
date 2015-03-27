#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

void minHeapInsert(int* ret, int k, int val)
{
  int p,q;

  if(val <= ret[0])
	return;

  p = 0;
  ret[p] = val;
  while(p < k){
	q = 2*p+1;
	if(q >= k)
	  break;
	if((q < k-1)&&(ret[q+1] < ret[q]))
	  q = q+1;
	if(ret[q] < ret[p]){
	  int t = ret[q];
	  ret[q] = ret[p];
	  ret[p] = t;
	  p = q;
	}
	else
	  break;
  }
}

void kLargeNum(const int* array, int N, int* ret, int k)
{
  if(array == NULL || N <= 0 || ret == NULL || k <=0 ){
	printf("Invalid input\n");
	return;
  }
	
  for(int i = 0; i < k; ++i)
	ret[i] = INT_MIN; // initialize a min heap

  for(int i = 0; i < N; ++i){
	if(array[i] > ret[0]){
	  minHeapInsert(ret, k, array[i]);
	}
  }
}

int main()
{
  int array[] = {1,2,3,1,2,3,5,6,7};

  int k = 3;
  int* ret = new int [k];

  kLargeNum(array, 9, ret, k);

  for(int i = 0; i < k; ++i){
	printf("%d ", ret[i]);
  }
  printf("\n");

  delete [] ret;

  return 0;
}
