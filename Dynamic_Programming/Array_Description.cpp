#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<int> a;
vector<pair<int, int>> LimitSet;
const int mxN = 1e5 + 2;
long long dp[mxN][102];
bool visited[mxN][102];

long long getFromFront(int i, int val) {
    if (i >= n) {
        return 1;
    }

    if (visited[i][val]) {
        return dp[i][val];
    }

    if (val < LimitSet[i].first || LimitSet[i].second < val) return 0;

    if (a[i]) {
        return (long long)(a[i] == val);
    }

    visited[i][val] = true;

    dp[i][val] = 0;

    if (i + 1 == n) {
        dp[i][val] = 1;
    } else {
        for (int j = -1; j <= 1; ++j) {
            dp[i][val] = (dp[i][val] + getFromFront(i + 1, val + j)) % M;
        }
    }
    // dp[i][val] = (getFromFront(i + 1, val - 1) + getFromFront(i + 1, val) +
    //               getFromFront(i + 1, val + 1)) %
    //              M;
    dp[i][val] = max(dp[i][val], 1LL);
    // cout << i << " " << val << ": " << dp[i][val] << endl;

    return dp[i][val];
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    cin >> n >> m;
    a.resize(n);
    LimitSet.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        LimitSet[i] = {a[i] ? a[i] : 1, a[i] ? a[i] : m};
    }
    for (int i = 1; i < n; ++i) {
        if (a[i]) continue;
        LimitSet[i] = {max(1, LimitSet[i - 1].first - 1),
                       min(m, LimitSet[i - 1].second + 1)};
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i]) continue;
        LimitSet[i] = {max(LimitSet[i].first, LimitSet[i + 1].first - 1),
                       min(LimitSet[i].second, LimitSet[i + 1].second + 1)};
    }

    long long result = 0;
    if (a[0]) {
        result = 1;
    } else {
        for (int i = LimitSet[0].first; i <= LimitSet[0].second; ++i) {
            dp[0][1] = 0;
            if (1 == n) {
                dp[0][i] = 1;
            } else {
                for (int j = -1; j <= 1; ++j) {
                    dp[0][i] = (dp[0][i] + getFromFront(1, i + j)) % M;
                }
            }
            result = (result + dp[0][i]) % M;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] && i != n - 1) {
            dp[i][a[i]] = 0;
            for (int j = -1; j <= 1; ++j) {
                dp[i][a[i]] = (dp[i][a[i]] + getFromFront(i + 1, a[i] + j)) % M;
            }
            // cout << "final " << i << ": " << dp[i][a[i]] << endl;
            result = (result * dp[i][a[i]]) % M;
        }
    }
    cout << result;
    return MONKE;
}