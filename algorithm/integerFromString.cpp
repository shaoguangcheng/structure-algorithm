#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

bool isDigit(char ch){
	if(ch <= '9' && ch >= '0')
		return true;
	else
		return false;
}

void integerFromString(const char* s, std::vector<int>& ret)
{
	if(NULL == s)
		return;

	bool isIntegerLastChar = false;
	int tmp = 0;
	
	for(int i = 0; s[i] != '\0'; ++i){
		if(isIntegerLastChar && (!isDigit(s[i]))){
			isIntegerLastChar = false;
			ret.push_back(tmp);
			tmp = 0;
		}

		if(isDigit(s[i])){
			isIntegerLastChar = true;
			tmp = 10*tmp + s[i] - '0';
		}
	}

	if(isIntegerLastChar)
		ret.push_back(tmp);
}

int main()
{
	const char* s = "123tft7";

	std::vector<int> v;

	integerFromString(s, v);

	for(int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);

	printf("\n");

	return 0;
}
