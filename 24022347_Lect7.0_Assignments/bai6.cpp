#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0;
    // tách số cuối cùng 
    int digit = n % 10;
    // loại chữ số cuối cùng 
    n /= 10;
    return digit + sum(n);
}

int main() {
    int n; cin >> n;
    cout << sum(n);

    return 0;
}