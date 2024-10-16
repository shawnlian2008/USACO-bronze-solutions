#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> vertices(n); // Vertices of the park
	for (int i = 0; i < n; i++)
	 	cin >> vertices[i];
		
	vector<vector<int>> graph(n); // Paths

	for (int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		graph[--x].push_back(--y);
		graph[y].push_back(x);
	}

	int ans = 0;
	vector<bool> visited(n);
	queue<pair<int, int>> q; // BFS queue
	q.push({0, (vertices[0] == 1)}); // Add vertex 1 starting point to the queue
	while (!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();

		if (visited[curr.first] || curr.second > m)
			continue;

		visited[curr.first] = true;

		if (vertices[curr.first] == 0) // Reset, because of the consecutive cats rule
			curr.second = 0;

		if (graph[curr.first].size() == 1 && curr.first != 0) // If a restaurant has been reached
			ans++;

		for (int i = 0; i < graph[curr.first].size(); i++)
			q.push({graph[curr.first][i], curr.second + (vertices[graph[curr.first][i]] == 1)}); // Update number of cats on path
	}

	cout << ans << endl;
}
