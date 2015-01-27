#include <stdio.h>

void detab(void)
{
	int tabnum = 0, c;
	while( (c=getchar()) != EOF)
	{
		if(c == '\t')
		{
			tabnum ++;
			printf("        ");//tabsize is 8
		}
		else if(tabnum == 0)
			putchar(c);
		else if(tabnum > 0)
			putchar(' ');

		if(tabnum == 2)
			tabnum = 0;
	}
}

main()
{
	detab();
	return 0;
}