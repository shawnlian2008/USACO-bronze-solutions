#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("notlast.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("notlast.out", "w", stdout);
	int n; cin >> n;
	vector<pair<string, int>> milk_counts;
	milk_counts.push_back(make_pair("Bessie", 0));
	milk_counts.push_back(make_pair("Elsie", 0));
	milk_counts.push_back(make_pair("Daisy", 0));
	milk_counts.push_back(make_pair("Gertie", 0));
	milk_counts.push_back(make_pair("Annabelle", 0));
	milk_counts.push_back(make_pair("Maggie", 0));
	milk_counts.push_back(make_pair("Henrietta", 0));

	if (n == 1){
		string name; int count; cin >> name >> count;
		cout << name << endl;
		return 0;
	}

	while (n--){
		string name; int milk_produced; cin >> name >> milk_produced;
		if (name == "Bessie")
			milk_counts[0].second += milk_produced;
		else if (name == "Elsie")
			milk_counts[1].second += milk_produced;
		else if (name == "Daisy")
			milk_counts[2].second += milk_produced;
		else if (name == "Gertie")
			milk_counts[3].second += milk_produced;
		else if (name == "Annabelle")
			milk_counts[4].second += milk_produced;
		else if (name == "Maggie")
			milk_counts[5].second += milk_produced;
		else if (name == "Henrietta")
			milk_counts[6].second += milk_produced;
	}

	std::sort(milk_counts.begin(), milk_counts.end(), [](auto &left, auto &right) {
    	return left.second > right.second;
	});

	//cout << milk_counts[5].second << endl;

	pair<string, int> second_to_last;
	for (int i = 6; i > 0; i--){
		//cout << i << " " << milk_counts[i].second << " " << milk_counts[i - 1].second << endl;
		if (milk_counts[i].second != milk_counts[i - 1].second){
			second_to_last.first = milk_counts[i - 1].first;
			second_to_last.second = milk_counts[i - 1].second;
			if ((milk_counts[i - 2].second != second_to_last.second) && i >= 2){
				cout << second_to_last.first << endl;
				return 0;
			} else {
				cout << "Tie" << endl;
				return 0;
			}
		}
	}

	cout << "Tie" << endl;
}
