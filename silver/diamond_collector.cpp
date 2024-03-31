#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<int> dist(n);
	int y = 0; // 2 pointers
	for (int i = 0; i < n; i++) { // Go through all positions
		while (y < n && v[y] - v[i] <= k) y++; // Search for the next diamond that satisfies the constraints
		dist[i] = y - i; // Distance from the current to the next diamond
	}

	vector<int> max_val(n + 1); // Prefix sum backwards
	max_val[n] = 0; // Initialise 'dummy' index
	for (int i = n - 1; i >= 0; i--) {
		max_val[i] = max(max_val[i + 1], dist[i]);
	}

	int ans = 0;
	for (int l = 0; l < n; l++) // Find maximum distance
		ans = max(ans, dist[l] + max_val[l + dist[l]]);
	
	cout << ans << endl;
}
