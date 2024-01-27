#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; 
    while (t--){
        string directions; cin >> directions;

        int lefts = 0, rights = 0;
        for (int i = 0; i < directions.length() - 1; i++){
            if ((directions[i] == 'N' && directions[i + 1] == 'E')
                || (directions[i] == 'E' && directions[i + 1] == 'S')
                || (directions[i] == 'S' && directions[i + 1] == 'W')
                || (directions[i] == 'W' && directions[i + 1] == 'N')){
                rights++;
            } else if ((directions[i] == 'N' && directions[i + 1] == 'W')
                || (directions[i] == 'W' && directions[i + 1] == 'S')
                || (directions[i] == 'S' && directions[i + 1] == 'E')
                || (directions[i] == 'E' && directions[i + 1] == 'N')){
                lefts++;
            }
        }
        
        if (lefts > rights)
            cout << "CCW" << endl;
        else
            cout << "CW" << endl;
    }
}
