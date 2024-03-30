#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: greedy
	// Greedy algorithm: Add cows in by largest wait limit, so that the cows with the smallest wait limit will go away after all the largest wait-time cows are in line
  	freopen("lemonade.in", "r", stdin);
  	freopen("lemonade.out", "w", stdout);
	int n; cin >> n;
	vector<int> w(n); // Wait limit of all the cows
	for (int i = 0; i < n; i++)
		cin >> w[i];

	// Sort by wait limit from largest to smallest
	sort(w.rbegin(), w.rend());

	vector<int> line; // Hold all the cows that were ever in line
	for (int i = 0; i < n; i++){
		if (w[i] < line.size()) // If number of cows in line exceeds wait limit
			continue;
		else line.push_back(i); // If number of cows in line is less than or equal to wait limit
	}

	cout << line.size() << endl; // Line size
}
