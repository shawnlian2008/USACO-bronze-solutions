#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, k; cin >> n >> k;
	map<int, pair<int, int>> occurences; // Maps all numbers to a pair
  // Pair format: {number of occurences so far, index of last occurence}
	
	int total = 0;
	for (int i = 0; i < n; i++){
		int num; cin >> num;
		total += num; // Current total of all numbers we have come across so far
		if (occurences[k - num].first > 0){ // If there is a value that fits to make up to k from the current total
			cout << ++occurences[k - num].second << " " << ++i << endl; // 1 indiced, so add to each index
			return 0;
		}
		occurences[num].first++; // Update number of occurences
		occurences[num].second = i; // Update last occurence index
	}

	cout << "IMPOSSIBLE" << endl; // If impossible
}
