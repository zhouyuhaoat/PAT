/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 07:42:10
 *	modified:	2023-04-12 08:08:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	vector<int> d(k);
	bool flag = true;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
		if (d[i] >= 0) {
			flag = false;
		}
	}
	if (flag) {
		cout << "0 " << d[0] << " " << d[k - 1] << "\n";
		return 0;
	}
	vector<int> dp(k), s(k);
	dp[0] = d[0];
	for (int i = 1; i < k; i++) {
		if (dp[i - 1] + d[i] > d[i]) {
			dp[i] = dp[i - 1] + d[i];
			s[i] = s[i - 1];
		} else {
			dp[i] = d[i];
			s[i] = i;
		}
	}
	int i = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[i] << " " << d[s[i]] << " " << d[i] << "\n";

	return 0;
}