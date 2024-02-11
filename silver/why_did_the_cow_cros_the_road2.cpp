#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n, k, b; cin >> n >> k >> b;
	vector<int> broken(n + 1, 0);
	for (int i = 0; i < b; i++){
		int broken_index; cin >> broken_index;
		broken[broken_index] = 1;
	}

	vector<int> num_broken(n + 1, 0);

	for (int i = 1; i <= n; i++)
		num_broken[i] = num_broken[i - 1] + broken[i];

	int ans = INT_MAX;
	for (int i = k; i <= n; i++)
		ans = min(ans, num_broken[i] - num_broken[i - k]);

	cout << ans << endl;
}
