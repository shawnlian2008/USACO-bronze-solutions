#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> slopes, waypoints;
vector<vector<bool>> visited;

bool valid(int x, int y){ // Check if cells given are in bounds
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

int main() { // Tags: floodfill/graphs and binary search
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	cin >> n >> m;
	slopes = vector<vector<int>>(n, vector<int>(m)); // Holds the map of the slopes
	waypoints = vector<vector<int>>(n, vector<int>(m)); // Holds maps of the waypoints
	visited = vector<vector<bool>>(n, vector<bool>(m)); // Holds if each cell is visited

	for (vector<int> &v1 : slopes)
		for (int &v : v1)
			cin >> v;

	int waypoint_counter = 0;
	pair<int, int> first_cell;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> waypoints[i][j];
			if (waypoints[i][j] == 1) { // Count the number of waypoints
				waypoint_counter++;
				first_cell = {i, j}; // First cell we are going to start from which has to be a waypoint
			}
		}
	}

	int low = 0, high = 1e9, ans = 1;
	while (low <= high){ // Binary Search
		int mid = low + (high - low) / 2, cnt = 0; // Calculate mid, and the number of waypoints to be visited with this current difficulty mid

		stack<pair<int, int>> s; // DFS stack
		s.push(first_cell); // Add first cell to stack 
		visited = vector<vector<bool>>(n, vector<bool>(m)); // Reset visited
		while (!s.empty()){
			pair<int, int> curr = s.top(); // Remove top element from stack
			s.pop();

			if (visited[curr.first][curr.second]) continue; // Check if the current cell has been visited or not (previously there was a problem of duplicate explored waypoints for some reason LOL)

			visited[curr.first][curr.second] = true; // Mark as visited

			if (waypoints[curr.first][curr.second] == 1) // We are at a waypoint
				cnt++; // Update number of waypoints explored

      // Check if each neighbouring cell is in bounds, has a slope difference smaller than the current difficulty, and isn't visited
			if (valid(curr.first + 1, curr.second) && abs(slopes[curr.first + 1][curr.second] - 
				slopes[curr.first][curr.second]) <= mid && !visited[curr.first + 1][curr.second])
				s.push({curr.first + 1, curr.second});
			
			if (valid(curr.first - 1, curr.second) && abs(slopes[curr.first - 1][curr.second] - 
				slopes[curr.first][curr.second]) <= mid && !visited[curr.first - 1][curr.second])
				s.push({curr.first - 1, curr.second});
			
			if (valid(curr.first, curr.second + 1) && abs(slopes[curr.first][curr.second + 1] - 
				slopes[curr.first][curr.second]) <= mid && !visited[curr.first][curr.second + 1])
				s.push({curr.first, curr.second + 1});
			
			if (valid(curr.first, curr.second - 1) && abs(slopes[curr.first][curr.second - 1] - 
				slopes[curr.first][curr.second]) <= mid && !visited[curr.first][curr.second - 1])
				s.push({curr.first, curr.second - 1});
		}

		if (cnt < waypoint_counter){ // If the difficulty is too low, meaning we can't reach every single waypoint from the first waypoint
			low = mid + 1;
		} else { // If we can, try to go less
			ans = mid;
			high = mid - 1;
		}
	}

	cout << ans << endl;
}
