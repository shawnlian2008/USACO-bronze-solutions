#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int min_ans = 0;
	if ((v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2) || 
		(v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2)){
		min_ans = 2;
	} else {
		int y = 0, range = 0;
		for (int i = 0; i < n; i++){
			while (y < n - 1 && v[y + 1] - v[i] <= n - 1)
				y++;
			range = max(range, y - i + 1);
		}
		min_ans = n - range;
	}
	cout << min_ans << "\n" << max(v[n - 2] - v[0], v[n - 1] - v[1]) - (n - 2) << endl;
}
