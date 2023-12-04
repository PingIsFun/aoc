#include <cctype>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <string>
#include <tuple>
#include <vector>

using namespace std;


bool is_close(tuple<int, int> symbol, tuple<int, int> loc) {
  int sL = get<0>(symbol);
  int sC = get<1>(symbol);
  int lL = get<0>(loc);
  int lC = get<1>(loc);
  if (!(sL == lL || sL + 1 == lL || sL - 1 == lL)) {
    return false;
  }
  if (!(sC == lC || sC + 1 == lC || sC - 1 == lC)) {
    return false;
  }
  //cout << sL << ", " << sC << " | ";
  //cout << lL << ", " << lC << endl;
  return true;
}


int main (int argc, char *argv[]) {
  ifstream f;
  f.open("dataF");
  string line;
  vector<tuple<int, int>> sl;
  int ln = 0;
  vector<string> lines;
  while (getline(f, line)) {
    lines.push_back(line);
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (!(c == '*')) {
        continue;
      }
      sl.push_back(make_tuple(ln, i));
    }
    ln++;
  }
  long res = 0;
  unordered_map<string, vector<int>> gear_list;
  for (int i = 0; i < lines.size(); i++) {
    string line = lines[i];
    string ts;
    bool ok = false;
    tuple<int, int> loc;
    tuple<int, int> star_loc;
    for (int j = 0; j < line.size(); j++) {
      char c = line[j];
      if (!isdigit(c)) {
        if (ok) {
          stringstream ss;
          ss << get<0>(star_loc) << "|" << get<1>(star_loc);
          gear_list[ss.str()].push_back(stoi(ts));
        }


        ts.clear();
        ok = false;
        continue;
      }
      for (auto val: sl) {
        loc = make_tuple(i, j);
        if (!ok && is_close(val, loc)) {
          ok = true;
          star_loc = val;
        }
      }
      
      ts += c;
    }
    if (ok) {
      stringstream ss;
      ss << get<0>(star_loc) << "|" << get<1>(star_loc);
      gear_list[ss.str()].push_back(stoi(ts));
    }
    ts.clear();
    ok = false;
  }
  
  for (auto i: gear_list) {
    if (i.second.size() != 2) {
      continue;
    }
    res += i.second[0] * i.second[1];
  }

  cout << res;

  return 0;
}
