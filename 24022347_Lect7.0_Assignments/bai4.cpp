#include <iostream>
using namespace std;

long long cal(int x, int n) {
    // TH thoát đệ quy 
    if (n == 0) return 1;
    // chia x^n thành x^(n / 2) * x^(n / 2)
    int half = cal(x, n / 2);
    if (n % 2 == 1) return half * half * x;
    else return half * half;
}

int main() {
    int n, x; cin >> x >> n;
    cout << cal(x, n);

    return 0;
}