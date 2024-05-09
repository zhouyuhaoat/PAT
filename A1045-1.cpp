/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 09:57:40
 *	modified:	2023-04-12 13:18:13
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> ht(n + 1);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int v;
		cin >> v;
		ht[v] = i;
	}
	int l;
	cin >> l;
	vector<int> c;
	for (int i = 0; i < l; i++) {
		int v;
		cin >> v;
		if (ht[v] != 0) {
			c.emplace_back(v);
		}
	}
	vector<int> dp(c.size());
	int ans = -1;
	for (int i = 0; i < (int)c.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ht[c[j]] <= ht[c[i]] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";

	return 0;
}