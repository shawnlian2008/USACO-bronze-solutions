
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int n; cin >> n;
	vector<int> v(n);
	set<int> rrr;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		rrr.insert(v[i]);
	}

	if (rrr.size() == 1){
		cout << 1 << " " << n << endl;
		return 0;
	}
	
	int minimum = 1, maximum = 1, seq = 0;
	for (int i = 1; i < n; i++){
		//cout << minimum << " " << maximum << endl;
		//cout << "Seq: " << seq << " " << v[i] << endl;
		if (v[i] == 0 && i > 0){
			minimum++;
			maximum++;
			maximum += seq;
			seq = 0;
		} else if (v[i] == -1){
			seq++;
		} else {
			if (i < v[i]){
				cout << -1 << endl;
				return 0;
			}
			if (v[i - v[i]] != 0 && v[i - v[i]] != -1){
				cout << -1 << endl;
				return 0;
			}
			if (v[i] > 0 && seq > 0){
				if (v[i] <= seq){
					minimum++;
					maximum += seq - v[i] + 1;
				}
			}
			seq = 0;
		}
	}

	//we know there's a breakout on the first day

	cout << minimum << " " << maximum << endl;
}
