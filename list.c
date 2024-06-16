
#include "list.h"

static void updateList(TList *list)
{
    TNode *ptr = list->next;
    int index = 0;
    while (ptr)
    {
        ptr->index = index;
        ptr = ptr->next;
        index++;
    }
    list->tail = ptr;
}

TList *List(void)
{
    printf("---LIST---\n");

    TNode *node = (TNode *)malloc(sizeof(TNode));

    initList(node);
    return (TList *)node;
}

void initList(TList *list)
{
    printf("---INIT LIST---\n");
    list->next = NULL;
    list->prev = NULL;
    list->tail = list;
    list->tail->index = -1;
    return;
}

void addNodeTail(TList *list)
{
    printf("ADD-NODE\n");
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->tail = NULL;
    node->index = list->tail->index + 1;
    /*
        TODO прописать вставку чтобы все указатели были правильные
        для того чтобы указатель на конец списка
        всегда указывал на самый последний узел
    */
    /* результат вывода в консоль
    ---LIST---
    ---INIT LIST---
    ADD-NODE
    v1
    tail:[0x7fc109705990]
    prev:[0x0]<--NODE:[0x7fc109705990][0]-->next:[0x0]
    ADD-NODE
    v1
    tail:[0x7fc1097059d0]
    prev:[0x0]<--NODE:[0x7fc1097059d0][0]-->next:[0x0]
    ADD-NODE
    v1
    tail:[0x7fc109705a10]
    prev:[0x0]<--NODE:[0x7fc109705a10][0]-->next:[0x0]
    ---FREE LIST---
    */
    if (node->index == 0)
    {
        printf("v1\n");
        list = node;
        list->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else
    {
        printf("v2\n");
        list->tail->next = node;
        node->prev = list->tail;
        node->next = NULL;
        list->tail = node;
    }
    printf("tail:[%p]\n", list->tail);
    printf("prev:[%p]", node->prev);
    printf("<--NODE:[%p][%d]-->", node, node->index);
    printf("next:[%p]\n", node->next);

    return;
}

TNode *addNode(TList *list, void *inValue, int inIndex)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->index = inIndex;
    node->tail = NULL;
    TNode *ptr = list->next; // first node
    do
    {
        if (ptr->index == inIndex)
        {
            if (ptr->prev == NULL && ptr) // head
            {
                //.
            }
            else if (ptr->prev && ptr) // midle
            {
                ptr->prev->next = node;
                node->prev = ptr->prev;
                node->next = ptr;
                ptr->prev = node;
            }
            else if (ptr->next == NULL && ptr) // tail
            {
                //.
            }
            node->value = malloc(sizeof(inValue));
            updateList(list);
            return node;
        }
        ptr = ptr->next;
    } while (ptr != NULL);
}

void checkList(TList *list)
{
    printf("---PRINT LIST---\n");
    TNode *ptr = list->next;
    printf("tail:[%p]\n", list->tail);
    printf("head:[%p]\n", list);
    do
    {
        printf("prev:[%p]", ptr->prev);
        printf("<--NODE:[%p][%d]-->", ptr, ptr->index);
        printf("next:[%p]\n", ptr->next);

        ptr = ptr->next;
    } while (ptr != NULL);

    free(ptr);
    ptr = NULL;
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

int getIndex(TList *list, void *inValue)
{
    TNode *ptr = list->next;
    do
    {
        if (ptr->value == inValue)
        {
            return ptr->index;
        }
        ptr = ptr->next;
    } while (ptr != NULL);
    assert(0 && "Not value in list");
}

void delList(TList *list)
{
    printf("---FREE LIST---\n");
    TNode *ptr = list->tail->prev;
    while (ptr)
    {
        TNode *tmp = ptr;
        ptr = ptr->prev;
        free(tmp);
        tmp->value = NULL;
        tmp = NULL;
    }
    return;
}
