#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n); // Graph
	vector<bool> visited(n); // Keep track of each visited node
	
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[--a].push_back(--b); // Which nodes can you reach from each node? (roads go both ways)
		adj[b].push_back(a);
	}

	vector<int> city_reps; // First nodes of unconnected
	for (int i = 0; i < n; i++) { // Go through each node
		if (visited[i]) { continue; }
    // The code to the rest of the for loop will only run if and only if the current node is unvisited
		visited[i] = true; // Mark node as visited
		city_reps.push_back(i); // Add the unvisited node, this node will be the first node of another unconnected sector of the graphs
		deque<int> todo{i}; // BFS deque, push first/starting node in
		while (!todo.empty()) { // Repeat until all nodes are visited
			int curr = todo.front(); // Oldest (first) element of the deque (new elements get added to back)
			todo.pop_front(); // Remove this element from the deque
			for (int next : adj[curr]) { // Go through all adjacent nodes
				if (!visited[next]) {
					visited[next] = true; // Mark as visited
					todo.push_back(next); // Add node if and only if it hasn't been visited yet
				}
			}
		}
	}

	cout << city_reps.size() - 1 << '\n';
	for (int i = 0; i < city_reps.size() - 1; i++) { // Output connect all sectors that are disconnected
		cout << city_reps[i] + 1 << ' ' << city_reps[i + 1] + 1 << '\n';
	}
}
