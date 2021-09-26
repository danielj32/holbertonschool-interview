#include "regex.h"
/**
 * regex_match - function checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 if they pattern matches, 0 otherwise.
 */

int regex_match(char const *str, char const *pattern)
{
	int down = 0, upt = 0;

	if (!str)
		return (0);
	if (!pattern)
		return (0);

	down = *str && (*str == *pattern || *pattern == '.');
	upt = *(pattern + 1) == '*';

	if (!*str)
		return (*pattern ? 0 : 1);
	if (!upt)
		return (*pattern ? 0 : 1);
	if (down && upt)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (down && !upt)
		return (regex_match(str + 1, pattern + 1));
	else if (upt)
		return (regex_match(str, pattern + 2));

	return (0);
}
