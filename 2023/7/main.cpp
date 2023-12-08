#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <tuple>

#define FIVE_OF_KIND 6
#define FOUR_OF_KIND 5
#define FULL_HOUSE 4
#define THREE_OF_KIND 3
#define TWO_PAIR 2
#define ONE_PAIR 1
#define HIGH_CARD 0

using namespace std;


const array<char, 5> power = {'T', 'J', 'Q', 'K', 'A'};

int get_power(char c) {
  if (c == 'J') {
    return 0;
  } 
  if (isdigit(c)) {
    return c - 0x31;
  }
  for (int i = 0; i < 5; i++) {
    if (power[i] == c) {
      return i+9;
    }
  }
  return -1;
}


int get_type(string s) {
  unordered_map<char, int> m;
  for (char c: s) {
    if (!(m[c])) {
      m[c] = 1;
      continue;
    }
    m[c] += 1;
  }
  //for (auto i: m) {
  //  cout << i.first << " -> " << i.second << endl;
  //}
  int size = m.size();
  if (size == 1) {
    return FIVE_OF_KIND;
  }

  if (m['J']) {
    size--;
    int n = 0;
    char c;
    for (auto i: m) {
      if (i.first == 'J') {
        continue;
      }
      else if (i.second > n) {
        n = i.second;
        c = i.first;
      }
    }
    m[c] += m['J'];
    m['J'] = 0;
  }

  switch (size) {
    case 5: 
      return HIGH_CARD;
    case 4: 
      return ONE_PAIR;
    case 3:
      for (auto i: m) {
        if (i.second == 3) {
          return THREE_OF_KIND;
        }
      }
      return TWO_PAIR;
    case 2:
      for (auto i: m) {
        if (i.second == 4) {
          return FOUR_OF_KIND;
        }
      }
      return FULL_HOUSE;
    case 1:
      return FIVE_OF_KIND;
  }
  return -1;
}

bool sort_thing(const tuple<int, string, int>& a, const tuple<int, string, int>& b) {
  if (get<0>(a) != get<0>(b)) { 
    return (get<0>(a) < get<0>(b)); 
  }
  string w1 = get<1>(a);
  string w2 = get<1>(b);
  for (int i = 0; i < 5; i++) {
    int p1 = get_power(w1[i]);
    int p2 = get_power(w2[i]);
    if (p1 != p2) {
      return p1 < p2;
    }
    
  }
  return -1;
}



int main (int argc, char *argv[]) {
  ifstream f;
  f.open("data");
  string s;
  vector<tuple<int, string, int>> v;
  while (getline(f, s)) {
    cout << s << endl;
    string ts;
    int type = -1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == ' ') {
        type = get_type(ts);
        ts.clear();
        continue;
      }
      ts += c;
    }
    v.push_back(make_tuple(type, s, stoi(ts)));
  }
  sort(v.begin(), v.end(), sort_thing);
  cout << "---------" << endl;
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    cout << get<0>(v[i]) << " " << get<1>(v[i]) << endl;
    res += (i+1)*get<2>(v[i]);
  }
  cout << res << endl;
  return 0;
}
