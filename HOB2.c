#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define ull unsigned long long

int R;
ull time[501];
bool rooms[501];

void updateallrooms(ull t) {
	int i;
	for (i = 0; i < R; i++) {
		if (time[i] <= t)
			rooms[i] = false;
	}
}

bool ifAllRoomsFull() {
	int i;
	for (i = 0; i < R; i++)
		if (rooms[i] == false)
			return false;
	return true;
}

int nextkroom(int r, int k) {
	return (r+k)%R;
}

ull RNG(char s[]) {
	int i, l = strlen(s);
	ull result = 0;
	for (i = 0; i < l; i++) {
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
		result += (s[i] - 'a' + 1) * pow (33, l-1-i);
	}
	return result;
}

int in(){
	int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked())
		;
	if(c=='-') 
		return -in();
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked())
		;
	return r;
}

void ins(char s[]) {
	int c;
	int i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
		s[i++] = c;
	s[i]='\0';
}

main()
{
	int T, N, H, M, G;
	int i;
	char S[11];
	ull previnc, currinc, prevtime, currtime, prevvisittime, mintime;
	bool flag;
	int r;
	T = in();
	while (T--) {
		N = in();
		R = in();
		previnc = 0ull;
		for (i = 0; i < R; i++) {
			rooms[i] = false;
			time[i] = 0ull;
		}
		prevtime = 0ull;
		prevvisittime = 0ull;
		while (N--) {
			H = in();
			M = in();
			G = in();
			ins(S);
			
			currtime = H*60ull + M;
			if (currtime < prevvisittime)
				prevtime += 24ull * 60ull;
			prevvisittime = currtime;
			currtime += prevtime;
			updateallrooms(currtime);
			
			r = (RNG(S)+previnc) % R;
			flag = ifAllRoomsFull();
			if (flag) {
				for (i = 0, mintime = 18446744073709551615ull; i < R; i++) {
					if (mintime > (time[i]-currtime))
						mintime = time[i] - currtime;
				}
				printf("-%llu\n", mintime);
				previnc += mintime;
			}
			else {
				currinc = 0ull;
				int a1 = 0, a2 = 0, a3 = 1, temp1, temp2;
				if (rooms[r] == false) {
					rooms[r] = true;
					time[r] = currtime + (ull)G * 60ull;
					printf("%llu\n", currinc);
				}
				else  {
					bool flag = false;
					while (!flag) {
						temp1 = a3;
						temp2 = a2;
						a3 = ((a1+a2)%R+a3)%R;
						a2 = temp1;
						a1 = temp2;
						currinc++;
						printf("%d-", a3);
						r = nextkroom(r,a3);
						if (rooms[r] == false) {
							rooms[r] = true;
							time[r] = currtime + (ull)G * 60ull;
							printf("%llu\n", currinc);
							previnc += currinc;
							flag = true;
						}
					}
				}
			}
		}
	}
	return 0;
}
