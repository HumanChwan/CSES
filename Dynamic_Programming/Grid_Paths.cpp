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
    int n;
    cin >> n;
    vt(vt(char)) grid(n, vt(char)(n));
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = input[j];
        }
    }
    const int MAX = 1e3 + 5;
    static ll ways[MAX][MAX];
    ways[0][0] = (grid[0][0] == '.');
    pii dir[2] = {{-1, 0}, {0, -1}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*')
                continue;
            for (int d = 0; d < 2; ++d) {
                int ni = i + dir[d].ff;
                int nj = j + dir[d].ss;

                if (!(0 <= ni && ni < n && 0 <= nj && nj < n))
                    continue;
                if (grid[ni][nj] == '*')
                    continue;

                ways[i][j] = (ways[i][j] + ways[ni][nj]) % M;
            }
        }
    }
    cout << ways[n - 1][n - 1];
    return MONKE;
}