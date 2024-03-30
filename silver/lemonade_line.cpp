#include <bits/stdc++.h>
using namespace std;

int main() {
  	freopen("lemonade.in", "r", stdin);
  	freopen("lemonade.out", "w", stdout);
	int n; cin >> n;
	vector<int> w(n); // Pair of cows in the format {id, wait}
	for (int i = 0; i < n; i++)
		cin >> w[i];

	// Sort by wait time
	sort(w.rbegin(), w.rend());

	vector<int> line;
	for (int i = 0; i < n; i++){
		if (w[i] < line.size())
			continue;
		else line.push_back(i);
	}

	cout << line.size() << endl;
}
