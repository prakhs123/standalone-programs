#include <stdio.h>

#define MAXN	1000000
#define MOD	1000000007

int steps[MAXN+10];

void precompute(void) {
	int i;
	steps[1] = 1;
	steps[2] = 2;
	for (i = 3; i <= MAXN; i++) {
		steps[i] = steps[i-2] + steps[i-1];
		if (steps[i] >= MOD)
			steps[i] -= MOD;
	}
}

int noofones(int x) {
	int count = 0;
	while (x) {
		count++;
		x = x&(x-1);
	}
	return count;
}

int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

main() {
	precompute();
	int T, N, G;
	T = in();
	while (T--) {
		N = in();
		G = in();
		if (noofones(steps[N]) != G)
			printf("INCORRECT\n");
		else
			printf("CORRECT\n");
	}
	return 0;
}
