#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Binary search for answer
	int startx, starty; cin >> startx >> starty; // Starting coordinates
	int endx, endy; cin >> endx >> endy; // Ending coordinates
	int n; string weather; cin >> n >> weather; // n and the weather pattern cycle

	vector<pair<long long, long long>> v(n + 1); // prefix sums of the distance travelled over every day of the weather cycle only (since every day after that would just loop around)
	for (int i = 1; i <= n; i++){
		if (weather[i - 1] == 'U'){ // Up
			v[i].first = v[i - 1].first;
			v[i].second = v[i - 1].second + 1; 
		} else if (weather[i - 1] == 'D'){ // Down
			v[i].first = v[i - 1].first;
			v[i].second = v[i - 1].second - 1; 
		} else if (weather[i - 1] == 'R'){ // Right
			v[i].first = v[i - 1].first + 1;
			v[i].second = v[i - 1].second; 
		} else if (weather[i - 1] == 'L'){ // Left
			v[i].first = v[i - 1].first - 1;
			v[i].second = v[i - 1].second;
		}
	}

	long long low = 0, high = 1e18, ans = 1e18; // Binary search variables
	while (low <= high){
		long long mid = low + (high - low) / 2; // Middle value, amount of days to pass

		pair<long long, long long> final_location; // Coordinates of location after mid amount of days
		
		long long mod = mid % n; // Remaining days after mid / n rounds of weather cycle
		final_location.first = startx + (v[n].first * (mid / n)) + v[mod].first; // Adds values from number of cycles added to the values of the remaining days in the cycle
		final_location.second = starty + (v[n].second * (mid / n)) + v[mod].second;
		
		//cout << abs(endx - final_location.first) + abs(endy - final_location.second) << " " << mid << endl;

		if (abs(endx - final_location.first) + abs(endy - final_location.second)
			> mid) // Since directly simulating moving with the current would be way too complex to implement, we can notice that we can just simulate wind directions and calculate the new coordinates of the ship after mid days of the weather cycle. Then, we calculate the distance needed to travel to get to the coordinates that we want to get to. If the distance needed to move is more than mid, meaning it'll have to take more than mid days, then we realise that we are going to be needing more time to complete the trip, since each day you can only move at most 1 unit.
			low = mid + 1;
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	
	if (ans == 1000000000000000000) cout << -1 << endl; // Original value of max
	else cout << ans << endl;
}
