#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int time, id, status;
	bool operator<(const Cow &y) { return time < y.time; }
};

int main() { // Tags: Custom sorting and point plotting
  	freopen("lifeguards.in", r, stdin);
  	freopen("lifeguards.out", w, stdout);
	int n; cin >> n;
	
	vector<Cow> v; // {time, id, and start or stop (1 for stop, -1 for end)}
	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.push_back({a, i, 1});
		v.push_back({b, i, -1});
	}

	sort(v.begin(), v.end()); // Sort by chronological order (time)

	vector<int> alone_time(n); // Holds the amount of time where each cow is alone
	set<int> working; // Which cows that are currently working 
	
	int prev = 0, total = 0;
	for (int i = 0; i < v.size(); i++){ // Go through all times
		int currTime = v[i].time;
		if (working.size() > 0)
			total += currTime - prev; // Add to total time
		
		if (working.size() == 1){
			alone_time[*working.begin()] += currTime - prev; // Add to alone_time to the cow working if there's only 1 cow working
		}

		// Add or remove based on the event
		if (v[i].status == 1){
			working.insert(v[i].id);
		} else working.erase(v[i].id);

		prev = currTime; // Update time
	}

	int minimum = *min_element(alone_time.begin(), alone_time.end());
	cout << total - minimum << endl;
}
