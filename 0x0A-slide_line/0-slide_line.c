#include "slide_line.h"
/**
 * slide_left - combines identical ints moving leftward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void slide_left(int *list, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (list[i] == list[i + 1])
		{
			list[i + 1] *= 2;
			list[i] = 0;
			++i;
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
	size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (list[i] == list[i - 1])
		{
			list[i - 1] *= 2;
			list[i] = 0;
			--i;
		}
	}
}

/**
 * second_left - moves all ints leftward
 * @list: a pointer to an integer list
 * @size: number of items in the list
 */
void second_left(int *list, size_t size)
{
	size_t i, tmp;

	for (i = 1; i < size; i++)
	{
		if (list[i] != 0)
		{
			tmp = i;
			while (list[i - 1] == 0 && i > 0)
			{
				list[i - 1] = list[i];
				list[i] = 0;
				--i;
			}
			i = tmp;
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
	size_t i, tmp;

	for (i = size - 2; i + 1 > 0; i--)
	{
		if (list[i] != 0)
		{
			tmp = i;
			while (list[i + 1] == 0 && i < size - 1)
			{
				list[i + 1] = list[i];
				list[i] = 0;
				++i;
			}
			i = tmp;
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
