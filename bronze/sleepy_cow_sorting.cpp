#include <iostream>
using namespace std;
 
int n;
int positions[100000];
 
int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> positions[i];
    
    int ans = n - 1;
    //loop through all positions backwards with sliding window of length 2
    for(int i = n - 2; i >= 0; i--)
    {
        //if it is already sorted
        if(positions[i] < positions[i + 1])
            ans = i;
        else break;
    }
    cout << ans << '\n';
    return 0;

    //all this program does is find the first index where a value is unsorted
}
