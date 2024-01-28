#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> sorted_v = v;
	sort(sorted_v.begin(), sorted_v.end());

	int ans = 0;
	for (int i = n - 1; i >= 0; i--){
		if (v[i] == sorted_v[i])
			continue;

		for (int j = i - 1; j >= 0; j--){
			if (v[j] == sorted_v[j])
				continue;
			
			if (v[j] == sorted_v[i]){
				swap(v[i], v[j]);
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;
}
