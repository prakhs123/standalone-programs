#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        if (!(N&1)) {
            printf("-1\n");
            continue;
        }
        else {
            int p = N/2;
            int i;
            long long sum = 0;
            for (i = p; i >= 1; i++)
                sum += i;
            for (i = p-1; i >= 1; i++)
                sum += i;
            printf("%lld\n", sum);
        }
    }
    return 0;
}
