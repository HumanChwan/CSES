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

bool sort_by_second(const pair<int, int>& a, const pair<int, int>& b) {
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

vt(string) paths;
vt(vt(bool)) grid(7, vt(bool)(7));

vt(pair<char, pii>) dirs = {{'U', {-1, 0}},
                            {'R', {0, 1}},
                            {'D', {1, 0}},
                            {'L', {0, -1}}};

bool valid(int i, int j) {
    return (0 <= i && i < 7 && 0 <= j && j < 7);
}

void get_paths(int i, int j, string path) {
    if (i == 6 && j == 0) {
        if (path.length() == 48) {
            paths.pb(path);
        }

        return;
    }

    int vertical = 0, horizontal = 0;
    for (auto dir : dirs) {
        int ni = i + dir.ss.ff, nj = j + dir.ss.ss;
        if (!valid(ni, nj))
            continue;
        if (grid[ni][nj])
            continue;

        if (dir.ff == 'U' || dir.ff == 'D')
            vertical++;
        else
            horizontal++;
    }

    if ((vertical == 2 && !horizontal) || (horizontal == 2 && !vertical))
        return;

    for (auto dir : dirs) {
        int ni = i + dir.ss.ff, nj = j + dir.ss.ss;
        if (!valid(ni, nj))
            continue;
        if (grid[ni][nj])
            continue;

        grid[ni][nj] = true;
        get_paths(ni, nj, path + dir.ff);
        grid[ni][nj] = false;
    }
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    string s;
    grid[0][0] = true;
    get_paths(0, 0, s);
    cout << paths.size();
    return MONKE;
}