#include <stdio.h>

#define MAXLINE 1024

int getoneline(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = '\\';
		i++;
		s[i] = 'n';
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;
	for(i = 0; from[i] != '\0'; i ++)
		to[i] = from[i];
	to[i] = '\0';
}

main()
{
	int maxlinelen = 0;
	int curlinelen = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((curlinelen = getoneline(line, MAXLINE)) > 0)
	{
		if(curlinelen > maxlinelen)
		{
			maxlinelen = curlinelen;
			copy(longest, line);
		}
	}

	if(maxlinelen > 0)
	{
		printf("The longest line length: %d\n", maxlinelen);
		printf("%s\n", longest);
	}
	return 0;
}