#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    int evens = 0, odds = 0;
    for (int i = 0; i < n; i++){
        if (values[i] % 2 == 0)
            evens++;
        else
            odds++;
    }

    int ans = min(evens, odds);
    evens -= ans;
    odds -= ans;
    ans *= 2;
    
    if (evens == odds){
        cout << evens + odds << endl;
        return 0;
    }

        if (odds > evens){
            int mod = odds % 3;
            if (mod == 1)
                ans += (((odds - 4) / 3) * 2) + 1;
            else if (mod == 2)
                ans += (((odds - 2) / 3) * 2) + 1;
            else ans += (odds / 3) * 2;
        } else if (evens > odds){
            ans++;
        }

    cout << ans << endl;
}
