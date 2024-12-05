#include <cstdlib>
#include <iostream>
#include <ios>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  vector<string> v;
  int res = 0;
  int idx = 0;
  while (getline(cin, s)) {
    idx++;
    cout << idx << ") ";

    vector<int> v;
    string ns;
    s += " "; // hack

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == ' ') {
        v.push_back(stoi(ns));
        ns = "";
        continue;
      }
      ns += c;
    }

    bool dec = v[0] > v[1];
    bool ok = true;
    bool bad = true;
    for (int i = 0; i+1 < v.size(); i++) {

      //cout << v[i] << "," << v[i+1] << " | ";
      cout << v[i] << " | ";
      if (v[i] > v[i+1] != dec || v[i] == v[i+1]) {
        if (!ok) {
          bad = false;
          break;
        }
        ok = false;
        if (i == 0 || i == v.size()-1) {
          cout << "B";
          continue;
        }
        
        if (((abs(v[i] - v[i+2]) > 3) && i != v.size()-2) && abs(v[i-1] - v[i+1]) > 3) {
          cout << "C" << v[i-1] << "," << v[i] << "," << v[i+1] << "," << v[i+2]  << "C";
          bad = false;
          break;
        }

      }

      if (abs(v[i] - v[i+1]) > 3) {
        if (!ok) {
          bad = false;
          break;
        }
        ok = false;
        
        if (i == 0 || i == v.size() -1) {
          continue;
        }
        
        if (((abs(v[i] - v[i+2]) > 3) && i != v.size()-2) && abs(v[i-1] - v[i+1]) > 3) {
          cout << "A";
          bad = false;
          break;
        }
      }
    }
    cout << v[v.size()-1] << " | " << bad << "\n";
    res += bad;
  }
  cout << res << '\n';
}
