#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> trees(n);
	
	int largest = 0;
	for (int i = 0; i < n; i++){
		cin >> trees[i];
		largest = max(largest, trees[i]); // Keep track of the tree with the most berries
	}
	
	int maximum = 0;

	for (int i = 1; i <= largest; i++){ // Go through all possible values of split from 1 to the largest 
		vector<int> buckets(1000); // Bucket "map-ish", maps indices to amounts
		for (int j = 0; j <= i; j++) // Initialise all possible bucket amounts to 0
			buckets[j] = 0;
		
		// Attempt to divide everything evenly
		for (int j = 0; j < n; j++){ // Go through all trees
			buckets[i] += trees[j]/i; // Increment the value at index of possible split amount as the most amount of times we can put berries into baskets
			buckets[trees[j] % i]++; // Put the remaining amounts into another bucket
		}

		if (m / 2 > buckets[i]) // Number of buckets to give to Elsie is more than the number of buckets we've filled
			continue;
		
		buckets[i] -= m/2; // Give m/2 of the buckets with i berries inside out to Elsie
		int given = 0, total = 0, curr = i;

		while (curr > 0 && given < m/2){ //
			if (buckets[curr] > 0){ // Add up all the values at each index
				given++;
				total += curr;
				buckets[curr]--; 
			} else curr--;
		}

		if (given == m/2) // Add only if we have the exact optimal amount for Elsie
			maximum = max(maximum, total);
	}

	cout << maximum << endl;
}
