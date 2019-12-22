#include <stdio.h>
/*
f(2n) = f(n)*f(n)+f(n+1)*f(n+1)
f(2n+1) = 2f(n)*f(n+1)+ f(n+1)*f(n+1)
*/
long int fib(long int n) {
 
    long int a=1, b=0, p=0, q=1, prev_a, prev_p = 0;
    while(n>0) {
        if (n%2 == 0) {
            prev_p = p;
            p = p*p + q*q;
            q = 2*prev_p*q + q*q;
            n /= 2;
        } else {
            prev_a = a;
            a = b*q + a*q + a*p;
            b = b*p + prev_a*q;
            n -= 1;
        }
    }
    return b;
}
int main(int argc, char **argv) {
 
    long int n;
 
    scanf("%ld", &n);
    printf("%ld\n", fib(n));
        return 0;
 
}
