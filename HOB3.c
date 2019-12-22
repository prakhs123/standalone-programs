#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define ull unsigned long long

int seq[501][500];
int R;
ull time[501];
bool rooms[501];
bool checkallrooms() {
	int i;
	for (i = 0; i < R; i++)
		if (rooms[i] == false)
			return false;
	return true;
}
void precompute() {
	int max = 0;
	for (R = 1; R <= 500; R++) {
		int i, j = 0;
		for (i = 0; i < R; i++)
			rooms[i] = false;
		ull a1 = 1, a2 = 2, a3 = 3, temp1, temp2;
		int counter = 0;
		int r = 0, prevr, prevprevr;
		bool flag = false;
		
		rooms[r] = true;
		seq[R][j++] = r;
		flag = checkallrooms();
		if (!flag) {
			r = nextkroom(r,a1);
			rooms[r] = true;
			seq[R][j++] = r;
			flag = checkallrooms();
			counter++; 
		}
		if (!flag) {
			r = nextkroom(r,a2);
			rooms[r] = true;
			seq[R][j++] = r;
			flag = checkallrooms();
			counter++;
		}
		prevprevr = r;
		if (!flag) {
			r = nextkroom(r,a3);
			rooms[r] = true;
			seq[R][j++] = r;
			flag = checkallrooms();
			counter++;
		}
		prevr = r;
		while (!flag&&counter <= 500) {
			temp1 = a3;
			temp2 = a2;
			a3 = ((a1+a2)%R+a3)%R;
			a2 = temp1;
			a1 = temp2;
			r = nextkroom(r,a3);
			if (r == 1 && prevr == 0 && prevprevr == 0) {
				flag = true;
			}
			else {
				seq[R][j++] = r;
				rooms[r] = true;
				flag = checkallrooms();
				counter++;
				prevprevr = prevr;
				prevr = r;
			}
		}
		seq[R][j] = -1;
	}
}

void updateallrooms(ull t) {
	int i;
	for (i = 0; i < R; i++) {
		if (time[i] <= t)
			rooms[i] = false;
	}
}

int nextkroom(int r, int k) {
	return (r+k)%R;
}

bool ifAllRoomsFull() {
	int i;
	for (i = 0; i < R; i++)
		if (rooms[i] == false)
			return false;
	return true;
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

main()
{
	precompute();
	int T, N, H, M, G;
	int i;
	char S[11];
	ull previnc, currinc, prevtime, currtime, prevvisittime, mintime;
	bool flag;
	int r, newr;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &R);
		previnc = 0ull;
		for (i = 0; i < R; i++) {
			rooms[i] = false;
			time[i] = 0ull;
		}
		prevtime = 0ull;
		prevvisittime = 0ull;
		while (N--) {
			scanf("%d %d %d %s", &H, &M, &G, S);
			
			currtime = H*60ull + M;
			if (currtime < prevvisittime)
				prevtime += 24ull * 60ull;
			prevvisittime = currtime;
			currtime += prevtime;
			updateallrooms(currtime);
			
			r = (RNG(S)+previnc) % R;
			i = 0;
			currinc = 0ull;
			flag = false;
			while (seq[R][i] != -1 && !flag) {
				newr = (r + seq[R][i]) % R;
				if (rooms[newr] == false) {
					rooms[newr] = true;
					time[newr] = currtime + (ull)G * 60ull;
					printf("%llu\n", currinc);
					previnc += currinc;
					flag = true;
				}
				i++;
				currinc++;
			}
			if (!flag) {
				for (i = 0, mintime = 18446744073709551615ull; i < R; i++) {
					if (mintime > (time[i]-currtime))
						mintime = time[i] - currtime;
				}
				printf("-%llu\n", mintime);
				previnc += mintime;
			}
		}
	}
	return 0;
}
