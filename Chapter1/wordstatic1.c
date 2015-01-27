#include <stdio.h>

main()
{
	int c;
	int ndigit[30];
	int INWORD = 1;
	int OUTWORD = 0;
	int prevStat = OUTWORD;
	int tmpCnt;

	int i,j;
	for(i = 0; i < 30; i ++)
		ndigit[i] = 0;
	
	tmpCnt = 0;
	while((c=getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(prevStat == INWORD)
			{
				ndigit[tmpCnt] ++;
				tmpCnt = 0;
				prevStat = OUTWORD;
			}
			else
			{
				continue;
			}
		}	
		else/*current is character*/
		{
			if(prevStat == INWORD)
			{
				tmpCnt ++;
				prevStat = INWORD;
			}
			else
			{
				tmpCnt = 1;
				prevStat = INWORD;
			}
		}	
	}
	
	for(i = 0; i < 30; i ++)
	{
		printf("%2d ", i);
		for(j = 0; j < ndigit[i]; j ++)
			printf("*");
		printf("\n");
	}
}