#include <stdio.h>

main()
{
	int c;
	int ndigit[30];
	int INWORD = 1;
	int OUTWORD = 0;
	int prevStat = OUTWORD;
	int tmpCnt;
	int maxCnt;

	int i,j;
	maxCnt = 0;
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
				if(ndigit[tmpCnt] > maxCnt)
					maxCnt = ndigit[tmpCnt];
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
	

	for(i = maxCnt; i > 0; i --)
	{
		for(j = 0; j < 30; j ++)
		{
			if(ndigit[j] >= i)
				printf("  *");
			else
				printf("   ");
		}
		printf("\n");
	}	
	for(i = 0; i < 30; i ++)
	{
		printf("%3d", i);
	}
	printf("\n");
}