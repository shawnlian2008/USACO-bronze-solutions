#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<vector<int>> stacks; // Holds each stack of increasing number sequences
	
	for (int i = 0; i < n; i++){
		int num; cin >> num; // Input each number

		int left = 0, right = stacks.size() - 1; // Binary search the index in the list of stacks and find which stack to put the number in, the stack with the largest last value smaller than the current number
		while (left <= right){
			int mid = left + (right - left) / 2; // Middle
			if (stacks[mid][stacks[mid].size() - 1] < num) right = mid - 1; // Number at index
			else left = mid + 1;
		}

		if (left == stacks.size()) stacks.push_back({num}); // Create separate stack
		else stacks[left].push_back(num); // Add to existing stack that we've found
	}

	for (int i = 0; i < stacks.size(); i++){ // Print out each stack
		for (int j = 0; j < stacks[i].size(); j++){
			cout << stacks[i][j] << " ";
		}
		cout << endl;
	}
}
