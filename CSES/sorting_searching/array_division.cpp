#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> numbers(n);
	int largest_value = INT_MIN;
	for (int i = 0; i < n; i++){
		cin >> numbers[i];
		largest_value = max(largest_value, numbers[i]);
	}

	long long high = 1e18, low = largest_value, ans = 1e18;

	while (low <= high){
		long long mid = (low + high) / 2, sum = 0;
		int split_counter = 1;
		for (int i = 0; i < n; i++){
			if (sum + numbers[i] > mid){
				sum = 0;
				split_counter++;
			}
			sum += numbers[i];
		}

		if (split_counter > k)
			low = mid + 1;
		else {
			ans = min(ans, mid); 
			high = mid - 1;
		}
	}

	cout << ans << endl;
}
