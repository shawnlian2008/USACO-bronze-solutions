#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<bool> ans(10), exists(10);

	//get user input and check the existing colours that we can see
	for (int i = 0; i < n; i++){
		string s; cin >> s; 
		for (int j = 0; j < n; j++){
			v[i][j] = s[j] - '0';
			if (v[i][j] > 0)
				ans[v[i][j]] = exists[v[i][j]] = true;
		}
	}

	for (int i = 0; i < 10; i++){
		if (exists[i]){
			int l = n, r = 0, d = n, u = 0;
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					if (v[j][k] == i){
						l = min(l, j);
						r = max(r, j);
						d = min(d, k);
						u = max(u, k);
					}
				}
			}	
			for (int j = l; j <= r; j++){
				for (int k = d; k <= u; k++){
					if (v[j][k] != i){
						ans[v[j][k]] = false;
					}
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < 10; i++){
		if (ans[i]) count++;
	}

	cout << count << endl;
}
