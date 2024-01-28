// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

string flip(int x, int y, string str){
    for (int i = x; i <= y; i++){
        str[i] = (str[i] == 'G') ? 'H' : 'G';
    }
    return str;
}

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n; cin >> n;
    string wanted, actual; cin >> wanted >> actual;
    
    int ans = 0;
    while (wanted.compare(actual) != 0){
        for (int i = n - 1; i >= 0; i--){
            if (wanted[i] != actual[i]){
                for (int j = i; j >= 0; j--){
                    if (j == 0 && wanted[j] != actual[j]){
                        actual = flip(j, i, actual);
                        ans++;
                        break;
                    }
                    if (wanted[j] != actual[j] && wanted[j - 1] == actual[j - 1]){
                        actual = flip(j, i, actual);
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
