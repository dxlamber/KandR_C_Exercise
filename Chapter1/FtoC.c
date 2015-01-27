#include <stdio.h>

float ftoc(float fVal)
{
	return 5.0*(fVal-32)/9.0;
}

main()
{
	int i;
	for(i = 0; i <= 300; i += 20)
		printf("%3.0f\t%6.1f\n",(float)i, ftoc(i));
}