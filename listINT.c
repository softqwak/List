
#include "listINT.h"

listINT_t *ListInt()
{
    listINT_t *list = malloc(sizeof(listINT_t));
    printf("list created!\n");
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void pushINT(listINT_t *list, int value)
{
    printf("pushINT\n");
    nodeINT_t *node = malloc(sizeof(nodeINT_t));
    node->next = NULL;
    node->value = value;
    node->index = list->length;
    node->prev = list->tail;
    if (list->length)
        list->tail->next = node;
    else
        list->head = node;
    list->tail = node;
    list->length++;
    return;
}

void toStringINT(listINT_t *list)
{
    nodeINT_t *node = list->head;
    while (node)
    {
        printf("add:[%p] value:[%i]\n", node, node->value);
        node = node->next;
    }
}