#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//В массиве, содержащем положительные и отрицательные целые числа, вычислить сумму четных положительных элементов.

int main() {
    system("chcp 65001");
    srand(time(NULL));
    int ArrSize;
    printf("Введите размер массива: ");
    scanf("%i", &ArrSize);
    int Array[ArrSize];

    int k;
    printf("Выберите способ заполнения массива: 1 - вручную, 2 - рандомно. Ваш выбор: ");
    scanf("%i", &k);

    switch (k) {

        case 1:
            for (int i = 0; i < ArrSize; i++) {
                int ArrElement;
                printf("%i элемент массива равен:", i + 1);
                scanf("%i", &ArrElement);
                Array[i] = ArrElement;
            }
            break;

        case 2:
            for (int i = 0; i <= ArrSize; i++) {
                Array[i] = rand() % 101;
                printf("%i элемент массива равен: %i", i + 1, Array[i]);
            }
            break;

        default:
            printf("Вы соверишили ошибку при вводе");
            return 1;
    }
    int loop, result = 0;
    printf("1. Сложение всех четных положительных чисел.\n");
    scanf("%i", &loop);

    switch (loop) {

    case 1:
    for (int i = 0; i < ArrSize; i++) {
        if(Array[i] > 0 && Array[i] % 2 == 0) {
            result = result + Array[i];
    }
    }
    break;

    default:
    printf("какая-то ошибка");
    }

    for (int i = 0; i < ArrSize; i++) {
        printf("%i равен %i \n", i, Array[i]);
    }
    printf("----------------------\nresult is = %i \n----------------------\n", result);
    }

