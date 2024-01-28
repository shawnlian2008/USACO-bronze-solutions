// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int manhattan_distance(int x1, int y1, int x2, int y2){
	return abs(
		x2 - x1
	) + abs(
		y2 - y1
	);
}

int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> checkpoints(n);
	//prefix sum
	int distance_travelled[n];
	//use 2 variables to hold greatest and the index at greatest
	int max_reduced_distance = -1, index = 0;
	for (int i = 0; i < n; i++){
		//get every checkpoint by input
		cin >> checkpoints[i].first >> checkpoints[i].second;
		//for each checkpoint:
		//if first iteration, then set the prefix array's first value to 0 
			//(no distance covered yet.)
		if (i == 0) distance_travelled[i] = 0;
		else {
			//after that, start adding to prefix array sum.
			distance_travelled[i] = distance_travelled[i - 1] + 
				manhattan_distance(
					checkpoints[i].first, checkpoints[i].second, 
					checkpoints[i - 1].first, checkpoints[i - 1].second
				);
			//if 3rd iteration or more, calculate the reduced distance to
				//if we were to pass the checkpoint and if we were to 
					//skip the checkpoint
			if (i >= 2){
				//goal to find the index of the checkpoint where the reduced distance
					//is greatest
				int reduced_distance = 
					(distance_travelled[i] - distance_travelled[i - 2]) - abs(
						manhattan_distance(
							checkpoints[i].first, checkpoints[i].second,
							checkpoints[i - 2].first, checkpoints[i - 2].second
						)
					);
				
				//cout << "reduced distance: " << reduced_distance << endl;
				//afterwards, subtract the reduced distance of that checkpoint from 
					//the total sum
				if (reduced_distance > max_reduced_distance){
					max_reduced_distance = reduced_distance;
					index = i - 1;
				}
			}
		}
	}

	/*cout << index << endl;

	for (int i = 0; i < n; i++){
		cout << distance_travelled[i] << endl;
	}*/

	cout << distance_travelled[n - 1] - max_reduced_distance << endl;
}
