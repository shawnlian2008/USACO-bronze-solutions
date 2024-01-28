#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("traffic.in","r", stdin);
  freopen("traffic.out","w", stdout);

  int n; cin >> n;
  vector<string> type(n);
  vector<int> start(n), end(n);

  for (int i = 0 ; i < n ; i++){
    cin >> type[i] >> start[i] >> end[i];
  }

  int st = 0, en = 1000;

  for(int i = n-1; i >= 0 ; i--){
    if(type[i] == "none"){
      //narrow the range likelyhood
      st = max(st, start[i]);
      en = min(en, end[i]);
    }
    else if(type[i] == "off"){
      //range before end (before people went off)
      st += start[i];
      en += end[i];
    }
    else if(type[i] == "on"){
      //range before start (before people went on)
      st -= end[i];
      en -= start[i];
 
      st = max(st, 0);
    }
  }
  cout<<st<<" "<<en<<endl;
  
   st = 0;
   en = 1000;
  for (int i = 0; i < n ; i++){
    if (type[i] == "none"){
      st = max(st , start[i]);
      en = min(en , end[i]);
    }
    else if (type[i] == "on"){
      st += start[i];
      en += end[i];
    }
    else if (type[i] == "off"){
      st -= end[i];
      en -= start[i];

      st = max(0, st);
    }
  }

  cout << st << " " << en << endl;
  return 0;
}
