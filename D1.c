#include <stdio.h>
#include <math.h>

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709};

int modPow(int a, int x, int p) {
    //calculates a^x mod p in logarithmic time.
    int res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

main()
{
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int no_of_divisors = 1, newn = n;
		int i;
		int l = sizeof(prime)/sizeof(int);
		for (i = 0; i < l && prime[i] <= n; i++) {
			int count = 0;
			while (newn % prime[i] == 0) {
				newn /= prime[i];
				count++;
			}
			if (count)
				no_of_divisors *= (count+1);
		}
		printf("%d\n", no_of_divisors);
		int ans;
		if (no_of_divisors&1) {
			int sqrt_root = sqrt(n);
			ans = modPow(sqrt_root,no_of_divisors-2,10000);
		}
		else
			ans = modPow(n,(no_of_divisors-2)/2,10000);
		printf("%d\n", ans);
		printf("%d\n", ans % 10000);
	}
	return 0;
}
