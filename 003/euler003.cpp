/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/08
 *  Name:
 *      euler003.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas;
long long n;
long long work(long long x) {
    long long ret = -1;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            do {
                x /= i;
            } while (x % i == 0);
            ret = i;
        }
    }

    return max(ret, x);
        
}
int main() {
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        scanf("%lld", &n);
        printf("%lld\n", work(n));
    }
    return 0;
}
