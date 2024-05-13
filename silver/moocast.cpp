#include <bits/stdc++.h>
using namespace std;

struct Cow {
	double x, y, p;
};

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n; cin >> n;
	vector<vector<int>> graph(n); // Graph
	vector<Cow> coordinates(n);

	for (int i = 0; i < n; i++)
		cin >> coordinates[i].x >> coordinates[i].y >> coordinates[i].p;

	for (int i = 0; i < n; i++){ // The graph is directed, and not all pairs of cows can send messages in both directions
		for (int j = 0; j < n; j++){ // So go through all cows and then go through every other cow to see which cows the current cow can send messages to directly (draw nodes)
			if (i == j) continue;
			double distance = sqrt(abs((coordinates[i].x - coordinates[j].x) * 
				(coordinates[i].x - coordinates[j].x)) + abs((coordinates[i].y - coordinates[j].y) * 
				(coordinates[i].y - coordinates[j].y))); // Calculate distance using distance formula

			if (distance <= coordinates[i].p) // Valid distance away from the current cow 
				graph[i].push_back(j);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){ // Loop through each cow
		set<int> num_visited; // Keep track of which cows were visited throughout the BFS search
		vector<bool> visited(n); // Whether or not each cow has been visited
		queue<int> q; // BFS queue
		q.push(i); // Initial value i
		while (!q.empty()){
			int curr = q.front(); // First element of the queue
			num_visited.insert(curr); // Add to the back of the queue
			visited[curr] = true; // Mark current cow as visited
			q.pop(); // Remove the first element
			for (int j = 0; j < graph[curr].size(); j++){ // Go through all of the connected neighbours of the current cow
				if (!visited[graph[curr][j]]){ // Add to queue only if the neighbour hasn't been visited yet
					q.push(graph[curr][j]);
				}
			}
		}

		ans = max(ans, (int)num_visited.size()); // Running maximum answer
	}

	cout << ans << endl;
}
