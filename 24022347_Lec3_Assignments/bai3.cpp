#include <iostream>

using namespace std;

int a[100000], maxN = 100000;
int n = 0;

int size() {
    return n;
} // O(1)


void push(int x) {
    if(n == maxN){
        return;
    }else{
        a[n] = x;
        n++;
    }
} // O(n)

void pop() {
    if (n == 0) return;
    for (int i = 0; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
} // O(n)

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
} // O(n)

int front() {
    return a[0];
} // O(1)

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