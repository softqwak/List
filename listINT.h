#ifndef _LISTINT_H_
#define _LISTINT_H_

#include <stdio.h>
#include <stdlib.h>

enum target_e
{
    STORAGE,
    SORTUP,
    SORTDOWN
};
typedef enum target_e target_t;

struct nodeINT_s;
typedef struct nodeINT_s nodeINT_t;

struct listINT_s;
typedef struct listINT_s listINT_t;

/**
 * Initializing the list of int values.
 * @param target enum type target: STORAGE, SORTUP, SORTDOWN
 * @attention SORTUP & SORTDOWN - Only addINT function is available
 * */
listINT_t *ListINT(target_t target);

/**
 * Freeing up memory
 * @param list a pointer to a list
 */
void freeINT(listINT_t *list);

/**
 * Return a poinet to a list item
 * @param list a pointer to a list item
 * @param index index of the list item
 */
nodeINT_t *nodeINT(listINT_t *list, int index);

/**
 * Output a list in the format: [item1, item2, ...]
 * @param list a pointer to a list
 */
void toStringINT(listINT_t *list);

/**
 * Add an element with the value value to the end of the list.
 * @paragraph
 * @param list a pointer to a list
 * @param value of int type
 * */
void pushINT(listINT_t *list, int value);

/**
 * Add a node with the value value to the top of the list.
 * @param list a pointer to a list
 * @param value of int type
 */
void unshiftINT(listINT_t *list, int value);

/**
 * Flip the sequence of nodes in the list.
 * @param list a pointer to a list
 * */
void reversINT(listINT_t *list);

/**
 *Change the node's value field by index in the list.
 * @param list pointer to a list
 * @param index index of the list item
 * @param value of int type
 * */
void putINT(listINT_t *list, int index, int value);

/**
 * Add the node with the value value to the index place in the list by sliding everything to the right.
 * @param list pointer to a list
 * @param index index of the list item
 * @param value of int type
 */
void insertINT(listINT_t *list, int index, int value);

/**
 * Add to the list, the value value. The position will set according to the purpose of the list. If target is STORAGE, will be called pushINT function
 * @param list a pointer to a list
 * @param value of int type
 */
void addINT(listINT_t *list, int value);

/**
 * Get the value field of the last node and remove it from the list.
 * @param list a pointer to a list
 */
int popINT(listINT_t *list);

/**
 * Get the value field of the first node and remove it from the list.
 * @param list a pointer to a list
 */
int shiftINT(listINT_t *list);

/**
 * Get the value of the node's value field at the index position in the list.
 * @param list pointer to a list
 * @param index index of the list item
 */
int getINT(listINT_t *list, int index);

/**
 * Delete the node in place of index in the list and return its value.
 * @param list pointer to a list
 * @param index index of the list item
 */
int removeINT(listINT_t *list, int index);

/**
 * Get length of list
 * @param list pointer to a list
 */
int lenINT(listINT_t *list);

/**
 * Get value of node
 * @param node a pointer to a node
 */
int valueINT(nodeINT_t *node);

#endif /* _LISTINT_H_ */
