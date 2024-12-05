#include <cctype>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  

  int st = 0;
  string cs = "mul(";
  string a, b;
  int res = 0;
  while (cin >> s) {
  for (char c: s) {
    cout << c << st << "\n";
    if (st < 4) {
      if (c != cs[st]) st = 0; 
      st++;
      if (st == 4) continue;
    }
    if (st == 4) {
      if (!isdigit(c)) {
        if (c == ',') {
          st = 5;
          continue;
        } else {
          st = 0;
          a = "";
          if (c == 'm') st = 1;
          continue;
        }
      }
      a+= c;
    }
    if (st == 5) {
      if (!isdigit(c)) {
        if (c == ')') {
          //cout << "OK(" << a << "," << b << ")\n";
          if (!(a.size() > 3 || b.size() > 3)) {

          int mul = stoi(a)*stoi(b);
          res += mul;
          cout << a << " "<< b << " " << mul << " " << res <<"\n";
            }
        } 
        st = 0;
        a = "";
        b = "";
        if (c == 'm') st = 1;
        continue;
      }
      b+=c;
    }
 
  }
  }
  cout << res;
}
