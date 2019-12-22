#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

#define MAXN 100
struct node {
	int key;
} nodes[MAXN+1];

void copy(struct node &src, struct node &dest) {
	dest.key = src.key;
}
void swap(struct node a[], int i, int j) {
	struct node temp;
	copy(a[i], temp);
	copy(a[j], a[i]);
	copy(temp, a[j]);
}
void maxHeapify(struct node a[], int &n, int index) {
	int l, r;
	l = 2*index;
	r = 2*index+1;
	int largest;
	if (l <= n && a[l].key > a[index].key)
		largest = l;
	else
		largest = index;
	if (r <= n && a[r].key > a[largest].key)
		largest = r;
	if (largest != index)
	{
		swap(a, index, largest);
		maxHeapify(a,n,largest);
	}
}
void buildMaxHeap(struct node a[], int &n) {
	int i;
	for (i = n/2; i >= 1; i--)
		maxHeapify(a, n, i);
}
struct node heapMaximum(struct node a[], int &n) {
	return a[1];
}
struct node extractMax(struct node a[], int &n) {
	if (n < 1)
		exit(1);
	struct node max;
	copy(a[1], max);
	copy(a[n], a[1]);
	n = n-1;
	maxHeapify(a, n, 1);
	return max;
}
void heapIncreaseKey(struct node a[], int &n, int i, int key) {
	if (key < a[i].key)
		exit(1);
	a[i].key = key;
	while (i > 1 && a[i/2].key < key) {
		swap(a, i, i/2);
		i = i/2;
	}
}
void maxHeapInsert(struct node a[], int &n, struct node &data) {
	n = n + 1;
	copy(data, a[n]);
	a[n].key = INT_MIN;
	heapIncreaseKey(a, n, n, data.key);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nodes[i].key);
	buildMaxHeap(nodes, n);
	struct node temp;
	while (1) {
		printf("1.extractMax\n2.heapIncreaseKey\n3.maxHeapInsert\n4.heapMaximum\n5.exit");
		int ch;
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				temp = extractMax(nodes, n);
				printf("%d\n", temp.key);
				break;
			case 2:
				int i, key;
				scanf("%d %d", &i, &key);
				heapIncreaseKey(nodes, n, i, key);
				break;
			case 3:
				int data;
				scanf("%d", &data);
				// initialize other data members of new node
				temp.key = data;
				maxHeapInsert(nodes, n, temp);
				break;
			case 4:
				temp = heapMaximum(nodes, n);
				printf("%d\n", temp.key);
				break;
			default:
				break;
		}
	}
	return 0;
}