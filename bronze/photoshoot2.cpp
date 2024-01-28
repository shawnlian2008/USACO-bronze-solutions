#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> wanted(n), actual(n);
    for (int i = 0; i < n; i++)
        cin >> wanted[i];
    for (int i = 0; i < n; i++)
        cin >> actual[i];

    // go through each sequence backwards
    int ans = 0;
    while (true){
        if (wanted == actual)
            break;
        
        for (int i = n - 1; i >= 0; i--){
            if (wanted[i] == actual[i])
                continue;
            
            for (int j = i - 1; j >= 0; j--){
                if (wanted[i] == actual[j]){
                    int value = actual[j];
                    actual.erase(actual.begin() + j);
                    actual.insert(actual.begin() + i, value);
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
