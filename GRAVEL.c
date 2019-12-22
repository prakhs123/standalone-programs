#include <stdio.h>
#define MAXN	1000010
#define LL	long long
LL tree[MAXN];

LL read(int idx) {
	LL sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, LL val) {
	while (idx <= MAXN) {
		tree[idx] += val;
		idx += (idx & -idx);
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

LL in(){LL r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

main()
{
	int n, m;
	LL c;
	char ch;
	scan(&n);
	scan(&m);
	c = in();
	while (m--) {
		ch = getchar();
		while (ch != 'Q' && ch != 'S' && ch != 'q' && ch != 's')
			ch = getchar();
		if (ch == 'Q' || ch == 'q') {
			int p;
			scan(&p);
			printf("%lld\n", read(p) + c);
		}
		else {
			int u, v;
			LL k;
			scan(&u);
			scan(&v);
			k = in();
			update(u, k);
			update(v+1, -k);
		}
	}
	return 0;
}
