#include <stdio.h>
#include <stdlib.h>

int guess(int fSecret) {
  for(;;) {
    int number;
    printf("Попробуй угадать число: ");
    scanf("%i", &number);

    if (number < fSecret) {
      printf("Ваше число меньше загаданного\n");
    }
    else if (number > fSecret) {
      printf("Ваше число больше загаданного\n");
    }
    else if (number == fSecret) {
      printf("Вы угадали! Загаданным число было %i \n\n\n", fSecret);
      return 100;
    }
  }
}


int main() {
  while(1) {
    int low, up, secret;
    printf("____________________________________________\n");
    printf("Введите первую границу ввода: ");
    scanf("%i", &low);
    printf("Введите последнюю границу ввода: ");
    scanf("%i", &up);
    printf("____________________________________________\n");
    

    secret = rand() % up + low;
    printf("%i", secret);

    guess(secret);

  }
}  