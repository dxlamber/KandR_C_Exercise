#include <stdio.h>

#define MAXLINE 1024
#define INLASTSPC 1
#define OUTLASTSPC 0


int getoneline(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void stringreverse(char to[], char from[], int fromlen)
{
	int i,j;
	i = fromlen-1;
	j = 0;
	while(i >= 0)
	{
		to[j] = from[i];
		i --;
		j ++;
	}
	to[j] = '\0';
}

main()
{
	int maxlinelen = 0;
	int curlinelen = 0;
	char line[MAXLINE];
	char revline[MAXLINE];

	while((curlinelen = getoneline(line, MAXLINE)) > 0)
	{
		stringreverse(revline, line, curlinelen);
		printf("%s", revline);
	}

	return 0;
}