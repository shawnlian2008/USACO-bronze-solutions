#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
	int k, n; cin >> k >> n;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		int speed = 0, t = -1, dist_speeding_up = 0, dist_slowing_down = 0;
		while (dist_speeding_up + dist_slowing_down < k){
			if (speed >= x){
				dist_slowing_down += speed;
				t++;
			}
			if (dist_speeding_up + dist_slowing_down >= k)
				break;
			dist_speeding_up += speed;
			speed++;
			t++;
			
			//cout << speed << " " << t << " " << dist_speeding_up << " "
				//<< dist_slowing_down << endl;
		}
		cout << t << endl;
	}
}
