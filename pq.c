#include <stdio.h>
#include <stdlib.h>
#define PI	1000000000
int heap_minimum(int a[], int heapsize) {
	return a[1];
}

void min_heapify(int a[], int heapsize, int i) {
	int l, r, smallest;
	l = 2*i;
	r = 2*i+1;
	if (l <= heapsize && a[l] < a[i])
		smallest = l;
	else
		smallest = i;
	if (r <= heapsize && a[r] < a[smallest])
		smallest = r;
	if (smallest != i) {
		int t = a[smallest];
		a[smallest] = a[i];
		a[i] = t;
		min_heapify(a,heapsize,smallest);
	}
}

void build_min_heap(int a[], int heapsize) {
	int i;
	for (i = heapsize/2; i >= 1; i--)
		min_heapify(a,heapsize,i);
}

int heap_extract_min(int a[], int heapsize) {
	if (heapsize < 1) {
		printf("Heap Underflow\n");
		exit(1);
	}
	int min = a[1];
	a[1] = a[heapsize];
	heapsize--;
	min_heapify(a,heapsize,1);
	return min;
}

void heap_decrease_key(int a[], int heapsize, int i, int key) {
	if (key > a[i]) {
		printf("new key is greater than current key\n");
		exit(1);
	}
	a[i] = key;
	while (i > 1 && a[i/2] > a[i]) {
		int t = a[i];
		a[i] = a[i/2];
		a[i/2] = t;
		i = i/2;
	}
}

void min_heap_insert(int a[], int heapsize, int key) {
	heapsize++;
	a[heapsize] = PI;
	heap_decrease_key(a,heapsize,heapsize,key);
}

int main()
{
	int a[100];
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build_min_heap(a,n);
	min_heap_insert(a,n,-1);
	printf("%d\n", heap_extract_min(a,n));
	return 0;
}
