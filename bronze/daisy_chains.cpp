#include <bits/stdc++.h>
using namespace std;

vector<double> v;
double getAvg(int x, int y) {
    double average = 0.0;
    for (int i = x; i <= y; i++){
        average += v[i];
    }
    return average / (y - x + 1);
}

bool inArray(int x, int y, double value){
    for (int i = x; i <= y; i++){
        if (v[i] == value) return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            //cout << i << " " << j << endl;
            //cout << getAvg(i, j) << endl;
            if (inArray(i, j, getAvg(i, j))){
                ans++;
                //cout << "YES" << endl;
            }
        }
    }

    cout << ans << endl;
}
