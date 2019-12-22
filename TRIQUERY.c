#include <stdio.h>
#define MAXN	300000

int x[MAXN+10], y[MAXN+10];

int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

main()
{
	int N, Q, i, j;
	N = in();
	Q = in();
	for (i = 0; i < N; i++) {
		x[i] = in();
		y[i] = in();
	}
	for (i = 0; i < Q; i++) {
		int X,Y,D;
		X = in();
		Y = in();
		D = in();
		double x1, x2, x3, y1, y2, y3;
		x1 = (double)X+(double)D;
		y1 = (double)Y;
		x2 = (double)X;
		y2 = (double)Y;
		x3 = (double)X;
		y3 = (double)Y+(double)D;
		double m1, m2, m3, c1, c2, c3;
		int f1, f2, f3;
		int flag1, flag2, flag3;
		flag1 = flag2 = flag3 = 1;
		f1 = f2 = f3 = 1;
		
		if (x2-x1 == 0)
			f1 = 0;
		else {
			m1 = -(y2-y1)/(x2-x1);
			c1 = -m1*x1-y1;
		}
		if (f1) {
			if (y3+m1*x3+c1 < 0)
				flag1 = 0;
		}
		else {
			if (x3 - x1 < 0)
				flag1 = 0;
		}
		
		if (x3-x2 == 0)
			f2 = 0;
		else {
			m2 = -(y3-y2)/(x3-x2);
			c2 = -m2*x2-y2;
		}
		if (f2) {
			if (y1+m2*x1+c2 < 0)
				flag2 = 0;
		}
		else {
			if (x1 - x2 < 0)
				flag2 = 0;
		}
		
		if (x3-x1 == 0)
			f3 = 0;
		else {
			m3 = -(y3-y1)/(x3-x1);
			c3 = -m3*x1-y1;
		}
		if (f3) {
			if (y2+m3*x2+c3 < 0)
				flag3 = 0;
		}
		else {
			if (x2 - x3 < 0)
				flag3 = 0;
		}
		
		int count = 0;
		for (j = 0; j < N; j++) {
			if (f1) {
				if (flag1) {
					if (y[j]+m1*x[j]+c1 < 0)
						continue;
				}
				else {
					if (y[j]+m1*x[j]+c1 > 0)
						continue;
				}
			}
			else {
				if (flag1) {
					if (x[j]-x1 < 0)
						continue;
				}
				else {
					if (x[j]-x1 > 0)
						continue;
				}
			}
			
			if (f2) {
				if (flag2) {
					if (y[j]+m2*x[j]+c2 < 0)
						continue;
				}
				else {
					if (y[j]+m2*x[j]+c2 > 0)
						continue;
				}
			}
			else {
				if (flag2) {
					if (x[j]-x2 < 0)
						continue;
				}
				else {
					if (x[j]-x2 > 0)
						continue;
				}
			}
			
			if (f3) {
				if (flag3) {
					if (y[j]+m3*x[j]+c3 < 0)
						continue;
				}
				else {
					if (y[j]+m3*x[j]+c3 > 0)
						continue;
				}
			}
			else {
				if (flag3) {
					if (x[j]-x3 < 0)
						continue;
				}
				else {
					if (x[j]-x3 > 0)
						continue;
				}
			}
			count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
