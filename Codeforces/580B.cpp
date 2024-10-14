#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<pair<long long, long long>> v(n); // Vector of pairs in format {money, relationship factor}
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end()); // Sort by money amount

	long long ans = 0, prefix_sum = 0, money_diff = v[0].first;
	int x = 0, y = 0;
	while (y < n){ // Parallel 2 pointers
		prefix_sum += v[y].second; // Add relationship factor
		while (v[y].first - money_diff >= k){ // If the money difference is greater than allowed
			prefix_sum -= v[x].second; // Subtract from first element
			x++; // Increment x
			money_diff = v[x].first; // Increment money_diff after incrementing x, as money_diff is initially set to the first person's amount of money (after sorting)
		}
		ans = max(ans, prefix_sum); // Find max answer
		y++; // Increment right pointer
	}
	cout << ans << "\n";
}
