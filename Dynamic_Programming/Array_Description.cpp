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
void debug(T container) {
    cerr << "[ ";
    for (auto x : container)
        cerr << x << " ";
    cerr << "]";
}

template <typename T1, typename T2>
bool sort_by_second_greater(const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return (a.ss > b.ss);
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    const int MAX_N = 1e5 + 2;
    const int MAX_M = 1e2 + 2;
    static ll ways[MAX_N][MAX_M] = {0};

    for (int i = 1; i <= m; ++i) {
        ways[0][i] = !a[0];
    }
    if (a[0])
        ways[0][a[0]] = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i]) {
            for (int j = 1; j <= m; ++j)
                ways[i][j] = 0;
            ways[i][a[i]] = (ways[i - 1][a[i] - 1] + ways[i - 1][a[i]] +
                             ways[i - 1][a[i] + 1]) %
                            M;
        } else {
            for (int j = 1; j <= m; ++j) {
                ways[i][j] =
                    (ways[i - 1][j - 1] + ways[i - 1][j] + ways[i - 1][j + 1]) %
                    M;
            }
        }
    }
    int ans = ways[n - 1][a[n - 1]];
    if (!a[n - 1]) {
        for (int i = 1; i <= m; ++i)
            ans = (ans + ways[n - 1][i]) % M;
    }
    cout << ans;
    return MONKE;
}