#include "holberton.h"
/**
 * main - Entry point
 * @ac: number of arguments
 * @av: array of pointers to arguments
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	int i, l1, l2;
	char *total;

	if (ac != 3)
	{
		printf("Error\n");
		exit(98);
	}
	l1 = valid_integer(av[1]);
	l2 = valid_integer(av[2]);
	total = check_if(l1 + l2);
	mul(av[1], av[2], l1, l2, total);
	for (i = 0; total[i] == '0' && total[i + 1]; i++)
	{
		;
	}
	printf("%s\n", &total[i]);
	free(total);
	return (0);
}

/**
 * valid_integer - checks if argument is a valid integer
 * @av: is the argument
 * Return: returns the length of argument
 */

int valid_integer(char *av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		if (av[i] < '0' || av[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (i);
}

/**
 * check_if - allocates a memory for the total
 * @length: length of the total
 * Return: A pointer to the empty allocated memory
 */

char *check_if(int length)
{
	char *p;
	int i;

	p = malloc(sizeof(char) * (length + 1));
	if (p == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; i < length; i++)
	{
		p[i] = '0';
	}
	p[i] = '\0';
	return (p);
}

/**
 * mul - multiplies 2 arrays of characters as if they were 2 numbers
 * @av1: array of first number
 * @av2: array of second number
 * @l1: length of first array
 * @l2: length of second array
 * @total: array of the total of mul
 */
void mul(char *av1, char *av2, int l1, int l2, char *total)
{
	int i, j;

	for (i = l2 - 1; i >= 0; i--)
	{
		for (j = l1 - 1; j >= 0; j--)
		{
			insert(total, (av2[i] - '0') * (av1[j] - '0'), i + j + 1);
		}
	}
}
/**
 * insert - inserts the product of 2 numbers in an array of characters
 * @total: the array of total
 * @x: the product of 2 numbers
 * @position: position of insertion in the array
 */
void insert(char *total, int x, int position)
{
	x = x + (total[position] - '0');
	while (x > 0)
	{
		total[position] = (x % 10) + '0';
		x /= 10;
		if (x == 0)
			break;
		position--;
		x += (total[position] - '0');
	}
}
