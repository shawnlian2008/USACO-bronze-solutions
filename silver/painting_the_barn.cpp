#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Cumulative and running vector sum
	int n, k; cin >> n >> k;

	int map[1002][1002]; // Store the field

	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		// Add or subtract all values so that there may be a cumulative value running through the field
		for (int j = y1; j < y2; j++){
			map[j][x1]++;
			map[j][x2]--;
		}
	}

	int ans = 0;
	for (int i = 0; i < 1000; i++){
		int factor = 0; // Cumulative value
		for (int j = 0; j < 1000; j++){
			factor += map[i][j];
			if (factor == k) ans++; // If cumulative value is optimal
		}
	}

	cout << ans << endl;
}
