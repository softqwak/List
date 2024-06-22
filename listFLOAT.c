
#include "listFLOAT.h"

struct nodeFLOAT_s
{
    int index;
    float value;
    nodeFLOAT_t *prev;
    nodeFLOAT_t *next;
};

struct listFLOAT_s
{
    int length;
    nodeFLOAT_t *tail;
    nodeFLOAT_t *head;
};

static void updateListIndexes(listFLOAT_t *list);
// static void printNode(nodeFLOAT_t *node);

listFLOAT_t *ListFloat()
{
    listFLOAT_t *list = malloc(sizeof(listFLOAT_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void freeFLOAT(listFLOAT_t *list)
{
    nodeFLOAT_t *tmp;
    nodeFLOAT_t *node = list->head;
    while(node)
    {
        tmp = node;
        free(tmp);
        tmp = NULL;
        node = node->next;
    }
}

int lenFLOAT(listFLOAT_t *list)
{
    return list->length;
}

static void updateListIndexes(listFLOAT_t *list)
{
    int tmp_index = 0;
    nodeFLOAT_t *node = list->head;
    while (node)
    {
        node->index = tmp_index;
        if (!node->next){
            list->tail = node;
            return;
        }
        node = node->next;
        tmp_index++;
    }
    list->length = tmp_index;
}

void pushFLOAT(listFLOAT_t *list, float value)
{
    nodeFLOAT_t *node = malloc(sizeof(nodeFLOAT_t));
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

void unshiftFLOAT(listFLOAT_t *list, float value)
{
    nodeFLOAT_t *node = malloc(sizeof(nodeFLOAT_t));
    node->index = 0;
    node->value = value;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    updateListIndexes(list);
}

void reversFLOAT(listFLOAT_t *list)
{
    if (!list->head->next) return;
    nodeFLOAT_t *tmp_node_prev;
    nodeFLOAT_t *tmp_list_head;
    nodeFLOAT_t *node = list->tail;
    tmp_list_head = list->head;
    list->head = node;
    while (node)
    {
        tmp_node_prev = node->prev;
        node->prev = node->next;        
        node->next = tmp_node_prev;
        
        if (node == tmp_list_head) break;
        tmp_node_prev->next = node;
        node = node->next;
    }
    list->tail = node;
    updateListIndexes(list);
}

float getFLOAT(listFLOAT_t *list, int index)
{
    nodeFLOAT_t *node = list->head;
    while (node)
    {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return -1;
}

void putFLOAT(listFLOAT_t *list, int index, float value)
{
    nodeFLOAT_t *node = list->head;
    while (node)
    {
        if (node->index == index)
        {
            node->value = value;
            return;
        }
        node = node->next;
    }
    return;
}

float removeFLOAT(listFLOAT_t *list, int index)
{
    nodeFLOAT_t *node = list->head;
    while (node)
    {
        if (node->index == index)
        {
            if (index == 0)
            {
                node->next->prev = node->prev;
                list->head = node->next;
            }
            else if (index < list->length - 1)
            {
                node->next->prev = node->prev;
                node->prev->next = node->next;
            }
            else if (index == list->length - 1)
            {
                list->tail = node->prev;
                node->prev->next = NULL;
            }
            float tmp_value = node->value;
            free(node);
            node = NULL;
            updateListIndexes(list);            
            return tmp_value;
        }
        node = node->next;
    }
    return -1;
}

void insertFLOAT(listFLOAT_t *list, int index, float value)
{
    nodeFLOAT_t *ptrnode = list->head;
    while (ptrnode)
    {
        if (ptrnode->index == index)
        {
            nodeFLOAT_t *node = malloc(sizeof(nodeFLOAT_t));
            node->index = index;
            if (ptrnode->prev == NULL && ptrnode)
            {
                node->next = ptrnode;
                node->prev = NULL;
                ptrnode->prev = node;
                list->head = node;
            }
            else if (ptrnode->prev && ptrnode) {
                node->prev = ptrnode->prev;
                node->next = ptrnode;
                ptrnode->prev->next = node;
                ptrnode->prev = node;
            }
            node->value = value;
            list->length++;
            updateListIndexes(list);
            return;
        }
        ptrnode = ptrnode->next;
    }
    return;
}

float popFLOAT(listFLOAT_t *list)
{
    float value = list->tail->value;
    nodeFLOAT_t *node = list->tail;
    list->tail = node->prev;
    node->prev->next = NULL;
    free(node);
    node = NULL;
    return value;
}

float shiftFLOAT(listFLOAT_t *list)
{
    float value = list->head->value;
    nodeFLOAT_t *node = list->head;
    node->next->prev = node->prev;
    list->head = node->next;
    free(node);
    node = NULL;
    return value;
}

nodeFLOAT_t *nodeFLOAT(listFLOAT_t *list, int index)
{
    nodeFLOAT_t *node = list->head;
    while (node)
    {
        if (node->index == index)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}


// static void printNode(nodeFLOAT_t *node)
// {
//     printf("prev:[%p]", (void *)node->prev);
//     printf("<--node:[%p]-->", (void *)node);
//     printf("next:[%p]\n", (void *)node->next);
// }

void toStringFLOAT(listFLOAT_t *list)
{
    nodeFLOAT_t *node = list->head;
    if (!node) return;
    printf("[");
    printf("%.5f", node->value);
    node = node->next;
    while (node)
    {
        printf(", %.5f", node->value);
        node = node->next;
    }
    printf("]\n");
    return;
}
