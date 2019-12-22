#include <stdio.h>
#include <string.h>

int main() {
	char input[50], mask[50];
	gets(input);
	gets(mask);
	int hash[256] = {0};
	int n, m;
	n = strlen(input);
	m = strlen(mask);
	int i, j;
	for (i = 0; i < m; i++)
		hash[mask[i]] = 1;
	for (i = 0, j = 0; i < n; i++) {
		if (!hash[input[i]]) {
			input[j] = input[i];
			j++;
		}
	}
	input[j] = '\0';
	printf("%s\n", input);
	return 0;
}