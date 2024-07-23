#include <bits/stdc++.h>
using namespace std;
 
int n;

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Hold all directions of the cows

bool graph[2002][2002]; // Cow plot graph
stack<pair<int, int>> st; // Stack to add new cows to

auto add_new_cow(int x, int y) { // Adds new cow if the current cow is comfortable
	if (!graph[x][y]) return; // Skip if there is no cow at the given position
	int num_adj = 0; // Count number of adjacent cows
	for (pair<int, int> direction : directions) // Go through all neighbour cells, and count the ones that have cows
		num_adj += graph[x + direction.first][y + direction.second];
	if (num_adj == 3){ // If a cow is comfortable (3 cows around it)
		for (pair<int, int> direction : directions){ // Go through all neighbours
			if (!graph[x + direction.first][y + direction.second]){ // Add a cow at the location that requires a 4th cow to make the cow uncomfortable
				st.push({x + direction.first, y + direction.second}); // Add new cow at that position
        return;
      }
    }
  }
}
 
int main() {
	cin >> n;
	int total = 0; // Total number of cows
	for (int i = 1; i <= n; i++) { // Initial number of cows that were already on the field
		int x, y; cin >> x >> y;
		x += 1001, y += 1001; // Add 1001 to deal with the cows that occupy the negative cells
		st.push({x, y}); // Add this current cow to stack
		while (!st.empty()) { // DFS
			pair<int, int> curr = st.top(); 
			st.pop();
			if (graph[curr.first][curr.second]) continue; // IF there already is a cow at the current grid location
			total++; // Increment to total cow for each cow that has been added to the stack
			graph[curr.first][curr.second] = 1; // Set the current cell to be occupied, since we just added a new cow
			add_new_cow(curr.first, curr.second); // After updating graph, check if the current cow is uncomfortable or not, if so, then add a new 4th cow to make this cow uncomfortable
			for (pair<int, int> direction : directions) // Go through all neighbours, and check if each neighbour cow is uncomfortable or not, if so then add a 4th cow to make this cow uncomfortable
				add_new_cow(curr.first + direction.first, curr.second + direction.second);
		}
		cout << total - i << "\n"; // Output the total number of cows that have been added minus the initial number of cows that were already on the field
	}
}
