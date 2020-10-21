#include <stdio.h>

int power(int x, int y) {
    int result = 1;
    for(int i; i < y; i++){
        result *= x;
    }

    return result;
}

int main()
{
    int a, b;
    printf("введите число");
    scanf("%i", &a);
    printf("введите степень");
    scanf("%i", &b);
    
    printf("%i", power(a, b));
}