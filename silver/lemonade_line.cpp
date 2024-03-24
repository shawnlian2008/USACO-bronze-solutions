#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> w(n);
	map<int, int> id_to_w;
	for (int i = 0; i < n; i++){
		w[i].first = i;
		cin >> w[i].second;
		id_to_w[i] = w[i].second;
	}
	
	sort(w.rbegin(), w.rend(), [](const pair<int, int> a, const pair<int, int> b){
		return a.second < b.second;
	});

	vector<int> line;
	for (int i = 0; i < n; i++){
		if (w[i].second < line.size())
			continue;
		else line.push_back(i);
	}

	cout << line.size() << endl;
}
