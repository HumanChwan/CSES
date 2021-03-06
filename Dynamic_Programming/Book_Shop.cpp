#include <bits/stdc++.h>

#if ONLINE_JUDGE
#define DEBUG(...)
#else
#define DEBUG(kek) cout << "DEBUG: [ " << #kek << " = " << kek << " ]\n"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define ff first
#define ss second
#define vt(...) vector<__VA_ARGS__>
#define sz(...) (int)(__VA_ARGS__).size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

constexpr int M = 1000000007;
constexpr int MONKE = 0;

using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& a) {
    os << "{" << a.first << ", " << a.second << "}";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> container) {
    os << "\n[ ";
    for (auto x : container)
        os << x << " ";
    os << "]\n";
    return os;
}

template <typename T1, typename T2>
bool sort_by_second_greater(const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return (a.ss > b.ss);
}

ll power(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1)
            res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, x;
    cin >> n >> x;
    vt(int) price(n), page(n);
    for (int i = 0; i < n; ++i)
        cin >> price[i];
    for (int i = 0; i < n; ++i)
        cin >> page[i];
    vt(vt(int)) maxPages(n, vt(int)(x + 1));

    for (int i = price[0]; i <= x; ++i)
        maxPages[0][i] = page[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            maxPages[i][j] = max(
                maxPages[i - 1][j],
                (j < price[i] ? 0 : maxPages[i - 1][j - price[i]] + page[i]));
        }
    }
    cout << maxPages[n - 1][x];
    return MONKE;
}