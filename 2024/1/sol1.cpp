#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a, b;
  string s;
  while (cin >> s) {
    a.push_back(stoi(s));
    cin >> s;
    b.push_back(stoi(s));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int res = 0;
  for (int i = 0; i < a.size(); i++) {
    res += abs(a[i] - b[i]);
  }
  cout << res;
}
