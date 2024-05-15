#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int x, y;
	vector<int> neighbours; // Mooing partners
};

int main() { // Tags: Graphs/BFS
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	int n, m; cin >> n >> m;

	vector<Cow> v(n); // Holds all cows' positions and neighbours

	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;

	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		v[--a].neighbours.push_back(--b); // Connect the nodes in both directions, since it is a bidirectional graph
		v[b].neighbours.push_back(a);
	}

	vector<bool> visited(n); // Keep track of the visited indices of each cow

	int ans = INT_MAX;
	for (int i = 0; i < n; i++){
		if (visited[i]) continue; // If already visited then continue, because we don't want to waste time on an already explored part of the graph
		int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN; // Keep track of maximum x and maximum y and minimum x and minimum y values to calculate perimeter later

		deque d{i}; // Breadth First Search deque
		while (!d.empty()){
			int curr = d.front(); // First item of deque
			d.pop_front(); // Remove first element of deque
			minX = min(minX, v[curr].x); // Running minimum
			minY = min(minY, v[curr].y);
			maxX = max(maxX, v[curr].x);
			maxY = max(maxY, v[curr].y);
			visited[curr] = true; // Mark visited
			for (int j = 0; j < v[curr].neighbours.size(); j++){ // Go through all neighbouring nodes
				if (!visited[v[curr].neighbours[j]]) // Only add to deque if not visited
					d.push_back(v[curr].neighbours[j]);
			}
		}

		int perimeter = ((maxX - minX) * 2) + ((maxY - minY) * 2); // Calculate perimeter

		ans = min(ans, perimeter); // Update answer if it's the minimum
	}

	cout << ans << endl;
}
