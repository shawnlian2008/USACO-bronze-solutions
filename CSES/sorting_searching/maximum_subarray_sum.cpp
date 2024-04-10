#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Prefix sums
  // Kadane's algorithm
	int n; cin >> n;

	long long curr_sum, best; cin >> best; 
	curr_sum = best; // Initialise to be first value of input
	for (int i = 1; i < n; i++){
		long long num; cin >> num;
		if (num > curr_sum + num) // If the total sum of all numbers so far is less than the current number, then reset best sum to be just this current number
			curr_sum = 0; 
		
		curr_sum += num; // Add to the current sum
		best = max(curr_sum, best); // Running maximum
	}

	cout << best << endl;
}
