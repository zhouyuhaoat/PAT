/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 21:39:33
 *	modified:	2023-03-28 22:01:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> post, in, level;

node *create(int pl, int pr, int il, int ir) {
	if (pl > pr) {
		return nullptr;
	}
	node *r = new node{post[pr]};
	int i = find(in.begin(), in.end(), post[pr]) - in.begin();
	r->lc = create(pl, pl + (i - il) - 1, il, i - 1);
	r->rc = create(pl + (i - il), pr - 1, i + 1, ir);
	return r;
}

void bfs(node *r) {
	queue<node *> q;
	q.emplace(r);
	while (!q.empty()) {
		node *t = q.front();
		q.pop();
		level.emplace_back(t->v);
		if (t->lc != nullptr) {
			q.emplace(t->lc);
		}
		if (t->rc != nullptr) {
			q.emplace(t->rc);
		}
	}
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
	node *r = create(0, n - 1, 0, n - 1);
	bfs(r);
	for (int i = 0; i < n; i++) {
		cout << level[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}