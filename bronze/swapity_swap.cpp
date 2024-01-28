#include <bits/stdc++.h>
using namespace std;

vector<int> reversed(int x, int y, vector<int> v){
    for (int i = x; i <= x + ((y - x) / 2); i++){
        if ((y - x) % 2 == 1){
            swap(v[i], v[(y - i + 1)]);
        } else {
            swap(v[i], v[(y - i + 2)]);
        }
    }
    return v;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> ordering(n);
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    a1--; a2--; b1--; b2--;

    for (int i = 0; i < n; i++)
        ordering[i] = i + 1;

    vector<int> cpy = ordering;
    int occurences = 0;
    for (int i = 0; i < n; i++){
        if (cpy == ordering && occurences > 0){
            break;
        }
        reverse(cpy.begin() + a1, cpy.begin() + a2 + 1);
        reverse(cpy.begin() + b1, cpy.begin() + b2 + 1);
        occurences++;
    }

    //cout << occurences << endl;

    for (int i = 0; i < k % occurences; i++){
        reverse(ordering.begin() + a1, ordering.begin() + a2 + 1);
        reverse(ordering.begin() + b1, ordering.begin() + b2 + 1);
    }

    for (int i = 0; i < n; i++)
        cout << ordering[i] << endl;
}
