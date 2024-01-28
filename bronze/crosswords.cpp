#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crosswords.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("crosswords.out", "w", stdout);
	string row;
	vector<string> board;
	while (cin >> row) board.push_back(row);
	vector<pair<int, int>> good_cell;

	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < row.length(); j++){
			if (board[i][j] == '#') continue;
			//find horizontal
			//if there is still room to the right
			if (j >= row.length() - 2){} //cout << j << endl;
			else {
				if (board[i][j + 1] == '.' && board[i][j + 2] == '.'){
					if (j == 0 || (board[i][j - 1] == '#'))
						good_cell.push_back(make_pair(i, j));
				}
			}
			//find vertical
			//if there is still room to the bottom
			if (i >= board.size() - 2){}
			else {
				if (board[i + 1][j] == '.' && board[i + 2][j] == '.'){
					if (i == 0 || (board[i - 1][j] == '#'))
						good_cell.push_back(make_pair(i, j));
				}
			}
		}
	}

	good_cell.erase( unique( good_cell.begin(), good_cell.end() ), good_cell.end() );

	cout << good_cell.size() << endl;

	for (int i = 0; i < good_cell.size(); i++){
		cout << good_cell[i].first + 1 << " " << good_cell[i].second + 1 << endl;
	}
}
