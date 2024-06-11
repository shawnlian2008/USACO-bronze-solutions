#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> friends; // Holds the graph of friend links
vector<bool> visited; // If each node has been visited or not
vector<int> assigned; // Assign team numbers to each person after team division

bool yuh; // If it is impossible or not to assign these 2 teams
void dfs(int node, int assignment){
	assigned[node] = assignment; // Assign team number
	visited[node] = true; // Mark as visited
	for (int i = 0; i < friends[node].size(); i++){
		if (assigned[friends[node][i]] == assignment){ // If there already exists a neighbour with the supposed assignment for this current node
			yuh = true;
			return;
		}

		if (!visited[friends[node][i]]){ // If the node hasn't been visited
			// Recurse dfs and change assignment
			if (assignment == 1) dfs(friends[node][i], 2);
			else if (assignment == 2) dfs(friends[node][i], 1);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	
	friends.resize(n);
	visited.resize(n);
	assigned.resize(n);

	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		//cout << a - 1 << " " << b - 1 << endl;
		friends[--a].push_back(--b);
		friends[b].push_back(a);
	}

	int dist = 1;
	for (int i = 0; i < n; i++){ // DFS each set of connected components
		if (visited[i]) continue;
	
		dfs(i, 1);
	}

	// Output
	if (yuh) cout << "IMPOSSIBLE" << endl;
	else { 
		for (int i = 0; i < n; i++){
			cout << assigned[i];
			if (i != n - 1) cout << " ";
		}
	}
}
