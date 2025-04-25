#include <iostream>
#include <cmath>
using namespace std;

// Hàm đệ quy để đảo ngược số nguyên n
int reverseNumber(int n) {
    if (n < 10) return n; // Nếu chỉ còn 1 chữ số, trả về chính nó

    int original = n;
    int digits = 0;

    // Đếm số chữ số của n
    while (original != 0) {
        original /= 10;
        ++digits;
    }

    int lastDigit = n % 10;
    // Nhân chữ số cuối với 10^(digits - 1) rồi cộng với phần còn lại đảo ngược
    return lastDigit * pow(10, digits - 1) + reverseNumber(n / 10);
}

int main() {
    int number;
    cin >> number;

    cout << reverseNumber(number);

    return 0;
}
