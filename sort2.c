#include <stdio.h>
#include <stdlib.h>

struct a {
	int x;
	int index;
};

int compare(const void *a, const void *b) {
	const struct a *t1 = (struct a *)a;
	const struct a *t2 = (struct a *)b;
	if (t1->x < t2->x)
		return -1;
	else if (t1->x > t2->x)
		return 1;
	else
		return 0;
}

int main() {
	struct a arr[15];
	int i = 0;
	for (; i < 15; i++) {
		scanf("%d", &arr[i].x);
		arr[i].index = i;
	}
	qsort(arr, 15, sizeof(struct a), compare);
	for (i = 0; i < 15; i++)
		printf("%d:%d\n", arr[i].index, arr[i].x);
	return 0;
}