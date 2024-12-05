#include <complex>
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
  while (getline(cin, s)) {
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
    for (int i = 0; i+1 < v.size(); i++) {
      // cout << v[i] << "," << v[i+1] << " | ";
      if (v[i] > v[i+1] != dec || v[i] == v[i+1]) {
        ok = false;
        break;
      }
      if (abs(v[i] - v[i+1]) > 3) {
        ok = false;
        break;
      }
    }
    res += ok;
  }
  cout << res << '\n';
}
