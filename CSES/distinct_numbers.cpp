#include <bits/stdc++.h>
using namespace std;
 
int main(void){
    int n; cin >> n;
    set<int> s; // Sets hold distinct numbers
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        s.insert(a);
    }
 
    cout << s.size() << endl;
}
