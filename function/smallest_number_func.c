#include <stdio.h>

//4 по списку, 1 вариант. Найти наименьшее число из трех.

int find_smallest_number(int x, int y, int z){
    
    int tmp;
    tmp = x;
    
    if(tmp>y)
        tmp = y;
    if(tmp>z)
        tmp = z;
    
    if(tmp == x)
        return x;
    if(tmp == y)
        return y;
    if(tmp == z)
        return z;
}

int main()
{
    int a, b, c, tmp;
    printf("Введите три числа!\n");
    scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	
	printf("Наименьшее число - %i\n", find_smallest_number(a, b, c));
	
}
