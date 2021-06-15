#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    // ios_base::sync_with_stdio(MONKE); //unsync uWu
    // cin.tie(MONKE); //cin-cout unsync uWu
    int n, m;
    ifstream bobux("bobux.txt");
    bobux >> n >> m;
    vector<vector<pair<int, ll>>> city(n+1);
    vector<bool> visited(n+1);
    ll a, b, d;
    for(int i = 0; i < m; ++i) {
        bobux >> a >> b >> d;
        city[a].push_back({b, d});
    }   
    // priority_queue<pair<int, int>, vector<int>, greater<pair<int, int>>> route;
    multiset<pair<ll, int>> route;
    vector<ll> dist(n+1, (ll)1e14 + 5);
    route.insert({0, 1});
    dist[1] = 0;
    while(!route.empty()) {
        pair<ll, int> data = *route.begin();
        route.erase(route.begin());
        int parent = data.second;
        // int distance = data.first;
        visited[parent] = true;
        for(pair<int, ll> child: city[parent]) {
            if(dist[child.first] > dist[parent] + child.second) {
                dist[child.first] = child.second + dist[parent];
                if(!visited[child.first])
                    route.insert({dist[child.first], child.first});
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return MONKE;
}