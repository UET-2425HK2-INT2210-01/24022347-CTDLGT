#include <iostream>
using namespace std;

// Hàm đệ quy tính ước chung lớn nhất theo thuật toán Euclid
int findGCD(int x, int y) {
    if (x == 0) return y;           // Trường hợp cơ sở: nếu x là 0, GCD là y
    return findGCD(y % x, x);       // Gọi đệ quy với phần dư và x
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;           // Nhập hai số nguyên từ bàn phím

    // In ra GCD của hai số
    cout << findGCD(num1, num2) << endl;

    return 0;
}