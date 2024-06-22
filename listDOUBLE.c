
#include "listDOUBLE.h"

struct nodeDOUBLE_s
{
    int index;
    double value;
    nodeDOUBLE_t *prev;
    nodeDOUBLE_t *next;
};

struct listDOUBLE_s
{
    int length;
    nodeDOUBLE_t *tail;
    nodeDOUBLE_t *head;
};

static void updateListIndexes(listDOUBLE_t *list);
// static void printNode(nodeDOUBLE_t *node);

listDOUBLE_t *ListDouble()
{
    listDOUBLE_t *list = malloc(sizeof(listDOUBLE_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void freeDOUBLE(listDOUBLE_t *list)
{
    nodeDOUBLE_t *tmp;
    nodeDOUBLE_t *node = list->head;
    while(node)
    {
        tmp = node;
        free(tmp);
        tmp = NULL;
        node = node->next;
    }
}

int lenDOUBLE(listDOUBLE_t *list)
{
    return list->length;
}

static void updateListIndexes(listDOUBLE_t *list)
{
    int tmp_index = 0;
    nodeDOUBLE_t *node = list->head;
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

void pushDOUBLE(listDOUBLE_t *list, double value)
{
    nodeDOUBLE_t *node = malloc(sizeof(nodeDOUBLE_t));
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

void unshiftDOUBLE(listDOUBLE_t *list, double value)
{
    nodeDOUBLE_t *node = malloc(sizeof(nodeDOUBLE_t));
    node->index = 0;
    node->value = value;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    updateListIndexes(list);
}

void reversDOUBLE(listDOUBLE_t *list)
{
    if (!list->head->next) return;
    nodeDOUBLE_t *tmp_node_prev;
    nodeDOUBLE_t *tmp_list_head;
    nodeDOUBLE_t *node = list->tail;
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

double getDOUBLE(listDOUBLE_t *list, int index)
{
    nodeDOUBLE_t *node = list->head;
    while (node)
    {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return -1;
}

void putDOUBLE(listDOUBLE_t *list, int index, double value)
{
    nodeDOUBLE_t *node = list->head;
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

double removeDOUBLE(listDOUBLE_t *list, int index)
{
    nodeDOUBLE_t *node = list->head;
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
            double tmp_value = node->value;
            free(node);
            node = NULL;
            updateListIndexes(list);            
            return tmp_value;
        }
        node = node->next;
    }
    return -1;
}

void insertDOUBLE(listDOUBLE_t *list, int index, double value)
{
    nodeDOUBLE_t *ptrnode = list->head;
    while (ptrnode)
    {
        if (ptrnode->index == index)
        {
            nodeDOUBLE_t *node = malloc(sizeof(nodeDOUBLE_t));
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

double popDOUBLE(listDOUBLE_t *list)
{
    double value = list->tail->value;
    nodeDOUBLE_t *node = list->tail;
    list->tail = node->prev;
    node->prev->next = NULL;
    free(node);
    node = NULL;
    return value;
}

double shiftDOUBLE(listDOUBLE_t *list)
{
    double value = list->head->value;
    nodeDOUBLE_t *node = list->head;
    node->next->prev = node->prev;
    list->head = node->next;
    free(node);
    node = NULL;
    return value;
}

nodeDOUBLE_t *nodeDOUBLE(listDOUBLE_t *list, int index)
{
    nodeDOUBLE_t *node = list->head;
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


// static void printNode(nodeDOUBLE_t *node)
// {
//     printf("prev:[%p]", (void *)node->prev);
//     printf("<--node:[%p]-->", (void *)node);
//     printf("next:[%p]\n", (void *)node->next);
// }

void toStringDOUBLE(listDOUBLE_t *list)
{
    nodeDOUBLE_t *node = list->head;
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
