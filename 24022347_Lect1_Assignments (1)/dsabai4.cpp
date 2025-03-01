#include <bits/stdc++.h>

using namespace std;
 
void sapxep(vector<int> &a){
    sort(a.begin(), a.end());
    for(size_t i = 0; i < a.size(); i++ ){
        cout << a[i] << " ";
    }
}
int main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sapxep(a);
    return 0;
}