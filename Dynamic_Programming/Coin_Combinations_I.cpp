#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
;
typedef long double ld;

using namespace std;
int n, x;
vector<int> a;
const int mxX = 1e6 + 2;
long long dp[mxX];

long long CountBoi(int k) {
    if (k == 0) return 1LL;
    if (k < 0) return 0LL;
    if (dp[k] != -1) return dp[k];

    dp[k] = 0LL;
    for (int i = 0; i < n; ++i) {
        dp[k] = (dp[k] + CountBoi(k - a[i])) % M;
    }

    return dp[k];
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    cin >> n >> x;
    a.resize(n);

    memset(dp, -1, sizeof(dp));
    for (int &c : a) {
        cin >> c;
    }

    cout << CountBoi(x);
    return MONKE;
}