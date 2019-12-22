#include <stdio.h>
#define MAXN	500005
int RS0TS[MAXN], RS1TS[MAXN], CS0TS[MAXN], CS1TS[MAXN];

int RS0[MAXN], RS1[MAXN], CS0[MAXN], CS1[MAXN];

void updateRS0(int time, int val)
{
	if (time != 0)
		while (time <= MAXN) {
			RS0[time] += val;
			time += (time & -time);
		}
}
int readRS0(int time)
{
	int sum = 0;
	while (time > 0) {
		sum += RS0[time];
		time -= (time & -time);
	}
	return sum;
}
void updateRS1(int time, int val)
{
	if (time != 0)
		while (time <= MAXN) {
			RS1[time] += val;
			time += (time & -time);
		}
}
int readRS1(int time)
{
	int sum = 0;
	while (time > 0) {
		sum += RS1[time];
		time -= (time & -time);
	}
	return sum;
}
void updateCS0(int time, int val)
{
	if (time != 0)
		while (time <= MAXN) {
			CS0[time] += val;
			time += (time & -time);
		}
}
int readCS0(int time)
{
	int sum = 0;
	while (time > 0) {
		sum += CS0[time];
		time -= (time & -time);
	}
	return sum;
}
void updateCS1(int time, int val)
{
	if (time != 0) 
		while (time <= MAXN) {
			CS1[time] += val;
			time += (time & -time);
		}
}
int readCS1(int time)
{
	int sum = 0;
	while (time > 0) {
		sum += CS1[time];
		time -= (time & -time);
	}
	return sum;
}
main()
{
	int N, Q;
	int i, x;
	int time = 0;
	char s[100];
	scanf("%d %d", &N, &Q);
	while (Q--) {
		scanf("%s", s);
		time++;
		if (s[0] == 'R' && s[3] == 'S') {
			scanf("%d %d", &i, &x);
			if (RS0TS[i] > RS1TS[i])
				updateRS0(RS0TS[i], -1);
			else
				updateRS1(RS1TS[i], -1);
			if (x == 0) {
				updateRS0(time, 1);
				RS0TS[i] = time;
			}
			else {
				updateRS1(time, 1);
				RS1TS[i] = time;
			}
		}
		else if (s[0] == 'C' && s[3] == 'S') {
			scanf("%d %d", &i, &x);
			if (CS0TS[i] > CS1TS[i])
				updateCS0(CS0TS[i], -1);
			else
				updateCS1(CS1TS[i], -1);
			if (x == 0) {
				updateCS0(time, 1);
				CS0TS[i] = time;
			}
			else {
				updateCS1(time, 1);
				CS1TS[i] = time;
			}
		}
		else if (s[0] == 'R' && s[3] == 'Q') {
			scanf("%d", &i);
			if (RS0TS[i] >= RS1TS[i]) {
				int T = RS0TS[i];
				int ones = readCS1(MAXN) - readCS1(T);
				printf("%d\n", N - ones);
			}
			else {
				int T = RS1TS[i];
				int zeros = readCS0(MAXN) - readCS0(T);
				printf("%d\n", zeros);
			}
		}
		else if (s[0] == 'C' && s[3] == 'Q') {
			scanf("%d", &i);
			if (CS0TS[i] >= CS1TS[i]) {
				int T = CS0TS[i];
				int ones = readRS1(MAXN) - readRS1(T);
				printf("%d\n", N - ones);
			}
			else {
				int T = CS1TS[i];
				int zeros = readRS0(MAXN) - readRS0(T);
				printf("%d\n", zeros);
			}
		}
	}
	
	return 0;
}
