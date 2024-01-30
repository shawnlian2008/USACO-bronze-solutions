// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; cin >> n;
    vector<int> hoof(n + 1, 0), paper(n + 1, 0), scissors(n + 1, 0);
    for (int i = 1; i <= n; i++){
        char c; cin >> c;
        hoof[i] = hoof[i - 1];
        paper[i] = paper[i - 1];
        scissors[i] = scissors[i - 1];
        if (c == 'H') hoof[i]++;
        else if (c == 'P') paper[i]++;
        else scissors[i]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++){
        //cout << paper[i] - paper[0] << " ";
        //cout << paper[n] - paper[i] << endl;
        int sum = max(hoof[i] - hoof[0], max(paper[i] - paper[0],
            scissors[i] - scissors[0]));
        sum += max(hoof[n] - hoof[i], max(paper[n] - paper[i],
            scissors[n] - scissors[i]));
        ans = max(ans, (long long)sum);
    }
    
    cout << ans << endl;
}
