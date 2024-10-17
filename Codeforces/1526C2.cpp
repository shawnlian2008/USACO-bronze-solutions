#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	set<pair<int, int>> s;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];

		s.insert({v[i], i}); // Set automatically sorts everything
		sum += v[i];

		cout << sum << endl;

		if (sum < 0) { // As we go along in order, if sum is less than 0, then we remove the potion with the lowest health value.
			pair<int, int> curr = *s.begin();
			cout << "e" << curr.first << endl;
			sum -= curr.first; // Replenish the sum
			s.erase(curr); // Remove the smallest element from the potion count
		}
	}

	cout << s.size() << endl;
}
