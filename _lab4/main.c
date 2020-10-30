#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    system("chcp 65001 && cls");
    srand(time(NULL));
    int size, element;
    printf("Введите размер массива (четное число): ");
    scanf("%i", &size);
    int gachi[size];

    printf("Вы хотите заполнить массив в ручную, или рандомно? 1/2");
    int k;
    scanf("%i", &k);

    if (k == 1) {
        for (int i = 0; i < size; i++) {
            printf("Введите %i элемент массива: ", i + 1);
            scanf("%i", &element);
            gachi[i] = element;
        }
    }
    else if (k == 2) {
        for (int i = 0; i < size; i++) {
            element = rand() % 101;
            printf("%i элемент массива равен: %i\n", i + 1, element);
            gachi[i] = element;
        }
    }
    else {
        printf("Вы ошиблись.");
        return 0;
    }

    int tmp;
    printf("---------------------\n");
    printf("Меняем местами...\n");
    printf("---------------------\n");
    for(int i = 0; i < size-1; i += 2){
        tmp = gachi[i];
        gachi[i] = gachi[i+1];
        gachi[i+1] = tmp;

    }

    for(int i = 0; i < size; i++) {
        printf("%i элемент массива равен %i\n", i+1, gachi[i]);
    }

    return 0;
}
