#include <stdio.h>

int findMaxSum(int a[], int n) {
	int i, j;
	int t1, t2, t3;
	t1 = a[n-1];
	t2 = a[n-2];
	t3 = a[n-3] + a[n-1];
	for (i = n-4, j = 0; i >= 0; j++, i--) {
		if (j%3==0)
 			t1 = a[i] + (t1 > t2 ? t1 : t2);
 		if (j%3==1)
 			t2 = a[i] + (t2 > t3 ? t2 : t3);
 		if (j%3==2)
 			t3 = a[i] + (t3 > t1 ? t3 : t1);
	}
	printf("%d %d %d\n", t1, t2, t3);
	return t1>t2?t1>t3?t1:t3:t2>t3?t2:t3;
}
int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  printf("%d \n", findMaxSum(arr, 6));
  getchar();
  return 0;
}