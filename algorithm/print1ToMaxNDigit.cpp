#include <stdio.h>

void printNum(char* num)
{
	bool isPrint = false;

	for(int i = 0; num[i] != '\0'; ++i){
		if(!isPrint && num[i] != '0')
			isPrint = true;
		if(isPrint)
			printf("%c", num[i]);
	}

	printf("\n");
}

void print1ToMaxNDigitCore(char* num, int length, int index)
{
	if(index > length){
		printNum(num);
		return;
	}

	for(int i = 0; i < 10; ++i){
		num[index] = char(i + '0');
		print1ToMaxNDigitCore(num, length, index+1);
	}
}

void print1ToMaxNDigit(int N)
{
	char* num = new char [N+1];

	memset(num, 0, N);
	num[N] = '\0';	

	print1ToMaxNDigitCore(num, N, 0);

	delete num;
}

int main()
{
	print1ToMaxNDigit(1);
}