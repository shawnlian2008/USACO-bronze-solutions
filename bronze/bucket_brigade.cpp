#include <bits/stdc++.h>
using namespace std;

pair<int, int> lake, barn;
vector<vector<bool>> isRock;
vector<string> field(10);
bool indicator = false;
int counter = 0;

void find_way(vector<pair<int, int>> a){
	counter++;
	vector<pair<int, int>> next_a;
    for (int i = 0; i < a.size(); i++){
		int x = a[i].first, y = a[i].second;
		field[x][y] = 'C';
		if (x == barn.first && y == barn.second){
			indicator = true;
			return;
		}
		if (x > 0 && !isRock[x - 1][y] && field[x - 1][y] != 'C'){
			next_a.push_back({x - 1, y});
		}
		if (x < 9 && !isRock[x + 1][y] && field[x + 1][y] != 'C'){
			next_a.push_back({x + 1, y});
		}
		if (y > 0 && !isRock[x][y - 1] && field[x][y - 1] != 'C'){
			next_a.push_back({x, y - 1});
		}
		if (y < 9 && !isRock[x][y + 1] && field[x][y + 1] != 'C'){
			next_a.push_back({x, y + 1});
		}
	}

	if (indicator)
		return;

	find_way(next_a);
}

int main() {
	for (int i = 0; i < 10; i++){
		cin >> field[i];
		isRock.push_back({false, false, false, false, false, false, false,
			false, false, false});
		for (int j = 0; j < 10; j++){
			if (field[i][j] == 'L')
				lake = {i, j};
			else if (field[i][j] == 'R')
				isRock[i][j] = true;
			else if (field[i][j] == 'B')
				barn = {i, j};
		}
	}

	find_way({lake});

	/*for (int i = 0; i < 10; i++){
		cout << field[i] << endl;
	}*/
	cout << counter - 2 << endl;
}
