#include <bits/stdc++.h>
using namespace std;

int x, y, m, maximum;

void find_sum(int total){
    maximum = max(maximum, total);
    if (total + x <= m){
        find_sum(total + x);
    }

    if (total + y <= m){
        find_sum(total + y);
    }
}

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> m;

    find_sum(0);

    cout << maximum << endl;
}
