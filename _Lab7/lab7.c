#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  system("chcp 65001 && cls");
  srand(time(NULL));

  int A[10][10];
  int i, j;
  int max = 0;
  int uzero = 1;
  for (i = 0; i < 10; i++){
    for ( j = 0; j < 10; j++){
      A[i][j] = -10 + rand() % 12;
    }
  }
  printf("Полученный массив: \n");
  for (i = 0; i < 10; i++){
    for (j = 0; j < 10; j++){
      printf("%d\t",A[i][j]);
    }
  printf("\n");
  }

  int B[10];
  for (int i = 0; i < 10; i++){
      max = A[i][0];
      for (int j = 0; j < 10; j++){
      if (max < A[i][j]){
        max = A[i][j];
      }
    }
    B[i] = max;
  }

  printf("Полученный вектор: \n");
  for (int i = 0; i < 10; ++i){
    printf("%d ", B[i]);
  }
  printf("\n");

  for (i = 0; i < 10; i++){
    if (B[i] < 0){
      uzero = uzero * B[i];
    }
  }
  for (i = 0; i < 10; i++)
  {
    if (B[i] == 0)
    {
      B[i] = uzero;
        printf("Новый вектор: \n");
        for (int i = 0; i < 10; ++i){
          printf("%d ", B[i]);
        }

      return 0;
    }
  }
}
