#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> swap;
	vector<int> guesses(n);
	for (int i = 0; i < n; i++){
		int s1, s2; cin >> s1 >> s2;
		s1--; s2--;
		swap.push_back({s1, s2});
		cin >> guesses[i];
		guesses[i]--;
	}

	// all combinations of which shell the pebble is under
	int possible_pts = -1;
	for (int i = 0; i < 3; i++){
		vector<int> shells(3, 0); 
		shells[i] = 1;

		//simulate all guesses
		int points = 0;
		for (int j = 0; j < n; j++){
			int tmp = shells[swap[j].first];
			shells[swap[j].first] = shells[swap[j].second];
			shells[swap[j].second] = tmp;
			points += shells[guesses[j]];
		}

		possible_pts = max(possible_pts, points);
	}

	cout << possible_pts << endl;
}
