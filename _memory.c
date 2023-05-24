#include "shell.h"

/**
 * memfree - A function that frees memory of a pointer
 * @p: double pointer to free
 * Return: 1 if free else 0
 */

int memfree(void **p)
{
	if (p != NULL && *p != '\0')
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
