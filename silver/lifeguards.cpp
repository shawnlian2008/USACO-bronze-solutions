// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int time, id, status;
	bool operator<(const Cow &y) { return time < y.time; }
};

int main() {
  freopen("lifeguards.in", r, stdin);
  freopen("lifeguards.out", w, stdout);
	int n; cin >> n;

	//first pair value is time, 2nd value is index
	vector<Cow> v;
	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.push_back({a, i, 1});
		v.push_back({b, i, -1});
	}

	sort(v.begin(), v.end());

	vector<int> alone_time(n);
	set<int> working; 
	int prev = 0, total = 0;
	
	for (int i = 0; i < v.size(); i++){
		int currTime = v[i].time;
		if (working.size() > 0) 
			total += currTime - prev;
		
		if (working.size() == 1){
			alone_time[*working.begin()] += currTime - prev;
		}

		if (v[i].status == 1){
			working.insert(v[i].id);
		} else working.erase(v[i].id);

		prev = currTime;
	}

	int minimum = *min_element(alone_time.begin(), alone_time.end());
	cout << total - minimum << endl;
}
