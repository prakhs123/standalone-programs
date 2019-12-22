#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? putchar('1'): putchar('0');
}
 
int main(void)
{
    int num;
    scanf("%d", &num);
    bin(num);
    
    return 0;
}
