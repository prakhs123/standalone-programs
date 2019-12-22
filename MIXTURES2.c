    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #define MAX 101
    #define MOD 100
    #define L 999999
     
    int main () {
    int n;
    while (scanf ("%d", &n) != EOF) {
    int a[n], sum, min, i, j, k, l, m[MAX][MAX] = {0}, c[MAX] = {0}, s[MAX][MAX] = {0};
    for (i = 0; i < n; i++) {
    scanf ("%d", c+i);
    m[i][i] = c[i];
    }
    for (i = 0; i < n; i++) {
    sum = c[i];
    for (j = i+1; j < n; j++) {
    sum += c[j];
    m[i][j] = sum % MOD;
    }
    }
    for (l = 1; l < n; l++) {
    for (i = 0; i < n-l; i++) {
    j = i+l;
    min = L;
    for (k = i+1; k <= j; k++) {
    if ((s[i][k-1] + s[k][j] + m[i][k-1]*m[k][j]) < min)
    min = s[i][k-1] + s[k][j] + m[i][k-1]*m[k][j];
    }
    s[i][j] = min;
    }
    }
    printf ("%d\n", s[0][n-1]);
    }
    return 0;
    } 
