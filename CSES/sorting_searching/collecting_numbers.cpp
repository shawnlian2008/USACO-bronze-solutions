#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> positions(n); // Hold positions of all numbers at each index
	for (int i = 0; i < n; i++){
		int num; cin >> num;
		positions[--num] = i; // Set the position of the number given
	}

	int ans = 1;
	for (int i = 1; i < n; i++){
		if (positions[i] < positions[i - 1]) // If the number before the previous number (cannot go back so add to answer)
			ans++;
	}

	cout << ans << endl;
}
