//https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
const int MAXN = 1e5 + 10;
int n, m, st[MAXN][30], lg[MAXN];

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) st[i][0] = read();
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[0] = -1; for(int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1, l, r; i <= m; i++) {
		l = read(), r = read(); int k = lg[r - l + 1];
		printf("%d\n", max(st[l][k], st[r - (1 << k) + 1][k]));
	}
}