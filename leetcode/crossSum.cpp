#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void crossSum(string& num, int& tmp)
{
	const int size = num.size();

	int flag = 1;
	tmp = 0;
	for(int i = 0; i < size; ++i){
		tmp += flag*(num[i] - '0');
		flag *= -1; 
	}
}

void sum_(string& a, string& b, string& d)
{
	const int aSize = a.size(), bSize = b.size();
	const int size = max(aSize, bSize);

	string c;

	c.resize(size+1);

	int flag = 0;
	int i;
	for(i = 0; i < size; ++i){
		int aDigit = 0, bDigit = 0, tmp;
		if(aSize - i > 0)
			aDigit = a[aSize-1-i] - '0';
		
		if(bSize - i > 0)
			bDigit = b[bSize-1-i] - '0';

		tmp = flag + aDigit + bDigit;
		if(tmp >= 10){
			flag = 1;
			tmp -= 10;
		}
		else
			flag = 0;
		c[size-i] = char(tmp + '0');
	}

	if(flag != 0){
		c[0] = char(flag+'0');
		d = c;
	}
	else
		d = c.substr(1, size);
}

void solve(string& low, string& upper, string& s, int k)
{
	string one("1");
	string tmp(low);

	sum_(upper, one, upper);

	int tmpCrossSum = 0;
	while(tmp != upper){
		crossSum(tmp, tmpCrossSum);
		if(tmpCrossSum == k){
			sum_(s, tmp, s);
		}

		sum_(tmp, one, tmp);
	}
}


int main()
{
	string low, upper, s;
	int k;

	cin >> low >> upper;
	cin >> k;

	solve(low, upper, s, k);

	cout << s << endl;

	return 0;
}