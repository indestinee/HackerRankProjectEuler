/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler006.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas;
long long n;
inline long long sqr(const long long &x) {
    return x * x;
}
inline long long work(const long long &n) {
    return abs(sqr(n*(n+1)/2) - n*(n+1)*(n*2+1)/6);
}
int main() {
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lld", &n);
        printf("%lld\n", work(n));
    }

    return 0;
}
