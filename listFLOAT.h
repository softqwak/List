
#ifndef _LISTFLOAT_H_
#define _LISTFLOAT_H_

#include <stdio.h>
#include <stdlib.h>

struct nodeFLOAT_s;
typedef struct nodeFLOAT_s nodeFLOAT_t; 

struct listFLOAT_s;
typedef struct listFLOAT_s listFLOAT_t;

// * Functions with listINT_t type
// инициализация списка
listFLOAT_t *ListFloat(); 

/*освобождение памяти списка*/
void freeFLOAT(listFLOAT_t *list);

// * Functions with nodeINT_t type
/* DONE получить указатель на узел под номером pos в списке (начиная с нуля). */
nodeFLOAT_t *nodeFLOAT(listFLOAT_t *list, int index);

// * Functions with void type
/*   вывести список как строку (nm0, nm1, n2,...).*/
void toStringFLOAT(listFLOAT_t *list);

/*   добавить узел со значением value в конец списка list.*/
void pushFLOAT(listFLOAT_t *list, float value);

/*   добавить узел со значением value в начало списка list.*/
void unshiftFLOAT(listFLOAT_t *list, float value);

/*   перевернуть последовательность узлов в списке.*/
void reversFLOAT(listFLOAT_t *list);

/*   поменять поле value узла по индексу index в списке (начиная с нуля).*/
void putFLOAT(listFLOAT_t *list, int index, float value);

/*   Добавить узел value на место index в списке (начиная с нуля), сдвинув всё вправо.*/
void insertFLOAT(listFLOAT_t *list, int index, float value);


// * Functions with float type
/*   получить поле value последнего узла и убрать его из списка.*/
float popFLOAT(listFLOAT_t *list);

/*   получить поле value первого узла и убрать его из списка.*/
float shiftFLOAT(listFLOAT_t *list);

/*   получить значение поля value узла на месте index в списке (начиная с нуля).*/
float getFLOAT(listFLOAT_t *list, int index);

/*   удалить узел на месте index в списке list (начиная с нуля) и вернуть его value.*/
float removeFLOAT(listFLOAT_t *list, int index);


// * Functions with int type
/*   Получить размер списка */
int lenFLOAT(listFLOAT_t *list);

#endif // _LISTFLOAT_H_
