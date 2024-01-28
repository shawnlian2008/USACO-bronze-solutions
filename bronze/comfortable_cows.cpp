#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n;
bool occupied[1005][1005];
set<pair<int, int>> s;

bool valid(int x, int y){
	return x >= 0 && y >= 0 && x <= 1000 && y <= 1000;
}

bool comfortable(int x, int y){
	if (!occupied[x][y]) return false;
	int adj = 0;
	for (int d = 0; d < 4; d++){
		if (valid(x + dx[d], y + dy[d])){
			if (occupied[x + dx[d]][y + dy[d]]) adj++;
		}
	}
	return (adj == 3);
}

int main(){
	cin >> n;
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 1005; j++)
			occupied[i][j] == false;

	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
        //remove previous affected comfortable cows, since they are gonna be uncomfortable after adding the new cow
		for (int d = 0; d < 4; d++){
			int x = a + dx[d], y = b + dy[d];
			if (valid(x, y) && comfortable(x, y)) s.erase({x, y});
		}

		occupied[a][b] = true;

        //check how many are comfortable now after the new one
		for (int d = 0; d < 4; d++){
			int x = a + dx[d], y = b + dy[d];
			if (valid(x, y) && comfortable(x, y)) s.insert({x, y});
		}

        //check if this current cow is comfortable
		if (comfortable(a, b)) s.insert({a, b});
		cout << s.size() << endl;
	}
}
