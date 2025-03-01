#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a(5);
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }
    int min = *min_element(a.begin(), a.end());
    int max = *max_element(a.begin(), a.end());
    cout << max + min;
    return 0;
}