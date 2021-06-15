#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
int n;
vector<pair<int, int>> dir{{1, 0}, {0, 1}};
int numberOfPathsFrom[1000][1000];
vector<vector<bool>> goodPath, visited;
vector<vector<char>> grid;

bool ok(int i, int j) { return (0 <= i && i < n && 0 <= j && j < n); }

void makeAvailable(int i, int j) {
    goodPath[i][j] = true;
    for (pair<int, int> dirXY : dir) {
        int ni = i - dirXY.first;
        int nj = j - dirXY.second;

        if (!ok(ni, nj)) continue;

        if (grid[ni][nj] == '*') continue;

        if (goodPath[ni][nj]) continue;

        makeAvailable(ni, nj);
    }
}

long long CountGoodPath(int i, int j) {
    if (grid[i][j] == '*') {
        return 0LL;
    }

    if (i == n - 1 && j == n - 1) {
        return 1LL;
    }

    if (visited[i][j]) {
        return numberOfPathsFrom[i][j];
    }

    if (!goodPath[i][j]) return 0LL;

    visited[i][j] = true;

    numberOfPathsFrom[i][j] = 0LL;

    for (pair<int, int> dirXY : dir) {
        int ni = i + dirXY.first;
        int nj = j + dirXY.second;

        if (!ok(ni, nj)) continue;

        numberOfPathsFrom[i][j] =
            (numberOfPathsFrom[i][j] + CountGoodPath(ni, nj)) % M;
    }

    return numberOfPathsFrom[i][j];
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    cin >> n;
    grid.resize(n, vector<char>(n));
    goodPath.resize(n, vector<bool>(n));
    visited.resize(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    makeAvailable(n - 1, n - 1);
    cout << CountGoodPath(0, 0);
    return MONKE;
}