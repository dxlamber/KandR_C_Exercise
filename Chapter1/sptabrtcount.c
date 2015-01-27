#include <stdio.h>

main()
{
	long spcnt=0,tabcnt=0,rtcnt = 0;
	int c;
	while((c=getchar()) != EOF)
	{
		if(c == ' ')
			spcnt ++;
		if(c == '\t')
			tabcnt ++;
		if(c == '\n')
			rtcnt ++;
	}
	printf("space\ttab\tline\n");
	printf("%ld\t%ld\t%ld\n", spcnt, tabcnt, rtcnt);
}