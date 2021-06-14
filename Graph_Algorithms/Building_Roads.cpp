#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007

typedef long long ll;
typedef long double ld;

using namespace std;
int n, m;
vector<bool> coursed;
vector<vector<int>> road;

void courseIT(int root) {
    coursed[root] = true;
    for(int x: road[root]) {
        if(coursed[x])
            continue;
        courseIT(x);
    }
}

int main(){
    ios_base::sync_with_stdio(MONKE); //unsync uWu
    cin.tie(MONKE); //cin-cout unsync uWu
    
    cin >> n >> m;
    road.resize(n+1);
    coursed.resize(n+1);
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        road[x].push_back(y);
        road[y].push_back(x);
    }
    vector<int> unDiscovered;
    for(int i = 1; i <= n; ++i) {
        if(coursed[i]) 
            continue;
        unDiscovered.push_back(i);
        courseIT(i);
    }
    cout << (int) unDiscovered.size() - 1 << endl;
    for(int i = 1 ; i < (int)unDiscovered.size(); ++i) {
        cout << unDiscovered[i-1] << " " << unDiscovered[i] << endl;
    }   
    return MONKE;
}