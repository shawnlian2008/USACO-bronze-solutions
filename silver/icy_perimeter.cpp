#include <bits/stdc++.h>
using namespace std;

int n; 
vector<string> v;
vector<vector<bool>> visited;

bool valid(int x, int y){ // Check if cell is in bounds
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	return true;
}

int get_perimeter(int x, int y){
	int value = 0;

  // Add to perimeter for the cells that are on the very very edge of the map
	if (!valid(x + 1, y)) value++;
	if (!valid(x, y + 1)) value++;
	if (!valid(x - 1, y)) value++;
	if (!valid(x, y - 1)) value++;

  // Add to perimeter based on how many blank spaces around the cell
	if (valid(x + 1, y) && v[x + 1][y] == '.')
		value++;
	if (valid(x, y + 1) && v[x][y + 1] == '.')
		value++;
	if (valid(x - 1, y) && v[x - 1][y] == '.')
		value++;
	if (valid(x, y - 1) && v[x][y - 1] == '.')
		value++;
	
	return value;
}

int area = 0, perimeter = 0, largest_area = 0, largest_perimeter = 0;

void dfs(int x, int y){ // DFS function
	if (!valid(x, y) || visited[x][y] || v[x][y] == '.') // If current cell is out of bounds, already visited, or empty
		return;

	visited[x][y] = true; // Mark as visited

	area++; // Add to area
	perimeter += get_perimeter(x, y); // Add to perimeter

    // DFS all neighbouring cells
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
}

int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	
	cin >> n;

	v.resize(n);
	visited = vector<vector<bool>>(n, vector<bool>(n));

	for (string &s : v) cin >> s

	pair<int, int> ans; // Holds the answer as a pair in format {area, perimeter}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (visited[i][j] || v[i][j] == '.') // If the current cell is already visited or is empty, there's no point running DFS on it because it won't count towards anything
				continue;

			dfs(i, j); // Run DFS on current cell
            
			if (area > largest_area){ // Follow the rules of finding the blob with the biggest possible area with smallest possible perimeter
				largest_area = area;
				largest_perimeter = perimeter;
			} else if (area == largest_area)
				largest_perimeter = min(largest_perimeter, perimeter);

            // Reset variables
			area = 0;
			perimeter = 0;
		}
	}

	cout << largest_area << " " << largest_perimeter << endl;
}
