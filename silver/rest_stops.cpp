#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Greedy
	// Greedy algorithm mentioned below
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	long long metres, rest_stops, pace_f, pace_b; 
	cin >> metres >> rest_stops >> pace_f >> pace_b;

	vector<pair<int, int>> r(rest_stops); // {location, tastiness value}

	for (int i = 0; i < rest_stops; i++)
		cin >> r[i].first >> r[i].second;

	long long largest_val = 0; // Largest value we've seen so far
	vector<int> optimal; // An index is optimal if there is no value after the index that is greater than the value at the index itself
	for (int i = rest_stops - 1; i >= 0; i--){ // Go through all rest stops backwards
		if (largest_val < r[i].second){ 
			optimal.push_back(i); // Found an optimal index 
			largest_val = r[i].second; // Running maximum
		}
	}

	// Simulation part
	long long ans = 0;
	int prev_time = 0; // Keep track of previous time
	for (int i = optimal.size() - 1; i >= 0; i--){ // Go through all optimal indices backwards, since it's already in decending order by time, but we want to go through it in ascending order, so we just loop through backwards
		long long time_taken = (r[optimal[i]].first - prev_time); // Get the elapsed time from this index to the previous index
		long long wait_time = (time_taken * pace_f) - (time_taken * pace_b); // Get the wait times by subtracting the time taken by Bessie from the time taken by the farmer
		ans += wait_time * r[optimal[i]].second; // Total tastiness points earnt from this rest stop
		prev_time = r[optimal[i]].first; // Update previous time to the current time
	}

	cout << ans << endl;
}
