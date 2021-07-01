#include "holberton.h"
/**
* my_atoi - converts a string in an integer
*@s: pointer to a string
*Return: the integer
*/

int my_atoi(char *s)
{
	int i = 0, integer = 0, sign = 1;

	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
			}
			i++;
			}
			while ((s[i] >= '0') && (s[i] <= '9'))
			{
				integer = (integer * 10) + (sign * (s[i] - '0'));
				i++;
				}
				return (integer);
}

/**
 *main - function principal
 *@ac: number arguments passed into it
 *@av: null
 *Return: 0
 */

int main(int ac, char *av[])
{
	int mul;

	if (ac == 3)
	{
		mul = my_atoi(av[1]) * atoi(av[2]);
		printf("%d\n", mul);
	}
	else
		printf("Error\n");
	return (0);
}
