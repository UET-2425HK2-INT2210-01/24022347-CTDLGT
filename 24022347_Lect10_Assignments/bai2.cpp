#include <iostream>
#include <vector>
#include <queue>

// Hàm tìm đường đi ngắn nhất từ X đến Y trong đồ thị có hướng
int shortestPathBFS(int n, int X, int Y, const std::vector<std::vector<int>> &graph) {
    if (X == Y) return 0;

    std::queue<int> bfsQueue;
    std::vector<int> distances(n + 1, -1);

    distances[X] = 0;
    bfsQueue.push(X);

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();

        for (int neighbor : graph[current]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                if (neighbor == Y) return distances[neighbor];
                bfsQueue.push(neighbor);
            }
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int n, m, X, Y;
    std::cin >> n >> m >> X >> Y;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v); // đồ thị có hướng
    }

    std::cout << shortestPathBFS(n, X, Y, graph) << '\n';

    return 0;
}
