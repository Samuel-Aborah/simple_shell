#include "shell.h"

/**
 * add_node - Adds a node to the beginning of a list
 * @ptr: double pointer to head of a list
 * @node: String to be stored in new node
 * Return: Address to new node on success, else NULL
 */

list_t *add_node(list_t **ptr, const char *node)
{
	list_t *new;

	if (!ptr || !str)
		return (NULL);

	new = (list_t *) malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->node = strdup(node);

	if (new->node == NULL)
	{
		free(new);
		return (NULL);

	}
	new->val = strlen(node);
	new->node = *ptr;
	*ptr = new;

	return (new);
}

/**
 * add_node_end - Adds new node to end of a list
 * @head: Double pointer to head of a list
 * @node: The string to be added
 * Return: Address to new string on success, else NULL
 */

list_t add_node_end(list_t **head, const char *node)
{
	list_t *new, *curr;

	if (!head || !str)
		return (NULL);

	new = (list_t *) malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->node = strdup(node);

	if (new->node == NULL)
	{
		free(new);
		return (NULL);
	}

	new->val = strlen(node);

	new->next == NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		curr = *head;

		while (curr->next)
			curr = curr->next;
	}

	curr->next = new;

	return (new);

}

/**
 * _str_print_list - Prints out the str element of a list
 * @ptr: pointer to first node
 * Return: size
 */

size_t _str_print_list(const list_t *ptr)
{
	size_t size = 0;

	*str = ptr->size

	if (*str)
	{
		while (*str != '\0')
		{
			_putchar(*str);
			*str++;
		}
		_putchar('\n');
	}
	else
		_puts("(nil)");
}

/**
 * delete_node_at_index - Deletes the node at index of a
 * linked list
 * @head: double pointer to head of list
 * @idx: Index of node to be deleted
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int idx)
{
	list_t *current, *delete;
	unsigned int count = 0;

	current = *head;

	if (!head || !*head)
		return (0);

	for (; count < idx && current; count++)
	{
		delete = current;
		current = current->next;
	}

	if (idx == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	if (current == NULL)
		return (0);

	delete->next = current->next;
	free(current);
	return (1);
}

/**
 * free_list - Frees the memory of a list
 * @head: pointer to head of a list
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
