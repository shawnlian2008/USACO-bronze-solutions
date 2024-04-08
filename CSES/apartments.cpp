// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() { // Standard 2 parallel pointers solution
	int n, m, k; cin >> n >> m >> k;

	vector<int> desired(n), sizes(m);
	for (int i = 0; i < n; i++)
		cin >> desired[i];
	for (int i = 0; i < m; i++)
		cin >> sizes[i];

	// Sort the arrays
	sort(desired.begin(), desired.end());
	sort(sizes.begin(), sizes.end());

	int x = 0, y = 0, ans = 0;
	while (x < n && y < m){ // Pointers that determine apartment assignments
		if (abs(desired[x] - sizes[y]) <= k){ // Found a good apartment
			ans++; x++; y++;
		} else if (desired[x] - sizes[y] > k) y++; // Apartment too big, skip current applicant since there will be no suitable apartments
		else x++; // Keep adding until either optimal or greater than
	}

	cout << ans << endl;
}
