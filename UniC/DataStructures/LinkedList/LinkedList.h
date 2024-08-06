//
// Created by andre on 8/8/2023.
//

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "../Nodes/Nodes.h"
# include <stddef.h>

typedef Node	LinkedList;

# define LINKEDLIST_EMPTY (LinkedList)0

LinkedList		LinkedList_Init(Generic value);

void			LinkedList_Push(LinkedList *list, Generic object);

LinkedList		LinkedList_Append(LinkedList *list, Generic value);

LinkedList		LinkedList_Insert(LinkedList *list, Generic value,
					size_t index);

void			LinkedList_Remove(LinkedList *node, Deallocator dealloc);

void			LinkedList_RemoveByValue(LinkedList *list, Generic value,
					Deallocator dealloc, int (*cmp)(Generic, Generic));

LinkedList		LinkedList_GetNext(LinkedList list);

Generic			LinkedList_GetInfo(LinkedList list);

LinkedList		LinkedList_GetNode(LinkedList list, Generic value);

LinkedList		LinkedList_GetNth(LinkedList list, size_t n);

void			LinkedList_RemoveNth(LinkedList *list, size_t n,
					Deallocator dealloc);

LinkedList		LinkedList_GetLast(LinkedList list);

void			LinkedList_Dealloc(LinkedList head, Deallocator dealloc);

size_t			LinkedList_Size(LinkedList list);

#endif // LINKEDLIST_H
