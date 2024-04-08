#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s; cin >> s;
 
    int longest_perm = 1, perm = 1; // Instance Variables
    for (int i = 1; i < s.length(); i++){ // Go through string
        if (s[i] != s[i - 1]){ // Reset
            longest_perm = max(longest_perm, perm); // Running maximum
            perm = 1;
        } else perm++; // Add to the longest permutation
    }
 
    longest_perm = max(longest_perm, perm); // Last sequence of the string
 
    cout << longest_perm << endl;
}
