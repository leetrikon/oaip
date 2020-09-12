#include <stdio.h>

// Решить уравнение "111 = 2x - 10"

int main()
{
    float y, k, b;
    printf("Отталкиваясь от формулы kx + b = y\n");
    printf("Введите коeффициент k:\n");
    scanf("%g", &k);
    
    printf("Введите коeффициент b:\n");
    scanf("%g", &b);
    
    printf("Введите коeффициент y:\n");
    scanf("%g", &y);
    
    float res = (y - b) / k;
    printf("Результат равен %g", res);
}

