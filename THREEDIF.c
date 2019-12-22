#include <stdio.h>

#define ull unsigned long long
#define swap(a, b) { ull _z; _z = a; a = b; b = _z; }
#define MOD 1000000007
ull in(){
	ull r = 0, c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}
main()
{
	ull n1, n2, n3, t, ans;
	t = in();
	while (t--) {
		n1 = in();
		n2 = in();
		n3 = in();
		if (n1 > n2)
			swap(n1, n2)
		if (n1 > n3)
			swap(n1, n3)
		if (n2 > n3)
			swap(n2, n3)
		ans = ((n1 % MOD) * ((n2 - 1) % MOD)) % MOD;
		ans = (ans * ((n3 - 2) % MOD)) % MOD;
		printf("%llu\n", ans);
	}

	return 0;
}
