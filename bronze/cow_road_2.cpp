// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = i + 1; j < s.length(); j++)
            for (int k = j + 1; k < s.length(); k++)
                for (int l = k + 1; l < s.length(); l++)
                    if (s[i] == s[k] && s[j] == s[l])
                        ans++;

    cout << ans << endl;
}
