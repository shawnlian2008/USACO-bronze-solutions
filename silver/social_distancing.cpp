#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() { // Tags: Binary Search, sorting
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<pair<ll, ll>> v(m);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end()); // Sort segments by position so that we can go through them later

	ll low = 1, high = 1e18, ans = 0; // Binary search initial variables
	while (low <= high){
		ll mid = low + (high - low) / 2, cow_count = 0; // How many cows can we put down with distance mid

		ll pos = v[0].first; // Positions of each cow we put down
		for (int i = 0; i < m; i++){
			if (cow_count > n) break; // No need to continue if we already know it's gonna work
			if (pos < v[i].first){ // Check if the position after the previous segment fits into the next segment, if it doesn't, then set it to the first position of this current segment
				pos = v[i].first;
			}
			while (true){ // Go through this segment with pos
				if (pos > v[i].second){
					break;
				}
				cow_count++; // Add to cows each time we put a value down
				pos += mid; // Move pos by the social distance (mid)
			}
		}

		if (cow_count < n){ // Move it down
			high = mid - 1;
		} else { // We're trying to find the highest, so we move it up in this instance.
			ans = mid;
			low = mid + 1;
		}
	}

	cout << ans << endl;
}
