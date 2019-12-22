#include <stdio.h>

void util(int a[], int data[], int n, int r, int i, int l) {
	if (l == r) {
		int j;
		for (j = 0; j < r; j++)
			printf("%d,", data[j]);
		printf("\n");
		return;
	}
	int j, k;
	for (j = i, k = 0; j < n && k < n-r+1; k++,j++) {
		data[l] = a[j];
		util(a,data,n,r,j+1,l+1);
	}
}

void f(int a[], int n, int r) {
	int data[r];
	util(a,data,n,r,0,0);
}


int main() {
	int a[] = {1,2,3,4,5,6,7};
	f(a,7,3);
	return 0;
}