#include <iostream>
#include <vector>

// Hàm duyệt một thành phần liên thông bằng DFS
void explore(const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            explore(graph, visited, neighbor);
        }
    }
}

// Hàm đếm số lượng thành phần liên thông trong đồ thị
int countConnectedComponents(const std::vector<std::vector<int>> &graph, int n) {
    std::vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++components;
            explore(graph, visited, i);
        }
    }

    return components;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::cout << countConnectedComponents(graph, n) << '\n';

    return 0;
}
