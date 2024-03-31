#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() { // Tags: 2 pointers, greedy, custom sorting
	// Greedy algorithm: Try to pair up the cows that take the least amount of time possible with the cows that take the most amount of time that there is
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> v(n); // {number of cows, milking time}
	for (int i = 0; i < n; i++) 
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end(), [](pair<int, int> &x, pair<int, int> &y){ // Sort by milking time
		return x.second < y.second;
	});

	int x = 0, y = v.size() - 1; // Set the 2 pointers, one to the smallest and one to the largest
	int minimum_time = INT_MIN;
	
	while (true){
		int f1 = v[x].first, f2 = v[y].first; // Numbers of cows at both pointers
		v[x].first -= min(f1, f2); // Subtract the least from both sides
		v[y].first -= min(f1, f2);

		minimum_time = max(minimum_time, v[y].second + v[x].second); // The minimum time would actually be the maximum of times so far, since we've already sorted the values, and we're trying to figure out the pair that takes the longest time, since the total time depends only on them

		// Move each pointer accordingly
		if (v[x].first == 0) x++;
		if (v[y].first == 0) y--;

		if (x == y - 1 || x == y) { // Breaking case
			if (x == y && v[x].first != 0)
				minimum_time = max(minimum_time, v[x].second * 2); // Whatever is left over on the stopping element
			else {
				if (v[x].first > 0){
					minimum_time = max(minimum_time, v[x].second * 2); // What is left over on the 2 stopping elements
				} else {
					minimum_time = max(minimum_time, v[y].second * 2);
				}
			}
			break;
		}
	}

	cout << minimum_time << endl;
}
