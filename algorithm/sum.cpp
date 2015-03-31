#include <stdio.h>
#include <stdlib.h>

///////////////method 1/////////////////////////////
typedef int (*func)(int x);

int return0(int n)
{
	return 0;
}

int sumCore(int n)
{
	func funArray[] = {return0, sumCore};
	return funArray[!!n](n-1)+n;
}

//////////////////method 2/////////////////////////
template <int n>
int sumCore_1()
{
	return n+sumCore_1<n-1>();
}

template <>
int sumCore_1<1>()
{
	return 1;
}

/////////////////method 3/////////////////////////
class base;
base* ptr[2];

class base
{
public:
	virtual int returnN(int n){return 0;}
};

class derived : public base
{
public:
	virtual int returnN(int n){return ptr[!!n]->returnN(n-1)+n;}
};

int sumCore_2(int n)
{
	base b;
	derived d;

	ptr[0] = &b;
	ptr[1] = &d;

	return ptr[1]->returnN(n);
}

int main()
{
	printf("sum from 1 to 100 : %d\n", sumCore_2(100));	

	return 0;
}

