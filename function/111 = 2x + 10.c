#include <stdio.h>

//Вариант 3
// Решить уравнение "111 = 2x - 10"

double solution(double a, double b, double c) 
{
        double res = (a - c) / b; // kx - b = y -> (y - b) / k  -> (111 - 10) / 2
    printf("%3.2lf", res);
}

int main()
{
    double y, k, b;
    printf("Отталкиваясь от формулы kx + b = y\n");
    printf("Введите коeффициент k:\n");
    scanf("%lf", &k);
    
    printf("Введите коeффициент b:\n");
    scanf("%lf", &b);
    
    printf("Введите коeффициент y:\n");
    scanf("%lf", &y);
    
    printf("Результат равен");
    return solution(y, k, b);
}

