#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <iterator>

using namespace std;

void countingSort(int *array, int min, int max, int N)
{
  if(array == NULL || N <=0 || max <= min){
	cout << "Error input\n" << endl;
	exit(-1);
  }

  int range = max - min + 1;
  
  int* arrayRange = new int [range];
  int* arraySorted = new int [N];

  memset(arrayRange, 0, range*sizeof(int));

  for(int i = 0; i < N; ++i){
	arrayRange[array[i]-min] += 1;
  }

  for(int i = 1; i < range; ++i){
	arrayRange[i] += arrayRange[i-1];
  }

  for(int i = N-1; i >= 0; --i){
	arraySorted[arrayRange[array[i]-min]-1] = array[i];
	arrayRange[array[i]-min] -= 1;
  }

  memcpy(array, arraySorted, N*sizeof(int));

  delete [] arrayRange;
  delete [] arraySorted;

  return;
}

int main()
{
  int array[] = {1,4,5,2,2,1};

  countingSort(array, 1, 5, 6);

  copy(array, array+6, ostream_iterator<int>(cout, " "));

  return 0;
}
