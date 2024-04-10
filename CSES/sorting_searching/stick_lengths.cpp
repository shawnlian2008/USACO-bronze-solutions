#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin >> n;
	vector<int> lengths(n);
	for (int i = 0; i < n; i++){
		cin >> lengths[i];
	}
 
	sort(lengths.begin(), lengths.end()); // Sort by length
 
	int mid = lengths[n / 2]; // Find median
	long long cost = 0;
	for (int i = 0; i < n; i++)
		cost += abs(mid - lengths[i]); // Level everything up to be the median
 
	cout << cost << endl;
}
