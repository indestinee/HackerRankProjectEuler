/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/23
 *  Name:
 *      euler017.cpp
 */

#include <bits/stdc++.h>
using namespace std;

string s20[20] = {
    " ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", 
    "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
}, t[10] = {
    " ", " ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "
}, hundred = "Hundred ", k[5] = {" ", "Thousand ", "Million ", "Billion ", "Trillion "}, zero = "Zero";

inline string work(long long n) {
    if (n == 0)
        return zero;
    string ans;
    for (int i = 0; n; i++, n /= 1000) {
        int m = n % 1000;
        if (m == 0)
            continue;
        string tmp = "";
        if (m >= 100) {
            tmp += s20[m/100] + hundred;
            m %= 100;
        }
        if (m >= 20) {
            tmp += t[m/10];
            m %= 10;
        } 
        tmp += s20[m];
        tmp += k[i];
        ans = tmp + ans;
    }
    char space = ' ';
    string ret = "";
    for (int i = 0; i < int(ans.length()); i++) {
        if (space == ' ' && ans[i] == ' ')
            continue;
        ret += ans[i];
        space = ans[i];
    }
    while (*ret.rbegin() == ' ')
        ret.pop_back();
    return ret;

}

int cas;
long long n;
int main() {
    cin >> cas;
    while (cas--) {
        cin >> n;
        cout << work(n) << endl;
    }

    return 0;
}
