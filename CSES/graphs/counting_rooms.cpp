#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector<string> v; // Holds the floorplan/layout of the building
vector<vector<bool>> visited; // If each grid is visited or not

void floodfill(int x, int y){
  // Check for if current cell is in bounds, if the current cell is a wall, or if the current cell was already visited
	if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == '#' || visited[x][y])
		return;

	visited[x][y] = true; // Mark visited

  // Recurse on all neighbours
	floodfill(x + 1, y); 
	floodfill(x, y + 1);
	floodfill(x - 1, y);
	floodfill(x, y - 1);
}

int main() {
	cin >> n >> m;
	v.resize(n);
	visited = vector<vector<bool>>(n, vector<bool>(m));
	
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ans = 0;
	for (int i = 0; i < n; i++){ // Go through all cells
		for (int j = 0; j < m; j++){
			if (visited[i][j] || v[i][j] == '#') continue; // Check if the current cell is visited or the current cell is a wall
  
			ans++; // Add to number of rooms
			floodfill(i, j);
		}
	}

	cout << ans << endl;
}
