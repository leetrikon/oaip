#include <stdio.h>

// Вариант 2

int even_or_odd(int x) 
{
    if(x % 2 == 0)
        printf("Ваше число чётное!");

    else
        printf("Ваше число нечётное!");
}

int main()
{
    int a;
    scanf("%d", &a);
    
    return even_or_odd(a);
}