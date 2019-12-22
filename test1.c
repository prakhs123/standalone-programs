#include <stdio.h>

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
	int x1,y1,x2,y2;
	x1 = in();
	y1 = in();
	x2 = in();
	y2 = in();
	double X1,Y1,X2,Y2;
	X1 = (double)x1;
	X2 = (double)x2;
	Y1 = (double)y1;
	Y2 = (double)y2;
	printf("%f\n", (Y2-Y1)/(X2-X1));
	return 0;
}
