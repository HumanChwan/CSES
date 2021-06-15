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
    vector<int> price(n), pages(n);

    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    const int mxN = 1e3 + 4;
    const int mxX = 1e5 + 4;
    static int maxPages[mxN][mxX];

    for (int i = 0; i <= x; ++i) {
        if (i >= price[0]) {
            maxPages[0][i] = pages[0];
        } else {
            maxPages[0][i] = 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            maxPages[i][j] = maxPages[i - 1][j];
            if (j >= price[i]) {
                maxPages[i][j] = max(maxPages[i][j],
                                     maxPages[i - 1][j - price[i]] + pages[i]);
            }
        }
    }

    cout << maxPages[n - 1][x];
    return MONKE;
}