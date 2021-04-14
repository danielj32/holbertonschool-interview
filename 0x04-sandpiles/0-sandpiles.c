#include "sandpiles.h"

/**
 * partition - Sandpile partition.
 * @grid1: Sandpile 1.
 * @grid2: Sandpile 2.
 * Return: Nothing.
*/

void partition(int grid1[3][3], int grid2[3][3])
{
	int row, colmn;

	for (row = 0; row < 3; row++)
	{
		for (colmn = 0; colmn < 3; colmn++)
		{
			if (grid1[row][colmn] > 3)
			{
				grid1[row][colmn] -= 4;
				if (colmn - 1 >= 0)
					grid2[row][colmn - 1]++;
				if (colmn + 1 < 3)
					grid2[row][colmn + 1]++;
				if (row - 1 >= 0)
					grid2[row - 1][colmn]++;
				if (row + 1 < 3)
					grid2[row + 1][colmn]++;
			}
		}
	}
}

/**
 * check_if_stable - Checks if a sandpile is check_if_stable or not.
 * @grid3: General sandpile.
 * Return: 1 if the sandpile is check_if_stable or 0 if not.
*/

int check_if_stable(int grid3[3][3])
{
	int row, colmn;

	for (row = 0; row < 3; row++)
	{
		for (colmn = 0; colmn < 3; colmn++)
		{
			if (grid3[row][colmn] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles.
 * @grid1: Sandpile 1.
 * @grid2: Sandpile 2.
 * Return: nothing.
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, colmn;

	for (row = 0; row < 3; row++)
	{
		for (colmn = 0; colmn < 3; colmn++)
		{
			grid1[row][colmn] = grid1[row][colmn] + grid2[row][colmn];
			grid2[row][colmn] = 0;
		}
	}

	while (check_if_stable(grid1) == 0)
	{
		printf("=\n");
		for (row = 0; row < 3; row++)
		{
			for (colmn = 0; colmn < 3; colmn++)
			{
				if (colmn)
					printf(" ");
				printf("%i", grid1[row][colmn]);
			}
			printf("\n");
		}

		partition(grid1, grid2);

		for (row = 0; row < 3; row++)
		{
			for (colmn = 0; colmn < 3; colmn++)
			{
				grid1[row][colmn] = grid1[row][colmn] + grid2[row][colmn];
				grid2[row][colmn] = 0;
			}
		}
	}
}
