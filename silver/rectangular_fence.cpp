#include <bits/stdc++.h>
using namespace std;

int main(){ // Tags: prefix sums
    int n; cin >> n;
    vector<pair<int, int>> points(n);

    // 2 Prefix sums arrays, one to calculate number of points higher than this point and number of values lower than this point at each point before and after each point, prefix array for each point
    vector<vector<int>> more(n, vector<int>(n + 1)), less(n, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    sort(points.begin(), points.end());
    
    for (int i = 0; i < n; i++){ // Go through each point
        for (int j = 1; j <= n; j++){ // Go through every point again, calculating how many are higher and how many are lower
            more[i][j] = more[i][j - 1];
            less[i][j] = less[i][j - 1];

            if (points[i].second < points[j - 1].second) // Points higher than current anchorpoint
                more[i][j]++;

            if (points[i].second > points[j - 1].second) // Points lower than current anchorpoint
                less[i][j]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++){ // Anchor point
        for (int j = i + 1; j < n; j++){
            ans++; // current point
            int a = 0, b = 0;

            // If the next point is higher than the anchor point
            if (points[j].second > points[i].second){
                a = less[i][j + 1] - less[i][i + 1]; // Prefix sum number of points higher from point i to point j
                b = more[j][j + 1] - more[j][i + 1]; // Prefix sum number of points lower from point i to point j
            } else { // If next point is less than or at the same height as anchor point
                a = more[i][j + 1] - more[i][i + 1]; 
                b = less[j][j + 1] - less[j][i + 1];
            }

            ans += a + (a * b) + b; // a and b only points from a to b added together + a and b multiplied together
        }
    }

    cout << ans + n + 1 << endl; // individual points
}
