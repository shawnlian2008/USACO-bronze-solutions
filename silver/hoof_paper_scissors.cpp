#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Prefix sums
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; cin >> n;
    vector<int> hoof(n + 1, 0), paper(n + 1, 0), scissors(n + 1, 0); // Prefix sums of all the moves that the farmer does
    for (int i = 1; i <= n; i++){
        char c; cin >> c;

        // Initialise all 3 prefix sums indices to be the previous index
        hoof[i] = hoof[i - 1];
        paper[i] = paper[i - 1];
        scissors[i] = scissors[i - 1];

        // Add to the current prefix index according to move type
        if (c == 'H') hoof[i]++;
        else if (c == 'P') paper[i]++;
        else scissors[i]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++){ // Go through all indices
        int sum = max(hoof[i] - hoof[0], max(paper[i] - paper[0],
            scissors[i] - scissors[0])); // Max number of any move before this current index
        sum += max(hoof[n] - hoof[i], max(paper[n] - paper[i],
            scissors[n] - scissors[i])); // Max number of any move after this current index
        ans = max(ans, (long long)sum);
    }
    
    cout << ans << endl;
}
