#include <bits/stdc++.h>
using namespace std;

int main() { 
  // Key observation: each connected component has 2 possible colourings, so the answer will just be all connected components multiplied by 2, and I don't fucking know how binary conversion works I just followed a tutorial on that part
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n); // Graph holding connected nodes
	vector<bool> visited(n);

	for (int i = 0; i < m; i++){
		char c; int a, b;
		cin >> c >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}

	string ans = "1";
	for (int i = 0; i < n; i++){ // Find all connected components
		if (visited[i]) continue;

		ans += "0";
		stack<int> st;
		st.push(i);
		while (!st.empty()){
			int curr = st.top();
			st.pop();
			visited[curr] = true;
			for (int j = 0; j < graph[curr].size(); j++){
				if (!visited[graph[curr][j]])
					st.push(graph[curr][j]);
			}
		}
	}

	cout << ans << "\n";
}
