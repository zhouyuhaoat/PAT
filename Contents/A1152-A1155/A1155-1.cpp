/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 21:01:12
 *	modified:	2023-04-04 21:34:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> t, path;

void dfs(int r, int n) {
	if (2 * r + 1 >= n && 2 * r + 1 >= n) {
		path.emplace_back(t[r]);
		for (int i = 0; i < (int)path.size(); i++) {
			cout << path[i];
			i < (int)path.size() - 1 ? cout << " " : cout << "\n";
		}
		path.pop_back();
		return;
	}
	if (2 * r + 2 < n) {
		path.emplace_back(t[r]);
		dfs(2 * r + 2, n);
		path.pop_back();
	}
	if (2 * r + 1 < n) {
		path.emplace_back(t[r]);
		dfs(2 * r + 1, n);
		path.pop_back();
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	dfs(0, n);
	bool ismax = true, ismin = true;
	if (t[0] > t[1]) {
		for (int i = 0; i < n / 2; i++) {
			if (2 * i + 1 < n && t[2 * i + 1] > t[i]) {
				ismax = false;
				break;
			}
			if (2 * i + 2 < n && t[2 * i + 2] > t[i]) {
				ismax = false;
				break;
			}
		}
		if (ismax) {
			cout << "Max Heap\n";
		}
	} else {
		for (int i = 0; i < n / 2; i++) {
			if (2 * i + 1 < n && t[2 * i + 1] < t[i]) {
				ismin = false;
				break;
			}
			if (2 * i + 2 < n && t[2 * i + 2] < t[i]) {
				ismin = false;
				break;
			}
		}
		if (ismin) {
			cout << "Min Heap\n";
		}
	}
	if (!(ismax && ismin)) {
		cout << "Not Heap\n";
	}

	return 0;
}