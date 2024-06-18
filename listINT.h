#ifndef FCFCF7AE_E40A_40A4_A72E_2BF332C11B0C
#define FCFCF7AE_E40A_40A4_A72E_2BF332C11B0C

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeINT_s nodeINT_t;
typedef struct listINT_s listINT_t;
struct nodeINT_s
{
    int value;
    int index;
    nodeINT_t *prev;
    nodeINT_t *next;
};
struct listINT_s
{
    int length;
    nodeINT_t tail;
    nodeINT_t head;
};

// * Functions with listINT_t type
// инициализация списка
listINT_t *ListInt();

// * Functions with nodeINT_t type
// получить узел под номером pos в списке (начиная с нуля).
nodeINT_t nodeINT(listINT_t *list, int index);

// * Functions with void type
// вывести список как строку (nm0, nm1, n2,...).
void toStringINT(listINT_t *list);

// добавить узел со значением value в конец списка list.
void pushINT(listINT_t *list, int value);

// добавить узел со значением value в начало списка list.
void unshiftINT(listINT_t *list, int value);

// перевернуть последовательность узлов в списке.
void reversINT(listINT_t *list);

// поменять поле nm узла месте pos в списке (начиная с нуля).
void put(listINT_t *list, int index, int value);

// удалить узел на месте pos в списке (начиная с нуля) и вернуть его nm.
void removeINT(listINT_t *list, int index);

// добавить узел с именем nm на место pos в списке (начиная с нуля), сдвинув всё вправо.
void insertINT(listINT_t *list, int index, int value);

// * Functions with INT type
// получить поле nm последнего узла и убрать его из списка.
int popINT(listINT_t *list);

// получить поле nm первого узла и убрать его из списка.
int shiftINT(listINT_t *list);

// получить значение поля nm узла на месте pos в списке (начиная с нуля).
int getINT(listINT_t *list, int index);

#endif /* FCFCF7AE_E40A_40A4_A72E_2BF332C11B0C */
