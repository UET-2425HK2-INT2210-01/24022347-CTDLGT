#include <iostream>
#include <string>
using namespace std;

string currentBits;  // Chuỗi tạm để xây dựng dãy nhị phân

// Hàm đệ quy sinh các xâu nhị phân độ dài n
void generateBinary(int pos, int length) {
    // Điều kiện dừng: đã đủ độ dài
    if (pos > length) {
        cout << currentBits << '\n';
        return;
    }

    // Duyệt qua các ký tự '0' và '1'
    for (char digit = '0'; digit <= '1'; ++digit) {
        currentBits.push_back(digit);           // Thêm ký tự vào cuối chuỗi
        generateBinary(pos + 1, length);        // Gọi đệ quy cho vị trí tiếp theo
        currentBits.pop_back();                 // Quay lui: xóa ký tự cuối
    }
}

int main() {
    int n;
    cin >> n;

    currentBits = "";          // Khởi tạo chuỗi rỗng ban đầu
    generateBinary(1, n);      // Bắt đầu từ vị trí 1 đến n

    return 0;
}
