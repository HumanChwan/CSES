#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<vector<char>> grid;
vector< pair<int, int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> minLength;
vector<vector<int>> path;
vector<vector<bool>> visited;

bool ok(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

int main(){
    // ios_base::sync_with_stdio(MONKE); //unsync uWu
    // cin.tie(MONKE); //cin-cout unsync uWu
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    minLength.resize(n, vector<int>(m, n*m));
    visited.resize(n, vector<bool>(m));
    pair<int, int> A;
    queue<pair<int,int>> parent, child;
    int depth = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                A = {i, j};
            else if(grid[i][j] == 'M') {
                parent.push({i, j});
                minLength[i][j] = depth;
                visited[i][j] = true;
            }
        }
    }
    depth++;
    while(!parent.empty()) {
        pair<int, int> cell = parent.front();
        parent.pop();
        int i = cell.first;
        int j = cell.second;
        for(pair<int, int> go: dir) {
            int ni = i + go.first;
            int nj = j + go.second;
            if(!ok(ni, nj))
                continue;
            if(visited[ni][nj])
                continue;
            if(grid[ni][nj] == '#')
                continue;
            child.push({ni,nj});
            visited[ni][nj] = true;
            minLength[ni][nj] = depth;
        }
        if(parent.empty()) {
            swap(child, parent);
            depth++;
        }
    }
    assert(parent.empty() && child.empty());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    parent.push(A);
    depth = 1;
    visited[A.first][A.second] = true;
    pair<int, int> End = {-1, -1};
    path.resize(n, vector<int>(m, n*m));
    path[A.first][A.second] = 0;
    while(!parent.empty()) {
        pair<int, int> cell = parent.front();
        parent.pop();
        int i = cell.first;
        int j = cell.second;
        if(i == 0 || i == n-1 || j == 0 || j == m-1) {
            End = {i, j};
            break;
        }
        for(pair<int, int> go: dir) {
            int ni = i + go.first;
            int nj = j + go.second;
            if(!ok(ni, nj))
                continue;
            if(visited[ni][nj])
                continue;
            if(depth >= minLength[ni][nj])
                continue;
            if(grid[ni][nj] == '#')
                continue;
            visited[ni][nj] = true;
            path[ni][nj] = depth;
            child.push({ni, nj});
        }
        if(parent.empty()) {
            swap(parent, child);
            depth++;
        }
    }
    if(End.first == -1) {
        cout << "NO";
        return MONKE;
    }
    cout << "YES\n";
    int i = End.first;
    int j = End.second; 
    vector<char> DIR{'D', 'U', 'R', 'L'};
    string directionBoi = "";
    while(grid[i][j] != 'A') {
        for(int d = 0; d < 4; ++d) {
            int ni = i + dir[d].first;
            int nj = j + dir[d].second;
            if(!ok(ni, nj))
                continue;
            if(path[ni][nj]+1 == path[i][j]) {
                directionBoi += DIR[d];
                i = ni;
                j = nj;
                break;
            }
        }
    }
    reverse(all(directionBoi));
    for(char &x: directionBoi) {
        if(x == 'D') x = 'U';
        else if(x == 'U') x = 'D';
        else if(x == 'L') x = 'R';
        else x = 'L';
    }
    cout << path[End.first][End.second] << endl;
    cout << directionBoi;
    return MONKE;
}