#include <bits/stdc++.h>
using namespace std;
 
int main() { // Tags: Data structures, greedy
    // Greedy algorithm: Stack blocks to the tower with the smallest possible block
	int n; cin >> n;
	multiset<int> towers; // keep a list of the smallest block in the towers
	
	for (int i = 0; i < n; i++){
		int block; cin >> block;
		if (towers.empty()) // First block
			towers.insert(block);
		else { 
			auto it = towers.upper_bound(block); // The smallest possible top block of any tower
			auto last = towers.end(); // Iterator of the last value
			last--;
			if (block >= *last){ // Block is larger than all the top blocks, create a new tower
				towers.insert(block);
			} else { // Block can fit, replace the top block of the selected tower with the new block
				towers.erase(it);
				towers.insert(block);
			}
		}
	}
 
	cout << towers.size() << endl;
}
