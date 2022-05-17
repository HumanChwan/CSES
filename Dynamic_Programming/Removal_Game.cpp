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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    const int MAX_N = 5e3 + 2;
    static ll score[MAX_N][MAX_N][2];
    for (int i = 0; i < n; ++i) {
        score[i][i][0] = a[i];
        score[i][i][1] = 0;
    }

    for (int s = 1; s < n; ++s) {
        for (int i = 0; i <= n - s; ++i) {
            if (a[i] + score[i + 1][i + s][1] >
                a[i + s] + score[i][i + s - 1][1]) {
                score[i][i + s][0] = a[i] + score[i + 1][i + s][1];
                score[i][i + s][1] = score[i + 1][i + s][0];
            } else {
                score[i][i + s][0] = a[i + s] + score[i][i + s - 1][1];
                score[i][i + s][1] = score[i][i + s - 1][0];
            }
        }
    }
    cout << score[0][n - 1][0];
    return MONKE;
}