#include <stdio.h>
#include <stdlib.h>
#include "ordination.h"




int main(int argc, char const *argv[])
{
	int vector[9] = {10,4,2,-100,9,2,-1,-7,40};
	unsigned i;
	void* p;


	bubbleSort(vector,9);

    
	for(i = 0; i < 9; i++)
		printf("%i\n",vector[i]);
	
	return 0;
}