#include <array>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <string>
#include <tuple>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


void pV(vector<long> v) {
  cout << "[";
  for (long s: v) {
    cout << s << ", ";
  }
  cout << "]" << endl;
}

array<long, 3> tTt(string s) {
  string ts;
  s += " ";
  array<long, 3> r;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ') {
      r[count] = stol(ts);
      //cout << "\"" << ts << "\" -> " << r[count] << endl;
      count++;
      ts.clear();
      continue;
    }
    ts += c;
  }
  return r;
}

vector<long> solve(vector<array<long, 3>>map, vector<long> ss) {
  vector<bool> lock;
  lock.reserve(ss.size());
  for (int i = 0; i < ss.size(); i++) {
    lock[i] = false;
  }

   
  for (int i = 0; i < map.size(); i++) {
    long d = map[i][0];
    long s = map[i][1];
    long r = map[i][2];

    for(int j = 0; j < ss.size(); j++) {
      if (lock[j]) {
        continue;
      }
      long n = ss[j];

      if (!(n >= s && n <= s+r-1)) {
        continue;
      }
      
      cout << n << " -> " << (n-s+d) << " | " << s << " -> " << d << " (" << r << ")" << endl;
      ss[j] = n-s+d;
      lock[j] = true;
    }
  }
  return ss;
}


int main (int argc, char *argv[]) {
  ifstream f;
  f.open("data");
  string s;
  getline(f, s);
  
  vector<long> seeds;
  
  string ts;
  s+= " ";
  long num = -1;

  for (int i = 7; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ') {
      if (num == -1) {
        num = stol(ts);
        cout << "num" << endl;
      } else {
        long bs = num;
        for (long j = 0; j < stol(ts); j++) {
          seeds.push_back(bs+j);
          num = -1;
        }
      }
      //cout << "\"" << ts << "\" -> " << seeds[seeds.size()-1]  << endl;
      ts.clear();
      continue;
    }
    ts += c;
  }
  seeds = {79, 14, 55, 13};
  pV(seeds);
  //sort(seeds.begin(), seeds.end());
  

  getline(f, s);
  getline(f, s);
  

  vector<array<long, 3>>map;
  while (getline(f, s)) {
    if (s.empty()) {
      // cout << "---------" << endl;
      getline(f, s);
      seeds = solve(map, seeds);
      pV(seeds);
      map.clear();
      // cout << endl;
      continue;
    }

    map.push_back(tTt(s));
    // cout << s << endl;
  }
  seeds = solve(map, seeds);
  pV(seeds);
  long min = seeds[0];
  // cout << endl << endl;
  for (long seed: seeds) {
    if (seed < min) {
      min = seed;
    }
    // cout << seed << " ";
  }
  cout << endl << min << endl;

  return 0;
}
