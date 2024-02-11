#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n + 5, 0);
	for (int i = 0; i < k; i++){
		int start, end; cin >> start >> end;
		v[start]++; v[end + 1]--;
	}

	int factor = 0;
	vector<int> stacks(n + 1, 0);
	for (int i = 1; i <= n; i++){
		factor += v[i];
		stacks[i] += factor;
	}

	stacks.erase(stacks.begin());
	sort(stacks.begin(), stacks.end());

	cout << stacks[n / 2] << endl;
}
