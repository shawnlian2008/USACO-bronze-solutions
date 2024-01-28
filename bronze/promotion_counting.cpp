#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("promote.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("promote.out", "w", stdout);
	int bronzebefore, bronzeafter; cin >> bronzebefore >> bronzeafter;
	int silverbefore, silverafter; cin >> silverbefore >> silverafter;
	int goldbefore, goldafter; cin >> goldbefore >> goldafter;
	int platbefore, platafter; cin >> platbefore >> platafter;

	int platpromotions = platafter - platbefore;
	int goldpromotions = platpromotions + goldafter - goldbefore;
	int silverpromotions = goldpromotions + silverafter - silverbefore;
	cout << silverpromotions << "\n" << goldpromotions << "\n" << 
		platpromotions << endl;
}
