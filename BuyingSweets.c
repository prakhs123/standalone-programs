#include<stdio.h>

main()
{
	int t;
	scanf("%d",&t);
	while (t--) {
		int N, X;
		scanf("%d",&N);
		scanf("%d",&X);
		int i = 0;
		int note_value[100];
		int sum = 0;
		for (i = 0; i < N; ++i) {
			scanf("%d",&note_value[i]);
			sum += note_value[i];
		}
		int flag = 0;
		int mod = sum % X;
		for (i = 0; i < N; ++i) {
			if (note_value[i] <= mod) {
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("-1\n");
		else
			printf("%d\n", sum / X);
	}
}
