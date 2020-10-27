#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 && cls");

    char months[12][20] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                           "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    while(1) {
        printf("Введите номер месяца: ");
        int number;
        scanf("%d", &number);

        switch (number) {

            case 1:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[0]);
                break;

            case 2:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[1]);
                break;

            case 3:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[2]);
                break;

            case 4:
                puts(months[3]);
                break;

            case 5:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[4]);
                break;

            case 6:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[5]);
                break;

            case 7:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[6]);
                break;

            case 8:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[7]);
                break;

            case 9:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[8]);
                break;

            case 10:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[9]);
                break;

            case 11:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[10]);
                break;

            case 12:
                printf("Номеру %i соответствует месяц ", number);
                puts(months[11]);
                break;

            default:
            printf("Введите число от 1 до 12!\n");
                break;
        }
        printf("____________________\n");
    }
}
