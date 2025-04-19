#include <iostream>
#include <string>
#include <vector>
using namespace std;

string currentPermutation;       // Chuỗi hiện tại chứa hoán vị
vector<bool> isUsed;             // Đánh dấu số đã dùng hay chưa

// Hàm đệ quy sinh các hoán vị của 1..n
void generatePermutation(int pos, int total) {
    // Điều kiện dừng: đã chọn đủ 'total' số
    if (pos > total) {
        cout << currentPermutation << '\n';
        return;
    }

    // Thử từng số từ 1 đến total
    for (int i = 1; i <= total; ++i) {
        if (!isUsed[i]) {
            isUsed[i] = true;                              // Đánh dấu đã dùng
            currentPermutation += to_string(i);            // Thêm số vào chuỗi
            generatePermutation(pos + 1, total);           // Đệ quy cho vị trí tiếp theo
            currentPermutation.pop_back();                 // Quay lui
            isUsed[i] = false;                             // Bỏ đánh dấu
        }
    }
}

int main() {
    int n;
    cin >> n;

    currentPermutation = "";                // Bắt đầu với chuỗi rỗng
    isUsed.assign(n + 1, false);            // Khởi tạo vector đánh dấu

    generatePermutation(1, n);              // Gọi hàm sinh hoán vị

    return 0;
}