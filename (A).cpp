#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int t; cin >> t;
  while (t--) {
    int k, q; cin >> k >> q;
    vector<int> a(k);
    for (auto & x : a) cin >> x;
    for (int i = 0; i < q; i++) {
      int qq; cin >> qq;
      if (qq < a[0]) cout << qq << " ";
      else cout << a[0] - 1 << " ";
    }
    cout << endl;
  }
}