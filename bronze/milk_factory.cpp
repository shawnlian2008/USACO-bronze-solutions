#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> from;

bool yes(int starting_node){
	int curr_node = starting_node;
	set<int> nodes_visited;
	vector<int> neighbours = {starting_node};
	nodes_visited.insert(starting_node);
	while (!neighbours.empty()){
		vector<int> new_neighbours;
		for (int i = 0; i < neighbours.size(); i++){
			//cout << neighbours[i] << endl;
			nodes_visited.insert(neighbours[i]);
			for (int j = 0; j < from[neighbours[i]].size(); j++){
				new_neighbours.push_back(from[neighbours[i]][j]);
			}
		}
		neighbours = new_neighbours;
	}

	return (nodes_visited.size() == n) ? true : false;
}

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	cin >> n;
	from.resize(n);
	for (int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		from[b].push_back(a);
	}

	//go thru each node until we find one that goes thru everything
	for (int i = 0; i < n; i++){
		if (yes(i)){
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
