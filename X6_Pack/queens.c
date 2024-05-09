#include <stdio.h>
#include <stdlib.h>
int col[13];
char field[13][13];
int rows, cols;

int checker(int r, int c)
{
	for(int step = 0; step < r; step++)
	{
		if (col[step] == c || abs(step - r) == abs(col[step] - c))
		{
			return 0;
		}
	}
	return 1;
}

int rec(int r)
{
	if (r == rows)
	{
		return 1;
	}
	for (int step = 0; step < cols; step++)
	{
		int flag = 1;
		if (field[r][step] == '?'  && checker(r, step))
		{
			col[r] = step;
			if (rec(r+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d\n", &rows, &cols);
	for(int step = 0; step < rows; step++)
	{
		fgets(field[step], cols + 1, stdin);
		getchar();
	}
	
	
	if (rec(0))
	{
		printf("YES\n");
		for(int step = 0; step < rows; step++)
		{
			for(int step2 = 0; step2 < cols; step2++)
			{
				if (col[step] == step2)
				{
					printf("X");
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("NO");
	}
	return 0;
}
