#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu

    const int mxSum = 6e6 + 4;
    static int sum[mxSum];
    int n;
    cin >> n;
    sum[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
        sum[i] = 0LL;
        for (int diceNumber = 1; diceNumber <= 6 && i >= diceNumber;
             ++diceNumber) {
            sum[i] = (sum[i] + sum[i - diceNumber]) % M;
        }
    }
    cout << sum[n];
    return MONKE;
}