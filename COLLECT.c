#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
 
#define MOD 3046201
#define MAXN 100000
#define ll long long
 
ll fact[MAXN * 30 + 10], invfact[MAXN + 30];
 
ll powmod(ll base, ll expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return base*powmod(base, expo-1)%MOD;
	else{
		ll root=powmod(base, expo>>1);
		return root*root%MOD;
	}
}
 
ll inverse(ll x){
	return powmod(x, MOD-2);
}
 
void init(){
	fact[0]=1;
	ll i;
	for(i=1; i<=MAXN*30+10; i++)
		fact[i]=i*fact[i-1]%MOD;
	invfact[MAXN+29]=inverse(fact[MAXN+29]);
	for(i=MAXN+29; i>0; i--)
		invfact[i-1]=i*invfact[i]%MOD;
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
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
/* A recursive function to update the nodes which have the given index in
   their range. The following are parameters
    st, index, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = (int *) malloc(sizeof(int) * max_size);
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

ll Query(int K, int sum, int i, int x) {
    ll ans;
    ans = ( fact[sum]*powmod(invfact[x + 1], i) )%MOD;
    ans = ( ans*powmod(invfact[x], K-i) )%MOD;
    ans = ( ans*fact[K] )%MOD;
    ans = ( ans*invfact[i] )%MOD;
    ans = ( ans*invfact[K-i] )%MOD;
    return ans;
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

int main()
{
	int N, Q, L, R, A, C;
	int B[MAXN];
	char s, c;
	scan(&N);
	int j;
	int K, sum, x, i;
	init();
	for (j = 0; j < N; j++)
		scan(&B[j]);
	int *st = constructST(B, N);
	scan(&Q);
	while (Q--) {
		s = getchar_unlocked();
        while(!isspace(getchar_unlocked()));
		if (s == 'c') {
			scan(&A);
            scan(&C);
			updateValue(B, st, N, A-1, C);
		}
		else {
			scan(&L);
            scan(&R);
			K = R - L + 1;
			sum = getSum(st, N, L-1, R-1);
			i = sum % K;
			x = sum / K;
			printf("%lld\n", Query(K, sum, i, x));
		}
	}
	return 0;
}
