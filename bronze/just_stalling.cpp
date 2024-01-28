#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> heights(n), stalls(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    sort(heights.begin(), heights.end());
    sort(stalls.begin(), stalls.end());

    vector<int> fitted(n, 0);
    
    int ans = 1;
    //go through every cow
    for (int i = 0; i < n; i++){
        //go through every stall
        for (int j = 0; j < n; j++){
            if (stalls[i] >= heights[j])
                fitted[i]++;
        }
    }

    int factor = 0;
    for (int i = 0; i < n; i++){
        ans *= fitted[i] - factor;
        factor++;
    }

    cout << ans << endl;
}
