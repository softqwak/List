
#include "main.h"

void print_heigth(TList *list);
void print_cars(TList *list);

int main()
{
    TList *cars = List();
    add(char)(cars, "BMW");
    add(char)(cars, "Mersedes");
    add(char)(cars, "Porshe");
    insert(char)(cars, "Ferrari", 1);
    insert(char)(cars, "Lexus", 0);
    print_cars(cars);
    delList(cars);

    TList *height = List();
    add(float)(height, 45.5f);
    add(float)(height, 55.5f);
    add(float)(height, 65.5f);
    insert(float)(height, 1.23f, 2);
    insert(float)(height, 144.23f, 2);
    print_heigth(height);

    del(float)(height, 55.5f);
    print_heigth(height);

    insert(float)(height, 5.55f, 0);
    print_heigth(height);

    delList(height);
    return 0;
}

void print_cars(TList *list)
{
    printf("\n");
    for (int c = 0; c < list->length; c++)
    {
        printf("[%d]: %s\n", c, getv(char)(list, c));
    }
}

void print_heigth(TList *list)
{
    printf("\n");
    for (int c = 0; c < list->length; c++)
    {
        printf("[%d]: %f\n", c, getv(float)(list, c));
    }
}