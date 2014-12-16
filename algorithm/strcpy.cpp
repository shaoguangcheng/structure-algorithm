#include <stdio.h>

char* my_strcpy(const char* src, char* dst)
{
	assert(src != NULL);
	assert(dst != NULL);

	char* ret = dst;
	int i = 0;
	for(;src[i] != '\0'; ++i)
		dst[i] = src[i];
	dst[i] = '\0';
	return ret;
}

int main()
{
	char src[10] = "here";
	char dst[10];

	my_strcpy(src, dst);

	return 0;
}