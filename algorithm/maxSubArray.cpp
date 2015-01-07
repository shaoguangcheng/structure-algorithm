#include <iostream>
#include <exception>
#include <limits.h>

using namespace std;

int findMaxSubArray(int* array, int size)
{
  if(array == NULL || size <= 0)
    return INT_MIN;

  int result = INT_MIN;
  int sum = 0;
  for(int i = 0; i < size; ++i){
    sum += array[i];
    if(sum < 0)
      sum = 0;
    if(sum > result)
      result = sum;
  }

  return result;
}

int main()
{
  int array[8] = {1,-2,3,10,-4,7,2,-5};

  cout << findMaxSubArray(array, 8) << endl;

  return 0;
}
