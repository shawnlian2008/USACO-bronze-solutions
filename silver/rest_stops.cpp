#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	long long metres, rest_stops, pace_f, pace_b; 
	cin >> metres >> rest_stops >> pace_f >> pace_b;

	vector<pair<int, int>> r(rest_stops);

	for (int i = 0; i < rest_stops; i++)
		cin >> r[i].first >> r[i].second;

	long long largest_val = 0;
	vector<int> optimal;
	for (int i = rest_stops - 1; i >= 0; i--){
		if (largest_val < r[i].second){
			optimal.push_back(i);
			largest_val = r[i].second;
		}
	}

	long long ans = 0;
	int prev_time = 0;
	for (int i = optimal.size() - 1; i >= 0; i--){
		long long time_taken = (r[optimal[i]].first - prev_time);
		long long wait_time = (time_taken * pace_f) - (time_taken * pace_b);
		ans += wait_time * r[optimal[i]].second;
		prev_time = r[optimal[i]].first;
	}

	cout << ans << endl;
}
