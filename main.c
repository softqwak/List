
#include "main.h"

void test_lintINT();

int main()
{
    test_lintINT();

    return 0;
}

void test_lintINT()
{
    listINT_t *persons = ListINT(STORAGE);
    pushINT(persons, 10);
    pushINT(persons, 20);
    toStringINT(persons);
    freeINT(persons);
    printf("\n");
}
