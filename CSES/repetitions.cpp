#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s; cin >> s;
 
    int longest_perm = 1, perm = 1;
    for (int i = 1; i < s.length(); i++){
        if (s[i] != s[i - 1]){
            longest_perm = max(longest_perm, perm);
            perm = 1;
        } else perm++;
    }
 
    longest_perm = max(longest_perm, perm);
 
    cout << longest_perm << endl;
}
