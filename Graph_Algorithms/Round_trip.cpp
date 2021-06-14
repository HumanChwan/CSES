#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<vector<int>> road;
vector<bool> visited;
int start_city = -1;
bool add = false;
vector<int> Path;

void findCircle(int root, int parent = -1) {
    visited[root] = true;
    for(int x: road[root]) {
        if(x == parent)
            continue;
        if(visited[x]) {
            start_city = x;
            add = true;
            Path.push_back(x);
            break;
        }
        findCircle(x, root);
        if(start_city != -1) 
            break;
    }
    if(add) {
        Path.push_back(root);
        add &= root != start_city;
    }
    
}

int main(){
    ios_base::sync_with_stdio(MONKE); //unsync uWu
    cin.tie(MONKE); //cin-cout unsync uWu
    cin >> n >> m;
    road.resize(n+1);
    visited.resize(n+1);
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        road[x].push_back(y);
        road[y].push_back(x);
    } 
    for(int i = 1; i <= n; ++i) {
        if(visited[i])
            continue;
        findCircle(i);
        if(start_city != -1) {
            break;
        }
    }
    if(start_city == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << Path.size() << endl;
        for(int x: Path) 
            cout << x << " ";
    }
    return MONKE;
}