#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
	int n; cin >> n;
	vector<int> room_capacities(n);
	for (int i = 0; i < n; i++)
		cin >> room_capacities[i];
	
	int mn = INT_MAX;
	for (int room_number = 0; room_number < n; room_number++){
		int counter = 0, curr_room = room_number, sum = 0;
		while (counter < n){
			if (curr_room == n){
				curr_room = 0;
			}
			sum += room_capacities[curr_room] * counter;
			curr_room++;
			counter++;
		}
		mn = min(mn, sum);
	}

	cout << mn << endl;
}
