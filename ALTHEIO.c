#include <stdio.h>

int compare(char c[], int max, int i, int j) {
	i = i + 1 - max;
	j = j + 1 - max;
	char p, q;
	while (max--) {
		p = c[i] > '9' ? '9' : c[i];
		q = c[j] > '9' ? '9' : c[j];
		if (p > q)
			return 1;
		else if (q > p)
			return 0;
		i++;
		j++;
	}
	return 0;
}

int main() {
	char c[1001];
	int s=0,d=0;
	int max=-1,ind=-1;
	gets(c);
	int i;
	for (i=0;c[i];i++) {
		if (c[i]<='9') {
			if (d) d++;
			else if (c[i]-'0') d=1;
			if (s) s++;
			else if (c[i]-'0') s=1;
		} else {
			s=d+1;
			d=0;
		}
		if (s == max) {
			if (compare(c,max,i,ind))
				ind = i;
		}
		else if(s>max) {
			max=s;
			ind=i;
		}
	}
	if(max==0) printf("0\n");
	else {
		ind=ind+1-max;
		while(max--){
			printf("%c",c[ind]>'9'?'9':c[ind]);
			ind++;
		}
	printf("\n");
	}
	return 0;
}