#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i]; 
		v[i]--;
	}
	
	int lhi = 0, lgi = 0;

	//get the index of last G and last H
	for (int i = 0; i < n; i++){
		if (s[i] == 'H') lhi = i;
		else lgi = i;
	}

	//check if first cow contains all of its kind
	int gval = n, hval = n;
	for (int i = 0; i < n; i++){
		if (s[i] == 'H'){
			if (v[i] >= lhi) hval = i;
			break;
		}
	}

	for (int i = 0; i < n; i++){
		if (s[i] == 'G'){
			if (v[i] >= lgi) gval = i;
			break;
		}
	}

	//if none then -1
	if (hval == n) hval = -1;
	if (gval == n) gval = -1;

	//count number of pairs of leaders
	int c = 0;
	for (int i = 0; i < hval; i++){
		if (s[i] == 'G' && v[i] >= hval)
			c++;
		else if (i == gval) //if h cow contains g cow's leader
			c++;
	}

	for (int i = 0; i < gval; i++){
		if (s[i] == 'H' && v[i] >= gval)
			c++;
		else if (i == hval) //if g cow contains h cow's leader
			c++;
	}

	cout << c << endl;
}
