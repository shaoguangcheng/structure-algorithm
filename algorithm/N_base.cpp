// N_base.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

using namespace std;

// 将十进制数字n转化为m进制
///////////////////////////////////////////////////
void n_base1(unsigned int n, int m){
	stack<int> s;
	while (n > 0){
		s.push(n%m);
		n /= m;
	}

	int size = s.size();
	for (int i = 0; i < size; ++i){
		printf("%d", s.top());
		s.pop();
	}
}
//////////////////////////////////////

// 数字n的二进制中1的个数
int numberOfOne(int n)
{
	int count = 0;
	int flag = 1 << (sizeof(int) * 8-1);
	while (n){
		if ((n & flag) == flag)
			count++;
		n = n << 1;
	}

	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
  	return 0;
}

