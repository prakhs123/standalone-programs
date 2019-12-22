#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 10000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/
#define	N	351
int numbers[LIMIT];// numbers[i] is -1 if it is not prime otherwise numbers[i] = i+2
int primes[PRIMES];// list of prime numbers 2,3,5,7...
int a[N][N]; // passwords of server[i][j]
bool b[N][N]; // is true if b[i][j] has been cracked by grid hacking mechanism
bool even[N][N];// even[i][j] = true if password of server is nonprime even, otherwise false
bool odd[N][N];// odd[i][j] = true if password of server is nonprime odd, otherwise false
bool memo1[N][N];// return true when memo1[i][j] has been visited once in grid hacking mechanism of even numbers function
bool memo2[N][N];// return true when memo2[i][j] has been visited once in grid hacking mechanism of odd numbers function

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
void gridhackeven(int i, int j, int n) {
	if (memo1[i][j] == true)
		return;
	memo1[i][j] = true;
	b[i][j] = true;
	if (j+1 <= n-1 && even[i][j+1] == true) {
		b[i][j+1] = true;
		gridhackeven(i,j+1,n);
	}
	if (j-1 >= 0 && even[i][j-1] == true) {
		b[i][j-1] = true;
		gridhackeven(i,j-1,n);
	}
	if (i-1 >= 0 && even[i-1][j] == true) {
		b[i-1][j] = true;
		gridhackeven(i-1,j,n);
	}
	if (i+1 <= n-1 && even[i+1][j] == true) {
		b[i+1][j] = true;
		gridhackeven(i+1,j,n);
	}
	return;
}
void gridhackodd(int i, int j, int n) {
	if (memo2[i][j] == true)
		return;
	memo2[i][j] = true;
	b[i][j] = true;
	if (j+1 <= n-1 && odd[i][j+1] == true) {
		b[i][j+1] = true;
		gridhackodd(i,j+1,n);
	}
	if (j-1 >= 0 && odd[i][j-1] == true) {
		b[i][j-1] = true;
		gridhackodd(i,j-1,n);
	}
	if (i-1 >= 0 && odd[i-1][j] == true) {
		b[i-1][j] = true;
		gridhackodd(i-1,j,n);
	}
	if (i+1 <= n-1 && odd[i+1][j] == true) {
		b[i+1][j] = true;
		gridhackodd(i+1,j,n);
	}
	return;
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
				b[i][j] = false;
				memo1[i][j] = false;
				memo2[i][j] = false;
				even[i][j] = false;
				odd[i][j] = false;
				if (numbers[a[i][j]-2] == -1) {
					if (a[i][j] % 2 == 0) {
						even[i][j] = true;
						odd[i][j] = false;
					}
					else {
						odd[i][j] = true;
						even[i][j] = false;
					}
				}
			}
		}
		count = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (b[i][j] != true) {
					if (numbers[a[i][j]-2] != -1) {
						b[i][j] = true;
						count += bSearch(a[i][j],0,limit-1);
					}	
					else if (even[i][j] == true) {
						count += (a[i][j]>>1);
						gridhackeven(i, j, n);
					}
					else if(odd[i][j] == true) {
						count += ((a[i][j]+1)>>1) +1;
						gridhackodd(i, j, n);
					}
				}
			}
		}
		printf("%lld\n", count);
	}
		
	return 0;
}
