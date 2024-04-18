#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> machine_times(n);

	for (int i = 0; i < n; i++)
		cin >> machine_times[i];

	sort(machine_times.begin(), machine_times.end());

	long long low = 0, high = 1e18, ans = 1e18;

	// Binary search from 0 to 1e18
	while (low <= high){
		// Middle element of the range
		long long mid = (low + high) / 2, products = 0;

		// How many products can you make in this time?
		// 1e9 is the maximum amount of products to make, so anything above would be overflow
		for (int i = 0; i < n; i++)
			products += min(mid / machine_times[i], (long long) 1e9);
		
		// Valid time to make less than or equal to the number of products
		if (products >= k){
			if (mid < ans) // Find the minimum time, so keep updating
				ans = mid;
			high = mid - 1; // Range down
		} else low = mid + 1; // Range up
	}

	cout << ans << endl;
}

