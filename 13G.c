#include <stdio.h>
#include <string.h>

char a[1000005];
char b[1000005];

void strrev(void) {
	int i, j;
	j = strlen(a) - 1;
	i = 0;
	while (i < j) {
		char t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}

int palindrome(void) {
	strcpy(b,a);
	strrev();
	if (strcmp(a,b) == 0)
		return 1;
	else
		return 0;
}

int main()
{
	scanf("%s", a);
	int l = strlen(a);
	if (palindrome())
		printf("Ram\n");
	else {
		if (l%2 == 0)
			printf("Shyam\n");
		else
			printf("Ram\n");
	}
	return 0;
}
