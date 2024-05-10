/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 12:57:40
 *	modified:	2023-03-27 13:14:02
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
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < n; i++) {
		int j = lower_bound(d.begin(), d.end(), m - d[i]) - d.begin();
		if (d[i] + d[j] == m && i != j) {
			cout << d[i] << " " << d[j] << "\n";
			return 0;
		}
	}
	cout << "No Solution\n";

	return 0;
}