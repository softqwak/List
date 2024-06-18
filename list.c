
#include "list.h"

#define NDEBUG

static void updateList(TList *list)
{
    TNode *ptr = list->next;
    int index = 0;
    while (ptr)
    {
        if (!ptr->next)
            list->tail = ptr;
        ptr->index = index;
        ptr = ptr->next;
        index++;
    }
    return;
}

TList *List(void)
{
#ifdef DEBUG
    printf("---LIST---\n");
#endif

    TNode *node = (TNode *)malloc(sizeof(TNode));

    initList(node);
    return (TList *)node;
}

void initList(TList *list)
{
#ifdef DEBUG
    printf("---INIT LIST---\n");
#endif
    list->next = NULL;
    list->prev = NULL;
    list->tail = list;
    list->tail->index = -1;
    list->length = 0;
    return;
}

void addNodeTail(TList *list)
{
#ifdef DEBUG
    printf("---ADD NODE TAILLIST---\n");
#endif
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->tail = NULL;
    node->index = list->tail->index + 1;
    list->tail->next = node;
    node->prev = list->tail;
    node->next = NULL;
    list->tail = node;
    list->length++;
    return;
}

TNode *insertNode(TList *list, void *inValue, int inIndex)
{
#ifdef DEBUG
    printf("---INSERT NODE---\n");
#endif
    TNode *ptr = HEADLIST; // first node
    do
    {
        if (ptr->index == inIndex)
        {
            TNode *node = (TNode *)malloc(sizeof(TNode));
            node->tail = NULL;
            node->index = inIndex;
            if (ptr->prev == NULL && ptr) // in HEADLIST
            {
                node->prev = HEADLIST;
                node->next = ptr;
                ptr->prev = node;
            }
            else if (ptr->prev && ptr) // anyware if not in HEADLIST
            {
                ptr->prev->next = node;
                node->prev = ptr->prev;
                node->next = ptr;
                ptr->prev = node;
            }
            node->value = malloc(sizeof(inValue));
            updateList(list);
            list->length++;
            return node;
        }
        ptr = ptr->next;
        if (ptr == NULL)
            printf("Attention! Index [%i] ouf of range list!\n", inIndex);
    } while (ptr != NULL);
    return NULL;
}

void checkList(TList *list)
{
#ifdef DEBUG
    printf("---PRINT LIST---\n");
#endif
    TNode *ptr = list->next;
    printf("TAILLIST:[%p]\n", TAILLIST);
    printf("HEADLIST:[%p]\n", HEADLIST);
    do
    {
        printf("prev:[%p]", ptr->prev);
        printf("<--N[%p]:[%d][%p]-->", ptr, ptr->index, ptr->value);
        printf(ptr->next ? "next:[%p]\n" : "NULL\n", ptr->next);
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

void del_index(TList *list, int inIndex)
{
#ifdef DEBUG
    printf("---DEL NODE BY INDEX---\n");
#endif
    TNode *ptr = HEADLIST;
    while (ptr)
    {
        if (ptr->index == inIndex)
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            free(ptr);
            ptr = NULL;
            updateList(list);
            list->length--;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

void del_value(TList *list, void *inValue)
{
#ifdef DEBUG
    printf("---DEL NODE BY VALUE---\n");
#endif
    TNode *ptr = HEADLIST;
    while (ptr)
    {
        if (memcmp(ptr->value, inValue, sizeof(ptr->value)) == 0)
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            free(ptr);
            ptr = NULL;
            updateList(list);
            list->length--;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

void delList(TList *list)
{
#ifdef DEBUG
    printf("---FREE LIST---\n");
#endif
    TNode *ptr = TAILLIST;
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
