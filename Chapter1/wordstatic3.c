#include <stdio.h>

main()
{
	int c;
	int iChar[128];
	int nChar[128];
	int tmpCnt;
	int maxCnt;

	int i,j;
	maxCnt = 0;
	for(i = 0; i < 128; i ++)
		iChar[i] = EOF;
	for(i = 0; i < 128; i ++)
		nChar[i] = 0;
	
	while((c=getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			continue;
		}	
		else/*current is character*/
		{
			for(i = 0; i < 128; i ++)
			{
				if(iChar[i] == -1)
				{
					iChar[i] = c;
					nChar[i] ++;
					break;
				}
				if(iChar[i] == c)
				{
					nChar[i] ++;
					break;
				}
			}
		}	
	}
	

	for(i = 0; i < 128; i ++)
	{
		if(iChar[i] == EOF)
			break;

		printf("%c ",iChar[i]);
		for(j = 0; j < nChar[i]; j ++)
			printf("*");
		printf("\n");
	}	
}