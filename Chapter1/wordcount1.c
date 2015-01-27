#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c;
	
	int prevState = OUT;
	while((c=getchar()) != EOF)
	{
		if(c == ' ' || c== '\n' || c == '\t')
		{
			if(prevState == OUT)
				continue;
			else
			{
				putchar('\n');
				prevState = OUT;
			}

		}
		else/*in word, not in space*/
		{
			if(prevState == OUT)
			{
				putchar('\n');
				putchar(c);
				prevState = IN;
			}
			else
			{
				putchar(c);
			}
		}
	}
}