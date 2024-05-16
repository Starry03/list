//
// Created by andre on 8/8/2023.
//

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "../Nodes/Nodes.h"

typedef Node	LinkedList;

# define LINKEDLIST_EMPTY (LinkedList)0

LinkedList		LinkedList_Init(Generic value);

void			LinkedList_Push(LinkedList *list, Generic object);

void			LinkedList_Append(LinkedList list, Generic value);

void			LinkedList_Remove(LinkedList *node, void (*dealloc)(Generic));

void			LinkedList_RemoveByValue(LinkedList *list, Generic value,
					void (*dealloc)(Generic), int (*cmp)(Generic, Generic));

LinkedList		LinkedList_GetNext(LinkedList list);

Generic			LinkedList_GetInfo(LinkedList list);

LinkedList		LinkedList_GetNode(LinkedList list, Generic value);

LinkedList		LinkedList_GetLast(LinkedList list);

void			LinkedList_Dealloc(LinkedList head, void (*dealloc)(Generic));

#endif // LINKEDLIST_H
