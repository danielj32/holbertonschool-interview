#include "slide_line.h"
/**
 * jump_it - Function game 2048
 * @l: pointer to an array
 * @size: size of the array
 * @nxt: next to move
 * Return: 1 upon success, or 0 upon failure
 */

void jump_it(int *l, size_t size, int nxt)
{
	size_t ct, second, tmp;

	if (nxt == 0)
	{
		for (ct = 0; ct < size; ct++)
			for (second = ct + 1; second < size; second++)
			{
				if (l[ct] < l[second] && l[ct] != 0)
					break;
				else if (l[ct] == 0 && l[second] != 0)
				{
					tmp = l[ct];
					l[ct] = l[second];
					l[second] = tmp;
				}
			}
	}
	else if (nxt == 1)
	{
		for (ct = size - 1; (int)ct >= 0; ct--)
			for (second = ct - 1; (int)second >= 0; second--)
			{
				if (l[ct] < l[second] && l[ct] != 0)
					break;
				else if (l[ct] == 0 && l[second] != 0)
				{
					tmp = l[ct];
					l[ct] = l[ct];
					l[second] = tmp;
				}
			}
	}
}

/**
 * slide_line - Function game 2048
 * @line: pointer to an array
 * @size: size of the array
 * @direction: next to move
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t ct, second;

	if (line == NULL)
		return (0);

	if (direction == 0 || direction == 1)
	{
		jump_it(line, size, direction);
		if (direction == 0)
		{
			for (ct = 0; ct < size; ct++)
				for (second = ct + 1; second < size; second++)
				{
					if (line[ct] == line[second])
					{
						line[ct] = line[ct] + line[second];
						line[second] = 0;
						break;
					}
				}
		}
		else if (direction == 1)
		{
			for (ct = size - 1; (int)ct >= 0; ct--)
				for (second = ct - 1; (int)second >= 0; second--)
				{
					if (line[ct] == line[second])
					{
						line[ct] = line[ct] + line[second];
						line[second] = 0;
						break;
					}
				}
		}
		jump_it(line, size, direction);
	}
	else
		return (0);
	return (1);
}
