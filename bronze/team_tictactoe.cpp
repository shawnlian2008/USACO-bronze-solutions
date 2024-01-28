#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<string> b(3);
    cin >> b[0] >> b[1] >> b[2];

    set<char> single_winners;
    set<pair<char, char>> double_winners;
    int team_wins = 0;

    set<char> ln;
    for (int i = 0; i < 3; i++){
        ln.insert(b[i][0]);
        ln.insert(b[i][1]);
        ln.insert(b[i][2]);
        if (ln.size() == 1)
            single_winners.insert(b[i][0]);
        else if (ln.size() == 2){
            if (b[i][0] != b[i][1]){
                char largest, smallest;
                if (b[i][0] > b[i][1]){
                    largest = b[i][0]; smallest = b[i][1];
                } else {largest = b[i][1]; smallest = b[i][0];}

                double_winners.insert({largest, smallest});
            } else if (b[i][1] != b[i][2]){
                char largest, smallest;
                if (b[i][1] > b[i][2]){
                    largest = b[i][1]; smallest = b[i][2];
                } else {largest = b[i][2]; smallest = b[i][1];}

                double_winners.insert({largest, smallest});
            }
        }
        ln.clear();

        ln.insert(b[0][i]);
        ln.insert(b[1][i]);
        ln.insert(b[2][i]);
        if (ln.size() == 1)
            single_winners.insert(b[0][i]);
        else if (ln.size() == 2){
            if (b[0][i] != b[1][i]){
                char largest, smallest;
                if (b[0][i] > b[1][i]){
                    largest = b[0][i]; smallest = b[1][i];
                } else {largest = b[1][i]; smallest = b[0][i];}

                double_winners.insert({largest, smallest});
            } else if (b[1][i] != b[2][i]){
                char largest, smallest;
                if (b[1][i] > b[2][i]){
                    largest = b[1][i]; smallest = b[2][i];
                } else {largest = b[2][i]; smallest = b[1][i];}

                double_winners.insert({largest, smallest});
            }
        }
        ln.clear();
    }

    ln.insert(b[0][0]);
    ln.insert(b[1][1]);
    ln.insert(b[2][2]);
    if (ln.size() == 1)
        single_winners.insert(b[0][0]);
    else if (ln.size() == 2){
        if (b[0][0] != b[1][1]){
            char largest, smallest;
            if (b[0][0] > b[1][1]){
                largest = b[0][0]; smallest = b[1][1];
            } else {largest = b[1][1]; smallest = b[0][0];}

            double_winners.insert({largest, smallest});
        } else if (b[1][1] != b[2][2]){
            char largest, smallest;
            if (b[1][1] > b[2][2]){
                largest = b[1][1]; smallest = b[2][2];
            } else {largest = b[2][2]; smallest = b[1][1];}

            double_winners.insert({largest, smallest});
        }
    }

    ln.insert(b[0][2]);
    ln.insert(b[1][1]);
    ln.insert(b[2][0]);
    if (ln.size() == 1)
        single_winners.insert(b[0][2]);
    else if (ln.size() == 2){
        if (b[0][2] != b[1][1]){
            char largest, smallest;
            if (b[0][2] > b[1][1]){
                largest = b[0][2]; smallest = b[1][1];
            } else {largest = b[1][1]; smallest = b[0][2];}

            double_winners.insert({largest, smallest});
        } else if (b[1][1] != b[2][0]){
            char largest, smallest;
            if (b[1][1] > b[2][0]){
                largest = b[1][1]; smallest = b[2][0];
            } else {largest = b[2][0]; smallest = b[1][1];}

            double_winners.insert({largest, smallest});
        }
    }

    cout << single_winners.size() << endl;
    cout << double_winners.size() << endl;
}
