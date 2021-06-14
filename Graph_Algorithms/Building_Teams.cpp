#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<vector<int>> frens;
bool possible = true;
vector<bool> visited;
vector<bool> Team;

void teamDFS(int root, bool team) {
    if(visited[root]) {
        if(Team[root] ^ team) {
            possible = false;
        }
        return;
    }
    visited[root] = true;
    Team[root] = team;
    for(int x: frens[root]) {
        teamDFS(x, !team);
    }
}

int main(){
    ios_base::sync_with_stdio(MONKE); //unsync uWu
    cin.tie(MONKE); //cin-cout unsync uWu
    cin >> n >> m;
    frens.resize(n+1);
    visited.resize(n+1);
    Team.resize(n+1);
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        frens[x].push_back(y);
        frens[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        if(visited[i])
            continue;
        teamDFS(i, true);
    }
    if(!possible) {
        cout << "IMPOSSIBLE";
    } else {
        for(int i = 1; i <= n; ++i) {
            cout << (int)Team[i]+1 << " ";
        }
    }
    return MONKE;
}