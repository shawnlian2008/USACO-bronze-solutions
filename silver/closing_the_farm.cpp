#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Graphs
	int n, m; cin >> n >> m;
	vector<vector<int>> paths(n); // Graph, holds nodes that are accessible at each node
	vector<bool> active(n, true); // The nodes that are and will be shut down throughout the test case

	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		paths[--a].push_back(--b); // Connect 2 nodes
		paths[b].push_back(a);
	}
	
	int num_active = n; // Current number of active nodes, we'll be comparing them to the number of nodes that can be visited later

    // Run BFS for the initial setting
	vector<bool> visited1(n); // Holds true or false whether or not each node has been visited yet (default false)
	deque<int> d{0}; // Deque, BFS number of nodes to visit
	int counter = 0; // Will hold number of nodes that can be visited
	while (!d.empty()){ // Standard BFS while loop
		counter++; // Update the number of nodes that can be visited
		int curr = d.front(); // Obtain first element of deque, FIFO style
		d.pop_front(); // Remove first element
		visited1[curr] = true; // Update visited1

		for (int i = 0; i < paths[curr].size(); i++){ // Go through all elements that you can go to from the current node that we just took out of the deque
			if (!visited1[paths[curr][i]] && active[paths[curr][i]]){ // Add to the back of deque only if the current node isn't visited and the current node hasn't been shut down yet
				d.push_back(paths[curr][i]);
			}
		}
	}

    // Compare number of active nodes to the number of nodes that the first BFS could get to
	if (counter < num_active) cout << "NO" << endl;
	else cout << "YES" << endl;

    // Run Bfs for the rest of the nodes
	for (int i = 0; i < n - 1; i++){
		int closed; cin >> closed; // Node to be closed
		active[--closed] = false; // Deactivate the node to be closed
		num_active--; // Subtract one from num_active
		vector<bool> visited(n); // Keep track of if each node has been visited or not

		int start = 0; // Find the first node that is active
		while (!active[start]) start++;

		deque<int> d{start}; // Deque for BFS
		set<int> vis; // Keep track of which nodes that we've visited, is a set so only contains unique elements
		while (!d.empty()){
			int curr = d.front(); // Get first element
			d.pop_front(); // Remove first element
			visited[curr] = true; // Mark visited
			vis.insert(curr); // Add to visited

			for (int i = 0; i < paths[curr].size(); i++){ // Go through all possible nodes that you can get to from the current node
				if (!visited[paths[curr][i]] && active[paths[curr][i]]){ // Add to the back of deque only if the current node isn't visited and the current node hasn't been shut down yet
					d.push_back(paths[curr][i]);
				}
			}
		}

		//cout << counter << " " << num_active << endl;

        // Compare the size of the visited set and the current number of active nodes
		if (vis.size() < num_active) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
