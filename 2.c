#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	char ch = 'A';
	char a[11][11];
	for (int i = 1; i < 11; i++) 
    {
		for (int j = 1; j < 11; j++) 
        {
			a[i][j] = '.';
		}
	}
	srand((unsigned)time(NULL));
	a[1][1] = 'A';
	int step = rand() % 4 + 1;
	int row = 1, col = 1, flag = 0;
	for (int i = 1; i < 26; i++) 
    {
		while (flag != 1) 
        {
			if (a[row][col + 1] != '.' && a[row + 1][col] != '.' && a[row][col - 1] != '.' && a[row - 1][col] != '.')
            {
				flag = 1;
				break;
			}
			switch (step)
			{
			case 1:if (a[row][col + 1] != '.') 
            {
				step = rand() % 4 + 1;
				break;
			}
				  else
			{
				flag = 1;
				a[row][col + 1] = ch + i;
				col++;
			}

				  break;
			case 2:if (a[row + 1][col] != '.') 
            {
				step = rand() % 4 + 1;
				break;
			}
				  else
			{
				flag = 1;
				a[row + 1][col] = ch + i;
				row++;
			}

				  break;
			case 3:if (a[row][col - 1] != '.' || col - 1 < 0)
             {
				step = rand() % 4 + 1;
				break;
			}
				  else
			{
				flag = 1;
				a[row][col - 1] = ch + i;
				col--;
			}
				  break;
			case 4:if (a[row - 1][col] != '.' || row - 1 < 0) 
            {
				step = rand() % 4 + 1;
				break;
			}
				  else
			{
				flag = 1;
				a[row - 1][col] = ch + i;
				row--;
			}
				  break;
			}
		}
		flag = 0;
		step = rand() % 4 + 1;

	}

	for (int i = 1; i < 11; i++) 
    {
		for (int j = 1; j < 11; j++) 
        {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}