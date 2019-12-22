#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/
int numbers[LIMIT];
int primes[PRIMES];

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

int main(){
    int i,j;
    int count = 0;

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
    /* we can use the numbers array to find whether a given no. is prime or not */
    /*for (i = 2; i < LIMIT; i++)
    	if (numbers[i-2] != -1)
    		count++;*/

	/* if we require array of prime no. */
    /*transfer the primes to their own array*/
    j = 0;
    for (i=0;i<LIMIT&&j<PRIMES;i++)
        if (numbers[i]!=-1)
            primes[j++] = numbers[i];
     
    /*for (i=2;i<LIMIT;i++)
        if (bSearch(i,primes,0,j-1) != -1)
            count++;

    printf("count=%d\n",count);*/
return 0;
}
