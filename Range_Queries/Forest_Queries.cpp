#include <bits/stdc++.h>

#if ONLINE_JUDGE
#define DEBUG(...)
#else
#define DEBUG(kek) cout << "DEBUG: [ " << kek << " ]\n"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MONKE 0
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define vt(...) vector<__VA_ARGS__>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define M 1000000007
#define fl(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

bool SortGrtScnd(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.ss > b.ss);
}

int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }

ll power(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

class SegmentTree {
   private:
    vt(vt(vt(int))) tree;
    int size;
    int LEVEL;

    int segment_recurs(int A[], int B[], int l, int ind[], int L[], int R[]) {
        if (R[0] < A[0] || R[1] < A[1] || B[0] < L[0] || B[1] < L[1]) return 0;
        if (A[0] <= L[0] && R[0] <= B[0] && A[1] <= L[1] && R[1] <= B[1])
            return tree[l][ind[0]][ind[1]];

        int sum = 0;
        int mi = (L[0] + R[0]) / 2;
        int li[] = {L[0], mi + 1};
        int ri[] = {mi, R[0]};

        int mj = (L[1] + R[1]) / 2;
        int lj[] = {L[1], mj + 1};
        int rj[] = {mj, R[1]};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int n_ind[] = {2 * ind[0] + i, 2 * ind[1] + j};
                int n_L[] = {li[i], lj[j]};
                int n_R[] = {ri[i], rj[j]};
                sum += segment_recurs(A, B, l + 1, n_ind, n_L, n_R);
            }
        }

        return sum;
    }

   public:
    SegmentTree(int n) {
        size = 1;
        LEVEL = 1;
        while (size < n) {
            LEVEL++;
            size *= 2;
        }
        tree = vt(vt(vt(int)))(LEVEL);
        int sz = 1;
        for (int i = 0; i < LEVEL; ++i) {
            tree[i] = vt(vt(int))(sz, vt(int)(sz));
            sz *= 2;
        }
    }

    void build(vt(vt(int)) & a) {
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < (int)a[i].size(); ++j) {
                tree[LEVEL - 1][i][j] = a[i][j];
            }
        }

        int tmp_size = size;
        for (int l = LEVEL - 2; l >= 0; --l) {
            tmp_size /= 2;
            for (int i = 0; i < tmp_size; ++i)
                for (int j = 0; j < tmp_size; ++j)
                    for (int i_delta = 0; i_delta < 2; ++i_delta)
                        for (int j_delta = 0; j_delta < 2; ++j_delta)
                            tree[l][i][j] +=
                                tree[l + 1][2 * i + i_delta][2 * j + j_delta];
        }
    }

    int evaluate(int A[], int B[]) {
        int ind[] = {0, 0};
        int L[] = {0, 0};
        int R[] = {size - 1, size - 1};

        return segment_recurs(A, B, 0, ind, L, R);
    }
};

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    cout.tie(MONKE);
    // todo
    int n, q;
    cin >> n >> q;
    vt(vt(int)) a(n, vt(int)(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char t;
            cin >> t;
            a[i][j] = (t == '*');
        }
    }

    vt(vt(int)) dp(n, vt(int)(n));
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) dp[i][0] = a[i][0] + dp[i - 1][0];
    for (int j = 1; j < n; ++j) dp[0][j] = a[0][j] + dp[0][j - 1];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    auto get = [&](int x, int y) {
        if (x >= 0 && y >= 0) return dp[x][y];
        return 0;
    };

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        cout << get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) +
                    get(x1 - 1, y1 - 1)
             << "\n";
    }

    return MONKE;
}