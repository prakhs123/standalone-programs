#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll num[10000000];
int mask[10000000], num_size;
int b2i[3000];

main()
{
	int i, k;
  	int rest, bt;

  	rep(i,10) b2i[1<<i] = i; /* b2i[2^i] = i, bit to int */

  	num_size = 0;
  	REP(i,1,10){
		num[num_size] = i;  /* current delicious numbers */
		mask[num_size] = ((1<<10)-1)^(1<<i); /* the set of unused digits */
		num_size++;
  	}

	  /* calculate all delicious numbers using BFS */
	  rep(k,num_size) {
			rest = mask[k]; /* the set of unused digits */
			while(rest) {
				  bt = (rest & -rest);
				  i = b2i[bt]; /* i is one of unused digits */

				  num[num_size] = num[k] * 10 + i;
				  mask[num_size] = mask[k]^(1<<i);
				  num_size++;

				  rest ^= bt;
			}
	  }
	printf("\n");
	return 0;
}
