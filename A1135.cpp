/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 00:44:58
 *	modified:	2023-04-04 09:09:25
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct node {
	int v, bh;
	node *lc, *rc;
};

vector<int> pre, in;

int getbh(node *r) {
	return r == nullptr ? 0 : r->bh;
}

void updatebh(node *r) {
	r->bh = max(getbh(r->lc), getbh(r->rc));
	if (r->v > 0) {
		++r->bh;
	}
}

node *create(int r, int s, int e) {
	if (s > e) {
		return nullptr;
	}
	node *root = new node;
	root->v = pre[r];
	if (root->v > 0) {
		root->bh = 1;
	}
	int i = find(in.begin(), in.end(), pre[r]) - in.begin();
	root->lc = create(r + 1, s, i - 1);
	root->rc = create(r + i - s + 1, i + 1, e);
	updatebh(root);
	return root;
}

void dfs(node *root, bool &flag) {
	if (root->v < 0) {
		if (root->lc != nullptr && root->lc->v < 0) {
			flag = false;
			return;
		}
		if (root->rc != nullptr && root->rc->v < 0) {
			flag = false;
			return;
		}
	}
	if (getbh(root->lc) != getbh(root->rc)) {
		flag = false;
		return;
	}
	if (root->lc == nullptr && root->rc == nullptr) {
		return;
	}
	if (root->lc != nullptr) {
		dfs(root->lc, flag);
	}
	if (root->rc != nullptr) {
		dfs(root->rc, flag);
	}
}

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int n;
		cin >> n;
		pre.resize(n), in.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
			in[i] = pre[i];
		}
		if (pre[0] < 0) {
			cout << "No\n";
			continue;
		}
		sort(in.begin(), in.end(), [](int a, int b) {
			return abs(a) < abs(b);
		});
		node *root = create(0, 0, n - 1);
		bool flag = true;
		dfs(root, flag);
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}