#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;


int solve(string s) {
  s += " ";
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ':') {
      s.erase(0, i+1);
      break;
    }
  }
  set<int> r;
  int res = 0;
  string ts;
  bool gP = false;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ') {
      if (ts.empty()) {
        continue;
      }

      if (!gP) {
        r.insert(stoi(ts));
      } else if (r.find(stoi(ts)) != r.end()) {
        res++;
      }
      ts.clear();
      continue;
    }
    ts += c;
    if (c == '|') {
      gP = true;
      ts.clear();
      continue;
    }
  }
  return res;
}

int main (int argc, char *argv[]) {
  ifstream f;
  f.open("data");
  string s;
  vector<int> res, im, inst;
  while (getline(f, s)) {
    res.push_back(solve(s));
  }

  for (int i = 0; i < res.size(); i++) {
    inst.push_back(1);
  }

  im = res;
  for (int i = 0; i < res.size(); i++) {
    //cout << "-------" << i << " " << res[i] << "-------" << endl;
    for (int j = 0; j < res[i]; j++) {
      inst[i+j+1] += inst[i];
    }
  }
  //cout << endl << "--------------" << endl;
  int result = 0;
  for (int i: inst) {
    result += i;
    cout << i << " "; 
  }
  cout << endl;
  for (int i: res) {
    cout << i << " "; 
  }
  cout  << endl << result;
  return 0;
}
