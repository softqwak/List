
#include "list.h"

TList *List(void)
{
    printf("LIST\n");

    TNode *node = malloc(sizeof(TNode));

    initList(node);
    return (TList *)node;
}

void initList(TList *list)
{
    printf("INIT-LIST\n");
    list->index = -1;
    list->next = NULL;
    list->prev = NULL;
    list->head = list;
    list->tail = list;
    return;
}

void addNode(TList *list)
{
    printf("ADD-NODE\n");
    TNode *node = malloc(sizeof(TNode));
    node->index = list->tail->index + 1;
    list->tail->next = node;
    node->prev = list->tail;
    node->next = NULL;
    list->tail = node;

    return;
}

void checkList(TList *list)
{
    printf("PRINT-LIST\n");
    TNode *ptr = list->next;
    do
    {
        printf("prev:[%p]", ptr->prev);
        printf("node:[%p]", ptr);
        printf("next:[%p]\n", ptr->next);

        ptr = ptr->next;
    } while (ptr != NULL);
    return;
}

void *getValue(TList *list, unsigned int inIndex)
{
    TNode *ptr = list->next;
    do
    {
        if (ptr->index == (int)inIndex)
        {
            return ptr->value;
        }
        ptr = ptr->next;
    } while (ptr != NULL);
    return NULL;
}

void delList(TList *list)
{
    free(list);
    list = NULL;
    return;
}
