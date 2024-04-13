#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, ans = 0; scanf("%d", &n);
		for(int i = 1; i <= n; i++) ans += i * (i * 2 - 1);
		
		printf("%d %d\n", ans, n * 2);
		for(int i = 1; i <= n; i++) {
			for(int k = 1; k <= 2; k++) {
				printf("%d %d", k, i);
				for(int j = n; j >= 1; j--) printf(" %d", j);
				puts("");
			}
		}
	}
	return 0;
}
