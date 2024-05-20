/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:24:58
 *	modified:	2023-04-05 23:55:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	int v, i, l;
	node *lc, *rc;
};

vector<int> in, temp;
map<int, int> loc;
vector<node> ans;

node *create(node *root, int l, int r, int i, int h) {
	if (l > r) {
		return nullptr;
	}
	temp.assign(in.begin() + l, in.begin() + r + 1);
	sort(temp.begin(), temp.end());
	root = new node{temp[0], i, h, nullptr, nullptr};
	int m = loc[temp[0]];
	root->lc = create(root->lc, l, m - 1, 2 * i + 1, h + 1);
	root->rc = create(root->rc, m + 1, r, 2 * i + 2, h + 1);
	ans.emplace_back(*root);
	return root;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		loc[in[i]] = i;
	}
	create(nullptr, 0, n - 1, 0, 1);
	sort(ans.begin(), ans.end(), [](node a, node b) {
		if (a.l != b.l) {
			return a.l < b.l;
		} else {
			return a.i < b.i;
		}
	});
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].v;
		i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}