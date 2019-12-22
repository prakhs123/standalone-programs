#include<cstdio>
#include<cmath>
using namespace std;
#define M 500000

int a[M+1]={0};

int pow(const int q,int w) {
	if (w==0) 
		return 1;
	else if (w==1) 
		return q;
	else{
		int t = pow(q,w/2);
		t = (t*t) % 10000;
		if (w&1) 
			t=(t*q)%10000;
		return t;
	}
}

int main() {
	int n,i,j,x,y,z,m,k;
	a[1]=1;
	for (i=2;i<=M;i+=2)
		a[i]=2;
	for (i=3;i<=M;i+=2)
		if (!a[i]) {
			a[i]=i;
		for (j=3*i;j<=M;j+=2*i)
			//if (!a[j])
			a[j]=i;
		}
 
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d",&x);
		k=x;
		m=(int)sqrt(x);
		if (m*m!=x) 
			m=1;
		y=1;
		while(a[x]>1) {
			z=0;
			j=a[x];
			do {
				z++;
				x=x/a[x];
			} while (j==a[x]);
			y*=z+1;
		};
		y=(y-2)/2;
		z=m;
		for (j=0;j<y;j++){
			z=z*k;
			if (z>10000) break;
		}
		if (z>10000||i<y) {
			z=(m*pow(k%10000,y))%10000;
			printf("%04d\n",z);
		}
		else
			printf("%d\n",z);
	}
	return 0;
}
