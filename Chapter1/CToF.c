#include <stdio.h>

float ctof(float cval)
{
	return 9.0 * cval / 5.0 + 32;
}

main()
{
	int i;
	printf("Celsius\tFahr\n");
	for(i = 0; i <= 300; i += 20)
		printf("%3.0f\t%6.1f\n",(float)i, ctof(i));
}