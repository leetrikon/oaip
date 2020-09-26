#include <stdio.h>

int main()
{
    float a, b, res;
    char sym;
    
    printf("Добро пожаловать в калькулятор имени Ванина Никиты!\n");
    printf("Введите первое число: ");
    scanf("%f", &a);
    printf("Введите второе число: ");
    scanf("%f", &b);
    printf("Что вы хотите сделать? Введите один из символов: *, /, +, -\n");
    scanf("%s", &sym);
    
    switch(sym){
        
        case ('+'): 
        res = a + b;
        break;
        
        case ('-'): 
        res = a - b;
        break;
        
        case ('*'): 
        res = a * b;
        break;
        
        case ('/'): 
        if(b == 0)
            break;
        else
            res = a / b;
        break;
        
        default:
        printf("Антон Викторович, не ломайте программу!\n");
        return 0;
        break;
    }
        
    printf("%3.2f", res);
}
