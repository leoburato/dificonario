/*										*/
/* Exemplo de implementação de uma lista encadeada simples em linguagem C    */
/* apresentado na Wikipedia: http://en.wikipedia.org/wiki/Linked_list                      */
/*										*/

#include <stdio.h>    /* for printf */
#include <stdlib.h>   /* for malloc */
 
struct node
{
	int data;
	struct node *next; /* pointer to next element in list */
};
 
struct node *list_add(struct node **p, int i)
{
	struct node *n = malloc(sizeof(struct node));
	if (n == NULL)
		return NULL;
 
	n->next = *p; /* the previous element (*p) now becomes the "next" element */
	*p = n;       /* add new empty element to the front (head) of the list */
	n->data = i;
 
	return *p;
}
 
void list_remove(struct node **p) /* remove head */
{
	if (*p != NULL)
	{
		struct node *n = *p;
		*p = (*p)->next;
		free(n);
	}
}
 
struct node **list_search(struct node **n, int i)
{
	while (*n != NULL)
	{
		if ((*n)->data == i)
		{
			return n;
		}
		n = &(*n)->next;
	}
	return NULL;
}
 
void list_print(struct node *n)
{
	if (n == NULL)
	{
		printf("list is empty\n");
	}
	while (n != NULL)
	{
		printf("print %p %p %d\n", n, n->next, n->data);
		n = n->next;
	}
}
 
int main(void)
{
	struct node *n = NULL;
 
	list_add(&n, 0); /* list: 0 */
	list_add(&n, 1); /* list: 1 0 */
	list_add(&n, 2); /* list: 2 1 0 */
	list_add(&n, 3); /* list: 3 2 1 0 */
	list_add(&n, 4); /* list: 4 3 2 1 0 */
	list_print(n);
	list_remove(&n);                 /* remove first (4) */
	list_remove(&n->next);           /* remove new second (2) */
	list_remove(list_search(&n, 1)); /* remove cell containing 1 (first) */
	list_remove(&n->next);           /* remove second to last node (0) */
	list_remove(&n);                 /* remove last (3) */
	list_print(n);
 
	return 0;
}