#include <stdio.h>

void maxheapify(int a[], int heapsize, int i) {
	int l, r, largest;
	l = 2*i;
	r = 2*i+1;
	if (l <= heapsize && a[l] > a[i])
		largest = l;
	else
		largest = i;
	if (r <= heapsize && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		int t = a[i];
		a[i] = a[largest];
		a[largest] = t;
		maxheapify(a,heapsize,largest);
	}
}

void buildmaxheap(int a[], int heapsize) {
	int i;
	for (i = heapsize/2; i >= 1; i--)
		maxheapify(a,heapsize,i);
}

void heapsort(int a[], int heapsize) {
	buildmaxheap(a,heapsize);
	int i;
	for (i = heapsize; i >= 2; i--) {
		int t;
		t = a[1];
		a[1] = a[i];
		a[i] = t;
		heapsize--;
		maxheapify(a,heapsize,1);
	}
}

int main()
{
	int num[100];
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	heapsort(num,n);
	for (i = 1; i <= n; i++)
		printf("%d ", num[i]);
	putchar('\n');
	return 0;
}
