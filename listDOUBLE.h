
#ifndef _LISTDOUBLE_H_
#define _LISTDOUBLE_H_

#include <stdio.h>
#include <stdlib.h>

struct nodeDOUBLE_s;
typedef struct nodeDOUBLE_s nodeDOUBLE_t; 

struct listDOUBLE_s;
typedef struct listDOUBLE_s listDOUBLE_t;

// * Functions with listINT_t type
// инициализация списка
listDOUBLE_t *ListDouble(); 

/*освобождение памяти списка*/
void freeDOUBLE(listDOUBLE_t *list);

// * Functions with nodeINT_t type
/* DONE получить указатель на узел под номером pos в списке (начиная с нуля). */
nodeDOUBLE_t *nodeDOUBLE(listDOUBLE_t *list, int index);

// * Functions with void type
/*   вывести список как строку (nm0, nm1, n2,...).*/
void toStringDOUBLE(listDOUBLE_t *list);

/*   добавить узел со значением value в конец списка list.*/
void pushDOUBLE(listDOUBLE_t *list, double value);

/*   добавить узел со значением value в начало списка list.*/
void unshiftDOUBLE(listDOUBLE_t *list, double value);

/*   перевернуть последовательность узлов в списке.*/
void reversDOUBLE(listDOUBLE_t *list);

/*   поменять поле value узла по индексу index в списке (начиная с нуля).*/
void putDOUBLE(listDOUBLE_t *list, int index, double value);

/*   Добавить узел value на место index в списке (начиная с нуля), сдвинув всё вправо.*/
void insertDOUBLE(listDOUBLE_t *list, int index, double value);


// * Functions with double type
/*   получить поле value последнего узла и убрать его из списка.*/
double popDOUBLE(listDOUBLE_t *list);

/*   получить поле value первого узла и убрать его из списка.*/
double shiftDOUBLE(listDOUBLE_t *list);

/*   получить значение поля value узла на месте index в списке (начиная с нуля).*/
double getDOUBLE(listDOUBLE_t *list, int index);

/*   удалить узел на месте index в списке list (начиная с нуля) и вернуть его value.*/
double removeDOUBLE(listDOUBLE_t *list, int index);


// * Functions with int type
/*   Получить размер списка */
int lenDOUBLE(listDOUBLE_t *list);

#endif // _LISTDOUBLE_H_
