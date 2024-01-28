#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> speeds;
	vector<int> bessie_speeds;

	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		for (int j = 0; j < a; j++){
			speeds.push_back(b);
		}
	}

	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		for (int j = 0; j < a; j++){
			bessie_speeds.push_back(b);
		}
	}

	int max_speed_break = -1;
	for (int i = 0; i < speeds.size(); i++)
		max_speed_break = max(bessie_speeds[i] - speeds[i], max_speed_break);
    
    if (max_speed_break == -1){
        cout << 0 << endl;
        return 0;
    }
	
	cout << max_speed_break << endl;
}
