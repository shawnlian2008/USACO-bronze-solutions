#include <bits/stdc++.h>
using namespace std;
 
vector<long long> nums;
 
int main(void){
    long long n;
    cin >> n;
    nums.push_back(n);
    while (n != 1) {
        if (n % 2 == 1){
            n *= 3;
            n++;
        } else {
            n = n/2;
        }
        nums.push_back(n);
    }
    
    for (auto &i : nums){
        cout << i << " ";
    }
}
