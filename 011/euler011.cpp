/*
 *  Author:
 *      indestinee
 *  Date:
 *      n18/08/15
 *  Name:
 *      euler011.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int n = 20, dx[4] = {1, 0, 1, 1}, dy[4] = {0, 1, 1, -1};
int a[n][n], ans = 0;
inline int work(const int &x, const int &y, const int &k) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int u = x + dx[k] * i, v = y + dy[k] * i;
        if (u >= 0 && u < n && v < n && v >= 0);
        else return 0;
        ans = ans * a[u][v];
    }
    return ans;
}
int main() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
                ans = max(ans, work(i, j, k));
    cout << ans << endl;
    return 0;
}
