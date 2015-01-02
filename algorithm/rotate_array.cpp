// rotate_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <exception>

using namespace std;

int min_rotate_array(int *array, int length)
{
	if (array == NULL || length <= 0)
		throw new exception("invalid input");
	
	if (array[0] < array[length - 1])
		return array[0];

	int left = 0, right = length - 1, mid;
	while (left < right){
		if (right - left == 1)
			return array[right];

		mid = left + (right - left) / 2;

		if (array[mid] == array[left] &&
			array[left] == array[right])
			;
			// do search in order

		if (array[mid] <= array[right])
			right = mid;
		if (array[mid] >= array[left])
			left = mid;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array[5] = {4,5,1,2,3};

	printf("%d\n", min_rotate_array(array, 5));

	return 0;
}

