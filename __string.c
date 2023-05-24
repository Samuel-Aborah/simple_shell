#include "shell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: destination of the string
 * @src: source of the string
 * Return: pointer to destination
 */

char *_strcpy(char *dest, const char *src)
{
	int str = 0;

	/* check if src and dest are equal or source is empty */
	if (dest == src || src == NULL)
		return (dest);

	/* Using a loop, copy each char from src to dest till end of src */
	for (; src[str] != '\0'; str++)
		dest[str] = src[str];

	/* Add null char to dest string */
	dest[str] = '\0';

	return (dest);
}

/**
 * _strdup - A function that duplicates a string
 * @s: the string to be duplicated
 * Return: A pointer to the duplicated string
 */

char *_strdup(const char *s)
{
	int len = 0;
	char *str;

	/* If string is empty */
	if (s == NULL)
		return (NULL);

	/* the length of the string */
	len = _strlen(s);

	/* Allocate memory to the duplicated string */
	str = (char *) malloc(sizeof(char) * (len + 1));

	/*If malloc fails */
	if (str == NULL)
		return (NULL);

	/* copy content of the input string */
	_strcpy(str, s);

	/* free memory of duplicated string */
	free(str);

	return (s);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: string to be printed
 */

void _puts(char *str)
{
	int a = 0;

	if (str == NULL)
		return;
	for (; str[a] = '\0'; a++)
	{
		_putchar(str[a]);
		a++;
	}
	_putchar('\n');
}
