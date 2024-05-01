#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Binary Search, Sorting
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<int> v(n); // Locations of haybales

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	int low = 1, high = 1e9, ans = 0; 
	while (low <= high){ // Binary search function
		int mid = low + (high - low) / 2, cow_count = 0; // cow_count: the number of cows needed to detonate all haybales with radius mid

		int blast_position = -1; // Position of each detonating cow
		for (int i = 0; i < n; i++){ 
			if (blast_position == -1 || v[i] > blast_position + mid) { // if the current haybale is out of reach of a detonated cow
				blast_position = v[i] + mid; // Next detonation position
				cow_count++; // Add to the number of cows needed
			}
		}

		if (cow_count > k){ // Over the limit of cows
			low = mid + 1;
		} else {
			ans = mid;
			high = mid - 1;
		}
	}

	cout << ans << endl;
}
