#include <bits/stdc++.h>
using namespace std;

int main() { 
	int n; cin >> n;
	vector<int> v(n);
	for (int &i : v) cin >> i;

	sort(v.begin(), v.end());

	long long ans = 1; // Start from 1

    // Essentially check all cumulative values + 1 at the moment for any gaps
	for (int i = 0; i < n; i++){ // Go all the way until either the next value is larger than ans or until after the very last value is processed and added
		if (v[i] > ans){
			cout << ans << endl; 
			return 0;
		}

		ans += v[i]; // Add the current value to answer
	}

	cout << ans << endl;
}
