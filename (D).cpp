#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 22;

int a[NN], b[NN];
bool flag[NN];
vector<pii> ans;

int vst[NN], runs;

int mex(int L, int R) {
	runs++;
	for(int i = L; i <= R; i++) if(b[i] < NN) vst[b[i]] = runs;
	for(int i = 0; ; i++) if(vst[i] ^ runs) return i;
}

void update(int L, int R) {
	int mx = mex(L, R);
	for(int i = L; i <= R; i++) b[i] = mx;
	ans.push_back({L, R});
}

void solve(int L, int R) {
	if(L == R) {
		if(b[L]) update(L, L);
		return;
	}
	solve(L, R - 1);
	if(b[R]) update(R, R);
	update(L, R);
	solve(L, R - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	
	INT mx = -1; int C;
	for(int c = 1 << n; c--; ) {
		for(int i = 0; i < n; i++) flag[i] = (1 << i) & c;
		
		INT ans = 0;
		for(int i = 0, j = 0; i < n; i = j) {
			INT sum = 0;
			for(; j < n && flag[i] == flag[j]; j++) sum += a[j];
			if(flag[i]) ans += (INT)(j - i) * (j - i);
			else ans += sum;
		}
		if(ans > mx) mx = ans, C = c;
	}
	
	for(int i = 0; i < n; i++) flag[i + 1] = (1 << i) & C, b[i + 1] = a[i];
	for(int i = 1, j = 1; i <= n; i = j) {
		for(; j <= n && flag[i] == flag[j]; j++);
		if(flag[i]) {
			solve(i, j - 1);
			ans.push_back({i, j - 1});
		}
	}
	
//	cerr<<"ans -= "<<endl;
	printf("%I64d %d\n", mx, ans.size());
	for(pii p : ans) printf("%d %d\n", p.x, p.y);
	return 0;
}