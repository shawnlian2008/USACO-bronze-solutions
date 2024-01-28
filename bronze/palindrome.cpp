#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> fields;
vector<string> paths;

int ans = 0;
void recurse_fields(string path, pair<int, int> current_cell){
	if (current_cell.first == n - 1 && 
		current_cell.second == n - 1){
		string reversed = path;
		reverse(path.begin(), path.end());
		if (strcmp(path.c_str(), reversed.c_str()) == 0){
			//cout << path << " " << reversed << endl;
			paths.push_back(path);
			ans++;
		}
		return;
	}

	if (current_cell.first + 1 < n) {
		path += fields[current_cell.first + 1][current_cell.second];
		recurse_fields(path, 
			make_pair(current_cell.first + 1, current_cell.second));
		path.pop_back();
	}
	if (current_cell.second + 1 < n){
		path += fields[current_cell.first][current_cell.second + 1];
		recurse_fields(path, 
			make_pair(current_cell.first, current_cell.second + 1));
		path.pop_back();
	}
}

int main() {
	freopen("palpath.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("palpath.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		string owobo; cin >> owobo;
		fields.push_back(owobo);
	}

	string placeholder = "";
	placeholder += fields[0][0];
	recurse_fields(placeholder, make_pair(0, 0));

	sort(paths.begin(), paths.end());
	paths.erase(unique(paths.begin(), paths.end()), paths.end());

	for (int i = 0; i < paths.size(); i++){
		cout << paths[i] << endl;
	}
	
	cout << paths.size() << endl;
}
