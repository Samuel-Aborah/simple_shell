#include "shell.h"

/**
 * _chain - checks if current char in buffer is a chain delimiter
 * @ptr: pointer to head of list
 * @buff: buffer
 * @s: pointer to current position in buffer
 * Return: 1 if char is a chain delimiter else 0
 */

int _chain(listinfo_t *ptr, char *buff, size_t *s)
{

	/* Loop through buffer chars till buff = NULL */
	while (buff[*s] != '\0')
	{
		/* Checks the logical or chain */
		if (buff[*s] == '|' && buff[*s + 1] == '|')
		{
			/* Cancel current command */
			buff[*s] = '\0';
			(*s)++;
			/*Set the cmd chain type to logical or */
			ptr->cmd_buff_type == CMD_OR;

		}
		/* Checks the logical and chain */
		else if (buff[*s] == '&' && buff[*s + 1] == '&')
		{
			/* Cancel current command */
			buff[*s] = '\0';
			(*s)++;
			/* Set the cmd chain type to logical and */
			ptr->cmd_buff_type = CMD_AND;
		}
		/* Check for cancellation of cmd chain */
		else if (buff[*s] == ';' && buff[*s + 1] == ';')
		{
			/* cancel current command */
			buff[s] = '\0';
			(*s)++;
			/* set cmd chain type to regular */
			ptr->cmd_buff_type = CMD_CHAIN;
		}
		else
			/* Cmd chain failed */
			return (0);
	}
	/* cmd chain succesful */
	return (1);
}

/**
 * _chain_check - test the chain checking per the last status
 * @ptr: pointer to head of list
 * @buff: buffer
 * @s:pointer to current position in buffer
 * @j:start position in buffer
 * @length: length of buffer
 * Return: void
 */

void _chain_check(listinfo_t *ptr, char *buff, size_t *s,
		size_t j, size_t length)
{
	/* Loop through buffer char till buffer = NULL */
	while (buff[*s] != '\0')
	{
		/* Check if the buffer type is logical & and its status is true*/
		if (ptr->cmd_buff_type == CMD_AND && ptr->status)
		{
			/* set buffer char to NULL */
			buff[*s] = '\0';
			/* Direct pointer s to length of buffer */
			*s = length;
		}
		else
		{
			/* Check if buffer type is logical or and its status is false */
			if (ptr->cmd_buff_type == CMD_OR && !ptr->status)
			{
				/* srt buffer char to NULL */
				buff[*s] = '\0';
				/* Direct pointer s to length of buffer */
				*s = length;
			}
		}
	}
}

/**
 * replace_alias - replaces aliases in tokenized strings
 * @ptr: pointer to head of the list
 * Return: 1 if replaced, else 0
 */

int replace_alias(listinfo_t *ptr)
{
	char *s;
	list_t *rep;
	int a = 0;

	/* Loop through whilst a is less than 10 */
	while (a < 10)
	{
		/* find the node that starts with the specified alias */
		rep = node_starts(ptr->alias, ptr->argv[0], '=');
		a++;

		/* If said node is not found, return 0 */
		if (rep == NULL)
			return (0);

		/* Free memory */
		free(ptr->argv[0]);

		/* Find position of '=' in node's string */
		s = _strchr(rep->str, '=');

		/* If '=' is not found, return 0 */
		if (s == NULL)
			return (0);

		/* Duplicate string after '=' */
		s = _strdup(s + 1);

		/* If string cannot be duplicated, return 0 */
		if (s == NULL)
			return (0);

		/* Point pointer to new string */
		ptr->argv[0] = s;
	}
	/* return 1 on success */
	return (1);
}

/**
 * replace_var - handles variable replacement
 * @ptr: pointer to head of the lists
 * Return: 1 upon replacement else 0
 */

int replace_var(listinfo_t *ptr)
{
	int a = 0;
	list_t *rep;

	while (ptr->argv[a])
	{
		/* Check if the arg starts with '$' or is not empty */
		if (ptr->argv[a][0] != '$' || ptr->argv[a][1] == '\0')
		{

			/* check if argument is not empty and is "$?" */
			if (_strcmp(ptr->argv[a] == '\0', "$?"))
			{
				/* replace status converted argument into a string */
				replace_str(ptr->argv + a,
						_strdup(_convert_num(ptr->status, 10, 0)));
			}
			/* Check if the arg is not emty and is "$$" */
			else if (_strcmp(ptr->argv[a] == '\0', "$$"))
			{
				/* replace converted argument with current pid into a string */
				replace_str(ptr->argv + a,
						_strdup(_convert_num(getpid(), 10, 0)));
			}
			else
			{
				/* Find node in env list that start with argument that has the '=' sign */
				rep = node_starts(ptr->env, ptr->argv[a] + 1, '=');
				if (rep != NULL)
				{
					/* Replace argument with value after '=' is found in env list */
					replace_str(ptr->argv + a,
							_strdup(_strchr(rep->str, '=') + 1));
				}
			}
			/* Replace argument with empty string */
			replace_str(ptr->argv + a, _strdup(""));
		}
		a++;
	}
	return (0);
}

/**
 * replace_str - Replaces a string
 * @str: former string
 * @s: new string
 * Return: Void
 */

void replace_str(char **str, char *s)
{
	/* free memory of old string */
	free(*str);
	/* point old string to new string */
	*str = s;

}
