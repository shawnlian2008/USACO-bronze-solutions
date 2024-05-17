#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;

		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		set<int> all_nums;
		for (int i = 0; i < n - 2; i++){
			//cout << v[i] << " " << v[i + 2] << endl;
			if (v[i] == v[i + 1])
				all_nums.insert(v[i]);
			else if (v[i] == v[i + 2]){
				all_nums.insert(v[i]);
			} else if (v[i + 1] == v[i + 2]){
				all_nums.insert(v[i + 1]);
			}
		}

		vector<int> ans(all_nums.begin(), all_nums.end());
		if (ans.size() == 0){
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i];
			if (i < ans.size() - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
