#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x;
    
    printf("Введите число a: ");
    scanf("%f", &a);
    printf("Введите число b: ");
    scanf("%f", &b);
    printf("Введите число c: ");
    scanf("%f", &c);
    
    int d;
    d = b*b;
    int tmp = 4.0*a*c;
    d -= tmp;
    if(d >= 0) {
        x = (b-2*b) + sqrt(d);
        x /= 2*a;
        printf("x1 = %3.2f\n", x);
        x = (b-2*b) - sqrt(d);
        x /= 2*a;
        printf("x2 = %3.2f\n", x);
    }
    else
        printf("HET.");
}
