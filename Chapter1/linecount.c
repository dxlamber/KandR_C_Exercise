#include <stdio.h>

main()
{
	long cnt = 0;
	int c;
	while((c=getchar()) != EOF)
	{
		if(c == '\n')
			cnt ++;
	}
	printf("%ld\n", cnt);
}