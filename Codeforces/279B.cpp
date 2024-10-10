#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t; cin >> n >> t;
	
	vector<int> v(n); // Hold the amounts of times to read each book
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int pfxsm = 0, y = -1, ans = -4; // Use a cumulative integer to count the amount of time to read all books so far
	for (int i = 0; i < n; i++){ // First pointer i
		if (pfxsm + v[i] <= t){ // As long as it is smaller than t
			pfxsm += v[i];		
		} else { // If time exceeds the given time limit for books
			pfxsm += v[i];
			while (pfxsm > t){ // Move y, the second pointer, up 1 from the beginning, to remove a value from the beginning to fit into the times
				y++;
				pfxsm -= v[y];
			}
		}

		ans = max(ans, i - y); // Count max number of books you can put each time to satisfy the time limit given
	}

	cout << ans << endl;
}
