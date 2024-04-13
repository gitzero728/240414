#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto & x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int cnt = 0;
    for (auto [k, v]: mp) {
      if (v >= 2) cnt++;
    }
    cout << cnt << endl;
  }
}