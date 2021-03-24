#include "palindrome.h"
/**
 * is_palindrome - Entry point
 * @n: Unsigned long
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long tmp, remainder, reverse = 0;

	tmp = n;

	while (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}

	if (reverse == tmp)
		return (1);
	else
		return (0);
}
