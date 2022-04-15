https://www.luogu.com.cn/problem/P3370
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN= 1e4 + 10, Base = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int N, ans = 1;
pair<int, int> v[MAXN];
inline pair<int, int> Hash(string &in) {
	int ret1 = 0, ret2 = 0;
	for(char c : in)
		ret1 = (ret1 * Base % mod1 + c) % mod1,
		ret2 = (ret2 * Base % mod2 + c) % mod2;
	return make_pair(ret1, ret2);
}
signed main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i = 1; i <= N; i++) {
		string in; cin >> in;
		v[i] = Hash(in);
	}
	sort(v + 1, v + N + 1);
	for(int i = 2; i <= N; i++)
		if(v[i] != v[i - 1]) ans++;
	cout << ans << endl;
	return 0;
}