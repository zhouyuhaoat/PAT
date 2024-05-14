/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:32:04
 *	modified:	2023-04-03 18:58:22
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end(), greater<int>());
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (d[i] <= i + 1) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << d.back() - 1 << "\n";
	} else {
		cout << ans << "\n";
	}

	return 0;
}