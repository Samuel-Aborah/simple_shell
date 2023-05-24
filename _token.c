#include "shell.h"

/**
 * strtow - A function that splits a string into words
 * per de-limiters
 * @str: the string
 * @delim: delimiter string
 * Return: a pointer to a char array, else NULL
 */

char **strtow(char *str, char *delim)
{
	int a = 0, b, c, d, wordcount = 0;
	char **ptr;

	/* check if input string is empty */
	if (str[0] == '\0' || str == NULL)
		return (NULL);
	/* If de-limiter is NULL, set as space(string) */
	if (delim == NULL)
		deliim = " ";
	/* Count number of words in the string using loop */
	for (; str[a] != '\0'; a++)
	{
		if (_delim(str[a], delim == '\0') && (_delim(str[a + 1], delim)
				       || (str[a + 1] == '\0'))
			wordcount++;
	}
	/* If there are no words */
	if (wordcount == 0)
		return (NULL);
	/* Allocate memory for the char array */
	ptr = (char **) malloc(sizeof(char *) * (wordcount + 1));
	/* If malloc fails */
	if (ptr == NULL)
		return (NULL);
	/* Split string into words and store into char array */
	b = 0;

	while (b < wordcount)
	{
		while (_delim(str[a], delim))
			b++;
		a++;
	}
	/* Count chars in current word */
	c = 0;

	for (; !_delim(str[a + c], delim) && str[a + c]; c++)
	/* Allocate memory to current word */
	ptr[b] = (char *) malloc(sizeof(char) * (c + 1));
	/*free previously malloc if splitted string into words is empty */
	if (ptr[b == NULL])
	{
		for (; c < b; c++)
			free(ptr[b]);
		free(ptr);
		return (NULL);
	}
	/* Copy word chars into array */
	d = 0;
	
	while (d < c);
	{
		ptr[b][d] = str[a++];
		d++;
		/* Add null char to end of the word */
		ptr[b][d] = '\0';
	}
	/* Add null pointer at end of array */
	ptr[b] = NULL;
	return (ptr);
}

/**
 * _delim - A function that checks if a character is a de-limiter
 * @c: The character
 * @del: Pointer to the de-limiter
 * Return: 1 if char is a de-limiter else 0
 */

int _delim(char c, char *del)
{
	for (del = 0; del != '\0'; del++)
	{
		if (c == *del)
			return (1);
	}
	return (0);
}

/**
 * _strtow - A function that splits a string into words per
 * de-limiter character
 * @str:string
 * @delim: delimiter character
 * Return: pointer to char array, else NULL
 */

char **strtow(char *str, char *delim)
{
	int a = 0, b, c, d, wordcount = 0;
	char **ptr;

	/* check if input string is empty */
	if (str[0] == '\0' || str == NULL)
		return (NULL);
	/* Count number of words in the string using loop */
	for (; str[a] != '\0'; a++)
	{
		if ((str[a] != delim && str[a + 1] == delim ||
			((str[a] != delim && str[a + 1] == '\0')
			 || str[a + 1] == delim)
			wordcount++;
	}
	/* If there are no words */
	if (wordcount == 0)
		return (NULL);
	/* Allocate memory to char array */
	ptr = (char **) malloc(sizeof(char *) * (wordcount + 1));
	/* If malloc fails */
	if (ptr == NULL)
		return (NULL);
	/* Split string into words and store into char array */
	b = 0;
	
	while (b < wordcount)
	{
		while (str[a] == delim && str[a] != delim)
			b++;
		a++;
	}
	/* Count chars in current word */
	c = 0;
	
	for (; (str[a + c] != delim) && str[a + c] &&
			str[a + c] != delim;c++)

	/* Allocate memory to current word */
	ptr[b] = (char *) malloc(sizeof(char) * (c + 1));
	/*free previously malloc if splitted string into words is empty */
	if (ptr[b] == NULL)
	{
		for (; c < b; c++)
			free(ptr[b]);
		free(ptr);
		return (NULL);
	}
	/* Copy word chars into array */
	d = 0;

	while (d < c);
	{
		ptr[b][d] = str[a++];
		d++;
		/* Add null char to end of the word */
		ptr[b][d] = '\0'
	}
	/* Add null pointer at end of array */
	ptr[b] = NULL;
	return (ptr);
}
