#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <ctype.h>

using namespace std;

int solve(string s) {
  unordered_map<string, int> cubes;
  cubes["blue"] = 0;
  cubes["red"] = 0;
  cubes["green"] = 0;
  int i = 0;
  char c = s[i];
  while (c != ':') {
    c = s[i];
    i++;
  }
  s.erase(0, i + 1);
  
  string ss;
  int n = 0;
  int cn;
  s += " "; // hack
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ') {
      if (n % 2 == 0) {
        cn = stoi(ss);
      } else if (cubes[ss] < cn) {
        cubes[ss] = cn;
      }

      //cout << n << " " << ss << endl;
      ss.clear();
      n++;
      continue;
    }
    if (c == ',' || c == ';') {
      continue;
    }
    ss += c;
  }

  //cout << s << endl;
  //cout << "b: " << cubes["blue"] << endl;
  //cout << "r: " << cubes["red"] << endl;
  //cout << "g: " << cubes["green"] << endl;
  // return cubes["blue"] <= 14 && cubes["red"] <= 12 && cubes["green"] <= 13;
  return cubes["blue"] * cubes["red"] * cubes["green"];

}


int main (int argc, char *argv[]) {
  ifstream f;
  string line;
  f.open("data.txt");
  int r = 0;
  //int c = 0;
  while (getline(f, line)) {
    //c++;
    //if (solve(line)) {
    //  r += c;
    //}
    r+=solve(line);
  }

  cout << "r: " << r << endl;

  f.close();
  return 0;
}
