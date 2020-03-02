#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void explote_node(int node_x, int node_y, int grid[3][3]);
void show_grid(int grid[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
void clean_grid(int temp[3][3]);


#endif /* _SANDPILES_H_ */
