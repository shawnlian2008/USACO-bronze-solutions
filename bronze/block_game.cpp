#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n; cin >> n;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    vector<int> ans(26, 0);
    for (int i = 0; i < n; i++){
        vector<int> b1(26), b2(26);
        for (int j = 0; j < v[i].first.size(); j++)
            b1[v[i].first[j] - 'a']++;
        for (int j = 0; j < v[i].second.size(); j++)
            b2[v[i].second[j] - 'a']++;
        
        for (int j = 0; j < 26; j++)
            ans[j] += max(b1[j], b2[j]);
    }

    for (int i : ans)
        cout << i << endl;
    
    return 0;
}
