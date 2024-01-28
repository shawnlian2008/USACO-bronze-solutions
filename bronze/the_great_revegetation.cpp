#include <bits/stdc++.h>
using namespace std;

vector<int> rm(vector<int> g, int item){
	for (int i = 0; i < g.size(); i++){
		if (g[i] == item){
			g.erase(g.begin() + i);
		}
	}
	return g;
}

int main(){
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> v[n];

	vector<int> grass_assignments(n, -1);
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++){
		//go through all neighbouring nodes, eliminating the unavailable grass types from array
		vector<int> grass_types{1, 2, 3, 4};

		for (int j = 0; j < v[i].size(); j++){
			if (grass_assignments[v[i][j]] == 1)
				grass_types = rm(grass_types, 1);
			else if (grass_assignments[v[i][j]] == 2)
				grass_types = rm(grass_types, 2);
			else if (grass_assignments[v[i][j]] == 3)
				grass_types = rm(grass_types, 3);
			else if (grass_assignments[v[i][j]] == 4)
				grass_types = rm(grass_types, 4);
			else continue;
		}

		if (grass_types.empty()){
			cout << -1 << endl;
			return 0;
		}

		grass_assignments[i] = grass_types[0];
	}

	for (int i = 0; i < n; i++)
		cout << grass_assignments[i];
}
