#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////method 1/////////////////////////////
int numberMoreThanHalf(const int* num, int N)
{
  if(num == NULL || N <=0){
	printf("error input\n");
	exit(-1);
  }
  
  int ret, i, nTimes = 0;
  for(i = 0; i < N; ++i){
	if(nTimes == 0){
	  ret = num[i];
	  nTimes = 1;
	}
	else{
	  if(ret == num[i])
		++nTimes;
	  else
		--nTimes;
	}
  }

  nTimes = 0;
  for(i = 0; i < N; ++i){
	if(ret == num[i])
	  ++nTimes;
  }

  if(nTimes >= N/2)
	return ret;
  else{
	printf("no integer's number is more than half\n");
	exit(-1);
  }
}

/////////////////method 2/////////////////////////
// using hashtable (maybe map better)

int numberMoreThanHalf_2(const int* array, int N)
{
  if(array == NULL || N <=0){
	printf("error input\n");
	exit(-1);
  }
  
  int* hashTable = new int [N];
  
  memset(hashTable, 0, sizeof(int)*N);

  int key;
  for(int i = 0;i < N; ++i){
	key = array[i]%N;
	++hashTable[key];
  }
  
  for(int i = 0; i < N; ++i){
	key = array[i]%N;
	if(hashTable[key] >= N/2)
	  return array[i];
  }

  delete [] hashTable;

  printf("no integer's number is more than half\n");
  exit(-1);
}

int main()
{
  int data[] = {1,2,9,3,5,3,3,3,3,4};

  printf("%d\n", numberMoreThanHalf_2(data, 10));

  return 0;
}
