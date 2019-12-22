#include <stdio.h>
#include <string.h>

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

int ddish[11][10] = { {0,1,2,3,4,5,6,7,8,9} , {0,10,19,28,37,46,55,64,73,82} , {0,90,162,234,306,378,450,522,594,666} , {0,738,1242,1746,2250,2754,3258,3762,4266,4770} , {0,5274,8298,11322,14346,17370,20394,23418,26442,29466} , {0,32490,47610,62730,77850,92970,108090,123210,138330,153450} , {0,168570,229050,289530,350010,410490,470970,531450,591930,652410} , {0,712890,894330,1075770,1257210,1438650,1620090,1801530,1982970,2164410}, {

int DDISH(char s[]) {
	int i = -1;
	int result = 0, len = strlen(s);
	while (s[++i] != '\0')
		result += ddish[len-i][s[i]-'0'];
		
	return result;
}
	
main()
{
	char L[20], R[20], c;
	int t;
	int i;
	long long answer;
	scan(&t);
	while (t--) {
		i = 0;
		while ((c = getchar()) != ' ')
			L[i++] = c;
		L[i] = '\0';
		i = 0;
		while ((c = getchar()) != '\n')
			R[i++] = c;
		R[i] = '\0';
		
		answer = DDISH(R) - DDISH(L-1);
		printf("%ld", answer);
	}
	
	return 0;
}
