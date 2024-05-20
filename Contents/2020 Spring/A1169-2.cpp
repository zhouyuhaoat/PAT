/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 10:52:36
 *	modified:	2024-05-17 11:11:27
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1;
vector<bool> sum(2 * maxn - 1), dup(maxn);

int main(int argc, char const *argv[]) {

	int n1, n2;
	cin >> n1 >> n2;
	sum[n1] = sum[n2] = true;
	dup[n1] = dup[n2] = true;
	vector<int> pre = {n1, n2};
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> d[i + 1][j + 1];
		}
	}
	vector<bool> out(n + 1);
	for (int q = 1; q <= m; q++) {
		for (int i = 1; i <= n; i++) {
			if (out[i]) {
				continue;
			}
			int num = d[i][q];
			bool dif = false;
			for (auto it : pre) {
				if (sum[it + num]) {
					dif = true;
					break;
				}
			}
			bool flag = dif && !dup[num];
			if (flag) {
				sum[num] = dup[num] = true;
				pre.emplace_back(num);
			} else {
				cout << "Round #" << q << ": " << i << " is out.\n";
				out[i] = true;
			}
		}
	}
	vector<int> win;
	for (int i = 1; i <= n; i++) {
		if (!out[i]) {
			win.emplace_back(i);
		}
	}
	if (!win.empty()) {
		cout << "Winner(s):";
		for (auto it : win) {
			cout << " " << it;
		}
		cout << "\n";
	} else {
		cout << "No winner.\n";
	}

	return 0;
}