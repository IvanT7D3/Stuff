#include <stdio.h>

int main()
{
	int Array[30] = {0,9,8,7,6,5,51,3,2,1,10,11,19,41,31,76,45,24,79,86,99,33,12,64,75,97,100,142,1742,361};
	int Hold = 0;
	int i, j, k;
	for (i = 0; i < 30; i++)
	{
		for (k = 0; k < 29; k++)
		//Keep k < 30 to avoid stack smashing. If increased to 30, then it'll go out of the array
		{
			if (Array[k] > Array[k + 1])
			{
				Hold = Array[k];
				Array[k] = Array[k + 1];
				Array[k + 1] = Hold;
			}
		}
	}
	
	printf("Sort:\n");
	for (j = 0; j < 30; j++)
	{
		printf("%d\n", Array[j]);
	}
	return 0;
}
