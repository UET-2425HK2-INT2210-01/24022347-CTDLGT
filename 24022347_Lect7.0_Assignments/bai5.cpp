#include <iostream>
using namespace std;

int count(int n) {
    // thoát đệ quy 
    if (n == 0) return 0;
    // giảm 1 chữ số 
    n /= 10;
    return count(n) + 1;
}

int main() {
    int n; cin >> n;
    cout << count(n);

    return 0;
}