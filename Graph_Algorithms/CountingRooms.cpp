#include <bits/stdc++.h>

#define MONKE 0
#define vt(x) vector < x >
#define p(x, y) pair < x, y >
#define M 1000000007

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int i, int j) {
    return  (0 <= i && i < n && 0 <= j && j < m);
}

void dfs(int i, int j) {
    visited[i][j] = true;
    for(pair<int, int> dirXY: dir) {
        int ni = i + dirXY.first;
        int nj = j + dirXY.second;
        if(!ok(ni, nj)) 
            continue;
        if(grid[ni][nj] == '#')
            continue;
        if(visited[ni][nj])
            continue;
        dfs(ni, nj);
    }
}

int main(){
    ios_base::sync_with_stdio(MONKE); //unsync uWu
    cin.tie(MONKE); //cin-cout unsync uWu
    cin >> n >> m;
    grid.resize(n);
    visited.resize(n, vector<bool>(m));
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int rooms = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(visited[i][j]) 
                continue;
            if(grid[i][j] == '#')
                continue;
            rooms++;
            dfs(i, j);
        }
    }
    cout << rooms;
    return MONKE;
}