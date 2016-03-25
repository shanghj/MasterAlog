/*****************************************************************************
*                                                                            *
*  -------------------------------- list.h --------------------------------  *
*                                                                            *
*****************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*****************************************************************************
*                                                                            *
*  Define a structure for linked list elements.                              *
*                                                                            *
*****************************************************************************/

typedef struct ListElmt_ {

void               *data;
struct ListElmt_   *next;

} ListElmt;

/*****************************************************************************
*                                                                            *
*  Define a structure for linked lists.                                      *
*                                                                            *
*****************************************************************************/

typedef struct List_ {

int                size;

int                (*match)(const void *key1, const void *key2);
void               (*destroy)(void *data);

ListElmt           *head;
ListElmt           *tail;

} List;

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/

//Return Value:	 None.
//Description:	 Initializes the linked list specified by list. This operation must
//	be called for a linked list before the list can be used with any other operation.
//	The destroy argument provides a way to free dynamically allocated data when
//	list_destroy is called. For example, if the list contains data dynamically allocated
//	using malloc, destroy should be set to free to free the data as the linked list is
//	destroyed. For structured data containing several dynamically allocated members,
//	destroy should be set to a user-defined function that calls free for each dynamically
//	allocated member as well as for the structure itself. For a linked list containing
//	data that should not be freed, destroy should be set to NULL.
//Complexity: O(1)
void list_init(List *list, void (*destroy)(void *data));

//Return Value:	None.
//Description:	Destroys the linked list specified by list. No other operations
//	are permitted after calling list_destroy unless list_init is called again. The list_
//	destroy operation removes all elements from a linked list and calls the function
//	passed as destroy to list_init once for each element as it is removed, provided
//	destroy was not set to NULL.
//Complexity:	O(n), where n is the number of elements in the linked list.
void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

#endif
