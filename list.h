#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define add(type) add_##type
#define insert(type) insert_##type

//------------add NODE TO TAIL OF LIST------------
#define add_int(list, inValue)                   \
    addNodeTail((list));                         \
    list->tail->value = malloc(sizeof(inValue)); \
    *((int *)list->tail->value) = (inValue);

#define add_float(list, inValue)                 \
    addNodeTail((list));                         \
    list->tail->value = malloc(sizeof(inValue)); \
    *((float *)list->tail->value) = (inValue);

#define add_double(list, inValue)                \
    addNodeTail((list));                         \
    list->tail->value = malloc(sizeof(inValue)); \
    *((double *)list->tail->value) = (inValue);

#define add_char(list, inValue)                  \
    addNodeTail((list));                         \
    list->tail->value = malloc(sizeof(inValue)); \
    list->tail->value = (inValue);

//------------instert NODE INTO LIST------------
#define insert_int(list, inValue, inIndex)               \
    TNode *node = addNode((list), (inValue), (inIndex)); \
    *((int *)node->value) = (inValue);

#define insert_float(list, inValue, inIndex)             \
    TNode *node = addNode((list), (inValue), (inIndex)); \
    *((float *)node->value) = (inValue);

#define insert_double(list, inValue, inIndex)            \
    TNode *node = addNode((list), (inValue), (inIndex)); \
    *((double *)node->value) = (inValue);

#define insert_char(list, inValue, inIndex)              \
    TNode *node = addNode((list), (inValue), (inIndex)); \
    node->value = (inValue);

#define getv(type) getv_##type
#define getv_int(list, index) *((int *)getValue(list, index))
#define getv_float(list, index) *((float *)getValue((list), (index)))
#define getv_double(list, index) *((double *)getValue((list), (index)))
#define getv_char(list, index) getValue((list), (index))

typedef struct SList TNode;
typedef struct SList TList;
struct SList
{
    int index;
    TNode *prev;
    TNode *next;
    TNode *tail;
    void *value;
};

TList *List(void);
void initList(TList *list);
void delList(TList *list);
void addNodeTail(TList *list);
TNode *addNode(TList *list, void *inValue, int inIndex);
void *getValue(TList *list, unsigned int inIndex);

int getIndex(TList *list, void *inValue);

void checkList(TList *list);
#endif // LIST_H
