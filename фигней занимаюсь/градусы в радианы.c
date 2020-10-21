#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main() {
  
  float grad, rad;

  printf("Введите количество градусов: ");
  scanf("%f", &grad);

  rad = grad * (M_PI / 180);

  printf("%f", rad);

  return 0;
}