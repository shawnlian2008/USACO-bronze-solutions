#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	vector<int> capacities(3, 0);
	vector<int> holdings(3, 0);
	for (int i = 0; i < 3; i++)
		cin >> capacities[i] >> holdings[i];
	
	int index = 1;
	for (int i = 0; i < 100; i++){
		//cout << index << endl;
		if (index != 3){
			if (holdings[index] + holdings[index - 1] > capacities[index]){
				holdings[index - 1] = (holdings[index] + holdings[index - 1]) - capacities[index];
				holdings[index] = capacities[index];
			} else {
				holdings[index] += holdings[index - 1];
				holdings[index - 1] = 0;
			}
		} else {
			if (holdings[0] + holdings[index - 1] > capacities[0]){
				holdings[index - 1] = (holdings[0] + holdings[index - 1]) - capacities[0];
				holdings[0] = capacities[0];
			} else {
				holdings[0] += holdings[index - 1];
				holdings[index - 1] = 0;
			}
			index = 0;
		}
		//cout << holdings[0] << " " << holdings[1] << " " << holdings[2] << endl;
		index++;
	}

	cout << holdings[0] << "\n" << holdings[1] << "\n" << holdings[2] << endl;
}
