#include <stdio.h>

int main()
{
    float a, b;
    char sym;
    float res;
printf("Добро пожаловать в калькулятор имени Ванина Никиты!\n");
printf("Что вы хотите сделать? Введите один из символов: *, /, +, -\n");
    scanf("%s", &sym);
    if (sym != '*' && sym != '/' && sym != '-' && sym != '+') {
        printf("Антон Викторович, не ломайте программу!");
        return 0;
    }
    printf("Введите первое число: ");
    scanf("%g", &a);
    printf("Введите второе число: ");
    scanf("%g", &b);

    
    if (sym == '+') 
        res = a + b;
        
    if (sym == '-') 
        res = a - b;

     if (sym == '/') {
        if (b == 0)
            printf("На ноль делить нельзя, Антон Викторович");
        else {
            res = a / b;
        }
    }
    if (sym == '*') 
        res = a * b;
    
        
    printf("%g", res);
}
