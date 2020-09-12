#include <stdio.h>

int main()
{
    int a, b, c, z;
    printf("Введите три числа!\n");
    scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	z = a;

    if(z>b)
        z = b;
    if(z>c)
        z = c;
    
    if(z == a)
        printf("Наименьшее число  a = %d\n", a);
    if(z == b)
        printf("Наименьшее число  b = %d\n", b);
    if(z == c)
        printf("Наименьшее число  c = %d\n", c);
    
}

