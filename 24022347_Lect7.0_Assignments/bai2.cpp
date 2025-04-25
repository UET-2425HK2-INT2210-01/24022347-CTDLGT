#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của một số nguyên n
long long computeFactorial(int n) {
    if (n == 0) return 1;               // Quy ước: 0! = 1
    return n * computeFactorial(n - 1); // Công thức đệ quy: n! = n * (n-1)!
}

int main() {
    int number;
    cin >> number;                      // Nhập số nguyên n

    cout << computeFactorial(number);   // In ra n!

    return 0;
}
