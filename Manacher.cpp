#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e7;
char in[MAXN], s[MAXN];
int len, p[MAXN], ans;
void init_s() {
	s[0] = s[1] = '|'; len = 1;
	int len_in = strlen(in);
	for(int i = 0; i < len_in; i++) s[++len] = in[i], s[++len] = '|';
}
void manacher() {
	int mx = 0, id = 0;
	for(int i = 1; i <= len; i++) {
		if(i < mx) p[i] = min(p[2 * id - i], mx - i);
		else p[i] = 1;
		while(s[i - p[i]] == s[i + p[i]]) p[i]++;
		if(i + p[i] >= mx) mx = i + p[i], id = i;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> in;
	init_s();
	manacher();
	for(int i = 1; i <= len; i++) ans = max(ans, p[i]);
	cout << ans - 1 << endl;
	return 0;
}