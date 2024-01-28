#include <bits/stdc++.h>
using namespace std;

long long llmin(long long a, long long b){
	return (a < b) ? a : b;
}

int main() {
	long long n, t; cin >> n >> t;

	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++){
		long long a, b; cin >> a >> b;
		v.push_back({a, b});
	}

	long long num_bales = v[0].second;
	if (n == 1){
		cout << llmin(t, num_bales) << endl;
		return 0;
	}
	sort(v.begin(), v.end());

	if (t == 1){
		cout << llmin(1, num_bales) << endl;
		return 0;
	}

	long long ans = 0;
	for (int i = 1; i < n; i++){
		//days is in between
		if (t < v[i].first && t > v[i - 1].first){
			//minimum between the number of days and number of haybales
			ans += min((t - v[i - 1].first), num_bales);
			num_bales -= min((t - v[i - 1].first), num_bales);
		} else {
			ans += min((v[i].first - v[i - 1].first), num_bales);
			num_bales -= min((v[i].first - v[i - 1].first), num_bales);
		}

		num_bales += v[i].second;
	}

	if (t >= v[n - 1].first){
		//cout << (t - v[n - 1].first) + 1 << " " << num_bales << endl;
		ans += min((t - v[n - 1].first) + 1, num_bales);
	}

	cout << ans << endl;
}
