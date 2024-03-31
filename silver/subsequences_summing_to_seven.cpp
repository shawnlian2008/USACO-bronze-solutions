#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() { // Tags: Prefix sums
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    //Take inputs by their sum mod 7
    int n; cin >> n;
    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++){
        cin >> cows[i];
        cows[i] = (cows[i]+cows[i-1])%7;
    }

    // Find the first and last of the same value in the list
    // The cow ids between them must be divisible by 7
    // The difference between the first and last of these index must be the answer
    int ans = 0;
    vector<int> left(7);
    vector<int> right(7);
    for (int i = 1; i <= n; i++){
        right[cows[i]] = i;
    }
    for (int i = n; i > 0; i--){
        left[cows[i]] = i;
    }
    for (int i = 0; i < 7; i++){
        ans = max(ans, right[i]-left[i]);
    }

    //Output
    cout << ans;

    return 0;
}
