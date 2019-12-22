#include<stdio.h>
#include<string.h>
#include<ctype.h>

inline void scan(int *a) {
	register char c = 0;
	register char sign = 1;
	while (c < 33)
		c = getchar_unlocked();
	if (c == 45) {
		sign = -1;
		c = getchar_unlocked();
	}
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
	*a = *a * sign;
}

char name[1000000][16];
int remain[1000000], up[1000000];

int main(){
  int N;
  
  int k, size, i;
  char c;

  scan(&N);

  size = 0;
  while(N--){
    scan(&k);
    if(k==-1){
      printf("%d %s\n",size-1 - up[size-1], name[up[size-1]]);
      size = up[size-1];
    } else {
      i = 0;
      while ((c = getchar()) != '\n') {
      	if (isalpha(c))
      		name[size][i++] = c;
      }
      name[size][i] = '\0';
      remain[size] = k;

      if(k==0) continue;
      
      if(remain[size] <= remain[up[size-1]])
      	up[size] = size;
      else
      	up[size] = up[size-1];
      size++;
    }
  }

  return 0;
}
