#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> friends;
vector<bool> visited;
vector<int> assigned;

bool yuh;
void dfs(int node, int assignment){
	//cout << assignment << endl;
	assigned[node] = assignment;
	visited[node] = true;
	for (int i = 0; i < friends[node].size(); i++){
		if (assigned[friends[node][i]] == assignment){
			yuh = true;
			return;
		}

		if (!visited[friends[node][i]]){
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
	for (int i = 0; i < n; i++){
		if (visited[i]) continue;
	
		dfs(i, 1);
	}

	if (yuh) cout << "IMPOSSIBLE" << endl;
	else {
		for (int i = 0; i < n; i++){
			cout << assigned[i];
			if (i != n - 1) cout << " ";
		}
	}
}
