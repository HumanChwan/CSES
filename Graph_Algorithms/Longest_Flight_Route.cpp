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
int n;
vt(vt(int)) edges;
vt(bool) vis;
vt(int) mxLen;

int get_len(int i) {
    if (i == n - 1)
        return mxLen[n - 1];

    if (vis[i])
        return mxLen[i];

    vis[i] = true;

    int mx = -1;
    for (int child : edges[i]) {
        int nx = get_len(child);
        if (nx < 0)
            continue;
        mx = max(mx, 1 + nx);
    }

    return mxLen[i] = mx;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int m;
    cin >> n >> m;
    edges = vt(vt(int))(n);
    vis = vt(bool)(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].pb(b);
    }
    mxLen = vt(int)(n, -1);
    mxLen[n - 1] = 1;
    get_len(0);

    if (mxLen[0] != -1) {
        cout << mxLen[0] << "\n";
        int mx = mxLen[0], parent = 0;
        while (mx--) {
            cout << parent + 1 << " ";
            for (int x : edges[parent]) {
                if (mxLen[x] == mx) {
                    parent = x;
                    break;
                }
            }
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    return MONKE;
}