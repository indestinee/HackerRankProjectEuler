/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/23
 *  Name:
 *      euler019.cpp
 */

#include <bits/stdc++.h>
using namespace std;
inline long long whatday(long long y, long long m, const long long &d = 1) {
    if (m == 1 || m == 2)
        m += 12, y--;
    auto x = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return x;
}
int main() {
    long long cas, y1, m1, d1, y2, m2, d2;
    cin >> cas;
    while (cas--) {
        cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
        if (d1 > 1)
            m1++;
        
        long long ans = 0;

        if (y1 == y2) {
            for (long long i = y1, j = m1; j <= m2; j++)
                if (whatday(i, j) == 6)
                    ans++;
        } else {
            for (long long i = y1, j = m1; j <= 12; j++)
                if (whatday(i, j) == 6)
                    ans++;
        }

        y1++;
        
        long long cnt = 0;
        for (long long i = y1; i < y1 + 400; i++)
            for (long long j = 1; j <= 12; j++)
                cnt += whatday(i, j) == 6;

        
        long long t = 0;
        //  y1 --> y2 - 1
        for (long long i = y1 + ((y2 - y1) / 400 * (1 - (long long)(t==0)) + t) * 400; i <= y2; i++) {
            for (long long j = 1; j <= 12; j++) {
                if (i == y2 && j > m2)
                    break;
                if (whatday(i, j) == 6)
                    ans++;
            }
        }
        cout << ans + ((y2 - y1) / 400 * (1 - (long long)(t == 0)) + t) * cnt << endl;


    }
    return 0;
}

/*
4
1800 1 1
3000 1 1
1800 1 1
2999 1 1
1800 1 1
2998 1 1
1800 1 1
2997 1 1
*/
