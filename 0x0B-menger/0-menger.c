#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge
 *
 */
void menger(int level)
{
	int x, n;

	n = 1 << 2 * level;
	for (x = n * n; x--;)
	{
		printf(x & x / 2 & n * n / 3 ? "" : x & x / n & n / 3
		? "  " : x & (n - 1) ? "# " : "#\n");
	}
}
