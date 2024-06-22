
#include "main.h"

void test_listINT();
void test_listCHAR();

int main()
{
    // test_listINT();
    test_listCHAR();
    return 0;
}

void test_listCHAR()
{
    printf("start test_listCHAR\n------------------\n");
    listCHAR_t *names = ListCHAR(SORTUP_CHAR);

    addCHAR(names, "1");
    addCHAR(names, "88888888");
    addCHAR(names, "55555");
    addCHAR(names, "22");
    addCHAR(names, "22");
    addCHAR(names, "4444");
    toStringCHAR(names);

    freeCHAR(names);
    printf("------------------\nend test_listCHAR\n\n");
    return;
}

void test_listINT()
{
    printf("start test_listINT\n------------------\n");
    listINT_t *persons = ListINT(STORAGE_INT);

    pushINT(persons, 10);
    pushINT(persons, 20);
    toStringINT(persons);

    freeINT(persons);
    printf("------------------\nend test_listINT\n\n");
    return;
}
