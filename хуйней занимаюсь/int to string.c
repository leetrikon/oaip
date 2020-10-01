#include <stdio.h>

int main() {
	int number, number_one, number_two, number_three, tmp;

	printf("Введите трехзначное число");
	scanf("%i", &number);
	
	number_one = number / 100;
	number_two = number / 10 % 10;
	tmp = number / 10 * 10;
	number_three = number % tmp;

    switch(number_one) {
    
        case 1:
        printf("сто ");
        break;
        case 2:
        printf("двести ");
        break;
        case 3:
        printf("триста ");
        break;
        case 4:
        printf("четыреста ");
        break;
        case 5:
        printf("пятьсот ");
        break;
        case 6:
        printf("шестьсот ");
        break;
        case 7:
        printf("семьсот ");
        break;
        case 8:
        printf("восемьсот ");
        break;
        case 9:
        printf("девятьсот ");
        break;
    }
    printf("%i", number_two);
	printf("%i \n", number_three);
	printf("остальные кейсы лень писать");
	
}