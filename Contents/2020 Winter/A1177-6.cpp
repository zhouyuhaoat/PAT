/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 16:36:06
 *	modified:	2024-05-17 16:40:17
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
	vector<vector<int>> dp(2, vector<int>(m + 1));
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			if (s[i - 1] == p[j - 1]) {
				dp[j & 1][i] = j == 1 ? i : dp[(j - 1) & 1][i - 1];
			} else {
				dp[j & 1][i] = dp[j & 1][i - 1];
			}
		}
	}
	int sta = 0, mindl = m + 1;
	for (int i = 1; i <= m; i++) {
		if (s[i - 1] == p[n - 1] && dp[n & 1][i] != 0) {
			int j = dp[n & 1][i] - 1;
			if (i - j < mindl) {
				sta = j;
				mindl = i - j;
			}
		}
	}
	cout << s.substr(sta, mindl) << "\n";

	return 0;
}