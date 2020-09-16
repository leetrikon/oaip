#include <stdio.h>

int main()
{
    int n, i, fact;
    fact = 1;
    printf("Введите целое число: ");
    scanf("%d", &n);
    
    if (n = 0)
        printf("Факториала от 0 равен 1.");
    if (n < 0)
        printf("Факториала от отрицательного числа не существует!");
    if (n > 0)
        for(i = 1; i <= n; i++)
            fact *= i;
    }
    printf("Факториал числа %d равен %d!", n, fact);
    
}

