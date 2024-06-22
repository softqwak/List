
#ifndef _LISTCHAR_H_
#define _LISTCHAR_H_

#include <stdio.h>
#include <stdlib.h>

struct nodeCHAR_s;
typedef struct nodeCHAR_s nodeCHAR_t; 

struct listCHAR_s;
typedef struct listCHAR_s listCHAR_t;

// * Functions with listINT_t type
// инициализация списка
listCHAR_t *ListChar(); 

/*освобождение памяти списка*/
void freeCHAR(listCHAR_t *list);

// * Functions with nodeINT_t type
/* DONE получить указатель на узел под номером pos в списке (начиная с нуля). */
nodeCHAR_t *nodeCHAR(listCHAR_t *list, int index);

// * Functions with void type
/*   вывести список как строку (nm0, nm1, n2,...).*/
void toStringCHAR(listCHAR_t *list);

/*   добавить узел со значением value в конец списка list.*/
void pushCHAR(listCHAR_t *list, char *value);

/*   добавить узел со значением value в начало списка list.*/
void unshiftCHAR(listCHAR_t *list, char *value);

/*   перевернуть последовательность узлов в списке.*/
void reversCHAR(listCHAR_t *list);

/*   поменять поле value узла по индексу index в списке (начиная с нуля).*/
void putCHAR(listCHAR_t *list, int index, char *value);

/*   Добавить узел value на место index в списке (начиная с нуля), сдвинув всё вправо.*/
void insertCHAR(listCHAR_t *list, int index, char *value);


// * Functions with char type
/*   получить поле value последнего узла и убрать его из списка.*/
char *popCHAR(listCHAR_t *list);

/*   получить поле value первого узла и убрать его из списка.*/
char *shiftCHAR(listCHAR_t *list);

/*   получить значение поля value узла на месте index в списке (начиная с нуля).*/
char *getCHAR(listCHAR_t *list, int index);

/*   удалить узел на месте index в списке list (начиная с нуля) и вернуть его value.*/
char *removeCHAR(listCHAR_t *list, int index);


// * Functions with int type
/*   Получить размер списка */
int lenCHAR(listCHAR_t *list);

#endif // _LISTCHAR_H_