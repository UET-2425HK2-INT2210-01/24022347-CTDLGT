#include <iostream>
#include <vector>

// Hàm kiểm tra có tồn tại tập con có tổng bằng x không
bool isSubsetSum(const std::vector<int> &num, int x, int n, std::vector<std::vector<int>> &memo) {
    if (x == 0) return true;     // Nếu tổng cần tìm là 0 thì luôn đúng
    if (n == 0) return false;    // Không còn phần tử nào để chọn

    if (memo[n][x] != -1) return memo[n][x];  // Trả về nếu đã tính trước đó

    if (num[n - 1] > x) {
        memo[n][x] = isSubsetSum(num, x, n - 1, memo);  // Bỏ qua phần tử nếu lớn hơn x
    } else {
        // Thử cả hai trường hợp: chọn hoặc không chọn phần tử hiện tại
        memo[n][x] = isSubsetSum(num, x, n - 1, memo) || isSubsetSum(num, x - num[n - 1], n - 1, memo);
    }

    return memo[n][x];
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> num(n);
    for (int &v : num) {
        std::cin >> v;
    }

    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(x + 1, -1));

    if (isSubsetSum(num, x, n, memo)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
