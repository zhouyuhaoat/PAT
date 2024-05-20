/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 08:50:22
 *	modified:	2023-04-06 11:05:43
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1;
vector<bool> dif(maxn), dup(maxn);

int main(int argc, char const *argv[]) {

	int n1, n2;
	cin >> n1 >> n2;
	dif[abs(n1 - n2)] = true;
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
	int cntout = 0;
	for (int q = 1; q <= m && cntout < n; q++) {
		vector<int> outid;
		for (int i = 1; i <= n; i++) {
			if (out[i]) {
				continue;
			}
			int num = d[i][q];
			if (dif[num] && !dup[num]) {
				for (auto it : pre) {
					dif[abs(it - num)] = true;
				}
				dup[num] = true;
				pre.emplace_back(num);
			} else {
				out[i] = true;
				outid.emplace_back(i);
				if (++cntout == n) {
					break;
				}
			}
		}
		for (auto it : outid) {
			cout << "Round #" << q << ": " << it << " is out.\n";
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