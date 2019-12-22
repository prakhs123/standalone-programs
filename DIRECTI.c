#include <stdio.h>
#include <string.h>

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}

main()
{
	int t, N, i, j;
	char c;
	int leftright[50];
	char places[50][60], temp[50];
	scan(&t);
	while (t--) {
		scan(&N);
		j = 0;
		while ((c = getchar()) != ' ')
			;
		while ((c = getchar()) != ' ')
			;
		while ((c = getchar()) != '\n' && c != EOF)
			places[0][j++] = c;
		places[0][j] = '\0';
		for (i = 1; i < N; i++) {
			j = 0;
			while ((c = getchar()) != ' ')
				temp[j++] = c;
			temp[j] = '\0';
			if (strcmp(temp, "Left") == 0)
				leftright[i] = 0;
			else if (strcmp(temp, "Right") == 0)
				leftright[i] = 1;
			while ((c = getchar()) != ' ')
				;
			j = 0;
			while ((c = getchar()) != '\n' && c != EOF)
				places[i][j++] = c;
			places[i][j] = '\0';
		}
		printf("Begin on %s\n", places[N-1]);
		for (i = N-2; i >= 0; i--) {
			if (leftright[i+1] == 0)
				printf("Right on ");
			else
				printf("Left on ");
			printf("%s\n", places[i]);
		}
		printf("\n");
	}
	
	return 0;
}
			
