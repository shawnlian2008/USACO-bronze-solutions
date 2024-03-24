// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	int n; cin >> n;
	vector<int> e(n);
	map<int, bool> used;
	multiset<int> b;
	for (int i = 0; i < n; i++){
		cin >> e[i];
		used[e[i]] = true;
	}

	for (int i = 1; i <= 2 * n; i++)
		if (!used[i])
			b.insert(i);

	sort(e.begin(), e.end());

	int ans = 0;
	for (int i = 0; i < e.size(); i++){
		auto it = b.upper_bound(e[i]);

		/*for (int i : b) cout << i << " ";
		cout << endl;*/

		//no possible win for bessie this round
		if (it == b.end()){
			//use the smallest card in the set
			b.erase(b.begin());
		} else {
			ans++;
			b.erase(it);
		}
	}

	cout << ans << endl;
}
