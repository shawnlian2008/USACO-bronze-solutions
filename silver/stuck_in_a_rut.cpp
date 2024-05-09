#include <bits/stdc++.h>
using namespace std;

struct Cow{
	int index, x, y;
};

int main() {
	int n; cin >> n;

	vector<Cow> north, east; // Lists of all cows facing east and north
	vector<bool> stopped(n); // Keep track of whether or not each cow has stopped
	vector<int> ans(n, 0); // Blames of each cow

	for (int i = 0; i < n; i++){
		char direction; int x, y;
		cin >> direction >> x >> y;
		
		if (direction == 'N') // Sort north and east directions
			north.push_back({i, x, y});
		else east.push_back({i, x, y});
	}

	// Sort norths by x, top to bottom
	sort(north.begin(), north.end(), [](const Cow &a, const Cow &b){
		if (a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	});

	// Sort easts by y, left to right
	sort(east.begin(), east.end(), [](const Cow &a, const Cow &b){
		if (a.y == b.y) return a.x < b.x;
		else return a.y < b.y;
	});

	// Go through all pairs of north and east cows from least to greatest x and y's
	for (int i = 0; i < north.size(); i++){
		for (int j = 0; j < east.size(); j++){
			// Stop if they have 0 chances of ever colliding (if either they're past each other or they're already stopped)
			if (east[j].x > north[i].x || north[i].y > east[j].y || stopped[north[i].index] || stopped[east[j].index])
				continue;
			
			// vertical distance between 2 cows
			int northDist = east[j].y - north[i].y;
			// horizontal distance between 2 cows
			int eastDist = north[i].x - east[j].x;

			// if the east one collides first
			if (northDist < eastDist){
				stopped[east[j].index] = true; // mark as stopped
				ans[north[i].index] += ans[east[j].index] + 1; // transitive
			} else if (eastDist < northDist){ // if north collides first
				stopped[north[i].index] = true; // mark as stopped
				ans[east[j].index] += ans[north[i].index] + 1; // transitive
			}
			else continue;
		}
	}

	// output the answers
	for (int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
}
