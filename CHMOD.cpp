// Program to show segment tree operations like construction, query and update
#include <stdio.h>
#include <math.h>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;
 
#define MAXN    100000

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

int a[MAXN+10];
int st[6553575][25];
int p_n[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int p[101] = {0, 0, 0, 1, 0, 2, 0, 3, 0, 0, 0, 4, 0, 5, 0, 0, 0, 6, 0, 7, 0, 0, 0, 8, 0, 0, 0, 0, 0, 9, 0, 10, 0, 0, 0, 0, 0, 11, 0, 0, 0, 12, 0, 13, 0, 0, 0, 14, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 16, 0, 17, 0, 0, 0, 0, 0, 18, 0, 0, 0, 19, 0, 20, 0, 0, 0, 0, 0, 21, 0, 0, 0, 22, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0};
int fact[101][5];

 void init() {
    int i;
    for (i = 2; i <= 100; i++) {
        int temp = i;
        fact[i][4] = 0;
        while (temp % 2 == 0) {
            fact[i][0]++;
            temp /= 2;
        }
        while (temp % 3 == 0) {
            fact[i][1]++;
            temp /= 3;
        }
        while (temp % 5 == 0) {
            fact[i][2]++;
            temp /= 5;
        }
        while (temp % 7 == 0) {
            fact[i][3]++;
            temp /= 7;
        }
        if (temp != 1)
            fact[i][4] = temp;
    }
 }

 void print() {
    int i;
    for (i = 1; i <= 100; i++) {
        int j;
        printf("%d- ", i);
        for (j = 0; j <= 3; j++)
            printf("%d:%d ", p_n[j], fact[i][j]);
        printf("%d:%d\n", fact[i][4], 1);
    }
 }
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
void getMulUtil(int store[], int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // mul of the segment
    if (qs <= ss && qe >= se) {
        int i;
        for (i = 0; i < 25; i++)
            store[i] += st[index][i];
        return ;
    }
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return ;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    getMulUtil(store, ss, mid, qs, qe, 2*index+1);
    getMulUtil(store, mid+1, se, qs, qe, 2*index+2);
    return;
}
 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
void getMul(int store[], int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
    }
 
    getMulUtil(store, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        int i;
        for (i = 0; i <= 3; i++)
            st[si][i] = fact[arr[ss]][i];
        if (fact[arr[ss]][4] != 0)
            st[si][p[fact[arr[ss]][4]]] = 1;
        return si;
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    int i;
    int i1, i2;
    i1 = constructSTUtil(arr, ss, mid, 2*si+1);
    i2 = constructSTUtil(arr, mid+1, se, 2*si+2);
    for (i = 0; i < 25; i++)
        st[si][i] = st[i1][i] + st[i2][i];
    return si;
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
void constructST(int arr[], int n)
{
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}
 
// Driver program to test above functions
int main()
{
    init();
    int N;
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    // Build segment tree from given array
    constructST(a, N);
    int T;
    scanf("%d", &T);
    while (T--) {
        int L, R, mi;
        scanf("%d %d %d", &L, &R, &mi);
        int temp[25] = {0};
        getMul(temp, N, L-1, R-1);
        int num = 1;
        for (i = 0; i < 25; i++)
            if (temp[i] != 0)
                num = (num * modPow(p_n[i], temp[i], mi)) % mi;
        printf("%d\n", num);
    }
 
    return 0;
}
