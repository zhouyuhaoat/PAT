/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:39:04
 *	modified:	2023-03-29 21:05:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int v, l, i;
	int lc, rc;
};

vector<node> t;
vector<int> in, ans;
int n, front = 0;

void intra(int r, int l, int i) {
	if (r == -1 || r >= n) {
		return;
	}
	intra(t[r].lc, l + 1, 2 * i + 1);
	t[r].v = in[front++], t[r].l = l, t[r].i = i;
	intra(t[r].rc, l + 1, 2 * i + 2);
}

void bfs(int r) {
	queue<int> q;
	q.emplace(r);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.emplace_back(t[now].v);
		if (t[now].lc != -1) {
			q.emplace(t[now].lc);
		}
		if (t[now].rc != -1) {
			q.emplace(t[now].rc);
		}
	}
}

int main(int argc, char const *argv[]) {

	cin >> n;
	t.resize(n);
	vector<bool> isroot(n, true);
	for (int i = 0; i < n; i++) {
		cin >> t[i].lc >> t[i].rc;
		if (t[i].lc != -1) {
			isroot[t[i].lc] = false;
		}
		if (t[i].rc != -1) {
			isroot[t[i].rc] = false;
		}
	}
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	intra(r, 1, 0);
	bfs(r);
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}