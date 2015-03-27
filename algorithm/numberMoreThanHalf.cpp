#include <stdio.h>
#include <stdlib.h>

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

int main()
{
  int data[] = {1,2,9,4,5,3,3,4,3,4};

  printf("%d\n", numberMoreThanHalf(data, 10));

  return 0;
}
