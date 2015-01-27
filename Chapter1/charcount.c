#include <stdio.h>

main()
{
	long cnt = 0;
	while(getchar() != EOF)
		cnt ++;
	printf("%ld\n", cnt);
}