#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int M, K, N, R[18], R2[18];

int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	if(c=='-') 
		return -in();
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

bool ifNoFault(void) {
	int i, j, max, count;
	for (i = 0; i <= N-K; i++) {
		for (j = i, max = 0; j <= i+K-1; j++)
			if (max < R2[j])
				max = R2[j];
		for (j = i, count = 0; j <= i+K-1; j++) {
			if (max == R2[j]) {
				count++;
				if (count >= M)
					return false;
			}
		}
	}
	return true;
} 
main()
{
	int T;
	int i, j, count, min;
	bool flag;
	T = in();
	while (T--) {
		N = in();
		K = in();
		M = in();
		for (i = 0; i < N; i++)
			R[i] = in();
		if (M == 1) {
			printf("-1\n");
			continue;
		}
		for (i = 0, min = 18; i < pow(2, N); i++) {
			for (j = 0; j < N; j++)
				R2[j] = R[j];
			for (j = 0, count = 0, flag = false; j < N; j++) {
				if ((1<<j) & i) {
					R2[j]++;
					count++;
				}
			}
			flag =  ifNoFault();
			if (flag)
				if (min > count)
					min = count;
		}
		if (min == 18)
			printf("-1\n");
		else
			printf("%d\n", min);
	}
	
	return 0;
}
					
