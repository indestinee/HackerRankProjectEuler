/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/23
 *  Name:
 *      euler018.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas, n, a[20][20], dp[20][20];
int main() {
    cin >> cas;
    while (cas--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                cin >> a[i][j];
        memset(dp, 0, sizeof dp);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;

    }


    return 0;
}
