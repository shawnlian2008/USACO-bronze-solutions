#include <bits/stdc++.h>
using namespace std;

struct Mountain{
    int leftX, rightX;
    bool operator<(const Mountain &m){ return leftX < m.leftX; };
};

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> peaks(n);
    for (int i = 0; i < n; i++)
        cin >> peaks[i].first >> peaks[i].second;

    vector<Mountain> v;
    for (int i = 0; i < n; i++)
        v.push_back({peaks[i].first - peaks[i].second, peaks[i].first + peaks[i].second});

    sort(v.begin(), v.end());

    int ans = 0;
    int rightMost = INT_MIN;
    for (int i = 0; i < n; i++){
        if (v[i].rightX > rightMost){
            rightMost = v[i].rightX;
            ans++;
        }
    }

    cout << ans << endl;
}
