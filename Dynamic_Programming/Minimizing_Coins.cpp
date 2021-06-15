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
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    const int mxX = 1e6 + 5;
    static int minCoins[mxX];
    minCoins[0] = 0;
    for (int i = 1; i <= x; ++i) {
        minCoins[i] = mxX;
        for (int coinIndex = 0; coinIndex < n; ++coinIndex) {
            if (c[coinIndex] > i) continue;
            minCoins[i] = min(minCoins[i], minCoins[i - c[coinIndex]] + 1);
        }
    }

    cout << (minCoins[x] == mxX ? -1 : minCoins[x]);
    return MONKE;
}