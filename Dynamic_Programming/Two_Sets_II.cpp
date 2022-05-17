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

constexpr int MAX = 501;
constexpr int MAX_X = 62630;
ll ways[MAX_X][MAX];

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    for (int i = 0; i < MAX; ++i)
        ways[0][i] = 1;
    for (int x = 0; x < MAX_X; ++x)
        ways[x][0] = 0;

    int n;
    cin >> n;
    int req = (n * (n + 1)) / 4;
    for (int x = 1; x <= req; ++x) {
        for (int i = 1; i <= n; ++i) {
            ways[x][i] =
                ((x >= i ? ways[x - i][i - 1] : 0) + ways[x][i - 1]) % M;
        }
    }
    if ((n * (n + 1)) % 4 == 0)
        cout << ways[(n * (n + 1)) / 4][n];
    else
        cout << 0;
    return MONKE;
}