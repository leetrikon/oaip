#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rearrange(int n, int m, int arr[n][m]){
    int min, max, min1, max1; // переменные для индексов и значений индексов
    for(int i = 0; i < m; i++){
        min = arr[0][i]; //присваиваем МИНИМУМ к первому элементу матрицы
        max = arr[0][i]; //присваиваем МАКСИМУМ к первому элементу матрицы
        for(int j = 0; j < n; j++){
            if(arr[j][i] < min){ //проверяем, есть ли числа меньше чем min
                min = arr[j][i];
                min1 = j;
            }
            if(arr[j][i] > max){ //проверяем, есть ли числа больше чем max
                max = arr[j][i];
                max1 = j;
            }
        }
        arr[max1][i] = arr[max1][i] + arr[min1][i]; // меняем без лишних переменных
        arr[min1][i] = arr[max1][i] - arr[min1][i];
        arr[max1][i] = arr[max1][i] - arr[min1][i];
        // не выебываемся, меняем с дополнительно переменной
        /* int tmp;
         * tmp = arr[max1][i]
         * arr[max1][i] = arr[min1][i]
         * arr[min1][i] = tmp
         */
        max1 = 0; min1 = 0; // обнуляем значения
    }
    return 0;
}
int main()
{
    srand(time(NULL));
    system("chcp 65001");
    int n, m; //n - строки, m - столбцы
    printf("Введите количество строк: "); // вводим размер
    scanf("%i", &n);
    printf("Введите количество столбцов: ");
    scanf("%i", &m);
    int arr[n][m]; //создаем массив
    for(int i = 0; i < n; i++){ // заполняем массив рандомными значениями от 10 до 100
        for(int j = 0; j < m; j++){
            arr[i][j] = 10 + rand() % 100;
            printf("%i ", arr[i][j]); //и выводим
        }
        printf("\n");
    }
    rearrange(n, m, arr); // обращаемся к функции rearrange которая выполняет задание
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%i ", arr[i][j]); // выводим массив
        }
        printf("\n");
    }
    return 0;
}