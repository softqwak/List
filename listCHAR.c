
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
    targetCHAR_t target;
    size_t lenMax;
    size_t lenMin;
};

static void updateListIndexes(listCHAR_t *list);
// static void printNode(nodeCHAR_t *node);

listCHAR_t *ListCHAR(targetCHAR_t target)
{
    return initListCHAR(target);
}

listCHAR_t *initListCHAR(targetCHAR_t target)
{
    listCHAR_t *list = malloc(sizeof(listCHAR_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->target = target;
    list->lenMax = 0;
    list->lenMin = 0;
    return list;
}

void freeCHAR(listCHAR_t *list)
{
    nodeCHAR_t *tmp;
    nodeCHAR_t *node = list->head;
    while (node)
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
        if (!node->next)
        {
            list->tail = node;
            tmp_index += 1;
            break;
        }
        node = node->next;
        tmp_index += 1;
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
    list->length += 1;
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

void addCHAR(listCHAR_t *list, char *value)
{
    char tmp[200];
    size_t lenValue;
    if (!list)
        return;
    switch (list->target)
    {
    case STORAGE_CHAR:
        pushCHAR(list, value);
        break;
    case SORTUP_CHAR:

        strncpy(tmp, value, 200);
        lenValue = strlen(tmp);

        if (list->length == 0)
        {
            // printf("first\n");
            list->lenMax = lenValue;
            list->lenMin = lenValue;
            pushCHAR(list, value);
        }
        else if (lenValue <= list->lenMin)
        {
            // printf("min\n");
            list->lenMin = lenValue;
            unshiftCHAR(list, value);
        }
        else if (lenValue >= list->lenMax)
        {
            // printf("max\n");
            list->lenMax = lenValue;
            pushCHAR(list, value);
        }
        else
        {
            int indexCenterValue = lenCHAR(list) / 2;
            char *centerValue = getCHAR(list, indexCenterValue);
            strncpy(tmp, centerValue, 200);
            size_t lenCenterValue = strlen(tmp);
            strncpy(tmp, value, 200);
            lenValue = strlen(tmp);
            // printf("indexCenterValue = %d\n", indexCenterValue);
            // printf("lenCenterValue = %zu\n", lenCenterValue);
            // printf("lenValue = %zu\n", lenValue);

            while (lenValue < lenCenterValue)
            {
                indexCenterValue += 1;
                centerValue = getCHAR(list, indexCenterValue);
                strncpy(tmp, centerValue, 200);
                lenCenterValue = strlen(tmp);
            }
            insertCHAR(list, indexCenterValue + 1, value);
        }
        break;
    case SORTDOWN_CHAR:
        /* code */
        break;
    default:
        break;
    }
}

void reversCHAR(listCHAR_t *list)
{
    if (!list->head->next)
        return;
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

        if (node == tmp_list_head)
            break;
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
            else if (ptrnode->prev && ptrnode)
            {
                node->prev = ptrnode->prev;
                node->next = ptrnode;
                ptrnode->prev->next = node;
                ptrnode->prev = node;
            }
            node->value = value;
            list->length += 1;
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
    if (!node)
        return;
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
