#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

vector<vector<int>> permutations;

// make all combinations of dice
void build_seq(vector<int> perm) {
	if ((int)(perm.size()) == 4) {
		permutations.push_back(perm);
		return;
	}	
	for (int i = 1; i <= 10; i++) {
		perm.push_back(i);
		build_seq(perm);
		perm.pop_back();
	}
}

// returns true if a beats b
bool beats(vector<int> a, vector<int> b) {
	int wins_a = 0, wins_b = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i] > b[j]) {
				wins_a++;
			} else if (a[i] < b[j]) {
				wins_b++;
			}
		}
	}

	return (wins_a > wins_b);
}

void solve() {
	vector<int> die1(4), die2(4);
	
	for (int i = 0; i < 4; i++) {
		cin >> die1[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> die2[i];
	}

	if (!beats(die1, die2)) {
		swap(die1, die2);
	}
	
	// try every combo of dice
	for (vector<int> die3 : permutations) {
		if (beats(die2, die3) && beats(die3, die1)) {

			cout << "yes" << endl;
			return;
		}
	}

	cout << "no" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	build_seq({});

	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}
}
