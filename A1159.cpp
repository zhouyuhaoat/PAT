/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 13:46:25
 *	modified:	2023-04-05 14:16:38
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	int v, i, l;
	node *lc, *rc;
};

vector<int> post;
map<int, int> loc;
map<int, node *> t;
bool isfbt = true;

node *create(node *root, int r, int s, int e, int i, int l) {
	if (s > e) {
		return nullptr;
	}
	root = new node{post[r], i, l, nullptr, nullptr};
	int mi = loc[post[r]];
	root->lc = create(root->lc, r - (e - mi) - 1, s, mi - 1, 2 * i, l + 1);
	root->rc = create(root->rc, r - 1, mi + 1, e, 2 * i + 1, l + 1);
	t[root->v] = root;
	if ((root->lc == nullptr && root->rc != nullptr) || (root->lc != nullptr && root->rc == nullptr)) {
		isfbt = false;
	}
	return root;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	post.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		loc[v] = i;
	}
	create(nullptr, n - 1, 0, n - 1, 1, 1);
	int m;
	cin >> m;
	getchar();
	for (int q = 0; q < m; q++) {
		string s;
		getline(cin, s);
		bool flag = false;
		if (s.find("root") != string::npos) {
			int r;
			sscanf(s.c_str(), "%d is the root", &r);
			if (t[r]->i == 1) {
				flag = true;
			}
		} else if (s.find("siblings") != string::npos) {
			int u, v;
			sscanf(s.c_str(), "%d and %d are siblings", &u, &v);
			if (t[u]->i / 2 == t[v]->i / 2) {
				flag = true;
			}
		} else if (s.find("parent") != string::npos) {
			int pa, ch;
			sscanf(s.c_str(), "%d is the parent of %d", &pa, &ch);
			if (t[ch]->i / 2 == t[pa]->i) {
				flag = true;
			}
		} else if (s.find("left") != string::npos) {
			int lc, pa;
			sscanf(s.c_str(), "%d is the left child of %d", &lc, &pa);
			if (t[lc]->i == t[pa]->i * 2) {
				flag = true;
			}
		} else if (s.find("right") != string::npos) {
			int rc, pa;
			sscanf(s.c_str(), "%d is the right child of %d", &rc, &pa);
			if (t[rc]->i == t[pa]->i * 2 + 1) {
				flag = true;
			}
		} else if (s.find("level") != string::npos) {
			int u, v;
			sscanf(s.c_str(), "%d and %d are on the same level", &u, &v);
			if (t[u]->l == t[v]->l) {
				flag = true;
			}
		} else if (s.find("full") != string::npos) {
			if (isfbt) {
				flag = true;
			}
		}
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}