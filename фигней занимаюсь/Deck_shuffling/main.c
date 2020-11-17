#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
    char suit;
    int value;
};

int main() {
    system("chcp 65001 && cls");
    srand(time(NULL));

    struct card deck[36] = {};
    struct card card;
    int j = 6;
    for (int i = 0; i < 36; i=i+4) {
        deck[i].value = j;
        deck[i+1].value = j;
        deck[i+2].value = j;
        deck[i+3].value = j;
        deck[i].suit = 'C';
        deck[i+1].suit = 'P';
        deck[i+2].suit = 'K';
        deck[i+3].suit = 'B';
        j++;
    }

    for (size_t i = 36; i > 1; i--) {
        int rand_index = rand() % i;

        /* Обмен элементов a[i-1] и a[rand_index]. */
        struct card tmp = deck[i - 1];
        deck[i - 1] = deck[rand_index];
        deck[rand_index] = tmp;
    }

    for (int i = 0; i < 36; i++) {
        printf("%i карта это ", i+1);

        switch (deck[i].value) {
            case 11:
                printf("Валет");
                break;
            case 12:
                printf("Дама");
                break;
            case 13:
                printf("Король");
                break;
            case 14:
                printf("Туз");
                break;
            default:
                printf("%i", deck[i].value);
        }
        switch (deck[i].suit) {
            case 'C':
                printf(" Черви");
                break;
            case 'K':
                printf(" Крести");
                break;
            case 'B':
                printf(" Буби");
                break;
            case 'P':
                printf(" Пики");
                break;
        }

        printf(".\n");
    }
    return 0;
}
