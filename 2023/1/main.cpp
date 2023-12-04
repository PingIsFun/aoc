#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <unordered_map>

using namespace std;

string W2N[10] = {"zero", "one","two","three","four","five","six","seven","eight","nine"};
unordered_map<string, int> um;



int solve(string s) {
  int a = -1;
  int b = -1;
  for (int i = 0; i < s.length(); i++) {
    string c{s[i]};
    if (isdigit(c[0])) {
      if (a == -1) {
        a = stoi(c);
        continue;
      }
      b = stoi(c);
      continue;
    }
    string ts;
    for (int j = 0; j < 5; j++) {
      ts += s[i+j];
      cout << ts;
      
      auto rn = um.find(ts);

      if (rn == um.end()) {
        cout << "-" << endl;
        continue;
      }      
      cout << endl;
      int n = (*rn).second;
      cout << n << endl;
      if (a == -1) {
        a = n;
        continue;
      }
      b = n;

    }
    cout << "---------------" << endl;

  }
  if (b == -1) {
    b = a;
  }

  return a*10+b;
}





int main (int argc, char *argv[]) {
  um["zero"] = 0;
um["one"] = 1;
um["two"] = 2;
um["three"] = 3;
um["four"] = 4;
um["five"] = 5;
um["six"] = 6;
um["seven"] = 7;
um["eight"] = 8;
um["nine"] = 9;
  ifstream f;
  string line;
  int res = 0;
  f.open("data.txt");
  while (getline(f, line)) {
    int tr;
    tr = solve(line);
    cout << tr << endl;
    res += tr;
  }

  cout << res;
  return 0;
}
