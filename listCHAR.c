
#include "listCHAR.h"

struct nodeCHAR_s
{
    int index;
    char *value;
    nodeCHAR_t *prev;
    nodeCHAR_t *next;
};

struct listCHAR_s
{
    int length;
    nodeCHAR_t *tail;
    nodeCHAR_t *head;
};

static void updateListIndexes(listCHAR_t *list);
// static void printNode(nodeCHAR_t *node);

listCHAR_t *ListChar()
{
    listCHAR_t *list = malloc(sizeof(listCHAR_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void freeCHAR(listCHAR_t *list)
{
    nodeCHAR_t *tmp;
    nodeCHAR_t *node = list->head;
    while(node)
    {
        tmp = node;
        free(tmp);
        tmp = NULL;
        node = node->next;
    }
}

int lenCHAR(listCHAR_t *list)
{
    return list->length;
}

static void updateListIndexes(listCHAR_t *list)
{
    int tmp_index = 0;
    nodeCHAR_t *node = list->head;
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

void pushCHAR(listCHAR_t *list, char *value)
{
    nodeCHAR_t *node = malloc(sizeof(nodeCHAR_t));
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

void unshiftCHAR(listCHAR_t *list, char *value)
{
    nodeCHAR_t *node = malloc(sizeof(nodeCHAR_t));
    node->index = 0;
    node->value = value;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    updateListIndexes(list);
}

void reversCHAR(listCHAR_t *list)
{
    if (!list->head->next) return;
    nodeCHAR_t *tmp_node_prev;
    nodeCHAR_t *tmp_list_head;
    nodeCHAR_t *node = list->tail;
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

char *getCHAR(listCHAR_t *list, int index)
{
    nodeCHAR_t *node = list->head;
    while (node)
    {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return "";
}

void putCHAR(listCHAR_t *list, int index, char *value)
{
    nodeCHAR_t *node = list->head;
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

char *removeCHAR(listCHAR_t *list, int index)
{
    nodeCHAR_t *node = list->head;
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
            char *tmp_value = node->value;
            free(node);
            node = NULL;
            updateListIndexes(list);            
            return tmp_value;
        }
        node = node->next;
    }
    return "";
}

void insertCHAR(listCHAR_t *list, int index, char *value)
{
    nodeCHAR_t *ptrnode = list->head;
    while (ptrnode)
    {
        if (ptrnode->index == index)
        {
            nodeCHAR_t *node = malloc(sizeof(nodeCHAR_t));
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

char *popCHAR(listCHAR_t *list)
{
    char *value = list->tail->value;
    nodeCHAR_t *node = list->tail;
    list->tail = node->prev;
    node->prev->next = NULL;
    free(node);
    node = NULL;
    return value;
}

char *shiftCHAR(listCHAR_t *list)
{
    char *value = list->head->value;
    nodeCHAR_t *node = list->head;
    node->next->prev = node->prev;
    list->head = node->next;
    free(node);
    node = NULL;
    return value;
}

nodeCHAR_t *nodeCHAR(listCHAR_t *list, int index)
{
    nodeCHAR_t *node = list->head;
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


// static void printNode(nodeCHAR_t *node)
// {
//     printf("prev:[%p]", (void *)node->prev);
//     printf("<--node:[%p]-->", (void *)node);
//     printf("next:[%p]\n", (void *)node->next);
// }

void toStringCHAR(listCHAR_t *list)
{
    nodeCHAR_t *node = list->head;
    if (!node) return;
    printf("[");
    printf("\"%s\"", node->value);
    node = node->next;
    while (node)
    {
        printf(", \"%s\"", node->value);
        node = node->next;
    }
    printf("]\n");
    return;
}
