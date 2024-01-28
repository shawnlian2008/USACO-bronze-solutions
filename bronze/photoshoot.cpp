#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n; cin >> n;
    vector<int> sums(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> sums[i];

    vector<int> ans;
    for (int i = sums[0] - 1; i > 0; i--){
        map<int, bool> used;

        int nextSum = sums[0] - i;
        used[nextSum] = true;
        vector<int> seq = {i, nextSum};
        bool indicator = false;
        for (int j = 1; j < n - 1; j++){
            int currSum = sums[j] - nextSum;
            if (used[currSum] || currSum <= 0){
                indicator = true;
                break;
            }
            //cout << used.size() << " " << used[currSum] << " " << currSum << endl;
            used[currSum] = true;
            seq.push_back(currSum);
            nextSum = currSum;
        }

        if (!indicator){
            for (int i = 0; i < seq.size(); i++){
                cout << seq[i];
                if (i < seq.size() - 1)
                    cout << " ";
            }
            cout << "\n";
            return 0;
        }
    }
}
