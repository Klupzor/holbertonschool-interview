#include "sandpiles.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int is_stable, printed;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    do
    {
        is_stable = 1;
        printed = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    if (printed == 0)
                    {
                        printf("=\n");
                        show_grid(grid1);
                        printed = 1;
                    }
                    explote_node(j, i, grid1);
                    is_stable = 0;
                }
            }
        }

    } while (is_stable == 0);
}

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

    void show_grid(int grid[3][3])
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (x)
                    printf(" ");
                printf("%d", grid[y][x]);
            }
            printf("\n");
        }
    }