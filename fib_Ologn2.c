#include <stdio.h>
#define MOD 1000000007
#define LL long long
 
void multiply(LL F[2][2], LL M[2][2]);
 
void power(LL F[2][2], LL n);
 
/* function that returns nth Fibonacci number */
LL fib(LL n)
{
  LL F[2][2] = {{1,1},{1,0}};
  if(n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
/* Optimized version of power() in method 4 */
void power(LL F[2][2], LL n)
{
  if( n == 0 || n == 1)
      return;
  LL M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if( n%2 != 0 )
     multiply(F, M);
}
 
void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
  LL y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
  LL z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
  LL w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
/* Driver program to test above function */
LL main()
{
  LL n = 12;
  printf("%d", fib(12));
  getchar();
  return 0;
}
