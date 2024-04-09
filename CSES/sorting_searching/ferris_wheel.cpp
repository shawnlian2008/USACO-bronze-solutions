#include <bits/stdc++.h>
using namespace std;

int main() { // 2 pointers problem
	// Fill problem: Try to pair the smallest with the largest values, and if there isn't any pair valid for this value, then add to make room for itself
	int n, k; cin >> n >> k;
	vector<int> weights(n);
	map<int, bool> used; // Index to status

	for (int i = 0; i < n; i++)
		cin >> weights[i];

	sort(weights.begin(), weights.end());

	int x = 0, y = n - 1, ans = 0;
	while (x < y){
		// Already used, then skip
		if (used[x]) x++;
    if (used[y]) y--;

		// Increment answers in both
		if (weights[x] + weights[y] <= k){ // Found optimal pair of weights
			ans++;
			used[x] = true; used[y] = true;
			x++; y--; // Move both pointers closer
		} else {
			ans++;
			y--; // Only move y closer
			used[y] = true;
		}
	}

	for (int i = 0; i < n; i++) // Add any unpaired child
		if (!used[i]) ans++;

	cout << ans << endl;
}
