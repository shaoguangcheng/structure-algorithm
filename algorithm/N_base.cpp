// N_base.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stack>

using namespace std;

// ��ʮ��������nת��Ϊm����
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

// ����n�Ķ�������1�ĸ���
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

