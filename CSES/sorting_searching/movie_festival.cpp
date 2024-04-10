#include <bits/stdc++.h>
using namespace std;

int main(){ // Tags: Greedy, sorting
    // Greedy algorithm: watch the movies with the earliest possible end times
	int n; cin >> n;
	vector<pair<int, int>> v(n); // {start time, end time}

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	
	// Sort by earliest end time
	sort(v.begin(), v.end(), [](const pair<int, int> &x, const pair<int, int> &y){
		return x.second < y.second;
	});

	int curr_end = 0, ans = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i].first >= curr_end){ // You can watch this movie
			ans++;
			curr_end = v[i].second; // Update the current end to be the end of this movie
		}
	}
	
	cout << ans << endl;
}
