#include <bits/stdc++.h>
using namespace std;

int main() {
	string cowphabet, letters; cin >> cowphabet >> letters;
	map<char, int> index;
	for (int i = 0; i < 26; i++)
		index[cowphabet[i]] = i;

	int loop = 1;
	for (int i = 0; i < letters.length() - 1; i++){
		//cout << letters[i] << letters[i + 1] << endl;
		if (index[letters[i]] >= index[letters[i + 1]]){
			//cout << "yes" << endl;
			loop++;
		}
	}

	cout << loop << endl;
}
