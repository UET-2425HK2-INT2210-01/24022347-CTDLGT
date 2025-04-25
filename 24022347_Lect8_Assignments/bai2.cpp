#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;  // Nhập số lượng phần tử và tổng cần tìm

    vector<int> A(n);  // Mảng chứa độ tuổi các học sinh
    for (int i = 0; i < n; i++) {
        cin >> A[i];  // Nhập từng độ tuổi
    }

    // Mảng dp[i] lưu trạng thái: có thể tạo ra tổng i hay không
    vector<bool> dp(X + 1, false);
    dp[0] = true;  // Tổng bằng 0 luôn có thể tạo được (với tập rỗng)

    // Duyệt qua từng phần tử trong mảng A
    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ X về A[i] để tránh sử dụng lại cùng phần tử nhiều lần
        for (int j = X; j >= A[i]; j--) {
            if (dp[j - A[i]]) {
                dp[j] = true;  // Nếu có thể tạo j - A[i] thì có thể tạo được j
            }
        }
    }

    // Nếu dp[X] là true thì tồn tại tập con có tổng bằng X
    if (dp[X]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
