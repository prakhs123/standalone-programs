#include <stdio.h>

#define MAXN	1000

int freq(int a[], int size, int index, int flag[])
{
	int count = 0, i;
	for (i = 0; i < size; i++)
		if (a[i] == a[index]) {
			flag[i] = 0;
			count++;
		}

	return count;
}
int mode (int a[], int size, int *flag)
{
	int i;
	int num, max, f;
	int flg[MAXN];
	
	for (i = 0; i < size; i++)
		flg[i] = 1;
	num = a[0];
	max = freq(a, size, 0, flg);
	
	for (i = 1; i < size; i++)
		if (flg[i] && (f = freq(a, size, i, flg)) >= max) {
			if (f == max)
				*flag = 0;
			else {
				*flag = 1;
				max = f;
				num = a[i];
			}
		}
	
	return num;
}
main()
{
	int n;
	int a[MAXN];
	int i;
	int flag;
	int ans;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	flag = 1;
	ans = mode(a, n, &flag);
	if (flag)
		printf("Mode: %d\n", ans);
	else
		printf("No Mode\n");
	
	return 0;
}
