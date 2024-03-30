#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: 2d prefix sums
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<vector<long long>> map(2 * n - 1, vector<long long>(2 * n - 1, 0)); // This will be the 2d array that will hold the given field as a easily-processed square

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			cin >> map[i + j][n - i + j - 1]; // Read into the correct grid
		}
	}

	vector<vector<long long>> prefix_sums(2 * n, vector<long long>(2 * n, 0));

	for (int i = 1; i <= 2 * n - 1; i++){
		for (int j = 1; j <= 2 * n - 1; j++){
			prefix_sums[i][j] = prefix_sums[i - 1][j] + prefix_sums[i][j - 1] - 
				prefix_sums[i - 1][j - 1] + map[i - 1][j - 1];
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= 2 * n - 1; i++){
		for (int j = 1; j <= 2 * n - 1; j++){
			long long sums = prefix_sums[min(i + k, 2 * n - 1)][min(j + k, 2 * n - 1)] - 
				prefix_sums[max(i - k - 1, 1)][min(j + k, 2 * n - 1)] - 
				prefix_sums[min(i + k, 2 * n - 1)][max(j - k - 1, 1)] + 
				prefix_sums[max(i - k - 1, 1)][max(j - k - 1, 1)];
			ans = max(ans, sums); // Run 2d prefix sums and calculate the maximum number of points that can be earnt at each spot (brute force)
		}
	}

	cout << ans << endl;
}
