#include "main.h"
#include <stdio.h>

int main()
{
    int age = 25;
    int charactersPrinted = _printf("My age is %d years old.", age);
    
    printf("\nNumber of characters printed: %d\n", charactersPrinted);

    return 0;
}
