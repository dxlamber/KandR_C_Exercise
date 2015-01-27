#include <stdio.h>

main()
{
	int c;
	int result=1;
	while(result)
	{
		result = ((c=getchar()) != EOF);
		printf("%d",result);
	}
}