#include <ios>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  unordered_map<string, vector<string>> um;

  while (getline(cin, s)) {
    if (s == "") break;
    string n;
    string n2;
    for (char c: s) {
      if (c == '|') {
        n = n2;
        n2 = "";
        continue;
      }
      n2 +=c;
    }
    um[n].push_back(n2);
  }
  vector<string> v;
  while (getline(cin, s)) {
    string n;
    s+=',';
    for (char c: s) {
      if (c == ',') {
        v.push_back(n);
        n = "";
        continue;
      }
      n+=c;
    }
    bool ok = true;
    for (int i = 0; i < v.size(); i++) {
      for (string s: um[v[i]]) {
        for (int j = i+1; j < v.size(); j++) {
          if (s == v[j]) {
            ok = false;
            cout << s << "\n";
            break;
          }
        }
      }
    }

    if (ok) {
      for (auto x: v) cout << x << " "; 
    }
    cout << "\n";

    v.clear();
  }
}
