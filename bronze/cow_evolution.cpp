#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int n; 
vector<string> cows[30];
vector<string> allCharacteristics;

bool check(int a, int b){
	bool aNotB = false, bNotA = false, both = false;
	for (int i = 0; i < n; i++){
		bool hasA = false, hasB = false;
		for (int j = 0; j < cows[i].size(); j++){
			if (cows[i][j] == allCharacteristics[a])
				hasA = true;
			if (cows[i][j] == allCharacteristics[b])
				hasB = true;
		}
		if (hasA && !hasB)
			aNotB = true;
		if (hasB && !hasA)
			bNotA = true;
		if (hasA && hasA)
			both = true;
	}

	if (aNotB && bNotA && both)
		return false;

	return true;
}

int main() {
	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);
	cin >> n;
	int num; string characteristic; 
	for (int i = 0; i < n; i++){
		cin >> num;
		for (int j = 0; j < num; j++){
			cin >> characteristic;
			cows[i].push_back(characteristic);
			if (find(all(allCharacteristics), characteristic) ==
				allCharacteristics.end()){
				allCharacteristics.push_back(characteristic);
			}
		}
	}

	for (int i = 0; i < allCharacteristics.size(); i++){
		for (int j = i + 1; j < allCharacteristics.size(); j++){
			if (!check[i][j]){
				cout << "no" << endl;
				return 0;
			}
		}
	}

	cout << "yes" << endl;
}
