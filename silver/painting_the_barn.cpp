#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	int map[1002][1002];

	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++){
			map[j][x1]++;
			map[j][x2]--;
		}
	}

	int ans = 0;
	for (int i = 0; i < 1000; i++){
		int factor = 0;
		for (int j = 0; j < 1000; j++){
			factor += map[i][j];
			if (factor == k) ans++;
		}
	}

	cout << ans << endl;
}
