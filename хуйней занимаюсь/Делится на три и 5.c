#include <stdio.h>

int main()
{
    //ввод: 2 числа, 1ое меньше 2го
    //вывод все целые числа между ними, которые делятся на 3 ИЛИ на 5
    
    int a;
    int b;
    
    printf("Введите два числа, первое должно быть БОЛЬШЕ второго. \n");
    scanf("%i", &a);
    scanf("%i", &b);
    
    for(int i = a; i <= b; i++) {
        if(i % 3 == 0 ||i % 5 == 0)
            printf("%i\n", i);`
        else
            continue;
    }
    
    return 0;
}
