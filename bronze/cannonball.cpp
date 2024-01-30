// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s; cin >> n >> s;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	long long e = 0;
	vector<bool> broken(n, false);
	int curr_pos = s - 1, power = 1, direction = 1;
	while (curr_pos >= 0 && curr_pos < n){
		if (e == 1e9)
			break;
		//jump pad
		if (v[curr_pos].first == 0){
			power += v[curr_pos].second;
			direction = -direction;
			curr_pos += power * direction;
		} else {
			if (v[curr_pos].second <= power && !broken[curr_pos])
				broken[curr_pos] = true;
			curr_pos += power * direction;
		}
		e++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		if (broken[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}
