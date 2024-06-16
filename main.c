
#include "main.h"

int main()
{
    TList *cars = List();
    add(char)(cars, "BMW");
    add(char)(cars, "Mersedes");
    add(char)(cars, "Porshe");

    printf("value: %s\n", get(char)(cars, 0));
    printf("value: %s\n", get(char)(cars, 1));
    printf("value: %s\n", get(char)(cars, 2));
    checkList(cars);
    delList(cars);
    return 0;
}
