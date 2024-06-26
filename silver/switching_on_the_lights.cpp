#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1;
vector<vector<vector<pair<int, int>>>> graph;
vector<vector<bool>> lit, visited;

bool valid(int x, int y){
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	return true;
}

bool reachable(pair<int, int> cell){
	if (valid(cell.first + 1, cell.second) && visited[cell.first + 1][cell.second])
		return true;
	if (valid(cell.first - 1, cell.second) && visited[cell.first - 1][cell.second])
		return true;
	if (valid(cell.first, cell.second + 1) && visited[cell.first][cell.second + 1])
		return true;
	if (valid(cell.first, cell.second - 1) && visited[cell.first][cell.second - 1])
		return true;

	return false;
}

int main() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	cin >> n >> m;

	graph = vector<vector<vector<pair<int, int>>>>(n, vector<vector<pair<int, int>>>(n)); // Hold which cells each cell has a switch to
	lit = vector<vector<bool>>(n, vector<bool>(n)); // Holds whether or not each cell is lit or not
	visited = vector<vector<bool>>(n, vector<bool>(n)); // Keeps track of visited nodes

	for (int i = 0; i < m; i++){
		int x, y, a, b; cin >> x >> y >> a >> b;
		graph[--x][--y].push_back({--a, --b}); // Update and fill graph
	}

	//cout << lit.size() << endl;
	lit[0][0] = true; // Set first cell lit

	stack<pair<int, int>> st; 
	st.push({0, 0});
	while (!st.empty()){ // DFS each light
		pair<int, int> curr = st.top(); // Get last added item from stack
		st.pop();

		if (!valid(curr.first, curr.second) || visited[curr.first][curr.second] || 
			!lit[curr.first][curr.second]) // Must be in bounds, not visited, and lit, or we skip
			continue;

		if (!reachable(curr) && !(curr.first == 0 && curr.second == 0)) // Skip if this cell isn't reachable AND isn't 0
			continue;

		visited[curr.first][curr.second] = true; // Mark current cell visited

    // Add neighbouring cells around the current cell
		st.push({curr.first + 1, curr.second});
		st.push({curr.first - 1, curr.second});
		st.push({curr.first, curr.second + 1});
		st.push({curr.first, curr.second - 1});

		for (int i = 0; i < graph[curr.first][curr.second].size(); i++){ // Go through all cells that can be lit from this current cell
			if (!lit[graph[curr.first][curr.second][i].first][graph[curr.first][curr.second][i].second]) // Add to the answer all cells that aren't lit (since we already recorded them if they are)
				ans++;

			lit[graph[curr.first][curr.second][i].first][graph[curr.first][curr.second][i].second] = true; // Set each cell to lit
      
			st.push({graph[curr.first][curr.second][i].first, graph[curr.first][curr.second][i].second}); // Add to stack this cell
		}
	}

	cout << ans << endl;
}
