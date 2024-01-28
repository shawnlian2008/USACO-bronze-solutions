#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<int> elsie_log = vector<int>(n);
		int log_sum = 0;
		for (int &h : elsie_log) {
			cin >> h;
			log_sum += h;
		}

		// Try all possible number of hours after modification
		for (int num_hours = 0; num_hours <= log_sum; num_hours++) {
			if (num_hours != 0 && log_sum % num_hours != 0) {
				// The sum must be divisible by num_hours
				continue;
			}

			// Check if num_hours leads to a valid answer
			int curr_sum = 0;  // The current number of hours Elsie's logging
			bool valid = true;
			for (int h : elsie_log) {
				curr_sum += h;
				if (curr_sum > num_hours) {
					valid = false;  // curr_sum can't exceed num_hours
					break;
				} else if (curr_sum == num_hours) {
					curr_sum = 0;
				}
			}

			if (valid) {
				if (num_hours == 0) {
					// Handle the edge case where num_hours is 0
					cout << 0 << '\n';
				} else {
					// sum/num_hours is the total # of classes AFTER modifying
					cout << n - log_sum / num_hours << '\n';
				}
				break;
			}
		}
	}
}
