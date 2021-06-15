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
    const int mxSum = 1e6 + 5;
    static int orderedWays[mxSum]{0};
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int &c : coin) {
        cin >> c;
    }
    orderedWays[0] = 1LL;
    for (int i = 0; i < n; ++i) {
        for (int tempSum = coin[i]; tempSum <= x; ++tempSum) {
            orderedWays[tempSum] =
                (orderedWays[tempSum] + orderedWays[tempSum - coin[i]]) % M;
        }
    }
    cout << orderedWays[x];
    return MONKE;
}