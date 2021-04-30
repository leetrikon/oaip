/*Определить минимальную длину слова;
выдать на печать все слова, начинающиеся с гласной буквы;
заменить на ps первое вхождение х, если такое имеется;
удалить из всех слов первую букву;
проверить, есть ли в указанном слове согласные буквы.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char consonant[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

int shortestWord (char *str) {
    int len = 0, min = 0;
    int firstFlag = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' ' || i == strlen(str)-1){
            if (firstFlag == 0){
                min = len;
                len = 0;
                firstFlag = 1;
            }
            else {
                if (min > len){
                    min = len;
                }
                len = 0;
            }
        }
        else {
            len++;
        }
    }
    return min;
}

void vowelWords (char *str) {
    int j = 0, vowelWordFlag = 0;
    if (str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'y') {
        while (str[j] != ' ') {
            printf("%c", str[j]);
            j++;
        }
    }
    for (int i = 1; i < strlen(str); i++) {
        if (str[i-1] == ' ' && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')) {
            vowelWordFlag = 1;
        }
        if (str[i] == ' ') {
            vowelWordFlag = 0;
            printf(" ");
        }
        if (vowelWordFlag == 1) {
            printf("%c", str[i]);
        }
    }
}

void changeXLetter (char *str) {
    int xFlag = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (xFlag == 0 && str[i] == 'x') {
            printf("ps");
            xFlag = 1;
        }
        else{
            printf("%c", str[i]);
        }
    }
}

void removeLetter (char *str) {
    for (int i = 1; i < strlen(str); i++) {
        if (str[i - 1] != ' ') {
            printf("%c", str[i]);
        }
    }
}

void containsConsonant (char *str) {
    int number, spaces = 0, i = 0;
    int bool = 0;
    printf("Введите номер слова: ");
    scanf("%d", &number);
    while (spaces != number - 1) {
        if (str[i] == ' ') {
            spaces++;
        }
        i++;
    }
    while (str[i] != ' ') {
        for (int j = 0; j < 20; j++) {
            if (str[i] == consonant[j]) {
                bool = 1;
                break;
            }
        }
        i++;
    }
    if (bool == 1) {
        printf("Содержит.");
    }
    else {
        printf("Не содержит.");
    }

}

int main() {
    system("chcp 65001 && cls");
    printf("Введите строку: ");
    int act, strLenght = 100;
    char str[strLenght];
    fgets(str, strLenght, stdin);
    printf("Полученная строка: %s", str);
    printf("\n\n");

    printf("1. Определить минимальную длину слова\n");
    printf("2. Выдать на печать все слова, начинающиеся с гласной буквы\n");
    printf("3. Заменить на ps первое вхождение х, если такое имеется\n");
    printf("4. Удалить из всех слов первую букву\n");
    printf("5. Проверить, есть ли в указанном слове согласные буквы\n");

    printf("Введите цифру:");
    scanf("%d", &act);
    switch (act) {
        case 1:
            printf("%d", shortestWord(str));
            break;

        case 2:
            vowelWords(str);
            break;

        case 3:
            changeXLetter(str);
            break;

        case 4:
            removeLetter(str);
            break;

        case 5:
            containsConsonant(str);
            break;
    }
}