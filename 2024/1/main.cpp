#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  unordered_map<int, int> sm;
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a, b;
  string s;
  while (cin >> s) {
    a.push_back(stoi(s));
    cin >> s;
    b.push_back(stoi(s));
  }
  for (int i: b) {
    if (sm[i]) {
      sm[i]++;
    } else {
      sm[i] = 1;
    }
  }
  int res = 0;
  for (int i: a) {
    res += i*sm[i];
  }
  cout << res << '\n';
}
