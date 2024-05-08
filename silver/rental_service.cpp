#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	int n, m, r; cin >> n >> m >> r;

	vector<int> milk_amt(n), rent(r);
	vector<pair<int, int>> shops(m); // {price of each gallon, max gallons that they can accept}

	for (int i = 0; i < n; i++)
		cin >> milk_amt[i];

	for (int i = 0; i < m; i++) 
		cin >> shops[i].second >> shops[i].first;

	for (int i = 0; i < r; i++) 
		cin >> rent[i];
  
	sort(milk_amt.rbegin(), milk_amt.rend()); // Sort cows by milk production in descending order
	sort(shops.rbegin(), shops.rend()); // Sort shops by selling price in descending order
	sort(rent.rbegin(), rent.rend()); // Sort rent in descending order

	int rent_at = 0, shop_at = 0, cow_at = 0; // Pointers
	long long ans = 0;
	while (cow_at < n) {
		int amt = milk_amt[cow_at]; // Milk amount of the current cow
		int sold_money = 0; // Money that will be made from sold milk
		int curr_shop = shop_at; // The current shop
		int last = 0;

		// Calculate how much money this cow can make if we sell its milk
		while (curr_shop < m) {
			int sold = min(amt, shops[curr_shop].second); // The most amount of milk that you can sell for this store
			sold_money += shops[curr_shop].first * sold; // Money made from the milk that is sold at this store
			amt -= sold; // Subtract the milk sold from the cow's milk amount for the day

			if (amt == 0) { // If there is no more milk left
				last = sold; // Number of gallons sold to this store (need to keep track so that we can know how much more milk the store is willing to accept)
				break;
			} else {
				curr_shop++; // Keep going if there's still unsold milk
			}
		}

		if (rent_at >= r || sold_money > rent[rent_at]) { // If there is no more farmers who want to rent the cows or we can make more money by selling milk than renting the cow
			ans += sold_money; // Add the sold money to answer to contribute to the total amount of money made for the day
			shop_at = curr_shop; // Set the current shop (how many shops we went thru by selling this cow's milk)
			// subtract the amount sold to the last store from this store
			if (shop_at < m) { shops[shop_at].second -= last; } // Only if there are still shops left, calculate how much more milk the current shop will accept 
			cow_at++; // Go to the next cow to evaluate what to do with them
		} else { // You can make more by putting the cow out for rent
			ans += rent[rent_at]; // Add to amount we can make with the cow
			n--; // Move on from this cow, since we only loop through the cows that are possible to sell milk
			rent_at++; // Set pointer to next rented cow
		}
	}
	cout << ans << endl;
}
