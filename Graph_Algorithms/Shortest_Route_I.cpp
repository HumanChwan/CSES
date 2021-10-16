#include <iostream>
#include <queue>

constexpr int MONKE = 0;

int main () {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<std::pair<long long, int> > Q;
    std::vector<long long> dist(n + 1, 1e15);
    std::vector<bool> visited(n + 1);
    dist[1] = 0;

    std::vector<std::vector<std::pair<int, long long> > > edge(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }   

    Q.push({0, 1});

    while(!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        if (visited[top.second]) {
            continue;
        }
        visited[top.second] = true;

        for (auto x : edge[top.second]) {
            if (x.second + dist[top.second] < dist[x.first]) {
                dist[x.first] = dist[top.second] + x.second;
                Q.push({-dist[x.first], x.first});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << dist[i] << " ";
    }

    return MONKE;
}