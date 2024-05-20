/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 16:23:06
 *	modified:	2024-05-17 16:32:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	string s, p;
	cin >> s >> p;
	int m = s.size(), n = p.size();
	vector<int> dp0(m + 1), dp1(m + 1);
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			if (s[i - 1] == p[j - 1]) {
				dp1[i] = j == 1 ? i : dp0[i - 1];
			} else {
				dp1[i] = dp1[i - 1];
			}
		}
		swap(dp0, dp1);
	}
	int sta = 0, mindl = m + 1;
	for (int i = 1; i <= m; i++) {
		if (s[i - 1] == p[n - 1] && dp0[i] != 0) {
			int j = dp0[i] - 1;
			if (i - j < mindl) {
				sta = j;
				mindl = i - j;
			}
		}
	}
	cout << s.substr(sta, mindl) << "\n";

	return 0;
}