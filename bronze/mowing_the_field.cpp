#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	vector<pair<pair<int, int>, int>> cells_visited;
	vector<int> revisit_times;
	int n; cin >> n;

	pair<int, int> currCell = {0, 0};
	cells_visited.push_back({currCell, 0});
	int t = 0;
	for (int i = 0; i < n; i++){
		char dir; int steps; cin >> dir >> steps;
		if (dir == 'N'){
			for (int j = 0; j < steps; j++){
				currCell.second++;
				//cout << "(" << currCell.first << ", " << currCell.second << ")" << endl;
				t++;
				cells_visited.push_back({currCell, t});
				for (int k = 0; k < cells_visited.size() - 1; k++){
					if (cells_visited[k].first == currCell){
						revisit_times.push_back(t - cells_visited[k].second);
						break;
					}
				}
			}
		} else if (dir == 'S'){
			for (int j = 0; j < steps; j++){
				currCell.second--;
				//cout << "(" << currCell.first << ", " << currCell.second << ")" << endl;
				t++;
				cells_visited.push_back({currCell, t});
				for (int k = 0; k < cells_visited.size() - 1; k++){
					if (cells_visited[k].first == currCell){
						revisit_times.push_back(t - cells_visited[k].second);
						break;
					}
				}
			}
		} else if (dir == 'E'){
			for (int j = 0; j < steps; j++){
				currCell.first++;
				//cout << "(" << currCell.first << ", " << currCell.second << ")" << endl;
				t++;
				cells_visited.push_back({currCell, t});
				for (int k = 0; k < cells_visited.size() - 1; k++){
					if (cells_visited[k].first == currCell){
						revisit_times.push_back(t - cells_visited[k].second);
						break;
					}
				}
			}
		} else {
			for (int j = 0; j < steps; j++){
				currCell.first--;
				//cout << "(" << currCell.first << ", " << currCell.second << ")" << endl;
				t++;
				cells_visited.push_back({currCell, t});
				for (int k = 0; k < cells_visited.size() - 1; k++){
					if (cells_visited[k].first == currCell){
						revisit_times.push_back(t - cells_visited[k].second);
						break;
					}
				}
			}
		}
	}

	if (revisit_times.empty()){
		cout << -1 << endl;
		return 0;
	}

	cout << *min_element(revisit_times.begin(), revisit_times.end()) << endl;
}
