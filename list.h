#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define HEADLIST list->next
#define TAILLIST list->tail
#define add(type) add_##type
#define insert(type) insert_##type

int iv;
float fv;
double dv;

float *pfv;
int *piv;
double *pdv;

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
#define insert_int(list, inValue, inIndex)            \
    iv = inValue;                                     \
    piv = &iv;                                        \
    node_insert = insertNode((list), piv, (inIndex)); \
    if (node_insert)                                  \
        *((int *)node_insert->value) = (inValue);

#define insert_float(list, inValue, inIndex)          \
    fv = inValue;                                     \
    pfv = &fv;                                        \
    node_insert = insertNode((list), pfv, (inIndex)); \
    if (node_insert)                                  \
        *((float *)node_insert->value) = (inValue);

#define insert_double(list, inValue, inIndex)         \
    dv = inValue;                                     \
    pdv = &dv;                                        \
    node_insert = insertNode((list), pdv, (inIndex)); \
    if (node_insert)                                  \
        *((double *)node_insert->value) = (inValue);

#define insert_char(list, inValue, inIndex)                 \
    node_insert = insertNode((list), (inValue), (inIndex)); \
    if (node_insert)                                        \
        node_insert->value = (inValue);

#define getv(type) getv_##type
#define getv_int(list, index) *((int *)getValue(list, index))
#define getv_float(list, index) *((float *)getValue((list), (index)))
#define getv_double(list, index) *((double *)getValue((list), (index)))
#define getv_char(list, index) getValue((list), (index))

#define del(type) del_##type
#define del_float(list, inValue) \
    fv = inValue;                \
    pfv = &fv;                   \
    del_value((list), pfv);

typedef struct SList TNode;
typedef struct SList TList;
struct SList
{
    int index;
    TNode *prev;
    TNode *next;
    TNode *tail;
    int length;
    void *value;
};

TNode *node_insert;

TList *List(void);
void initList(TList *list);
void delList(TList *list);
void del_index(TList *list, int inIndex);
void del_value(TList *list, void *inValue);

void addNodeTail(TList *list);
TNode *insertNode(TList *list, void *inValue, int inIndex);
void *getValue(TList *list, unsigned int inIndex);
int getIndex(TList *list, void *inValue);
void checkList(TList *list);
#endif // LIST_H
