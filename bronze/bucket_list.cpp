#include <bits/stdc++.h>
using namespace std;

bool sortbyth(const tuple<int, int, int>& a, const tuple<int, int, int>& b){ 
    return (get<0>(a) < get<0>(b)); 
} 

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int n; cin >> n;
	vector<tuple<int, int, int>> info;
	for (int i = 0; i < n; i++){
		int s, t, b; cin >> s >> t >> b;
		info.push_back(make_tuple(s, t, b));
	}

	sort(info.begin(), info.end(), sortbyth);

	for (int i = 0; i < n; i++){
		cout << get<0>(info[i]) << " " << get<1>(info[i]) << " " << get<2>(info[i]) << endl;
	}

	int buckets_needed = 0, maximum = INT_MIN;
	for (int i = 1; i < 1001; i++){
		for (int j = 0; j < n; j++){
			if (get<0>(info[j]) == i){
				buckets_needed += get<2>(info[j]);
				maximum = max(buckets_needed, maximum);
			} else if (get<1>(info[j]) == i){
				buckets_needed -= get<2>(info[j]);
			}
		}
	}

	cout << maximum << endl;
}
