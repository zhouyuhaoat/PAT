/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 12:49:06
 *	modified:	2024-05-17 13:14:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
// Not Accepted by test 3, 5 and 6, due to the memory limit or the long subsequence
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	string s, p;
	cin >> s >> p;
	int m = s.size(), n = p.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == p[j - 1]) {
				dp[i][j] = j == 1 ? i : dp[i - 1][j - 1];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int sta = 0, mindl = m + 1;
	for (int i = 1; i <= m; i++) {
		if (s[i - 1] == p[n - 1] && dp[i][n] != 0) {
			int j = dp[i][n] - 1;
			if (i - j < mindl) {
				sta = j;
				mindl = i - j;
			}
		}
	}
	cout << s.substr(sta, mindl) << "\n";

	return 0;
}