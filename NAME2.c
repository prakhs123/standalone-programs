#include <stdio.h>
#include <string.h>

main()
{
	char M[25050], W[25050];
	int i, j, T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s %s", M, W);
		int l1, l2;
		l1 = strlen(M);
		l2 = strlen(W);
		int flag = 0;
		// checking if W is inside M
		for (i = 0, j = 0; i < l1 && j < l2; i++)
			if (M[i] == W[j])
				j++;
				
		if (j == l2)
			flag = 1;
			
		// checking if M is inside W
		for (i = 0, j = 0; i < l2 && j < l1; i++)
			if (W[i] == M[j])
				j++;
		
		if (j == l1)
			flag = 1;
			
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
