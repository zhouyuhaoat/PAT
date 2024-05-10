/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 20:56:35
 *	modified:	2023-04-12 21:54:11
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <cmath>
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
	int col = 0, row = 0;
	for (int i = sqrt(n); i >= 1; i--) {
		if (n % i == 0) {
			col = i;
			row = n / i;
			break;
		}
	}
	vector<vector<int>> ans(row, vector<int>(col));
	int run = 0, loc = 0;
	while (loc < n) {
		int x = run, y = run;
		for (int i = 0; i < col; i++) {
			ans[x][y++] = d[loc++];
		}
		if (loc >= n) {
			break;
		}
		--y, ++x;
		for (int i = 0; i < row - 1; i++) {
			ans[x++][y] = d[loc++];
		}
		if (loc >= n) {
			break;
		}
		--x, --y;
		for (int i = 0; i < col - 1; i++) {
			ans[x][y--] = d[loc++];
		}
		if (loc >= n) {
			break;
		}
		++y, --x;
		for (int i = 0; i < row - 2; i++) {
			ans[x--][y] = d[loc++];
		}
		row -= 2, col -= 2, run++;
	}
	for (int i = 0; i < (int)ans.size(); i++) {
		for (int j = 0; j < (int)ans[i].size(); j++) {
			cout << ans[i][j];
			j < (int)ans[i].size() - 1 ? cout << " " : cout << "\n";
		}
	}

	return 0;
}