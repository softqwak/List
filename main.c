
#include "main.h"

#define N 50

int main()
{
    // test_lintINT();

    listINT_t *persons = ListINT(STORAGE);
    pushINT(persons, 10);
    pushINT(persons, 20);
    toStringINT(persons);
    freeINT(persons);
    return 0;
}