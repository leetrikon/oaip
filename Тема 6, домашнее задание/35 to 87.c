#include <stdio.h>

int main()
{
    int i;
    
    for(i = 35; i < 87; i++)
        if(i % 7 == 1 || i % 7 == 2 || i % 7 == 5)
            printf("%d\n", i);
    
}

