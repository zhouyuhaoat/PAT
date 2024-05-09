/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 14:01:53
 *	modified:	2023-04-12 14:14:26
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	getline(cin, s);
	vector<vector<int>> dp(s.size(), vector<int>(s.size()));
	int ans = 1;
	for (int i = 0; i < (int)s.size(); i++) {
		dp[i][i] = 1;
		if (i < (int)s.size() - 1 && s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int l = 3; l <= (int)s.size(); l++) {
		for (int i = 0; i + l - 1 < (int)s.size(); i++) {
			int j = i + l - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}