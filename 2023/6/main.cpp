#include <iostream>
#include <array>

using namespace std;

int main()
{
    // distance = (time-wait)*wait

    const int N = 4;
    //array<int, N> arrayT = {7, 15, 30};
    array<int, N> arrayT = {51, 92, 68, 90};
    //array<int, N> arrayD = {9, 40, 200};
    array<int, N> arrayD = {222, 2031, 1126, 1225};
  int res = 1;  
  for (int i = 0; i < N; i++) {
        int t = arrayT[i];
        int rd = arrayD[i];
        cout << "t: " << t << " d: " << rd << endl;
        int r = 0;
        for (int j = 0; j < t+1; j++) {
            int d = (t-j)*j;
            if (d <= rd) {
                continue;
            }
            cout << j << " d:" << d << endl;
            r++;
        }
      res *= r;
    }
  cout << res << endl;
    return 0;
}
