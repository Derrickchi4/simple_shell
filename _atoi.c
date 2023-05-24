#include "shell.h"
/**
 * interactive - if the shell is in interactive mode, it returns true
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this is to see if the character is a delimeter
* @c: the char to check
 * @delim: the delimeter string
 * Return: 0 for false and 1 for true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - this  checks for alphabetic characters
 * @c: The character to input
 * Return: 1 when c is alphabetic and 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this helps create an integer from a string
 * @s: string being tranformed
 * Return: 0 if the string has no numbers, 1 a converted number
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;
	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

