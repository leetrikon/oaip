#include <stdio.h>

int main() {
  
  int sec, hrs;

  printf("Введите количество секунд: ");
  scanf("%i", &sec);

  hrs = sec / 3600;

  printf("%i", hrs);

  return 0;
}