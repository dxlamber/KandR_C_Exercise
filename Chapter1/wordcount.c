#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c;
	int nl=0,nw=0,nc=0;
	int state = OUT;
	while((c=getchar()) != EOF)
	{
		nc ++;

		if(c == '\n')
			nl ++;

		if(c == ' ' || c== '\n' || c == '\t')
		{
			if(state == OUT)
				continue;
			else
				state = OUT;

		}
		else
		{
			if(state == OUT)
			{
				nw ++;
				state = IN;
			}
			else
				continue;
		}
	}
	printf("Line\tWord\tCharacters\n");
	printf("%d\t%d\t%d\n", nl, nw, nc);
}