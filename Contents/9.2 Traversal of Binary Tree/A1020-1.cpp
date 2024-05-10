/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 17:21:19
 *	modified:	2023-03-28 21:38:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v, i;
	node(int v, int i) : v(v), i(i) {
	}
};

vector<int> post, in;
vector<node> level;

void pretra(int r, int s, int e, int i) {
	if (s > e) {
		return;
	}
	level.emplace_back(post[r], i);
	int j = find(in.begin(), in.end(), post[r]) - in.begin();
	pretra(r - (e - j) - 1, s, j - 1, 2 * i);
	pretra(r - 1, j + 1, e, 2 * i + 1);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	post.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	pretra(n - 1, 0, n - 1, 1);
	sort(level.begin(), level.end(), [](node a, node b) -> bool {
		return a.i < b.i;
	});
	for (int i = 0; i < n; i++) {
		cout << level[i].v;
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}