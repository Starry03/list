#ifndef DOUBLELINKEDLIST_H
# define DOUBLELINKEDLIST_H

# include "../Nodes/Nodes.h"
# include <stddef.h>

# define DOUBLELINKEDLIST_EMPTY (DoubleLinkedList) NULL

typedef DoubleNode	DoubleLinkedList;

DoubleLinkedList	DoubleLinkedList_Init(Generic info);
DoubleLinkedList	DoubleLinkedList_Insert(DoubleLinkedList *list,
						Generic info, size_t index);
DoubleLinkedList	DoubleLinkedList_Append(DoubleLinkedList list,
						Generic info);
DoubleLinkedList	DoubleLinkedList_Push(DoubleLinkedList *list, Generic info);
void				DoubleLinkedList_RemoveByValue(DoubleLinkedList list,
						Comparator cmp, Generic info, Deallocator dealloc);
void				DoubleLinkedList_Remove(DoubleLinkedList node,
						Deallocator dealloc);
void				DoubleLinkedList_RemoveByIndex(DoubleLinkedList list,
						size_t index, Deallocator dealloc);
DoubleLinkedList	DoubleLinkedList_Search(DoubleLinkedList list,
						Comparator cmp, Generic info);
DoubleLinkedList	DoubleLinkedList_GetNth(DoubleLinkedList list,
						size_t index);
DoubleLinkedList	DoubleLinkedList_GetFirst(DoubleLinkedList list);
DoubleLinkedList	DoubleLinkedList_GetLast(DoubleLinkedList list);
DoubleLinkedList	DoubleLinkedList_GetNext(DoubleLinkedList list);
DoubleLinkedList	DoubleLinkedList_GetPrev(DoubleLinkedList list);
DoubleLinkedList	DoubleLinkedList_GetInfo(DoubleLinkedList list);
size_t				DoubleLinkedList_GetLength(DoubleLinkedList list);
void				DoubleLinkedList_Dealloc(DoubleLinkedList list,
						Deallocator dealloc);

#endif