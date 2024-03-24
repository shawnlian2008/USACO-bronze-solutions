#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end(), [](pair<int, int> &x, pair<int, int> &y){
		return x.second < y.second;
	});

	int x = 0, y = v.size() - 1;
	int minimum_time = INT_MIN;
	//while (true){
		
	for (int i = 0; i < 100; i++){
		//cout << x << " " << y << endl;
		//cout << v[x].first << " " << v[x].second << ", " << v[y].first << " " << v[y].second << ", " << v[y].second + v[x].second << endl;
		int f1 = v[x].first, f2 = v[y].first;
		v[x].first -= min(f1, f2);
		v[y].first -= min(f1, f2);

		minimum_time = max(minimum_time, v[y].second + v[x].second);

		if (v[x].first == 0) x++;
		if (v[y].first == 0) y--;

		if (x == y - 1 || x == y) {
			if (x == y && v[x].first != 0)
				minimum_time = max(minimum_time, v[x].second * 2);
			else {
				if (v[x].first > 0){
					minimum_time = max(minimum_time, v[x].second * 2);
				} else {
					minimum_time = max(minimum_time, v[y].second * 2);
				}
			}
			break;
		}
	}

	cout << minimum_time << endl;
}
