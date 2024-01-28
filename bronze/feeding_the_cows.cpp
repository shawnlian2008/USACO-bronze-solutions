#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;

		int patchG, patchH;
		patchG = patchH = -k - 1;

		int count = 0;
		string ans(n, '.');

		for (int i = 0; i < n; i++) {
			if (s[i] == 'G' && i - patchG > k) {
				count++;
				if (i + k >= n) {
					patchG = i;
					if (ans[patchG] == 'H') patchG--;
				} else {
					patchG = i + k;
					if (ans[patchG] == 'H') patchG--;
				}
				ans[patchG] = 'G';
			}
			if (s[i] == 'H' && i - patchH > k) {
				count++;
				if (i + k >= n) {
					patchH = i;
					if (ans[patchH] == 'G') patchH--;
				} else {
					patchH = i + k;
					if (ans[patchG] == 'H') patchG--;
				}
				ans[patchH] = 'H';
			}
		}
		cout << count << "\n" << ans << endl;
	}
}
