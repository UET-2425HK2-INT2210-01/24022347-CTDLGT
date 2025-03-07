#include <iostream>
 
using namespace std;

int nhan1(int a) {  
    long long dem = 1;
    for (int i = 0; i < a; i++) {
        dem *= 2;
    }
    return dem;
} // O(n)

int nhan2(int a) {
    if (a == 0){
        return 0;
    }
    if (a < 0) {
        return -2 + nhan2(a + 1);
    }else{
        return 2 + nhan2(a - 1);
    }
} // O(n)

int main() {
    int n;
    cin >> n;
    cout << nhan2(n);
    return 0;
}