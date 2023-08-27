#include <ctype.h>

/**
 * is_int - checks if a string is a valid integer
 * @str: the string to check
 * Return: 1 if true, 0 if false
 */
int is_int(char *str)
{
	int i = 0;

	/* check for negative sign */
	if (str[i] == '-')
		i++;

	/* check for digits */
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	/* check for empty string */
	if (i == 0)
		return (0);

	return (1);
}
