#include <bits/stdc++.h>
using namespace std;

int r, c; 
vector<string> grid(r);

int ans = 0;
void recurse_grids(int index1, int index2){
	//cout << index1 << " " << index2 << endl;
	if (index1 == r - 1 && index2 == c - 1){
		//cout << "eeeee" << endl;
		ans++;
		return;
	}
	char square_colour = grid[index1][index2];
	//cout << square_colour << endl;
	for (int i = index1 + 1; i < r; i++){
		for (int j = index2 + 1; j < c; j++){
			if (grid[i][j] != square_colour){
				recurse_grids(i, j);
			}
		}
	}
}

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	cin >> r >> c;
	for (int i = 0; i < r; i++){
		string asjfog; cin >> asjfog;
		grid.push_back(asjfog);
	}
	
	recurse_grids(0, 0);
	cout << ans << endl;
}
