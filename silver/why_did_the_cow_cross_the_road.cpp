#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	int chickens, cows; cin >> chickens >> cows;

	vector<int> chicken_times(chickens); // Hold the time available of all the chickens
	multiset<pair<int, int>> cow_times; // {end, start} of all cow time starts and ends

	for (int i = 0; i < chickens; i++)
		cin >> chicken_times[i];
	
	for (int i = 0; i < cows; i++){
		int start, end; cin >> start >> end;
		cow_times.insert({end, start});
	}

	sort(chicken_times.begin(), chicken_times.end());
	
	int ans = 0;
	for (int i = 0; i < chickens; i++){
		auto itr = cow_times.lower_bound({chicken_times[i], 0}); // Earliest ending cow preference time
		
		pair<int, int> it = *itr;
		while (it.second > chicken_times[i] && itr != cow_times.end()){ // Earliest ending cow preference time with a possible cow starting time
			itr++;
			it = *itr;
		}

		if (itr != cow_times.end() && it.second <= chicken_times[i]){ // Valid index and start
			pair<int, int> at_itr = *itr; 
			ans++;
			cow_times.erase(at_itr); // Since one cow to one chicken and the reverse, remove the current cow from the set
		}
	}

	cout << ans << endl;
}
