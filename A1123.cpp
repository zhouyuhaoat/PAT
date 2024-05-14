/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:25:52
 *	modified:	2023-04-03 02:44:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v, l, i, h;
	node *lc, *rc;
};

int geth(node *r) {
	return r == nullptr ? 0 : r->h;
}

void updateh(node *r) {
	r->h = max(geth(r->lc), geth(r->rc)) + 1;
}

int getbf(node *r) {
	return geth(r->lc) - geth(r->rc);
}

node *connect34(node *a, node *b, node *c, node *t0, node *t1, node *t2, node *t3) {
	a->lc = t0, a->rc = t1, updateh(a);
	c->lc = t2, c->rc = t3, updateh(c);
	b->lc = a, b->rc = c, updateh(b);
	return b;
}

void insert(node *&r, int v) {
	if (r == nullptr) {
		r = new node{v, 0, 0, 1, nullptr, nullptr};
		return;
	}
	if (v < r->v) {
		insert(r->lc, v), updateh(r);
		if (getbf(r) == 2) {
			if (getbf(r->lc) == 1) {
				r = connect34(r->lc->lc, r->lc, r, r->lc->lc->lc, r->lc->lc->rc, r->lc->rc, r->rc);
			} else if (getbf(r->lc) == -1) {
				r = connect34(r->lc, r->lc->rc, r, r->lc->lc, r->lc->rc->lc, r->lc->rc->rc, r->rc);
			}
		}
	} else {
		insert(r->rc, v), updateh(r);
		if (getbf(r) == -2) {
			if (getbf(r->rc) == 1) {
				r = connect34(r, r->rc->lc, r->rc, r->lc, r->rc->lc->lc, r->rc->lc->rc, r->rc->rc);
			} else if (getbf(r->rc) == -1) {
				r = connect34(r, r->rc, r->rc->rc, r->lc, r->rc->lc, r->rc->rc->lc, r->rc->rc->rc);
			}
		}
	}
}

vector<node> ans;
void dfs(node *r, int l, int i) {
	if (r == nullptr) {
		return;
	}
	r->l = l, r->i = i;
	ans.emplace_back(*r);
	dfs(r->lc, l + 1, 2 * i + 1);
	dfs(r->rc, l + 1, 2 * i + 2);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	node *r = nullptr;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		insert(r, v);
	}
	dfs(r, 1, 0);
	sort(ans.begin(), ans.end(), [](node a, node b) {
		if (a.l != b.l) {
			return a.l < b.l;
		} else {
			return a.i < b.i;
		}
	});
	for (int i = 0; i < n; i++) {
		cout << ans[i].v;
		i < n - 1 ? cout << " " : cout << "\n";
	}
	ans[n - 1].i == n - 1 ? cout << "YES\n" : cout << "NO\n";

	return 0;
}