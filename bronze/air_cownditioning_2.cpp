// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int start, end;
	int cool_req;
};

struct AC {
	int start, end;
	int cool_amt;
	int cost;
};

int main() {
	int cow_num, ac_num; cin >> cow_num >> ac_num;

	vector<Cow> cows(cow_num);
	for (Cow &c : cows)
		cin >> c.start >> c.end >> c.cool_req;

	vector<AC> acs(ac_num);
	for (AC &ac : acs)
		cin >> ac.start >> ac.end >> ac.cool_amt >> ac.cost;

	int min_cost = INT32_MAX;
	for (int ss = 0; ss < (1 << ac_num); ss++){//checking from AC 0 to 2^AC - 1
		vector<int> stalls(101);// index 0 won't be used
		int cost = 0;
		for (int a = 0; a < ac_num; a++){// loop through all AC's, check if they're included in the subset
			if (ss & (1 << a)){// if this result is non-zero
				for (int i = acs[a].start; i <= acs[a].end; i++){
					stalls[i] += acs[a].cool_amt;
				}
				cost += acs[a].cost;
			}
		}

		for (Cow &c : cows)
			for (int i = c.start; i <= c.end; i++)
				if (stalls[i] < c.cool_req)
					goto end;
		
		min_cost = min(min_cost, cost);
		end:;
	}

	cout << min_cost << endl;
}
