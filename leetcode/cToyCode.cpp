#include <stdio.h>

int main()
{
	int x = 10, y = 10;
		
	x = x++;
	y = ++y;

	printf("%d, %d\n", x, y);

	return 0;
}