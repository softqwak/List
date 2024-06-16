#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define add(type) add_##type
#define add_int(list, inValue)                   \
    addNode((list));                             \
    list->tail->value = malloc(sizeof(inValue)); \
    *((int *)list->tail->value) = (inValue);

#define add_float(list, inValue)                 \
    addNode((list));                             \
    list->tail->value = malloc(sizeof(inValue)); \
    *((float *)list->tail->value) = (inValue);

#define add_char(list, inValue)                  \
    addNode((list));                             \
    list->tail->value = malloc(sizeof(inValue)); \
    list->tail->value = (inValue);

#define get(type) get_##type
#define get_int(list, index) *((int *)getValue(list, index))
#define get_float(list, index) *((float *)getValue((list), (index)))
#define get_double(list, index) *((double *)getValue((list), (index)))
#define get_char(list, index) getValue((list), (index))

typedef struct SList TNode;
typedef struct SList TList;
struct SList
{
    int index;
    TNode *prev;
    TNode *next;
    TNode *head;
    TNode *tail;
    void *value;
};

TList *List(void);
void initList(TList *list);
void delList(TList *list);
void addNode(TList *list);
void *getValue(TList *list, unsigned int inIndex);

void checkList(TList *list);
#endif // LIST_H
