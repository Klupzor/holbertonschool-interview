#include "sandpiles.h"

/**
 * sandpiles_sum - sum sandpiles
 *
 * @grid1: first grid
 * @grid2: second grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int is_stable, printed, i, j;
	int prev[3][3];

	sum_grids(grid1, grid2);
	do {
		is_stable = 1;
		printed = 0;

		clean_grid(prev);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (printed == 0)
					{
						printf("=\n");
						show_grid(grid1);
						printed = 1;
					}
					explote_node(j, i, prev);
					is_stable = 0;
				}
			}
		}
		sum_grids(grid1, prev);

	} while (is_stable == 0);
}

/**
 * explote_node - separate grid in "+" pattern
 *
 * @node_x: first coordinate
 * @node_y: second coordinate
 * @grid: grid to put results
 *
 */

void explote_node(int node_x, int node_y, int grid[3][3])
{

	grid[node_y][node_x] = grid[node_y][node_x] - 4;

	if (node_x + 1 < 3)
		grid[node_y][node_x + 1]++;

	if (node_x - 1 > -1)
		grid[node_y][node_x - 1]++;

	if (node_y + 1 < 3)
		grid[node_y + 1][node_x]++;

	if (node_y - 1 > -1)
		grid[node_y - 1][node_x]++;
}

/**
 * show_grid - Display grid
 *
 * @grid: first grid
 *
 */

void show_grid(int grid[3][3])
{
	int y, x;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (x)
				printf(" ");
			printf("%d", grid[y][x]);
		}
		printf("\n");
	}
}

/**
 * sum_grids - sum two grids
 *
 * @grid1: first grid
 * @grid2: second grid
 *
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * clean_grid - clean grid
 *
 * @temp: grid to be clean
 *
 */

void clean_grid(int temp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = 0;
		}
	}
}
