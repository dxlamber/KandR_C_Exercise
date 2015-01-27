#include <stdio.h>

#define MAXLINE 1024

int maxlinelen;
char line[MAXLINE];
char longest[MAXLINE];

int getoneline(void)
{
	int c, i;
	extern char line[];

	for(i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy(void)
{
	int i;
	extern char line[], longest[];

	for(i = 0; line[i] != '\0'; i ++)
		longest[i] = line[i];
	longest[i] = '\0';
}

main()
{
	int curlinelen = 0;

	extern int maxlinelen;
	extern char longest[MAXLINE];

	maxlinelen = 0;
	while((curlinelen = getoneline()) > 0)
	{
		if(curlinelen > maxlinelen)
		{
			maxlinelen = curlinelen;
			copy();
		}
	}

	if(maxlinelen > 0)
	{
		printf("The longest line length: %d\n", maxlinelen);
		printf("%s", longest);
	}
	return 0;
}