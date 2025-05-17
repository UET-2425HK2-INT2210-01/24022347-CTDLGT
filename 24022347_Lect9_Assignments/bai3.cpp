#include <iostream>
#include <vector>

// Hàm đệ quy giải bài toán Knapsack 0/1
int getMaxValue(int capacity, const std::vector<int> &values, const std::vector<int> &weights, int n) {
    if (n == 0 || capacity == 0)
        return 0;

    int include = 0;

    if (weights[n - 1] <= capacity)
        include = values[n - 1] + getMaxValue(capacity - weights[n - 1], values, weights, n - 1);

    int exclude = getMaxValue(capacity, values, weights, n - 1);

    return std::max(include, exclude);
}

int main() {
    int n, X;
    std::cin >> n >> X;

    std::vector<int> weights(n), values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
    }

    std::cout << getMaxValue(X, values, weights, n) << '\n';

    return 0;
}
