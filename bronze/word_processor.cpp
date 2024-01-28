#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int n, k; cin >> n >> k; 
	string words[n];

	for (int i = 0; i < n; i++) cin >> words[i];

	vector<string> format;

	string ans = words[0];
	int len = words[0].length();
	for (int i = 1; i < n; i++){
		if (len + words[i].length() > k){
			format.push_back(ans);
			ans = words[i];
			len = words[i].length();
			continue;
		}
		ans += " ";
		ans += words[i];
		len += words[i].length();
	}

	format.push_back(ans);

	for (string word : format){
		cout << word << endl;
	}
}
