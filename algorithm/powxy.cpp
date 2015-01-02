// powxy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>

using namespace std;

// compute pow(x, y)
bool equal(double x, double y)
{
	if ((x-y) < 1e-6 && (x-y) > -1e-6)
		return true;
	else
		return false;
}

double powerWithUnsignedExp(double base, unsigned int exponent)
{
	double result = 1.0;
	for (unsigned int i = 0; i < exponent; ++i)
		result *= base;
	return result;
}

double powerWithUnsignedExp2(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = powerWithUnsignedExp2(base, exponent >> 1);
	result *= result;

	if (exponent & 1 == 1)
		return base*result;
	else
		return result;
}

double powxy(double base, int exponent)
{
	if (equal(base, 0)){
		if (exponent <= 0)
			throw new exception("invliad input");
		else
			return 0;
	}
	else{
		if (exponent == 0)
			return 1;
		else{
			if (exponent > 0)
				return powerWithUnsignedExp(base, exponent);
			else
				return 1.0 / powerWithUnsignedExp(base, -1*exponent);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%lf\n", powxy(0, 1));
	printf("%lf\n", powxy(2, 0));
	printf("%lf\n", powxy(3, 3));
	printf("%lf\n", powxy(3, -1));
	return 0;
}

