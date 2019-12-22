#include <stdio.h>
#define MAXN	300000

struct node {
	int sum;
	int x;
};

struct node array[MAXN+10];
int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

void sort(int n)
{
	unsigned int gaps[] = {
        1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 
        16001, 36289, 64769, 146305, 260609};
	
	int i, j, k, temp, tempx;
	int gap;
	
	for (k = 15; k >= 0; k --) {
		gap = gaps[k];
		for (i = gap; i < n; i++) {
			temp = array[i].sum;
			tempx = array[i].x;
			for (j = i; j >= gap && array[j-gap].sum > temp; j -= gap) {
				array[j].sum = array[j-gap].sum;
				array[j].x = array[j-gap].x;
			}
			array[j].sum = temp;
			array[j].x = tempx;
		}
	}
	
	return;
}

int bsearch(int x, int low, int high)
{
	int mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < array[mid].sum)
			high = mid-1;
		else if (x > array[mid].sum)
			low = mid+1;
		else
			return mid;
	}
	return -1;
}
main()
{
	int N, Q, i, j, k, s;
	N = in();
	Q = in();
	for (i = 0; i < N; i++) {
		array[i].x = in();
		s = in();
		array[i].sum = s + array[i].x;
	}
	sort(N);
	for (i = 0; i < Q; i++) {
		int X,Y,D;
		X = in();
		Y = in();
		D = in();
		int count = 0;
		for (j = X+Y; j <= X+Y+D; j++) {
			int index = bsearch(j,0,N-1);
			for (k = index; array[k].sum == j; k++)
				if (array[k].x >= X && (array[k].sum - array[k].x) >= Y)
					count++;
			for (k = index-1; array[k].sum == j; k--)
				if (array[k].x >= X && (array[k].sum - array[k].x) >= Y)
					count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
