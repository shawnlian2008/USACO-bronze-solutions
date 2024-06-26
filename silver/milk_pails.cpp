#include <bits/stdc++.h>
using namespace std;

int x, y, k, m, difference = INT_MAX;
bool visited[101][101][101]; // Visited array that keeps track of whether or not each combination was visited

void dfs(int pail1, int pail2, int times){
	if (visited[pail1][pail2][times] || times > k) return; // If this move is already visited or the number of operations exceeds k

	visited[pail1][pail2][times] = true; // Set current combination of amounts and operations visited

	times++; // Add to number of operations

	difference = min(difference, abs(m - (pail1 + pail2))); // Set the difference from the orders of milk

    // Fill either bucket 1 or 2 full
	dfs(pail1, y, times);
	dfs(x, pail2, times);

    // Empty either bucket 1 or 2
	dfs(pail1, 0, times);
	dfs(0, pail2, times);

    // Pour from bucket 2 to 1
	if (pail1 + pail2 <= x){
		dfs(pail1 + pail2, 0, times);
	} else {
		dfs(x, abs(pail1 + pail2 - x), times);
	} 

    // Pour from bucket 1 to 2
	if (pail1 + pail2 <= y){
		dfs(0, pail1 + pail2, times);
	} else {
		dfs(abs(pail1 + pail2 - y), y, times);
	} 
}

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	cin >> x >> y >> k >> m;

	dfs(0, 0, 0);

	cout << difference << endl;
}
