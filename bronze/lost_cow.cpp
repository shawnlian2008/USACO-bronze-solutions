#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("lostcow.out", "w", stdout);
	int x, y; cin >> x >> y;

	int factor = 1, ans = 0, which_way = 1, curr = x;
	//for (int i = 0; i < 250; i++) {
	while (true){
		if (which_way < 0){
			//shift negative
			int d = x - factor; 
			while (curr != d){
				curr--;
				ans++;
				if (curr == y){
					cout << ans << endl;
					return 0;
				}
			}
		} else {
			//shift positive
			int d = x + factor;
			while (curr != d){
				curr++;
				ans++;
				if (curr == y){
					cout << ans << endl;
					return 0;
				}
			}
		}

		which_way *= -1;
		factor *= 2;
	}
}
