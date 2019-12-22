#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10000000
int counter = 0;
bool isprime[SIZE]={1,1};
int pi[SIZE]={};
#define	N	351

int a[N][N]; // passwords of server[i][j]
bool color[N][N];
void precompute()
{
	long long int i, j;
    for(i=2;i<SIZE;++i)
    {
        if(isprime[i]==0)
        {
            ++counter;
            pi[i] = counter;
            for(j = i*i;j<SIZE;j += i)
            {
                isprime[j] = 1;
            }
        }
    }
}

void gridhack(int i, int j, int n)
{
	color[i][j] = true;
	if (a[i][j] & 1) {
		if (i+1 < n && isprime[a[i+1][j]]  && a[i+1][j]&1 && color[i+1][j] == false)
			gridhack(i+1,j,n);
		if (i-1 >= 0 && isprime[a[i-1][j]]  && a[i-1][j]&1 && color[i-1][j] == false)
			gridhack(i-1,j,n);
		if (j+1 < n && isprime[a[i][j+1]]  && a[i][j+1]&1 && color[i][j+1] == false)
			gridhack(i,j+1,n);
		if (j-1 >= 0 && isprime[a[i][j-1]]  && a[i][j-1]&1 && color[i][j-1] == false)
			gridhack(i,j-1,n);
	}
	else {
		if (i+1 < n && isprime[a[i+1][j]] && !(a[i+1][j]&1) && color[i+1][j] == false)
			gridhack(i+1,j,n);
		if (i-1 >= 0 && isprime[a[i-1][j]] && !(a[i-1][j]&1) && color[i-1][j] == false)
			gridhack(i-1,j,n);
		if (j+1 < n && isprime[a[i][j+1]] && !(a[i][j+1]&1) && color[i][j+1] == false)
			gridhack(i,j+1,n);
		if (j-1 >= 0 && isprime[a[i][j-1]] && !(a[i][j-1]&1) && color[i][j-1] == false)
			gridhack(i,j-1,n);
	}
}
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

int main(){
	precompute();
    int i, j;
	int t, n;
	long long count;
	scan(&t);
	while (t--) {
		scan(&n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scan(&a[i][j]);
				color[i][j] = false;
			}
		}
		count = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (color[i][j] == false) {
					if (!isprime[a[i][j]]) {
						count += pi[a[i][j]] - 1;
						color[i][j] = true;
					}	
					else {
						if (a[i][j] & 1)
							count += (a[i][j]+1) / 2 + 1;
						else
							count += a[i][j] / 2;
						gridhack(i,j,n);
						color[i][j] = true;
					}
				}
			}
		}
		printf("%lld\n", count);
	}
		
	return 0;
}
