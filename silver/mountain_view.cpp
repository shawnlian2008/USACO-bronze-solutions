#include <bits/stdc++.h>
using namespace std;

struct Mountain{
    int leftX, rightX;
    bool operator<(const Mountain &m){ return leftX < m.leftX; };
};

int main() { // Tags: Custom Sorting
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> peaks(n); // Coordinate of each mountain peak
    for (int i = 0; i < n; i++)
        cin >> peaks[i].first >> peaks[i].second;

    vector<Mountain> v; // {left x value, right x value}
    for (int i = 0; i < n; i++) // Get the left and right x values of each mountain
        v.push_back({peaks[i].first - peaks[i].second, peaks[i].first + peaks[i].second});

    sort(v.begin(), v.end()); // Sort by left x value least to greatest

    int ans = 0;
    int rightMost = INT_MIN; // Record the rightmost x value we've come across
    for (int i = 0; i < n; i++){
        if (v[i].rightX > rightMost){ // A mountain's peak is revealed if and only if the right x value exceeds the rightmost value come across so far
            rightMost = v[i].rightX;
            ans++;
        }
    }

    cout << ans << endl;
}
