#include <bits/stdc++.h>
using namespace std;

long long llmax(long long a, long long b){
  return (a > b) ? a : b;
}

int main() {
	freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
	int n; cin >> n;
	vector<int> connected[100005];

	for (int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		connected[a].push_back(b);
		connected[b].push_back(a);
	}

	long long maximum = 0;
	for (int i = 0; i < 100005; i++)
		maximum = llmax(maximum, connected[i].size());

	cout << maximum + 1 << endl;
}
