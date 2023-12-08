#include <iostream>
#include <array>

using namespace std;

int main()
{
  // distance = (time-wait)*wait

  //long t = 15;
  //long t = 71530;
  long t = 51926890;
  
  //long rd = 40;
  //long rd = 940200;
  long rd = 222203111261225;
  cout << "t: " << t << " d: " << rd << endl;
  long r = 0;
  
  for (long j = 0; j < t+1; j++) {
    long d = (t-j)*j;
    if (d <= rd) {
        continue;
    }
    cout << ">>" << j << " d:" << d << endl;
    r = j;
    break;
  }

  for (long j = t; j < t+1; j--) {
    long d = (t-j)*j;
    if (d <= rd) {
        continue;
    }
    cout << ">>" << j << " d:" << d << endl;
    r = j - r + 1;
    break;
  }
  cout << r << endl;
  return 0;
}
