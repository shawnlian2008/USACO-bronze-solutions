#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> positions;

set<int> get_size(int index){
	set<int> hold_ball;
	int curr_index = index, prev_size = 0;
	while (true){
		hold_ball.insert(curr_index);

		if (curr_index == 0)
			curr_index = 1;
		else if (curr_index == n - 1)
			curr_index = n - 2;
		else {
			int inx1 = positions[curr_index] - positions[curr_index - 1];
			int inx2 = positions[curr_index + 1] - positions[curr_index]; 

			if (inx1 <= inx2){
				curr_index = curr_index - 1;
			} else {
				curr_index = curr_index + 1;
			}
		}

		if (hold_ball.size() == prev_size)
			return hold_ball;
		
		prev_size = hold_ball.size();
	}
}

int main() {
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
	cin >> n;
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}
	positions.resize(n);
	for (int i = 0; i < n; i++)
		cin >> positions[i];
	
	sort(positions.begin(), positions.end());

	vector<set<int>> v(n);
	//find how many cows in total can hold the ball for each cow
	int largest_set_index, largest_set_size = 0;
	for (int i = 0; i < n; i++){
		v[i] = get_size(i);
		if (v[i].size() > largest_set_size){
			largest_set_index = i;
			largest_set_size = v[i].size();
		}
	}

	set<int> cow_hold_total = v[largest_set_index];
	v.erase(v.begin() + largest_set_index);

	int ans = 1;
	while (cow_hold_total.size() != n){
		int index_of_greatest = 0, size_of_greatest = 0;

		for (int i = 0; i < v.size(); i++){
			set<int> pdl = cow_hold_total;
			pdl.insert(v[i].begin(), v[i].end());
			if (pdl.size() > size_of_greatest){
				size_of_greatest = pdl.size();
				index_of_greatest = i;
			}
		}

		cow_hold_total.insert(v[index_of_greatest].begin(), v[index_of_greatest].end());
		v.erase(v.begin() + index_of_greatest);
		ans++;
	}

	cout << ans << endl;
}
