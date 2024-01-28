#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> rounds(n);
	for (int i = 0; i < n; i++){
		cin >> rounds[i].first >> rounds[i].second;
	}

	int maximum = -101;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			for (int k = 1; k <= 3; k++){
				if (i == j || j == k || i == k) 
					continue;
				
				int hoof = i, paper = j, scissors = k, points = 0;
				for (int p = 0; p < n; p++){
					if (rounds[p].first == rounds[p].second)
						continue;
					if (rounds[p].first == hoof && rounds[p].second == scissors ||
						rounds[p].first == scissors && rounds[p].second == paper || 
						rounds[p].first == paper && rounds[p].second == hoof){
						points++;
					}
				}
				
				maximum = max(points, maximum);
			}
		}
	}

	cout << maximum << endl;
}
