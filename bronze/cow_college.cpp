#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> max_pay(n);
    for (int i = 0; i < n; i++)
        cin >> max_pay[i];

    vector<int> possible_tuitions = max_pay;
    sort(possible_tuitions.begin(), possible_tuitions.end());
    sort(max_pay.begin(), max_pay.end());
    possible_tuitions.erase(unique(possible_tuitions.begin(), possible_tuitions.end()), possible_tuitions.end());

    long long maximum = 0, ideal_cost = 0;
    //loop through all tuitions
    for (int i = 0; i < possible_tuitions.size(); i++){
        //cout << possible_tuitions[i] << " ";
        std::vector<int>::iterator upper = std::upper_bound(max_pay.begin(), max_pay.end(), possible_tuitions[i] - 1);
        
        //cout << (n - (upper - max_pay.begin())) << " ";
        if (possible_tuitions[i] * (n - (upper - max_pay.begin())) > maximum)
            ideal_cost = possible_tuitions[i];
        
        maximum = max((long long)(possible_tuitions[i] * (n - (upper - max_pay.begin()))), maximum);
        //cout << possible_tuitions[i] * (n - (upper - max_pay.begin())) << " " << maximum << endl;
    }
    //cout << endl;
    
    cout << maximum << " " << ideal_cost << endl;
}
