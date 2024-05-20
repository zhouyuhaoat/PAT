/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 14:26:30
 *	modified:	2023-04-14 14:35:05
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		d[i + 1] = d[i] + v;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (d[j] - d[i - 1] <= m) {
				++cnt;
			} else {
				break;
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}