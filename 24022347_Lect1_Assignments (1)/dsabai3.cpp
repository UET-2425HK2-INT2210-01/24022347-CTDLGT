#include <bits/stdc++.h>

using namespace std;

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << ucln(a, b);
    return 0;
}