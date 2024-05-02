/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 11:37:11
 *	modified:	2023-03-27 12:25:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> d[i + 1];
		d[i + 1] += d[i];
	}
	bool flag = false;
	while (!flag) {
		for (int i = 0; i <= n; i++) {
			int j = lower_bound(d.begin() + i, d.end(), m + d[i]) - d.begin();
			if (d[j] - d[i] == m) {
				cout << i + 1 << "-" << j << "\n";
				flag = true;
			}
		}
		m++;
	}

	return 0;
}