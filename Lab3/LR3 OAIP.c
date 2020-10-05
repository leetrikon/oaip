#include <stdio.h>
#include <stdlib.h>


int main() {
    system("chcp 65001");
  float x1, x2, y1, y2, x_res, y_res;
  
  printf("Введите значения x1, x2, y1, y2 \n");
  scanf("%f%f%f%f", &x1, &x2, &y1, &y2);
  
  x_res = x1 - x2;
  y_res = y1 - y2;

  printf("\t\t\t\t\t\t ----------------------------\n");
  printf("\t\t\t\t\t\t КООРДИНАТЫ ТОЧЕК\n");
  printf("\t\t\t\t\t\t ----------------------------\n");
  
  printf("\t\t\t\t\t\t ----------------------------\n");
  printf("\t\t\t\t\t\t x1 = %f y1 = %f\n", x1, y1);
  printf("\t\t\t\t\t\t x2 = %f y2 = %f\n", x2, y2);
  printf("\t\t\t\t\t\t ----------------------------\n\n");
  
  printf("\t\t\t\t\t\t ПОЛУЧЕНО ЗНАЧЕНИЕ = (%3.2f, %3.2f) \n", x_res, y_res);
  
  printf("\t\t\t\t\t\t\t КОНЕЦ РАСЧЕТА");
}