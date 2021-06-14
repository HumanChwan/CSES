#include<bits/stdc++.h>

#define MONKE 0

using namespace std;
int n, m;
vector< vector<char> > grid;
vector< vector<bool> > path, visited;
vector< pair<int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int mxN = 1e3 + 5;
vector<vector<int>> minLength;

bool ok(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

void setPath(int i, int j) {
    path[i][j] = true;
    if(grid[i][j] == 'A')
        return;
    for(pair<int, int> go: dir) {
        int ni = i + go.first;
        int nj = j + go.second;
        if(!ok(ni, nj))
            continue;
        if(grid[ni][nj] == '#')
            continue;
        if(minLength[ni][nj]+1 != minLength[i][j])
            continue;
        setPath(ni, nj);
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    minLength.resize(n, vector<int>(m, -1));
    pair<int, int> A, B;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                A = {i, j};
            else if(grid[i][j] == 'B') 
                B = {i, j};
        }
    }
    // bfs
    queue<pair<int, int>> parent, child;
    visited.resize(n, vector<bool>(m, false));
    parent.push(A);
    int depth = 0;
    visited[A.first][A.second] = true;
    while(!child.empty() || !parent.empty()) {
        int i = parent.front().first;
        int j = parent.front().second;
        parent.pop();
        minLength[i][j] = depth;
        if(grid[i][j] == 'B')
            break;
        for(pair<int, int> go: dir) {
            int ni = i + go.first;
            int nj = j + go.second;
            if(!ok(ni, nj))
                continue;
            if(grid[ni][nj] == '#') 
                continue;
            if(visited[ni][nj])
                continue;
        
            child.push({ni, nj});
            visited[ni][nj] = true;
        }
        if(parent.empty()) {
            if(child.empty()) 
                break;
            swap(parent, child);
            depth++;
        }
    }
    if(minLength[B.first][B.second] != -1) {
        path.resize(n, vector<bool>(m, false));
        // int presentLength = dp[B.first][B.second];
        setPath(B.first, B.second);
        cout << "YES" << endl;
        cout << minLength[B.first][B.second] << endl;
        string directionBoi = "";
        int i = A.first;
        int j = A.second;
        int pI = -1, pJ = -1;
        vector<char> DIR{'D', 'U', 'R', 'L'};
        while(grid[i][j] != 'B') {
            for(int d = 0; d < 4; ++d) {
                int ni = i + dir[d].first;
                int nj = j + dir[d].second;
                if(!ok(ni, nj))
                    continue;
                if(!path[ni][nj]) 
                    continue;
                if(pI == ni && pJ == nj)
                    continue;
                directionBoi += DIR[d];
                pI = i;
                pJ = j;
                i += dir[d].first;
                j += dir[d].second;
                break;
            }
        }
        cout << directionBoi;
    } else {
        cout << "NO";
    }
    return MONKE;
}