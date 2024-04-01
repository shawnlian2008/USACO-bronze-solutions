#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: 2 pointers
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	vector<int> v(n); // Holds all the cows' positions
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end()); // Sort positions in ascending order

	int min_ans = 0;
	if ((v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2) || 
		(v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2)){ // Edge cases: if a cow on either edge is the only cow that has to be moved closer
		min_ans = 2;
	} else {
		int y = 0, range = 0;
		for (int i = 0; i < n; i++){
			while (y < n - 1 && v[y + 1] - v[i] <= n - 1)
				y++;
			range = max(range, y - i + 1);  // Find the largest range of positions on the number line field
		}
		min_ans = n - range; // Answer will be the smallest number of cows not in the range
	}
	cout << min_ans << "\n" << max(v[n - 2] - v[0], v[n - 1] - v[1]) - (n - 2) << endl;
}
