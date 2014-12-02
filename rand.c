#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;

	srand(time(NULL));
	
	x=rand()%52;
	printf("\n%i",x);
	
	printf("\n");

	return 0;
}
