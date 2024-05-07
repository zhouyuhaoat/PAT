/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 18:52:44
 *	modified:	2023-03-29 19:15:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

bool isMirror = false;
vector<int> pre, post;

void posttra(int r, int e) {
	if (r > e) {
		return;
	}
	int i = r + 1, j = e;
	if (!isMirror) {
		while (i <= e && pre[i] < pre[r]) {
			++i;
		}
		while (j > r && pre[j] >= pre[r]) {
			--j;
		}
	} else {
		while (i <= e && pre[i] >= pre[r]) {
			++i;
		}
		while (j > r && pre[j] < pre[r]) {
			--j;
		}
	}
	if (i - j != 1) {
		return;
	}
	posttra(r + 1, j);
	posttra(i, e);
	post.emplace_back(pre[r]);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	posttra(0, n - 1);
	if ((int)post.size() != n) {
		isMirror = true;
		post.clear();
		posttra(0, n - 1);
	}
	if ((int)post.size() == n) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << post[i];
			i < n - 1 ? cout << " " : cout << "\n";
		}
	} else {
		cout << "NO\n";
	}

	return 0;
}