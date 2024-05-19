#include <bits/stdc++.h>
using namespace std;

int main() { // STATUS: TEST CASE 43
	int g; cin >> g;
	vector<int> arr_g(g); // Girls' dance skill levels
	for (int i = 0; i < g; i++)
		cin >> arr_g[i]; 

	sort(arr_g.begin(), arr_g.end()); // Sort array

	int b; cin >> b;
	multiset<int> arr_b; // Boys dance skills
	for (int i = 0; i < b; i++){
		int s; cin >> s;
		arr_b.insert(s);
	}
	
	int ans = 0;
	for (int i = 0; i < arr_g.size(); i++){ // Loop through all girls' dance skills
		auto ptr = lower_bound(arr_b.begin(), arr_b.end(), arr_g[i]); // Find a dance skill from the boys that is less than or equal to the skills of the girls
		if (ptr == arr_b.begin()){ // If first element is already greater than or equal to current girl skills
			if (abs(*ptr - arr_g[i]) <= 1){ // If the first element greater than or equal to the current girl's skill's differences is less than 1, then add to answer and remove that already paired up boy from the multiset
				ans++;
				arr_b.erase(arr_b.find(*ptr));
			}
		} else {
			ptr--; 
			if (abs(*ptr - arr_g[i]) <= 1){ // First element less than skill
				ans++;
				arr_b.erase(arr_b.find(*ptr)); // Remove from multiset
			} else {
				ptr++;
				if (abs(*ptr - arr_g[i]) <= 1){ // First element greater than or equal to skill
					ans++;
					arr_b.erase(arr_b.find(*ptr)); // Remmove from multiset
				}
			}
		}
	}

	cout << ans << endl;
}
