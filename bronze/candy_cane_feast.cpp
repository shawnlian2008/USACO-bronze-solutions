#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;

    vector<long long> cow_heights(n);
    for (int i = 0; i < n; i++)
        cin >> cow_heights[i];
    
    //first will be heights from the ground
    //second will be the actual height of the cow.
    vector<pair<long long, long long>> cane_heights(m);
    for (int i = 0; i < m; i++){
        long long height; cin >> height;
        cane_heights[i].first = 0;
        cane_heights[i].second = height;
    }

    //loop through all candy cane heights
    for (int i = 0; i < m; i++){
        //let all cows pass through
        for (int j = 0; j < n; j++){
            //cout << cow_heights[j] << " " << cane_heights[j].second << ", ";
            long long old_cow_heights = cow_heights[j];
            //if the current cow is in between the candy cane height
                // and the candy cane's height from the ground
            if (cow_heights[j] > cane_heights[i].first
                && cow_heights[j] < cane_heights[i].second){
                //cout << "one" << endl;
                cow_heights[j] += cow_heights[j] - cane_heights[i].first;
                cane_heights[i].first += old_cow_heights - cane_heights[i].first;
            } else if (cow_heights[j] >= cane_heights[i].second){
                //cout << "two" << endl;
                //cout << cane_heights[i].second << " - " << cane_heights[i].first << endl;
                cow_heights[j] += cane_heights[i].second - cane_heights[i].first;
                break;
            }
            //cout << cane_heights[i].first << endl;
            //the height from the ground after eaten
        }
    }

    for (int i = 0; i < n; i++)
        cout << cow_heights[i] << endl;
}
