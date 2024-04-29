#include <bits/stdc++.h>
using namespace std;

int main() {
	int street_length, num_lights; cin >> street_length >> num_lights;
	set<int> s = {0, street_length}; // Holds all the positions of lights, initially the endpoints of the street
	multiset<int> lengths = {street_length}; // Hold all the lengths of the segments without traffic lights
	
	while (num_lights--){
		int pos; cin >> pos;

		auto after = s.upper_bound(pos), before = after; // Search for pointers to point to the positions with traffic lights before and after the new traffic light
		before--; // End points 1 index out of bounds so we move it down

		lengths.erase(lengths.find(*after - *before)); // Remove one of the previous length segments
		lengths.insert(*after - pos); // Insert the 2 broken up segments divided by the new traffic light
		lengths.insert(pos - *before);
		s.insert(pos); // Add the new light position to the set of positions

		auto largest = lengths.end();
		largest--;
		cout << *largest << endl; // Output the largest segment length
	}
}
