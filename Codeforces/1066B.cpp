#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r; cin >> n >> r;
    vector<int> a(n + 1), h(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    
	int m, ans = 0;
    // Moral of the programme: go through each index of the entire house, and try to see if every index can be reached by a heater
    for (int i = 1; i <= n; i++) {
        if (h[i] == 1) continue;
		ans++;
        int k = -1;
        m = min(i + r - 1, n);

        // Try to get the heater that is farthest forward within the range limit of this heater
        for (int j = i; j <= m; j++){ // Go through all positions forward to the next limit or n
            if (a[j] == 1) 
                k = j;
        }
        
        // If there is no heater in front of this heater within the range limit
		if (k == -1){
            m = max(1, i - r + 1);

            // Try to get the heater that is right behind this heater within the range
            for (int j = i; j >= m; j--){ // Go through all positions backward to the next limit or 1
                if (a[j] == 1){
                    k = j;
                    break;
                }
            }
        }

        if (k == -1){ // IF there's no heaters within the range both forward and backward, it's impossible
            cout << -1 << endl;
            return 0;
        }

        a[k] = 0; // Deactivate this heater since it's already been used

        // Update the number of heated indices in the house
        m = min(r + k - 1, n);
        for (int j = k; j <= m; j++)
            h[j] = 1;

        m = max(1, k - r + 1);
        for (int j = k; j >= m; j--)
            h[j] = 1;
    }
    cout << ans << endl;
	return 0;
}
