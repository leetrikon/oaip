#include <stdio.h>

int main()
{
    int x1, x2, x3;
    int y1, y2, y3;
    
    printf("Введите x1: ");
    scanf("%d", &x1);
    printf("Введите x2: ");
    scanf("%d", &x2);
    printf("Введите x3: ");
    scanf("%d", &x3);
    
    y1 = (2 * x1) - 10;
    y2 = (2 * x2) - 10;
    y3 = (2 * x3) - 10;
    printf("При x = %d, y равен %d\n", x1, y1);
    printf("При x = %d, y равен %d\n", x2, y2);
    printf("При x = %d, y равен %d\n", x3, y3);
}
