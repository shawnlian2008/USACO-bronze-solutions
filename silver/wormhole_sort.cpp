#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> v; // Holds all graph connections with format {next node, width}
vector<int> cow_positions; // Index of cow in each position
vector<bool> visited, mini_visited, sorted; // visited: keeps track of all visited and unvisited nodes, mini_visited: keeps track of all visited and unvisited nodes, but resets for every dfs connected component
set<int> found; // Keeps track of all the indices of cow positions that were visited with DFS (not the actual cow positions)
int mid = 0; // Minimum size of the wormhole that will be gone through 

void dfs(int node){
	visited[node] = true; // Mark current node as main visited
	mini_visited[node] = true; // Mark current node as the visited for each connected group of cows
	if (!sorted[node]) found.insert(cow_positions[node]); // Add to found, if and only if the current node is sorted (the main idea at the end is to check if the sorted position of each unsorted cow can be reached from its current unsorted position)
	for (int i = 0; i < v[node].size(); i++){
		if (!visited[v[node][i].first] && v[node][i].second >= mid){ // Go through wormhole if not visited and the width of the whole is larger than the minimum size
			dfs(v[node][i].first); // Recall dfs
		}
	}
}

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
	int n, m; cin >> n >> m;
    
	v.resize(n); // Preset all global vector arrays, since they cannot be set outside of main
	cow_positions.resize(n);
	visited.resize(n);
	sorted.resize(n);

	int num_sorted = 0; // Counts the number of sorted cows so far
	for (int i = 0; i < n; i++){
		cin >> cow_positions[i];
		cow_positions[i]--; // 0-index cow positions
		if (cow_positions[i] == i){ // Cow already in its ideal position
			sorted[i] = true; // Mark it sorted
			num_sorted++;
		}
	}

	if (num_sorted == n) { // If the number of sorted cows is equal to the number of 
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		v[--a].push_back({--b, w}); // Link graph components with next node and the width of the wormhole to get there
		v[b].push_back({a, w});
	}

	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < v[i].size(); j++){
			cout << "{" << v[i][j].first << ", " << v[i][j].second << "}, ";
		}cout << endl;
	}*/

	int low = 1, high = 1e9, ans = 1e9;
	while (low <= high){ // Binary Search
		mid = low + (high - low) / 2;
		visited = vector<bool>(n); // Reset main visited
        
		bool nr = true;
		for (int i = 0; i < n; i++){ // DFS here only if main visited
			if (visited[i]) continue;
			found.clear(); // Clear the found set
			
			mini_visited = vector<bool>(n); // reset mini_visited, since this would be a subgraph of connected components
			dfs(i);

			for (int j = 0; j < n; j++){ // Go through all cows
				if (mini_visited[j] && !mini_visited[cow_positions[j]]){ // If you cannot get from the current unsorted cow to its sorted position
					nr = false; 
					break;
				}
			}

			if (nr == false) break; // There would be no point in continuing
		}

		if (!nr) high = mid - 1; // Set the smallest wormhole bound down
		else {
			ans = mid; // Set answer
			low = mid + 1; // See if we can go higher (looser)
		}
	}

	cout << ans << endl;
}
