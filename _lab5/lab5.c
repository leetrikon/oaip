#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void wait() { // функция для красоты
    printf("Работа в процессе.\r"); // \r - возвращает курсор в начало строки
    sleep(1); //функци
    printf("Работа в процессе..\r");
    sleep(1);
    printf("Работа в процессе...\r\n");
    sleep(1);
}

int randomFilling(int array[], int arrayLenght) {  //заполнение массива случайными числами
    int upLimit;
    printf("Введите верхний предел генерации чисел: ");
    scanf("%i", &upLimit);
    wait();
    for(int i = 0; i < arrayLenght; i++) {
        array[i] = rand() % upLimit;
    }

    printf("Ваш массив: ");
    for (int i = 0; i < arrayLenght; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
    return 0;
}

int handFilling(int array[], int arrayLenght) { //заполнение массива вручную
    int element;
    for(int i = 0; i < arrayLenght; i++) {
        printf("Введите %i элемент массива: ", i+1);
        scanf("%i", &element);
        array[i] = element;
    }
    printf("Ваш массив: ");
    for (int i = 0; i < arrayLenght; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
}

int sortAscending (int array[], int arrayLenght){  //Сортировка пузырьком по возрастанию
    for (int i = 0; i < arrayLenght - 1; i++) {
        for (int j = (arrayLenght - 1); j > i; j--) {  //крутим массив
            if (array[j - 1] > array[j]) {  // если элемент больше
                int tmp = array[j - 1];    // обмен значениями
                array[j - 1] = array[j];
                array[j] = tmp;
            };
        }
    }
    printf("Ваш массив: ");
    for (int i = 0; i < arrayLenght; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
}

int sortDescending(int array[], int arrayLenght) {  //Сортировка пузырьком по убыванию
    for (int i = 0; i < arrayLenght - 1; i++) {
        for (int j = (arrayLenght - 1); j > i; j--) {
            if (array[j - 1] < array[j]) {  //меняем знак, чтобы все пошло в другую сторону
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            };
        }
    }
    printf("Ваш массив: ");
    for (int i = 0; i < arrayLenght; i++) {
        printf("%i, ", array[i]);
    }
    printf("\n");
}

int binarySearch(int array[], int end, int sought) { //бинарный поиск

    int middle;
    int start = 0;
    while (1) {
        middle = (start + end) / 2;

        if (sought < array[middle]) {    //если меньще, чем середина
            end = middle - 1;      // меняем границы поиска
        }
        else if (sought > array[middle]) {  //если больше, чем середина
            start = middle + 1;    // меняем границы поиска
        }
        else {                       // если не больше и не меньше, то возврат middle
            return middle;           // вовзрат угаданного числа
        }

        if (start > end) {          // если чисел между границами не остальность
            return -1;
        }
    }
}

int removeElement(int array[], int arrayLenght) { //удаление элемента
    for (int i = 0; i < arrayLenght; i++) {
        printf("%i индекс массива имеет значение %i\n", i+1, array[i]); //просмотр всех элементов в массиве
    }

    printf("Выберите индекс значения которого вы хотите удалить: ");
    int index;
    scanf("%i", &index);

    if (index >= arrayLenght + 1) {  //если введенный индекс больше размера массива
        printf("Удаление невозможно. Вы ввели несуществющий индекс.\n");
    }
    else {
        for (int i = index-1; i < arrayLenght-1; i++) {  //перебор массива, до значения index-1
            array[i] = array[i+1];  //обмен значениями элементов // при таком обмене значение array[index] уйдет за пределы массива
        }
    }
    printf("Полученный массив: ");
    for (int i = 0; i < arrayLenght-1; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int generateArray(int array[], int arrayLenght) {
    printf("Как вы хотите заполнить массив? 1 - рандомно, 2 - вручную.\n Ваш выбор: ");
    int decision, size;
    scanf("%i", &decision);

    switch (decision) {

        case 1:
            randomFilling(array, arrayLenght);
            break;

        case 2:
            handFilling(array, arrayLenght);
            break;

        default:
            printf("Ну что же вы, следуйте указаниям программы. Попробуйте сначала.\n");
            break;
    }
    return 0;
}

int main() {

    system("chcp 65001 && cls");
    srand(time(NULL));

    printf("добро пожаловать в пятую лабу!\n");
    int arrayLenght;
    printf("Введите размер массива: ");
    scanf("%i", &arrayLenght);
    int array[arrayLenght];

    generateArray(array, arrayLenght);

    int act;

    while (1) {
        printf("-------------------------\n");
        printf("Выберите действие:\n");
        printf("-------------------------\n");
        printf("1. Сортировка массива по возрастанию\n"); // DA
        printf("2. Сортировка массива по убыванию\n"); // DA
        printf("3. Бинарный поиск элемента в массиве\n"); // NET
        printf("4. Удаление элемента из массива\n"); // DA
        printf("5. Повтор генерации массива\n"); // DA
        printf("Ваш выбор: ");
        scanf("%i", &act);

        switch (act) {

            case 1:
                sortAscending(array, arrayLenght);
                break;

            case 2:
                sortDescending(array, arrayLenght);
                break;

            case 3:
                printf("Введите число, которое вы хотите найти: ");
                int search;
                scanf("%i", &search);

                int index;
                index = binarySearch(array, arrayLenght, search); // binarySearch возвращает  значение в index

                if (index >= 0)
                    printf("Указанное число находится в ячейке с индексом: %i\n", index);
                else
                    printf("В массиве нет такого числа!\n");
                break;

            case 4:
                removeElement(array, arrayLenght);
                break;

            case 5:
                generateArray(array, arrayLenght);
                break;

            case 6:
                return 0;

            default:
                printf("Ну что же вы, следуйте указаниям программы. Попробуйте сначала.");
        }

    }
}