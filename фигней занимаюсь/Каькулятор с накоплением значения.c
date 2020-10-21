//калькулятор 4 действия с накоплением значения
#include <stdio.h>

int main()
{
    double rezult = 0;
    char symbol;
    double number;
    
    
    while(1) {
        printf("------------------------\n");
        printf("Введите знак и число\n");
        printf("------------------------\n");     
        scanf(" %c %lf", &symbol, &number);
        
        switch(symbol) {
            
            case '+':
            rezult += number; 
            printf("%lf\n", rezult);
            break;
            
            case '-':
            rezult -= number; 
            printf("%lf\n", rezult);
            break;
            
            case '/':
            rezult /= number; 
            printf("%lf\n", rezult);
            break;
            
            case '*':
            rezult *= number; 
            printf("%lf\n", rezult);
            break;
            
            case '=':
            printf("%lf\n", rezult);
            break;

            default:
            printf("Некорректная операция");
            break;
        }
        
    }

    return 0;
}
