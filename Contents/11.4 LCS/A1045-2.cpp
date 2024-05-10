/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 13:18:35
 *	modified:	2023-04-12 14:00:36
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> a(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> a[i + 1];
	}
	int l;
	cin >> l;
	vector<int> b(l + 1);
	for (int i = 0; i < l; i++) {
		cin >> b[i + 1];
	}
	vector<vector<int>> dp(m + 1, vector<int>(l + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= l; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] == b[j]) {
				++dp[i][j];
			}
		}
	}
	cout << dp[m][l] << "\n";

	return 0;
}