#include <bits/stdc++.h>
using namespace std;

//#1: how many single routes connect the starting city to the goal city
//If the cities are in the route, and
//if the index of the starting city in the route is before/less than the ending city, add to vector
//Find the route with the greatest cost from there.

int main() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	int start, end, route_count; cin >> start >> end >> route_count;
	//holds cost to list of cities in each route in order
	vector<vector<int>> cities(route_count);
	vector<int> cost(route_count);
	vector<int> supported_routes;
	//first line of every route is cost and then number of cities, followed by another line of the cities in order
	for (int i = 0; i < route_count; i++){
		int city_count; cin >> cost[i] >> city_count;
		for (int j = 0; j < city_count; j++) {
			int a; cin >> a;
			cities[i].push_back(a);
		}
	}

	for (int i = 0; i < route_count; i++){
		vector<int>::iterator index1 = find(cities[i].begin(), cities[i].end(), start);
		vector<int>::iterator index2 = find(cities[i].begin(), cities[i].end(), end);
		if ((index1 == cities[i].end() || index2 == cities[i].end()) || 
			index1 > index2) continue;
		supported_routes.push_back(i);
	}

	if (supported_routes.empty()){
	}

	int minimum = 1000;
	if (supported_routes.empty()){
		minimum = -1;
	}
	for (int i = 0; i < supported_routes.size(); i++)
		minimum = min(cost[supported_routes[i]], minimum);

	cout << minimum << endl;
}
