#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("square.out", "w", stdout);
	int x1, y1, x2, y2, x3, y3, x4, y4; 
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int maxX = max(max(max(x1, x2), x3), x4);
	int maxY = max(max(max(y1, y2), y3), y4);
	
	int minX = min(min(min(x1, x2), x3), x4);
	int minY = min(min(min(y1, y2), y3), y4);

	cout << max(abs(maxX - minX), abs(maxY - minY)) * max(abs(maxX - minX), abs(maxY - minY)) << endl;
}
