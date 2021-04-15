#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Nothing.
 */

void menger(int level)
{
	int u, c, number_level;

	if (level < 0)
		return;
	number_level = pow(3, level);
	for (u = 0; u < number_level; u++)
	{
		for (c = 0; c < number_level; c++)
			putchar(aux_drawing(u, c));
		putchar('\n');
	}
}
/**
 * aux_drawing - function to draw
 * @columns: columns
 * @rows: rows
 * Return: "#" or " "
 */
char aux_drawing(int columns, int rows)
{
	while (rows || columns)
	{
		if (columns % 3 == 1 && rows % 3 == 1)
			return (' ');
		rows = rows / 3;
		columns = columns / 3;
	}
	return ('#');
}
