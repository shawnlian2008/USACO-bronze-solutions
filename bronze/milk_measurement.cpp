#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n; cin >> n;
    vector<tuple<int, string, int>> info;
    for (int i = 0; i < n; i++){
        int day; string name, change;
        cin >> day >> name >> change;
        int inChange = 0;
        if (change[0] == '+') inChange = stoi(change.substr(1, change.length() - 1));
        else inChange = stoi(change);
        info.push_back({day, name, inChange});
    }
    
    sort(info.begin(), info.end());
    
    vector<pair<string, int>> stats;
    stats.push_back({"Bessie", 7});
    stats.push_back({"Elsie", 7});
    stats.push_back({"Mildred", 7});

    int ans = 0;
    string winner, prevWinner;
    for (int i = 0; i < n; i++){
        if (get<1>(info[i]) == "Bessie") stats[0].second += get<2>(info[i]);
        else if (get<1>(info[i]) == "Elsie") stats[1].second += get<2>(info[i]);
        else if (get<1>(info[i]) == "Mildred") stats[2].second += get<2>(info[i]);
        
        int max = 0;
        for (int j = 0; j < 3; j++){
            if (stats[j].second > max) {
                winner = stats[j].first;
                max = stats[j].second;
            }
        }

        if (winner != prevWinner)
            ans++;

        prevWinner = winner;

        //cout << stats[0].first << " " << stats[0].second <<
        //    " " << stats[1].first << " " << stats[1].second << " " << stats[2].first << " " << stats[2].second << endl;
    }

    cout << ans << endl;
}
