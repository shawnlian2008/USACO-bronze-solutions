#include <bits/stdc++.h>
using namespace std;
 
int main() { // Tags: Prefix sums
	int n, s; cin >> n >> s;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) 
        cin >> nums[i];

    // One key observation for this problem is that to find the subarray with the sum s, we can just use a cumulative variable that keeps track of the total sum so far, and if the current sum is greater than s, then all we need to do is to see if we can make the sum of the subarray to s is to see if we can subtract a prefix sum from the current prefix sum to get to the value s
    
	long long prefix_sum = 0, ans = 0;
	map<long long, int> sums; // Map to keep track of numbers that we've passed before
	sums[0] = 1;
	for (int i = 0; i < n; i++){
		prefix_sum += nums[i]; // Add to prefix sum
		ans += sums[prefix_sum - s]; // Subtract prefix sum from current prefix sum
		sums[prefix_sum]++; // Keep track of the prefix sums that we've come across before
	}
	cout << ans << endl;
}
