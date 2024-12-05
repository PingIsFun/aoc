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

int check(int x, int y, vector<string> &v) {
  int res = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (j == 0 && i == 0) {
        continue;
      }
      if (x+i < 0 || y+j < 0 || x+i > (v.size()-1)|| y+j > (v[0].size()-1) ) continue;
      
      //cout << v[x+i][y+j] << ": " << x+i << " " << y+j;
      if (v[x+i][y+j] == 'M') {
        cout << "M: " << x+i << " " << y+j << " | " << i << " " << j <<  "\n";
        //cout << "+\n";
        if (dcheck(x+i, y+j, v, 2, i, j)) res++;
      }
      //cout << "\n";

    }
  }
  return res;
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
      if (v[i][j] == 'X') {
        cout << "check: " << i << " " << j << "\n";
        r+=check(i, j, v);
      }
    }
  }
  cout << r << '\n';

}
