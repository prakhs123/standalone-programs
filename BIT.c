#include <stdio.h>

#define MAXN 1000

int BIT[MAXN+1];

int read(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += BIT[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val) {
	while (idx <= MAXN) {
		BIT[idx] += val;
		idx += (idx & -idx);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int i, num;
	for (i = 1; i <= n; i++) {
		scanf("%d", &num);
		update(i, num);
	}
	int choice;
	while (1) {
		printf("1.Read\n2.Update\n3.Exit\n");
		scanf("%d", &choice);
		if (choice == 1) {
			int x;
			scanf("%d", &x);
			printf("%d\n", read(x));
		}
		else if (choice == 2) {
			int idx, val;
			scanf("%d %d", &idx, &val);
			update(idx, val);
		}
		else
			break;
	}
	return 0;
}