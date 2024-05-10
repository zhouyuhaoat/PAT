/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:20:41
 *	modified:	2023-03-28 22:52:16
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v, id;
	int lc, rc;
};

vector<node> d;
vector<int> in;

void intra(int r, int i) {
	if (d[r].rc != -1) {
		intra(d[r].rc, 2 * i);
	}
	d[r].id = i;
	in.emplace_back(r);
	if (d[r].lc != -1) {
		intra(d[r].lc, 2 * i + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	d.resize(n);
	vector<bool> isroot(n, true);
	for (int i = 0; i < n; i++) {
		d[i].v = i;
		char c;
		cin >> c;
		if (isdigit(c)) {
			d[i].lc = c - '0';
			isroot[d[i].lc] = false;
		} else {
			d[i].lc = -1;
		}
		cin >> c;
		if (isdigit(c)) {
			d[i].rc = c - '0';
			isroot[d[i].rc] = false;
		} else {
			d[i].rc = -1;
		}
	}
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	intra(r, 1);
	sort(d.begin(), d.end(), [](node a, node b) -> bool {
		return a.id < b.id;
	});
	for (int i = 0; i < n; i++) {
		cout << d[i].v;
		i < n - 1 ? cout << " " : cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		cout << in[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}