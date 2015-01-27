#include <stdio.h>

#define MAXLINE 1024

int getoneline(char s[], int lim)
{
	int c, i;
	int dec = 0;

	for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
	{
		if(c == '\t')
		{
			s[i] = '\\';
			i ++;
			s[i] = 't';
			dec ++;
		}
		else
			s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = '\\';
		i++;
		s[i] = 'n';
		i++;
		dec ++;
	}
	s[i] = '\0';
	return i-dec;
}

main()
{
	int maxlinelen = 0;
	int curlinelen = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((curlinelen = getoneline(line, MAXLINE)) > 0)
	{
		if(curlinelen > 30)
			printf("%3d %s\n", curlinelen, line);
	}

	return 0;
}