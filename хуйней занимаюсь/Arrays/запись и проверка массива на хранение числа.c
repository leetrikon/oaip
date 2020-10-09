#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ввод числа, если такое число есть то вывести его индекс, если нет, то сказать об этом

int main()
{
    srand(time(NULL));
    int size, element, up_limit, down_limit;
    printf("Введите размер массива: ");
    scanf("%i", &size);
    
    int gachi[size];
    
    printf("Вы хотите заполнить массив в вручную или рандомно? 1 - ручками, 2 - рандомно : ");
    int k;
    scanf(" %i", &k);
    
    switch (k) {
        
        case 1:
            for(int i = 0; i < size; i++) {
                printf("%i элемент масссива равен: ", i);
                scanf("%i", &element);
                gachi[i] = element;
            }
            break;
        
        case 2:
            printf("Введите нижний предел рандомизации: ");
            scanf("%i", &down_limit);
            printf("Введите верхний предел рандомизации: ");
            scanf("%i", &up_limit);
            
            for(int i = 0; i < size; i++) {
                element = down_limit + rand() % up_limit;
                gachi[i] = element;
                printf("%i элемент масссива равен: %i\n", i, element);
            }
    }
    
    for(;;) {
        printf("Введите 'x', чтобы выйти ИЛИ Введите число, а мы проверим, есть ли оно в массиве: ");
        int number;
        scanf("%i", &number);
        if(number == 'x'){
            return 0;
        }
        else {
            for(int i = 0; i < size; i ++) {
                if(gachi[i] == number) {
                printf("Ваше число находится в массиве \"gachi\" под индексом %i\n", i);
                continue;
                }
            }
            printf("числа (больше) нет в массиве\n");
    }

    }
}
