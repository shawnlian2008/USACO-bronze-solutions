#include <bits/stdc++.h>
using namespace std;

int main() { // Cumulative running vector sum
	int n; cin >> n;
	vector<pair<int, int>> v; // {time, start or end} 
	// 1 for start, -1 for end

	for (int i = 0; i < n; i++){
		int start, end; cin >> start >> end;
		v.push_back({start, 1});
		v.push_back({end, -1});
	}

	sort(v.begin(), v.end());

	int curr_ppl = 0, ans = 0;
	for (int i = 0; i < v.size(); i++){
		curr_ppl += v[i].second; // Simply add the start/end value since 1 if arrive and -1 if leave
		ans = max(ans, curr_ppl); // Running maximum, maximum number of people
	}

	cout << ans << endl;
}
