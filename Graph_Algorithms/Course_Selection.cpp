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

enum class LEGEND { WHITE, GREY, BLACK };

bool has_cycle(int i, vt(vt(int)) & edges, vt(LEGEND) & visited) {
    visited[i] = LEGEND::GREY;
    bool cycle = false;
    for (int child : edges[i]) {
        if (visited[child] == LEGEND::BLACK)
            continue;

        if (visited[child] == LEGEND::GREY) {
            cycle = true;
            break;
        }

        cycle = has_cycle(child, edges, visited);
        if (cycle) {
            break;
        }
    }
    visited[i] = LEGEND::BLACK;
    return cycle;
}

vt(int) order;

void topological_sort(int i, vt(vt(int)) & edges, vt(LEGEND) & visited) {
    visited[i] = LEGEND::BLACK;

    for (int child : edges[i]) {
        if (visited[child] == LEGEND::BLACK)
            continue;

        topological_sort(child, edges, visited);
    }

    order.pb(i);
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, m;
    cin >> n >> m;
    vt(vt(int)) edges(n);
    vt(LEGEND) visited(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[b].pb(a);
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == LEGEND::BLACK)
            continue;

        if (has_cycle(i, edges, visited)) {
            cout << "IMPOSSIBLE";
            return MONKE;
        }
    }

    for (int i = 0; i < n; ++i)
        visited[i] = LEGEND::WHITE;

    vt(int) in(n);
    for (int i = 0; i < n; ++i)
        for (int x : edges[i])
            in[x]++;

    for (int i = 0; i < n; ++i) {
        if (in[i] == 0)
            topological_sort(i, edges, visited);
    }
    for (int i = 0; i < n; ++i)
        cout << order[i] + 1 << " ";
    return MONKE;
}