/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 15:22:47
 *	modified:	2023-04-04 15:56:06
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> t, post;

void dfsmax(int r, int n, bool &flag) {
	if (r >= n) {
		return;
	}
	if (2 * r + 1 < n && t[r] < t[2 * r + 1]) {
		flag = false;
	}
	if (2 * r + 2 < n && t[r] < t[2 * r + 2]) {
		flag = false;
	}
	dfsmax(2 * r + 1, n, flag);
	dfsmax(2 * r + 2, n, flag);
	post.emplace_back(t[r]);
}

void dfsmin(int r, int n, bool &flag) {
	if (r >= n) {
		return;
	}
	if (2 * r + 1 < n && t[r] > t[2 * r + 1]) {
		flag = false;
	}
	if (2 * r + 2 < n && t[r] > t[2 * r + 2]) {
		flag = false;
	}
	dfsmin(2 * r + 1, n, flag);
	dfsmin(2 * r + 2, n, flag);
	post.emplace_back(t[r]);
}

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	t.resize(n);
	for (int q = 0; q < m; q++) {
		for (int i = 0; i < n; i++) {
			cin >> t[i];
		}
		bool ismax = true, ismin = true;
		if (t[0] > t[1]) {
			dfsmax(0, n, ismax);
			if (ismax) {
				cout << "Max Heap\n";
			}
		} else {
			dfsmin(0, n, ismin);
			if (ismin) {
				cout << "Min Heap\n";
			}
		}
		if (!ismin || !ismax) {
			cout << "Not Heap\n";
		}
		for (int i = 0; i < n; i++) {
			cout << post[i];
			i < n - 1 ? cout << " " : cout << "\n";
		}
		post.clear();
	}

	return 0;
}