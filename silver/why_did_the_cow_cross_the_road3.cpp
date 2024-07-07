#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

int n, k, r; 
vector<vector<vector<point>>> roads;
vector<vector<bool>> graph, visited;

bool valid(int x, int y, pair<int, int> curr_cell){
	if (x < 0 || y < 0 || x >= n || y >= n) // The current cell isn't valid if either its x or y are out of bounds
		return false;

	for (point m : roads[curr_cell.first][curr_cell.second]) // If there is a road between the current and the neighbouring cell, then the cell isn't valid either
		if (m.x == x && m.y == y)
			return false;

	return true;
}

int main() {
	cin >> n >> k >> r;
	
	roads = vector<vector<vector<point>>>(n, vector<vector<point>>(n)); // Hold whichever grid is in between each 2 cells on the map
	graph = vector<vector<bool>>(n, vector<bool>(n)); // Hold whether or not there is a cow at each grid location
	visited = vector<vector<bool>>(n, vector<bool>(n)); // Whether or not each grid location has been visited

	for (int i = 0; i < r; i++){ // Connect the 2 cells both ways that are blocked by roads
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		roads[--x1][--y1].push_back({--x2, --y2});
		roads[x2][y2].push_back({x1, y1});
	}

	for (int i = 0; i < k; i++){ 
		int x, y; cin >> x >> y;
		graph[--x][--y] = true; // Mark cow location
	}

	vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // List of all directions you can go

	long long ans = 0; 
	vector<int> regions; // Number of cows in each region
	for (int i = 0; i < n; i++){ // Go through all cells of the farm
		for (int j = 0; j < n; j++){
			if (visited[i][j]) continue; // Skip current cell if it is already visited

			int num_cows_region = 0; // Hold number of cows in this current connected component

			stack<pair<int, int>> st; // DFS stack
			st.push({i, j}); // Add current cell to stack

			while (!st.empty()){
				pair<int, int> curr = st.top();
				st.pop();
		
				if (visited[curr.first][curr.second]) continue;

				visited[curr.first][curr.second] = true;

				num_cows_region += graph[curr.first][curr.second]; // Add to num_cows_region if the current spot is occupied by a cow

				for (pair<int, int> d : directions) // Go through all directions
					if (valid(curr.first + d.first, curr.second + d.second, curr)) // If in bounds
						st.push({curr.first + d.first, curr.second + d.second}); // Add to stack
			}

			if (num_cows_region != 0) regions.push_back(num_cows_region); // Add to regions as long as num_cows_region isn't 0 (to be multiplied later)
		}
	}

	for (int i = 0; i < regions.size(); i++) // Add to all combinations of multiplication for each pair of cells
		for (int j = i + 1; j < regions.size(); j++)
			ans += regions[i] * regions[j];

	cout << ans << endl;
}
