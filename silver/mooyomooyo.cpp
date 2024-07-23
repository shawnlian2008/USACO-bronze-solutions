#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> v; // Hold the colour associated with each grid
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Hold directional coordinate operations 
vector<vector<bool>> visited, before_visited; // Hold visited (will get to before_visited in the dfs)

bool valid(pair<int, int> p){ // Check if given cell is out of bounds
	if (p.first < 0 || p.first >= 10 || p.second < 0 || p.second >= n) return false;
	return true;
}

int maxx = 0, minx = INT_MAX; // Calculate the maximum x value and minimum x value (resets after each section is processed)
int square_count(int startx, int starty){ // Count the number of squares in the connected component
	stack<pair<int, int>> st; // DFS
	st.push({startx, starty}); 
	int curr_val = v[startx][starty], cnt = 0; // Holds the colour of the current connected component and the number that will hold the number of cells in the section, respectively
	while (!st.empty()){
		pair<int, int> curr = st.top();
		st.pop();

		if (!valid(curr) || visited[curr.first][curr.second] || 
			v[curr.first][curr.second] != curr_val) continue; // Check if the current value is out of bounds or if the current cell is a different colour than the colour of the processing section
        // ^^^ If so, continue.

		visited[curr.first][curr.second] = true; // Mark current cell as visited
		cnt++;

        // calculate minimum and maximum x values of the section
		minx = min(minx, curr.first);
		maxx = max(maxx, curr.first);

		for (pair<int, int> d : dir) // Go through all neighbouring cells and add to the stack each neighbour (check for validity once we actually get to the cell)
			st.push({curr.first + d.first, curr.second + d.second});
	}

	return cnt; // Count number of squares in the region after the dfs
}

int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	cin >> n >> k;
	v.resize(10); // Set the vector size to 10, the game is 10 wide

	visited = vector<vector<bool>>(10, vector<bool>(n)); // Initialise size of visited

	for (int i = 0; i < n; i++){ 
		string s; cin >> s;
		for (int j = 0; j < 10; j++)
			v[j].push_back(s[j] - '0'); // Convert from char to int
	}

	
	while (true) {
		bool indicator = false; // If there are still regions with size above k
		for (int i = 0; i < 10; i++){ // Go through all the cells of the game
			for (int j = 0; j < n; j++){
				if (v[i][j] == 0 || visited[i][j]) continue; // 0's don't count, and cell has already been visited (standard connected component finder algorithm)

				before_visited = visited; // Set before_visited to be the exact same as visited
				
				if (square_count(i, j) >= k) // If this current region has mat least k number of squares
					indicator = true;
				else visited = before_visited; // If not, then revert visited to before_visited, since the function affects visited each time you call it
			}
		}

		if (!indicator) break; // Break if there are no more sections with size above k

		for (int i = minx; i <= maxx; i++){ // Go through all rows from minx to maxx
			vector<int> replacement; // This will be the replacement row to replace the current row after processing this section with size above k (we are to remove all cells in that section)
			for (int j = n - 1; j >= 0; j--) // Go through all squares of the row backwards, and add to replacement only if the current square isn't 0 and the current cell was visited in the square_count process
				if (v[i][j] != 0 && !visited[i][j]) replacement.push_back(v[i][j]);

			while (replacement.size() != n) // Add 0's until the replacement row is back to the original size of n (calculating it didn't work for some odd reason)
				replacement.push_back(0);

			reverse(replacement.begin(), replacement.end()); // Reverse the replacement row, since gravity goes down in the layout

			v[i] = replacement; // Set the current row to be the replacement row
		}

		maxx = 0; // Reset minx, maxx, and visited
		minx = INT_MAX; 
		visited = vector<vector<bool>>(10, vector<bool>(n));
	}

	for (int i = 0; i < n; i++){ // Output in the format of the problem's intended output
		for (int j = 0; j < 10; j++){
			cout << v[j][i];
		}
		cout << endl;
	}
}
