/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 16:16:37
 *	modified:	2023-04-04 17:03:46
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

bool islie(int d, int i, int j) {
	if (d > 0) {
		return d == i || d == j;
	} else {
		return abs(d) != i && abs(d) != j;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> d[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int wolflie = 0;
			if (islie(d[i], i, j)) {
				++wolflie;
			}
			if (islie(d[j], i, j)) {
				++wolflie;
			}
			int lie = 0;
			for (int k = 1; k <= n; k++) {
				if (islie(d[k], i, j)) {
					++lie;
				}
			}
			if (wolflie == 1 && lie == 2) {
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}
	cout << "No Solution\n";

	return 0;
}