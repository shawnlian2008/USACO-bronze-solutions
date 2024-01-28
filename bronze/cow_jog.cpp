#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("cowjog");
	int n; cin >> n;
	//first value is position, second value is speed
	vector<pair<int, int>> properties(n);

	for (int i = 0; i < n; i++) cin >> properties[i].first >> properties[i].second;

	int ans = 1;
	for (int i = n - 2; i >= 0; i--){
		if (properties[i].second > properties[i + 1].second){
			properties[i].second = properties[i + 1].second;
		} else {
			ans++;
		}
	}

	cout << ans << endl;
}
