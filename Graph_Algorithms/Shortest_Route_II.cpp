#include <iostream>

constexpr int MONKE = 0;
constexpr long long INF = 1e16;

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    long long dist[n + 1][n + 1];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) 
            dist[i][j] = INF;

    while (m--) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        c = std::min(dist[a][b], c);
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }

    return MONKE;
}