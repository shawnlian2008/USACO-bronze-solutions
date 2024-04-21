#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Binary Search
	int n, k; cin >> n >> k;
	vector<int> numbers(n);
	int largest_value = INT_MIN; // Answer has to be higher than largest value, so we will record that and then set the low for Binary Search
	for (int i = 0; i < n; i++){
		cin >> numbers[i];
		largest_value = max(largest_value, numbers[i]);
	}

	long long high = 1e18, low = largest_value, ans = 1e18;

	while (low <= high){// Normal while loop condition for binary search
		long long mid = (low + high) / 2, sum = 0; // Calculate middle value in between low nad high
		int split_counter = 1; // Track the number of splits we have to make in order to fit every subarray sum to a value lower than the current value (mid) that we are testing
		for (int i = 0; i < n; i++){ // Go through all numbers
			if (sum + numbers[i] > mid){ // Cannot fit anymore
				sum = 0; // Reset sum and split again
				split_counter++;
			}
			sum += numbers[i]; // Add to sum
		}

		if (split_counter > k) // Too many splits
			low = mid + 1;
		else { // Valid number of splits, keep going
			// Find the minimum valid largest value with binary search
			ans = min(ans, mid); 
			high = mid - 1;
		}
	}

	cout << ans << endl;
}
