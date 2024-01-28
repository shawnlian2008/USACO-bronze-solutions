#include <bits/stdc++.h>
using namespace std;

string strings[100];
int output[100];
bool used[100];

int n, m; 

bool split(int j, int comp, int out){
	if (used[j]) return false;
	for (int i = 0; i < m; i++){
		if (!strings[i].empty() && strings[i][j] == comp && output[i] != out){
			return false;
		}
	}
	used[j] = true;
	for (int i = 0; i < m; i++){
		if (!strings[i].empty() && strings[i][j] == comp) strings[i] = "";
	}
	return true;
}

bool all_equal(int test_out){
	for (int i = 0; i < m; i++)
		if (!strings[i].empty() && output[i] != test_out) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> strings[i] >> output[i];

		for (int j = 0; j < n; j++) used[j] = false;

		while (true){
			bool split_found = false;

			//try splitting by each bit
			for (int j = 0; j < n; j++){
				if (split(j, '0', 0) ||
					split(j, '0', 1) ||
					split(j, '1', 0) ||
					split(j, '1', 1)
				){
					split_found = true;
				}
			}

			if (!split_found){
				cout << "LIE\n";
				break;
			}

			if (all_equal(0) || all_equal(1)){
				cout << "OK\n";
				break;
			}
		}
	}
}
