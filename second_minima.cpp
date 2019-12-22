#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int,int> ii;

bool isPowerOfTwo (int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
// modified
int log_2(unsigned int n) {
	int bits = 0;
	if (!isPowerOfTwo(n))
		bits++;
	if (n > 32767) {
 		n >>= 16;
		bits += 16;
	}
	if (n > 127) {
		n >>= 8;
		bits += 8;
	}
	if (n > 7) {
		n >>= 4;
		bits += 4;
	}
	if (n > 1) {
		n >>= 2;
		bits += 2;
	}
	if (n > 0) {
		bits++;
	}
	return bits;
}

int second_minima(int a[], unsigned int n) {
    
    // build a tree of size of log2n in the form of 2d array
    // 1st row represents all elements which fights for min
    // candidate pairwise. winner of each pair moves to 2nd
    // row and so on
	int log_2n = log_2(n);
    long comparison_count = 0;
    // pair of ints : first element stores value and second
    //                stores index of its first row
    ii **p = new ii*[log_2n];
	int i, j, k;
	for (i = 0, j = n; i < log_2n; i++) {
		p[i] = new ii[j];
		j = j&1 ? j/2+1 : j/2;
	}
	for (i = 0; i < n; i++)
		p[0][i] = make_pair(a[i], i);
    
    
    
    // find minima using pair wise fighting
	for (i = 1, j = n; i < log_2n; i++) {
        // for each pair
		for (k = 0; k+1 < j; k += 2) {
            // find its winner
            if (++comparison_count && p[i-1][k].first < p[i-1][k+1].first) {
				p[i][k/2].first = p[i-1][k].first;
                p[i][k/2].second = p[i-1][k].second;
            }
            else {
				p[i][k/2].first = p[i-1][k+1].first;
                p[i][k/2].second = p[i-1][k+1].second;
            }
            
		}
        // if no. of elements in row is odd the last element
        // directly moves to next round (row)
        if (j&1) {
			p[i][j/2].first = p[i-1][j-1].first;
            p[i][j/2].second = p[i-1][j-1].second;
        }
		j = j&1 ? j/2+1 : j/2;
	}
    
    
    
    int minima, second_minima;
    int index;
    minima = p[log_2n-1][0].first;
    // initialize second minima by its final (last 2nd row)
    // potential candidate with which its final took place
    second_minima = minima == p[log_2n-2][0].first ? p[log_2n-2][1].first : p[log_2n-2][0].first;
    // minima original index
    index = p[log_2n-1][0].second;
    for (i = 0, j = n; i <= log_2n - 3; i++) {
        // if its last candidate in any round then there is
        // no potential candidate
        if (j&1 && index == j-1) {
            index /= 2;
            j = j/2+1;
            continue;
        }
        // if minima index is odd, then it fighted with its index - 1
        // else its index + 1
        // this is a potential candidate for second minima, so check it
        if (index&1) {
            if (++comparison_count && second_minima > p[i][index-1].first)
                second_minima = p[i][index-1].first;
        }
        else {
            if (++comparison_count && second_minima > p[i][index+1].first)
                second_minima = p[i][index+1].first;
        }
        index/=2;
        j = j&1 ? j/2+1 : j/2;
    }
    
    
    printf("-------------------------------------------------------------------------------\n");
    printf("Minimum          : %d\n", minima);
    printf("Second Minimum   : %d\n", second_minima);
    printf("comparison count : %ld\n", comparison_count);
    printf("Least No. Of Comparisons (");
    printf("n+ceil(log2_n)-2) : %d\n", (int)(n+ceil(log(n)/log(2))-2));
	return 0;
}

int main()
{
	unsigned int n;
	scanf("%u", &n);
	int a[n];
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	second_minima(a,n);
	return 0;
}
