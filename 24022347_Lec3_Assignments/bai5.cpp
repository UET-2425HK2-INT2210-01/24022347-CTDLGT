#include <iostream>

using namespace std;

int n = 0, stack[10001];

void push(int x) {
    stack[n] = x;
    n++;
} // O(1)

void pop() {
    if (n >= 1)
    n--;
} // O(1)

int top() {
    return stack[n];
} // O(1)

void print() {
    for (int i = 0; i <= n; i++) {
        cout << stack[i];
    }
} // O(n)

int main() {
    int n; 
    cin >> n;
    int x;
    string require;
    for (int i = 0; i < n; i++) {
        cin >> require;
    if (require == "push") {
        cin >> x;
        push(x);
    }else{
        pop();
    }
}
print();
    return 0;
}