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
void minHeapify(struct node a[], int &n, int index) {
	int l, r;
	l = 2*index;
	r = 2*index+1;
	int smallest;
	if (l <= n && a[l].key < a[index].key)
		smallest = l;
	else
		smallest = index;
	if (r <= n && a[r].key < a[smallest].key)
		smallest = r;
	if (smallest != index)
	{
		swap(a, index, smallest);
		minHeapify(a,n,smallest);
	}
}
void buildMinHeap(struct node a[], int &n) {
	int i;
	for (i = n/2; i >= 1; i--)
		minHeapify(a, n, i);
}
struct node heapMinimum(struct node a[], int &n) {
	return a[1];
}
struct node extractMin(struct node a[], int &n) {
	if (n < 1)
		exit(1);
	struct node max;
	copy(a[1], max);
	copy(a[n], a[1]);
	n = n-1;
	minHeapify(a, n, 1);
	return max;
}
void heapDecreaseKey(struct node a[], int &n, int i, int key) {
	if (key > a[i].key)
		exit(1);
	a[i].key = key;
	while (i > 1 && a[i/2].key > key) {
		swap(a, i, i/2);
		i = i/2;
	}
}
void minHeapInsert(struct node a[], int &n, struct node &data) {
	n = n + 1;
	copy(data, a[n]);
	a[n].key = INT_MAX;
	heapDecreaseKey(a, n, n, data.key);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nodes[i].key);
	buildMinHeap(nodes, n);
	struct node temp;
	while (1) {
		printf("1.extractMin\n2.heapDecreaseKey\n3.minHeapInsert\n4.heapMinimum\n5.exit\n");
		int ch;
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				temp = extractMin(nodes, n);
				printf("%d\n", temp.key);
				break;
			case 2:
				int i, key;
				scanf("%d %d", &i, &key);
				heapDecreaseKey(nodes, n, i, key);
				break;
			case 3:
				int data;
				scanf("%d", &data);
				// initialize other data members of new node
				temp.key = data;
				minHeapInsert(nodes, n, temp);
				break;
			case 4:
				temp = heapMinimum(nodes, n);
				printf("%d\n", temp.key);
				break;
			default:
				break;
		}
	}
	return 0;
}