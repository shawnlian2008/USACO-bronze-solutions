#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<string> spotty(n);
    for (int i = 0; i < n; i++)
        cin >> spotty[i];

    vector<string> normal(n);
    for (int i = 0; i < n; i++)
        cin >> normal[i];

    vector<int> diff;

    for (int i = 0; i < m; i++){
        vector<bool> exists1(26, false);
        vector<bool> exists2(26, false);
        for (int j = 0; j < n; j++){
            exists1[spotty[j][i] - 'A'] = true;
            exists2[normal[j][i] - 'A'] = true;
        }

        bool indicator = true;
        for (int j = 0; j < 26; j++){
            if (exists1[j] == true && exists2[j] == true){
                indicator = false;
            }
        }
        if (indicator)
            diff.push_back(i);
    }

    cout << diff.size() << endl;
}
