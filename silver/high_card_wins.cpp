// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	int n; cin >> n;
	vector<int> e(n); // Elsie's cards
	map<int, bool> used; // Determine which cards Bessie gets from Elsie's cards
	multiset<int> b;
	for (int i = 0; i < n; i++){
		cin >> e[i];
		used[e[i]] = true;
	}

	for (int i = 1; i <= 2 * n; i++)
		if (!used[i])
			b.insert(i); // Bessie gets all the other cards that Elsie doesn't get from 1 to 2 * n

	sort(e.begin(), e.end()); // Sort Elsie's cards

	int ans = 0;
	for (int i = 0; i < e.size(); i++){ // Go through all of Elsie's cards
		auto it = b.upper_bound(e[i]); // Lowest card that is larger than Elsie's current card

		if (it == b.end()){ // No possible win for Bessie this round, because there are no cards larger than Elsie's
			b.erase(b.begin()); // Use the worst card, or smallest card that Bessie has
		} else {
			ans++;
			b.erase(it); // Remove the lowest card larger than Elsie's current card
		}
	}

	cout << ans << endl;
}
