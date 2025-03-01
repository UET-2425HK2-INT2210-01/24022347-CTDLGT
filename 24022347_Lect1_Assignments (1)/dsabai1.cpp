#include <bits/stdc++.h>

using namespace std;

void daonguoc(string a){
    reverse(a.begin(), a.end());
    cout << a;
}
int main(){
    string a;
    getline(cin, a);
    daonguoc(a);
    return 0;
}