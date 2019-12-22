#include <stdio.h>
#define MAXN	300000

int x[MAXN+10], y[MAXN+10];

int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

main()
{
	int N, Q, i, j;
	N = in();
	Q = in();
	for (i = 0; i < N; i++) {
		x[i] = in();
		y[i] = in();
	}
	for (i = 0; i < Q; i++) {
		int X,Y,D;
		X = in();
		Y = in();
		D = in();
		int count = 0;
		for (j = 0; j < N; j++) {
			if (x[j] >= X && y[j] >= Y && x[j]+y[j] <= X+Y+D)
				count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
