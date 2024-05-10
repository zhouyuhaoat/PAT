/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:14:51
 *	modified:	2023-03-29 18:48:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> d, dpre, dpreMirror, dpost, dpostMirror;

void insert(node *&r, int v) {
	if (r == nullptr) {
		r = new node{v, nullptr, nullptr};
		return;
	}
	if (v < r->v) {
		insert(r->lc, v);
	} else {
		insert(r->rc, v);
	}
}

void pre(node *r, vector<int> &d) {
	if (r == nullptr) {
		return;
	}
	d.emplace_back(r->v);
	pre(r->lc, d);
	pre(r->rc, d);
}

void preMirror(node *r, vector<int> &d) {
	if (r == nullptr) {
		return;
	}
	d.emplace_back(r->v);
	preMirror(r->rc, d);
	preMirror(r->lc, d);
}

void post(node *r, vector<int> &d) {
	if (r == nullptr) {
		return;
	}
	post(r->lc, d);
	post(r->rc, d);
	d.emplace_back(r->v);
}

void postMirror(node *r, vector<int> &d) {
	if (r == nullptr) {
		return;
	}
	postMirror(r->rc, d);
	postMirror(r->lc, d);
	d.emplace_back(r->v);
}

void print(vector<int> d) {
	for (int i = 0; i < (int)d.size(); i++) {
		cout << d[i];
		i < (int)d.size() - 1 ? cout << " " : cout << "\n";
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	node *r = nullptr;
	d.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		insert(r, d[i]);
	}
	pre(r, dpre), preMirror(r, dpreMirror);
	post(r, dpost), postMirror(r, dpostMirror);
	if (d == dpre) {
		cout << "YES\n";
		print(dpost);
	} else if (d == dpreMirror) {
		cout << "YES\n";
		print(dpostMirror);
	} else {
		cout << "NO\n";
	}

	return 0;
}