#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct Positions { // Contains x and y coordinates, plus the id of the cow (what place of order was it given)
	int x, y, id;
};

int distances(int x1, int y1, int x2, int y2){ // Calculate distance squared
	int d = (x2 - x1) * (x2 - x1);
	d += (y2 - y1) * (y2 - y1);
	return d;
}

int main() { // Tags: connected components, binary search
	freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
	int n; cin >> n;

	vector<Positions> coordinates(n); // Hold all coordinates of cows
	
	for (int i = 0; i < n; i++){ 
		cin >> coordinates[i].x >> coordinates[i].y;
		coordinates[i].id = i;
	}
	
	int low = 1, high = 1e9, ans = 1e9;
	while (low <= high){ // Binary search function
		int mid = low + (high - low) / 2; // Max Distance away
		//cout << "mid: " << mid << endl;
		vector<bool> visited(n); // If each cow has been visited or not
		unordered_set<int> s; // Holds all visited nodes from this DFS, no recurring elements, unordered so insertion and deletion will be O(1) 
		stack<int> st;
		st.push(0); // Test if we can get to all cows with this current max distance
		while (!st.empty()){ // Non-recursive DFS, using a stack
			int curr = st.top(); // Last item added to stack
			st.pop(); // Remove from back
			visited[curr] = true; // Mark current node as visited
			s.insert(curr); // Add current node to visited nodes set
			for (int i = 0; i < n; i++){
				if (!visited[i] && distances(coordinates[i].x, coordinates[i].y,
					coordinates[curr].x, coordinates[curr].y) <= mid){ // If the distance between the cows 
					st.push(coordinates[i].id);
				}
			}
		}

		//cout << s.size() << endl;

		if (s.size() < n) // If not all cows were visited
			low = mid + 1; // Make distance higher
		else {
			ans = mid; // Record answer
			high = mid - 1; // See if we can make distance lower
		}
	}

	cout << ans << endl;
}
