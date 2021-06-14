#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    ios_base::sync_with_stdio(MONKE); //unsync uWu
    cin.tie(MONKE); //cin-cout unsync uWu
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<vector<int>> connections(n+1);
    vector<int> Depth(n+1, -1);
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }
    queue<int> parent, child;
    int depth = 0;
    Depth[1] = depth;
    depth++;
    parent.push(1);
    vector<bool> visited(n+1);
    visited[1] = true;
    while(!parent.empty()) {
        int root = parent.front();
        parent.pop();
        for(int x: connections[root]) {
            if(visited[x])
                continue;
            child.push(x);
            visited[x] = true;
            Depth[x] = depth;
        }
        if(parent.empty()) {
            swap(child, parent);
            depth++;
        }
    } 
    if(Depth[n] == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << Depth[n]+1 << endl;
        vector<int> path;
        int root = n;
        path.push_back(root);
        while(root != 1) {
            int TempRoot = root;
            for(int x: connections[TempRoot]) {
                if(Depth[x]+1 == Depth[TempRoot]) {
                    root = x;
                    break;
                }
            }
            path.push_back(root);
        }
        reverse(all(path));
        for(int x: path)
            cout << x << " ";
    }
    return MONKE;
}
