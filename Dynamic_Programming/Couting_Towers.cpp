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
    const int MAX_N = 1e6 + 5;
    static ll ways[MAX_N][2];

    ways[1][0] = 1;
    ways[1][1] = 1;

    for (int i = 2; i < MAX_N; ++i) {
        ways[i][0] = (ways[i - 1][0] * 2 + ways[i - 1][1]) % M;
        ways[i][1] = (ways[i - 1][0] + ways[i - 1][1] * 4) % M;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (ways[n][0] + ways[n][1]) % M << "\n";
    }
    return MONKE;
}