#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
 
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Edge cases
    if (n < 4){ 
        cout << "NO SOLUTION" << endl;
        return 0;
    } else if (n == 5){
        cout << 2 << " " << 4 << " " << 1 << " " << 5 << " " << 3 << endl;
        return 0;
    } else if (n == 4){
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
        return 0;
    }
 
    vector<int> v; // Final vector
 
    if (n % 2 == 1){ // If n is even then add n
        v.push_back(n);
        n--;
    }
 
    for (int i = 1; i < (n / 2) + 1; i++){ // Add from forward and backward
        v.push_back(i);
        v.push_back(i + (n / 2));
    }
 
    for (int val : v) cout << val << " ";
}
