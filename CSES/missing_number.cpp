#include <bits/stdc++.h>
using namespace std;
 
int main(void){
    int n; cin >> n;
    vector<int> v(n - 1);
    
    for (int i = 0; i < n - 1; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 1; i < n - 1; i++){
        if (v[i] - v[i - 1] > 1) {
            cout << v[i - 1] + 1 << endl;
            return 0;
        }
    }
 
    if (v[n - 2] != n) cout << n << endl;
    else if (v[0] != 1) cout << 1 << endl;
}
