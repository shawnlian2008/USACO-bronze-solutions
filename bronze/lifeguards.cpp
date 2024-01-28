#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    vector<int> times(1001, 0);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        int start, end; cin >> start >> end;
        for (int j = start; j < end; j++)
            times[j]++;
        v.push_back({start, end});
        //cout << endl;
    }

    int times_covered = 0;
    for (int i = 0; i < 1001; i++)
        if (times[i] > 0)
            times_covered++;
    
    //cout << times_covered << endl;

    int mn = INT_MIN;
    for (int i = 0; i < n; i++){
        int prev = times_covered;
        for (int j = v[i].first; j < v[i].second; j++)
            times[j]--;

        for (int j = v[i].first; j < v[i].second; j++)
            if (times[j] == 0)
                times_covered--;
        

        for (int j = v[i].first; j < v[i].second; j++)
            times[j]++;

        mn = max(mn, times_covered);
        times_covered = prev;
    }

    cout << mn << endl;
}
