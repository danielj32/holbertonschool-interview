#include "slide_line.h"
/**
 * slide_left - combines identical ints moving leftward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void slide_left(int *list, size_t size)
{
	unsigned int long ct;

	for (ct = 0; ct < size - 1; ct++)
	{
		if (list[ct] == list[ct + 1])
		{
			list[ct + 1] *= 2;
			list[ct] = 0;
			++ct;
		}
	}
}

/**
 * slide_right - combines identical ints moving rightward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void slide_right(int *list, size_t size)
{
	unsigned int long ct;

	for (ct = size - 1; ct + 1 > 1; ct--)
	{
		if (list[ct] == list[ct - 1])
		{
			list[ct - 1] *= 2;
			list[ct] = 0;
			--ct;
		}
	}
}

/**
 * second_left - moves all integers leftward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void second_left(int *list, size_t size)
{
	unsigned int long ct, tmp;

	for (ct = 1; ct < size; ct++)
	{
		if (list[ct] != 0)
		{
			tmp = ct;
			while (list[ct - 1] == 0 && ct > 0)
			{
				list[ct - 1] = list[ct];
				list[ct] = 0;
				--ct;
			}
			ct = tmp;
		}
	}
}

/**
 * second_right - moves all ints rightward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void second_right(int *list, size_t size)
{
	unsigned int long ct, tmp;

	for (ct = size - 2; ct + 1 > 0; ct--)
	{
		if (list[ct] != 0)
		{
			tmp = ct;
			while (list[ct + 1] == 0 && ct < size - 1)
			{
				list[ct + 1] = list[ct];
				list[ct] = 0;
				++ct;
			}
			ct = tmp;
		}
	}
}

/**
 * slide_line - slides a line to a direction, adding indentical ints
 * @line: a pointer to an listay of ints
 * @size: number of elements in the list
 * @direction: left or right
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			second_left(line, size);
			slide_left(line, size);
			second_left(line, size);
			break;
		case SLIDE_RIGHT:
			second_right(line, size);
			slide_right(line, size);
			second_right(line, size);
	}
	return (1);
}
