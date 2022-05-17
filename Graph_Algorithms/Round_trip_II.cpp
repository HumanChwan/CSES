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
enum class LEGENDS { WHITE, GREY, BLACK };

bool dfs(int i, vt(vt(int)) & edges, vt(LEGENDS) & visited, vt(int) & path) {
    visited[i] = LEGENDS::GREY;

    bool result = false;
    for (int child : edges[i]) {
        if (sz(path) == 2)
            path.clear();

        if (sz(path))
            return false;
        if (visited[child] == LEGENDS::BLACK)
            continue;

        if (visited[child] == LEGENDS::GREY) {
            path.pb(child);

            result = true;
            break;
        }

        result |= dfs(child, edges, visited, path);
        if (result) {
            path.pb(child);
            if (path.front() == i) {
                path.pb(i);
                result = false;
            }
            break;
        }
    }

    visited[i] = LEGENDS::BLACK;

    return result;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, m;
    cin >> n >> m;
    vt(vt(int)) edges(n);
    vt(LEGENDS) visited(n);
    vt(int) circular_path;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].pb(b);
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] != LEGENDS::BLACK) {
            dfs(i, edges, visited, circular_path);
            if (sz(circular_path) == 2)
                circular_path.clear();
            if (sz(circular_path))
                break;
        }
    }
    if (sz(circular_path)) {
        cout << sz(circular_path) << "\n";
        reverse(all(circular_path));
        for (int i : circular_path)
            cout << i + 1 << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
    return MONKE;
}