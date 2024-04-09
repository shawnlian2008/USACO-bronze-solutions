#include <bits/stdc++.h>
using namespace std;

int main() { // Operations with data structures
	// Multiset benefits: easy to remove and easy to get sorted values from with upper_bound and lower_bound
	int n, m; cin >> n >> m;
	multiset<int> tickets; // Hold the maximum prices of customers in a multiset
	for (int i = 0; i < n; i++){
		int price; cin >> price;
		tickets.insert(price);
	}

	vector<bool> used(n, false);
	for (int i = 0; i < m; i++){
		int d; cin >> d; // Input as you go
		auto it = tickets.upper_bound(d);
		if (it == tickets.begin()){ // No optimal ticket, all tickets are greater than the wanted ticket for this customer
			cout << -1 << endl;
			continue;
		}

		cout << *--it << endl; // Since upper_bound returns the value strictly greater than the value passed in, and we're supposed to find the value less than or equal to the value passed in, we decrement iterator, since the previous element is guaranteed to be smaller than or equal to the wanted price in this case
		tickets.erase(it); // Remove ticket from multiset
	}
}
