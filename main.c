
#include "main.h"

int main()
{
    TList *cars = List();
    add(char)(cars, "BMW");
    add(char)(cars, "Mersedes");
    add(char)(cars, "Porshe");

    // checkList(cars);
    // printf("value: %s\n", getv(char)(cars, 0));
    // printf("value: %s\n", getv(char)(cars, 1));
    // printf("value: %s\n", getv(char)(cars, 2));

    // checkList(cars);
    // insert(char)(cars, "Ferrari", 1);
    checkList(cars);

    delList(cars);
    return 0;
}
