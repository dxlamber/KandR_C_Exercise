#include <stdio.h>

main()
{
	int c;
	int isPrevEmpty = 0;
	while((c=getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(isPrevEmpty == 1)
				continue;
			else
			{
				isPrevEmpty = 1;
				putchar(c);
			}
		}
		else
		{
			isPrevEmpty = 0;
			putchar(c);
		}
	}
}