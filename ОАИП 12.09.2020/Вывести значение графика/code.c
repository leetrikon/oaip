#include <stdio.h>

// Вывести значения для графика функции "y = 2x - 10"

int main()
{
    float y, k, x, b;
    printf("Отталкиваясь от формулы kx + b = y\n");
    printf("Введите коeффициент k:\n");
    scanf("%g", &k);
    
    printf("Введите коeффициент x:\n");
    scanf("%g", &x);
    
    printf("Введите коeффициент b:\n");
    scanf("%g", &b);
    
    y = k * x + b ;
    printf("Результат равен %g", y);
}

