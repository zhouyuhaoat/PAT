/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:14:12
 *	modified:	2023-03-28 22:18:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> pre, in, ans;

node *create(int r, int s, int e) {
	if (s > e) {
		return nullptr;
	}
	int i = find(in.begin(), in.end(), pre[r]) - in.begin();
	node *root = new node;
	root->lc = create(r + 1, s, i - 1);
	root->rc = create(r + (i - s) + 1, i + 1, e);
	root->v = pre[r];
	return root;
}

void posttra(node *r) {
	if (r->lc != nullptr) {
		posttra(r->lc);
	}
	if (r->rc != nullptr) {
		posttra(r->rc);
	}
	ans.emplace_back(r->v);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
		string ss;
		cin >> ss;
		if (ss.size() == 4) {
			int num;
			cin >> num;
			s.emplace(num);
			pre.emplace_back(num);
		} else {
			in.emplace_back(s.top());
			s.pop();
		}
	}
	node *r = create(0, 0, n - 1);
	posttra(r);
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}