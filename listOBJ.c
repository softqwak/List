
#include "listOBJ.h"

struct nodeOBJ_s
{
    int index;
    void *value;
    nodeOBJ_t *prev;
    nodeOBJ_t *next;
};
typedef struct nodeOBJ_s nodeOBJ_t;

struct listOBJ_s
{
    int length;
    nodeOBJ_t *tail;
    nodeOBJ_t *head;
};

static void updateListIndexes(listOBJ_t *list);
// static void printNode(nodeOBJ_t *node);

listOBJ_t *ListObj()
{
    listOBJ_t *list = malloc(sizeof(listOBJ_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void freeOBJ(listOBJ_t *list)
{
    nodeOBJ_t *tmp;
    nodeOBJ_t *node = list->head;
    while(node)
    {
        tmp = node;
        free(tmp);
        tmp = NULL;
        node = node->next;
    }
}

int lenOBJ(listOBJ_t *list)
{
    return list->length;
}

static void updateListIndexes(listOBJ_t *list)
{
    int tmp_index = 0;
    nodeOBJ_t *node = list->head;
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

void pushOBJ(listOBJ_t *list, void *value)
{
    nodeOBJ_t *node = malloc(sizeof(nodeOBJ_t));
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

void unshiftOBJ(listOBJ_t *list, void *value)
{
    nodeOBJ_t *node = malloc(sizeof(nodeOBJ_t));
    node->index = 0;
    node->value = value;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    updateListIndexes(list);
}

void reversOBJ(listOBJ_t *list)
{
    if (!list->head->next) return;
    nodeOBJ_t *tmp_node_prev;
    nodeOBJ_t *tmp_list_head;
    nodeOBJ_t *node = list->tail;
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

void *getOBJ(listOBJ_t *list, int index)
{
    nodeOBJ_t *node = list->head;
    while (node)
    {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return NULL;
}

void putOBJ(listOBJ_t *list, int index, void *value)
{
    nodeOBJ_t *node = list->head;
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

void *removeOBJ(listOBJ_t *list, int index)
{
    nodeOBJ_t *node = list->head;
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
            void *tmp_value = node->value;
            free(node);
            node = NULL;
            updateListIndexes(list);            
            return tmp_value;
        }
        node = node->next;
    }
    return NULL;
}

void insertOBJ(listOBJ_t *list, int index, void *value)
{
    nodeOBJ_t *ptrnode = list->head;
    while (ptrnode)
    {
        if (ptrnode->index == index)
        {
            nodeOBJ_t *node = malloc(sizeof(nodeOBJ_t));
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

void *popOBJ(listOBJ_t *list)
{
    void *value = list->tail->value;
    nodeOBJ_t *node = list->tail;
    list->tail = node->prev;
    node->prev->next = NULL;
    free(node);
    node = NULL;
    return value;
}

void *shiftOBJ(listOBJ_t *list)
{
    void *value = list->head->value;
    nodeOBJ_t *node = list->head;
    node->next->prev = node->prev;
    list->head = node->next;
    free(node);
    node = NULL;
    return value;
}

nodeOBJ_t *nodeOBJ(listOBJ_t *list, int index)
{
    nodeOBJ_t *node = list->head;
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


// static void printNode(nodeOBJ_t *node)
// {
//     printf("prev:[%p]", (void *)node->prev);
//     printf("<--node:[%p]-->", (void *)node);
//     printf("next:[%p]\n", (void *)node->next);
// }

void toStringOBJ(listOBJ_t *list)
{
    nodeOBJ_t *node = list->head;
    if (!node) return;
    printf("[");
    printf("<%p>", node->value);
    node = node->next;
    while (node)
    {
        printf(", <%p>", node->value);
        node = node->next;
    }
    printf("]\n");
    return;
}


