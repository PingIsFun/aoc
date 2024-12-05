#include <ios>
#include <iostream>
#include <vector>

using namespace std;


string ss = "XMAS";



bool dcheck(int x, int y, vector<string> &v, int idx, int xdir, int ydir) {
  
  if (x+xdir < 0 
    || y+ydir < 0 
    || x+xdir > (v.size()-1)
    || y+ydir > (v[0].size()-1)
  ) return false;
  
  if (v[x+xdir][y+ydir] == ss[idx]) {
    cout << ss[idx] << ": " << x+xdir << " " << y+ydir << "\n";
    if (idx == 3) return true;
    return dcheck(x+xdir, y+ydir, v, idx+1, xdir, ydir);
  }
  return false;
}

bool check(int x, int y, vector<string> &v) {
  int res = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (j == 0 || i == 0) {
        continue;
      }
      if (x+i < 0 || y+j < 0 || x+i > (v.size()-1)|| y+j > (v[0].size()-1) ) continue;
      
      //cout << v[x+i][y+j] << ": " << x+i << " " << y+j;
      if (v[x+i][y+j] == 'M') {
        cout << "M: " << x+i << " " << y+j << " | " << i << " " << j <<  "\n";
      if (x+(i*(-1)) < 0 || y+(j*(-1)) < 0 || x+(i*(-1)) > (v.size()-1)|| y+(j*(-1)) > (v[0].size()-1) ) return false;
        //cout << "+\n";
        if (v[x+(i*(-1))][y+(j*(-1))] == 'S') res++;
      }
      //cout << "\n";

    }
  }
  return res == 2;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> v;
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  int r = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 'A') {
        cout << "check: " << i << " " << j << "\n";
        r+=check(i, j, v);
      }
    }
  }
  cout << r << '\n';

}
