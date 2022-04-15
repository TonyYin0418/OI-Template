#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 10;
char s1[MAXN], s2[MAXN];
int nxt[MAXN];
inline void solve_nxt(char *s) {
	int len = strlen(s);
	nxt[0] = -1;
	for(int i = 1; i < len; i++) {
		int match = nxt[i - 1];
		while(match != -1 && s[i] != s[match + 1]) match = nxt[match];
		if(s[i] == s[match + 1]) match++;
		nxt[i] = match;
	}
}
inline void KMP(char *s1, char *s2) {
	int match = -1, len1 = strlen(s1), len2 = strlen(s2);
	for(int i = 0; i < len1; i++) {
		while(s2[match + 1] != s1[i] && match != -1) match = nxt[match];
		if(s2[match + 1] == s1[i]) match++;
		if(match == len2 - 1) {
			cout << i - len2 + 2 << endl;
		}
	}
}
int main() {
	cin >> s1 >> s2;
	solve_nxt(s2);
	KMP(s1, s2);
	for(int i = 0; i < strlen(s2); i++) cout << nxt[i] + 1 << " "; cout << endl;
	return 0;
}