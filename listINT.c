
/**
 * Режим STORAGE работает стабильно быстрее SORTUP и SORTDOWN на 8-11 е.и.
 * Режим SORTDOWN работает стабильно медленнее SORTUP на 2-3 е.и.
 *
 * STORAGE / SORTUP : 2 / 10; 5 / 14
 */

#include "listINT.h"

struct nodeINT_s
{
    int index;
    int value;
    nodeINT_t *prev;
    nodeINT_t *next;
};
typedef struct nodeINT_s nodeINT_t;

struct listINT_s
{
    int length;
    nodeINT_t *tail;
    nodeINT_t *head;
    targetINT_t target;
    int minValue;
    int maxValue;
};

static void updateListIndexes(listINT_t *list);
static listINT_t *initINT(targetINT_t target);
// static void printNode(nodeINT_t *node);

listINT_t *ListINT(targetINT_t target)
{
    return initINT(target);
}

static listINT_t *initINT(targetINT_t target)
{
    listINT_t *list = malloc(sizeof(listINT_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->target = target;
    /* Возможно в будущем будет разнаая инициализация */
    switch (list->target)
    {
    case STORAGE_INT:
    case SORTUP_INT:
    case SORTDOWN_INT:
        list->minValue = __INT32_MAX__;
        list->maxValue = -__INT32_MAX__;
        break;
    }
    return list;
}

void freeINT(listINT_t *list)
{
    nodeINT_t *tmp;
    nodeINT_t *node = list->head;
    while (node)
    {
        tmp = node;
        free(tmp);
        tmp = NULL;
        node = node->next;
    }
}

int lenINT(listINT_t *list)
{
    return list->length;
}

static void updateListIndexes(listINT_t *list)
{
    int tmp_index = 0;
    nodeINT_t *node = list->head;
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

void pushINT(listINT_t *list, int value)
{
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
    list->length += 1;
    return;
}

void unshiftINT(listINT_t *list, int value)
{
    nodeINT_t *node = malloc(sizeof(nodeINT_t));
    node->index = 0;
    node->value = value;
    node->prev = NULL;
    if (list->head)
    {
        node->next = list->head;
        list->head->prev = node;
    }
    else
    {
        node->prev = NULL;
        node->next = NULL;
        list->tail = node;
    }

    list->head = node;
    updateListIndexes(list);
}

void reversINT(listINT_t *list)
{
    if (!list->head->next)
        return;
    nodeINT_t *tmp_node_prev;
    nodeINT_t *tmp_list_head;
    nodeINT_t *node = list->tail;
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

int getINT(listINT_t *list, int index)
{
    nodeINT_t *node = list->head;
    while (node)
    {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return __INT32_MAX__;
}

void putINT(listINT_t *list, int index, int value)
{
    nodeINT_t *node = list->head;
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

int removeINT(listINT_t *list, int index)
{
    nodeINT_t *node = list->head;
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
            int tmp_value = node->value;
            free(node);
            node = NULL;
            updateListIndexes(list);
            return tmp_value;
        }
        node = node->next;
    }
    return __INT32_MAX__;
}

void insertINT(listINT_t *list, int index, int value)
{
    nodeINT_t *ptrnode = list->head;

    while (ptrnode)
    {
        if (ptrnode->index == index)
        {
            nodeINT_t *node = malloc(sizeof(nodeINT_t));
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
            list->length++;
            updateListIndexes(list);
            return;
        }
        ptrnode = ptrnode->next;
    }
    return;
}

void addINT(listINT_t *list, int value)
{
    switch (list->target)
    {
    case STORAGE_INT:
        pushINT(list, value);
        break;
    case SORTUP_INT:
        if (list->length == 0)
        {
            list->maxValue = value;
            list->minValue = value;
            pushINT(list, value);
        }
        else if (value >= list->maxValue)
        {
            list->maxValue = value;
            pushINT(list, value);
        }
        else if (value <= list->minValue)
        {
            list->minValue = value;
            unshiftINT(list, value);
        }
        else
        {
            int indexActualNode = lenINT(list) / 2;
            nodeINT_t *actualNode = nodeINT(list, indexActualNode);
            int actualValue = valueINT(actualNode);
            int preactualValue = valueINT(nodeINT(list, indexActualNode - 1));
            if (actualValue > value)
            {
                while (actualValue > value && preactualValue > value)
                {
                    indexActualNode -= 1;

                    actualNode = nodeINT(list, indexActualNode);
                    actualValue = valueINT(actualNode);
                    preactualValue = valueINT(nodeINT(list, indexActualNode - 1));
                }
                insertINT(list, indexActualNode, value);
            }
            else if (actualValue < value)
            {
                while (actualValue < value && preactualValue < value)
                {
                    indexActualNode += 1;
                    actualNode = nodeINT(list, indexActualNode);
                    actualValue = valueINT(actualNode);
                    preactualValue = valueINT(nodeINT(list, indexActualNode));
                }
                insertINT(list, indexActualNode, value);
            }
            else
                insertINT(list, indexActualNode, value);
        }
        break;
    case SORTDOWN_INT:
        if (list->length == 0)
        {
            list->maxValue = value;
            list->minValue = value;
            pushINT(list, value);
        }
        else if (value >= list->maxValue)
        {
            list->maxValue = value;
            unshiftINT(list, value);
        }
        else if (value <= list->minValue)
        {
            list->minValue = value;
            pushINT(list, value);
        }
        else
        {
            int lenList = lenINT(list);
            int indexActualNode = lenList / 2;
            nodeINT_t *actualNode = nodeINT(list, indexActualNode);
            int actualValue = valueINT(actualNode);
            int postactualValue;

            if ((indexActualNode + 1) == lenList)
                postactualValue = actualValue;
            else
                postactualValue = valueINT(nodeINT(list, indexActualNode + 1));
            if (actualValue > value)
            {
                while (actualValue > value && postactualValue > value)
                {
                    indexActualNode += 1;
                    actualNode = nodeINT(list, indexActualNode);
                    actualValue = valueINT(actualNode);
                    if ((indexActualNode + 1) == lenList) // last node
                        postactualValue = actualValue;
                    else
                        postactualValue = valueINT(nodeINT(list, indexActualNode + 1));
                }
                insertINT(list, indexActualNode + 1, value);
            }
            else if (actualValue < value)
            {
                while (actualValue < value && postactualValue < value)
                {
                    indexActualNode -= 1;
                    actualNode = nodeINT(list, indexActualNode);
                    actualValue = valueINT(actualNode);
                    if (indexActualNode == 0)
                        postactualValue = actualValue;
                    else
                        postactualValue = valueINT(nodeINT(list, indexActualNode - 1));
                }
                insertINT(list, indexActualNode + 1, value);
            }
            else
                insertINT(list, indexActualNode, value);
        }

        break;
    default:
        /* code */
        break;
    }
}

int popINT(listINT_t *list)
{
    int value = list->tail->value;
    nodeINT_t *node = list->tail;
    list->tail = node->prev;
    node->prev->next = NULL;
    free(node);
    node = NULL;
    return value;
}

int shiftINT(listINT_t *list)
{
    int value = list->head->value;
    nodeINT_t *node = list->head;
    node->next->prev = node->prev;
    list->head = node->next;
    free(node);
    node = NULL;
    return value;
}

nodeINT_t *nodeINT(listINT_t *list, int index)
{
    nodeINT_t *node = list->head;
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

int valueINT(nodeINT_t *node)
{
    return node->value;
}

// static void printNode(nodeINT_t *node)
// {
//     printf("prev:[%p]", (void *)node->prev);
//     printf("<--node:[%p]-->", (void *)node);
//     printf("next:[%p]\n", (void *)node->next);
// }

void toStringINT(listINT_t *list)
{
    nodeINT_t *node = list->head;
    if (!node)
        return;
    printf("[");
    printf("%i", node->value);
    node = node->next;
    while (node)
    {
        printf(", %i", node->value);
        node = node->next;
    }
    printf("]\n");
    return;
}
