#include <iostream>

using namespace std;

bool isOdd(int x){
	return x&0x01;
}

void reorderOddEven1(int* array, int length, bool (*func)(int x))
{
	if(array == NULL || length <= 0)
		return;

	int i = -1, j = 0;
	int tmp;
	while(j < length){
		if(func(array[j])){
			++i;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			++j;
		}
		else
			++j;
	}
}

void reorderOddEven2(int* array, int length, bool (*func)(int x))
{
	if(array == NULL || length <= 0)
		return;

	int i = 0, j = length-1;
	int tmp;

	while(i < j){
		while(func(array[i]))
			++i;
		while(!func(array[j]))
			--j;

		if(i < j){
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		++i;
		--j;
	}	
}

int main()
{
	int array[6] = {1,2,3,4,5,6};

	reorderOddEven2(array, 6, isOdd);

	for(int i = 0; i < 6; ++i)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}