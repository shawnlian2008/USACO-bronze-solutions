#include <bits/stdc++.h>
using namespace std;

set<int> possible_values;

void end(vector<int> b1, vector<int> b2, int b1amount, int b2amount){
	possible_values.insert(b1amount);
}

void friday(vector<int> b1, vector<int> b2, int b1amount, int b2amount){
	for (int i = 0; i < b2.size(); i++){
		int cvl = b2[i];
		b1.push_back(cvl);
		b2.erase(b2.begin() + i);
		end(b1, b2, b1amount + cvl, b2amount - cvl);
		b1.pop_back();
		b2.insert(b2.begin() + i, cvl);
	}
}

void thursday(vector<int> b1, vector<int> b2, int b1amount, int b2amount){
	for (int i = 0; i < 10; i++){
		int cvl = b1[i];
		b2.push_back(cvl);
		b1.erase(b1.begin() + i);
		friday(b1, b2, b1amount - cvl, b2amount + cvl);
		b2.pop_back();
		b1.insert(b1.begin() + i, cvl);
	}
}

void wednesday(vector<int> b1, vector<int> b2, int b1amount, int b2amount){
	for (int i = 0; i < b2.size(); i++){
		int cvl = b2[i];
		b1.push_back(cvl);
		b2.erase(b2.begin() + i);
		thursday(b1, b2, b1amount + cvl, b2amount - cvl);
		b1.pop_back();
		b2.insert(b2.begin() + i, cvl);
	}
}

void tuesday(vector<int> b1, vector<int> b2, int b1amount, int b2amount){
	for (int i = 0; i < 10; i++){
		int cvl = b1[i];
		b2.push_back(cvl);
		b1.erase(b1.begin() + i);
		wednesday(b1, b2, b1amount - cvl, b2amount + cvl);
		b2.pop_back();
		b1.insert(b1.begin() + i, cvl);
	}
}

int main(){
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
	vector<int> b1(10), b2(10);

	for (int i = 0; i < 10; i++)
		cin >> b1[i];
	
	for (int i = 0; i < 10; i++)
		cin >> b2[i];

	int b1amount, b2amount;
	b1amount = b2amount = 1000;

	tuesday(b1, b2, b1amount, b2amount);

	cout << possible_values.size() << endl;
}
