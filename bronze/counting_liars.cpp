#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<char, int>> v;
    for (int i = 0; i < n; i++){
        char a; int m; cin >> a >> m;
        v.push_back({a, m});
    }

    sort(v.begin(), v.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    //brute force bessie's position
    int ans = INT_MAX;
    
    //loop through all necessary positions bessie could be at
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (v[j].first == 'G'){
                if (v[i].second < v[j].second){
                    cnt++;
                }
            } else {
                if (v[j].second < v[i].second){
                    cnt++;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}
