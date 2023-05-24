#include "shell.h"

/**
 * _memset - Fills memory with a constant byte
 * @mem: pointer to the memory area
 * @c: Constant byte
 * @i: Number of memory bytes
 * Return: a pointer to the memory area
 */

char *_memset(char *mem, char c, unsigned int i)
{
	unsigned int n = 0;

	while (n < i)
	{
		mem[n] = c;
		n++;
	}
	return (mem);
}

/**
 * _free - Frees memory of string(s)
 * @str: double pointer to string
 */

void _free(char **str)
{
	if (*str == NULL)
		return;

	while (**str)
		free(*str++);

	free(*str);
}

/**
 * _realloc_ - A function that re-allocates a memory block
 * @mem: void pointer to previous malloc'd block
 * @old: size of bytes of previous memory block
 * @new: size of bytes of new memory block
 * Return: pointer to the previous memory block
 */

void *_realloc(void *mem, unsigned int old, unsigned int new)
{
	char *ptr;

	/* Allocate memory to new block, if mem is empty */
	if (mem == NULL)
		return (malloc(new));

	/* Free mem, and return nothing if new block is empty */
	if (new == NULL)
	{
		free(mem);
		return (NULL);
	}
	/*If new is equal to old */
	if (new == old)
		return (mem);

	/* Allocate new size memory to pointer */
	ptr = malloc(new);

	/* If malloc fails */
	if (ptr == NULL)
		return (NULL);

	/* copy contents from mem to ptr */
	if (old < new)
		old = old;
	else
		old = new;

	while (old--)
		ptr[old] == ((char *)mem)[old];

	free(mem);

	return (ptr);
}


