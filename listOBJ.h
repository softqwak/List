#ifndef _LISTOBJ_H_
#define _LISTOBJ_H_

#include <stdio.h>
#include <stdlib.h>

struct nodeOBJ_s;
typedef struct nodeOBJ_s nodeOBJ_t; 

struct listOBJ_s;
typedef struct listOBJ_s listOBJ_t;

// * Functions with listOBJ_t type
// инициализация списка
listOBJ_t *ListObj(); 

/*освобождение памяти списка*/
void freeOBJ(listOBJ_t *list);

// * Functions with nodeOBJ_t type
/* DONE получить указатель на узел под номером pos в списке (начиная с нуля). */
nodeOBJ_t *nodeOBJ(listOBJ_t *list, int index);

// * Functions with void type
/* DONE вывести список как строку (nm0, nm1, n2,...).*/
void toStringOBJ(listOBJ_t *list);

/* DONE добавить узел со значением value в конец списка list.*/
void pushOBJ(listOBJ_t *list, void *value);

/* DONE добавить узел со значением value в начало списка list.*/
void unshiftOBJ(listOBJ_t *list, void *value);

/* DONE перевернуть последовательность узлов в списке.*/
void reversOBJ(listOBJ_t *list);

/* DONE поменять поле value узла по индексу index в списке (начиная с нуля).*/
void putOBJ(listOBJ_t *list, int index, void *value);

/* DONE Добавить узел value на место index в списке (начиная с нуля), сдвинув всё вправо.*/
void insertOBJ(listOBJ_t *list, int index, void *value);


// * Functions with OBJ type
/* DONE получить поле value последнего узла и убрать его из списка.*/
void *popOBJ(listOBJ_t *list);

/* DONE получить поле value первого узла и убрать его из списка.*/
void *shiftOBJ(listOBJ_t *list);

/* DONE получить значение поля value узла на месте index в списке (начиная с нуля).*/
void *getOBJ(listOBJ_t *list, int index);

/* DONE удалить узел на месте index в списке list (начиная с нуля) и вернуть его value.*/
void *removeOBJ(listOBJ_t *list, int index);

/* DONE Получить размер списка */
int lenOBJ(listOBJ_t *list);
#endif /* _LISTOBJ_H_ */
