#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string s; cin >> n >> s;

    //gets all lengths of segments of infected cows
    vector<int> segments;
    int region = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            region++;
        } else {
            if (region > 0) {
                segments.push_back(region);
                region = 0;
            }
        }
    }

    if (region > 0)
        segments.push_back(region);


    int minBlock[2] = {INT_MAX, INT_MAX}, minEnd = INT_MAX,
        sind = 0, eind = segments.size() - 1;

    //both ends edge cases
    if (s[0] == '1') {
        minEnd = min(minEnd, segments[sind++]);
    }

    if (s[n - 1] == '1') {
        minEnd = min(minEnd, segments[eind]);
        eind--;
    }

    for (int i = sind; i <= eind; i++)
        minBlock[segments[i] % 2] = min(minBlock[segments[i] % 2], segments[i]);

    int daySpread = min(minEnd * 2 - 1, min(minBlock[0] - 1, minBlock[1]));
    int numInfected = 0;

    for (int block : segments) {
        numInfected += (block + daySpread - 1) / daySpread;
    }

    cout << numInfected << endl;

    return 0;
}
