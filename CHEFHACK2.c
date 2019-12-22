#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 10000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/
#define	N	351
int numbers[LIMIT];// numbers[i] is -1 if it is not prime otherwise numbers[i] = i+2
int primes[PRIMES];// list of prime numbers 2,3,5,7...
int a[N][N]; // passwords of server[i][j]
bool color[N][N];

int bSearch(int x, int low, int high){
    int mid;
    while (low <= high) {
    	mid = (low + high) / 2;
    	if (x < primes[mid])
    		high = mid - 1;
    	else if (x > primes[mid])
    		low = mid + 1;
    	else
    		return mid;
    }
    return -1;
}

void gridhack(int i, int j, int n)
{
	color[i][j] = true;
	if (a[i][j] & 1) {
		if (i+1 < n && numbers[a[i+1][j]-2] == -1  && a[i+1][j]&1 && color[i+1][j] == false)
			gridhack(i+1,j,n);
		if (i-1 >= 0 && numbers[a[i-1][j]-2] == -1  && a[i-1][j]&1 && color[i-1][j] == false)
			gridhack(i-1,j,n);
		if (j+1 < n && numbers[a[i][j+1]-2] == -1  && a[i][j+1]&1 && color[i][j+1] == false)
			gridhack(i,j+1,n);
		if (j-1 >= 0 && numbers[a[i][j-1]-2] == -1  && a[i][j-1]&1 && color[i][j-1] == false)
			gridhack(i,j-1,n);
	}
	else {
		if (i+1 < n && numbers[a[i+1][j]-2] == -1 && !(a[i+1][j]&1) && color[i+1][j] == false)
			gridhack(i+1,j,n);
		if (i-1 >= 0 && numbers[a[i-1][j]-2] == -1 && !(a[i-1][j]&1) && color[i-1][j] == false)
			gridhack(i-1,j,n);
		if (j+1 < n && numbers[a[i][j+1]-2] == -1 && !(a[i][j+1]&1) && color[i][j+1] == false)
			gridhack(i,j+1,n);
		if (j-1 >= 0 && numbers[a[i][j-1]-2] == -1 && !(a[i][j-1]&1) && color[i][j-1] == false)
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
    int i,j;

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++){
        numbers[i]=i+2;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++){
        if (numbers[i]!=-1){
            for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
                numbers[j]=-1;
        }
    }
    j = 0;
    for (i=0;i<LIMIT&&j<PRIMES;i++)
        if (numbers[i]!=-1)
            primes[j++] = numbers[i];
	
	int limit = j;
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
					if (numbers[a[i][j]-2] != -1) {
						count += bSearch(a[i][j],0,limit-1);
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
