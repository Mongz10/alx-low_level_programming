#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the nth node of a listint_t list
 * @head: a pointer to the head node
 * @index: the index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    unsigned int i = 0;
    listint_t *cur, *prev;

    if (*head == NULL)
        return (-1); /* the list is empty */

    cur = *head;
    prev = NULL; /* Initialize prev to NULL to handle deletion at index 0 */

    while (cur != NULL)
    {
        if (i == index)
        {
            if (cur == *head)
                *head = (*head)->next;
            else
                prev->next = cur->next;
            free(cur);
            return (1); /* Return 1 for success (node deleted) */
        }
        prev = cur;
        cur = cur->next;
        i++;
    }

    return (1); /* Return 1 for success (index not found, no deletion) */
}

