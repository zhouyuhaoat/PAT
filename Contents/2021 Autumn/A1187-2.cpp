/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:48:13
 *	modified:	2023-04-13 22:55:09
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int key, pri;
	node *lc, *rc;
};

vector<node> t, level;

node *create(node *r, int i) {
	if (r == nullptr) {
		r = new node{t[i].key, t[i].pri, nullptr, nullptr};
		return r;
	}
	if (r->key > t[i].key) {
		r->lc = create(r->lc, i);
	} else {
		r->rc = create(r->rc, i);
	}
	return r;
}

void leveltra(node *r) {
	queue<node> q;
	q.emplace(*r);
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		level.emplace_back(t);
		if (t.lc != nullptr) {
			q.emplace(*t.lc);
		}
		if (t.rc != nullptr) {
			q.emplace(*t.rc);
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> t[i + 1].key >> t[i + 1].pri;
	}
	sort(t.begin() + 1, t.end(), [](node a, node b) {
		return a.pri < b.pri;
	});
	node *r = nullptr;
	for (int i = 1; i <= n; i++) {
		r = create(r, i);
	}
	leveltra(r);
	for (int i = 0; i < (int)level.size(); i++) {
		cout << level[i].key;
		i < (int)level.size() - 1 ? cout << " " : cout << "\n";
	}
	for (int i = 0; i < (int)level.size(); i++) {
		cout << level[i].pri;
		i < (int)level.size() - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}