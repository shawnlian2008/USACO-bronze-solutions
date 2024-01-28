// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("paint.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("paint.out", "w", stdout);
	int a, b, c, d; cin >> a >> b >> c >> d;
	vector<int> painted(101);
	int ans = 0;
	for (int i = a; i < b; i++)
		painted[i] = 1;

	for (int i = c; i < d; i++)
		painted[i] = 1;

	for (int i = 0; i < 101; i++){
		if (painted[i] == 1){
			ans++;
		}
	}
	cout << ans << endl;
}
