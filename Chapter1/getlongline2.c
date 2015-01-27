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

int linetrimright(char s[], int strlen)
{
	int i;
	int stat;
	
	stat = INLASTSPC;
	/*for(i = strlen-1; i > 0; i --)
	{
		if(s[i] == ' ' || s[i] == '\t')
		{
			if(stat == INLASTSPC)
			{
				s[i] = '\0';
				stat = INLASTSPC;
			}
			else
				break;
		}
		else
		{
			break;
		}
	}*/
	i = strlen-2; /*skip the last \n\0*/
	while((s[i] == ' ' || s[i] == '\t') && i > 0)
	{
		s[i] = '\n';
		s[i+1] = '\0';
		i --;
	}
	

	if(s[0] == '\n' && s[1] == '\0')
		return 0;

	return i;
}

main()
{
	int maxlinelen = 0;
	int curlinelen = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((curlinelen = getoneline(line, MAXLINE)) > 0)
	{
		curlinelen = linetrimright(line, curlinelen);
		if(curlinelen > 0)
			printf("%s", line);
	}

	return 0;
}