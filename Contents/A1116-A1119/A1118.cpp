/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:40:19
 *	modified:	2023-04-03 00:50:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

vector<int> f(1e4 + 1);

int find(int x) {
	int a = x;
	while (x != f[x]) {
		x = f[x];
	}
	while (a != f[a]) {
		int z = a;
		a = f[a], f[z] = x;
	}
	return x;
}

void joint(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa != fb) {
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	set<int> b;
	iota(f.begin(), f.end(), 0);
	for (int i = 0; i < n; i++) {
		int k, b1;
		cin >> k >> b1;
		b.emplace(b1);
		for (int j = 1; j < k; j++) {
			int b2;
			cin >> b2;
			joint(b1, b2);
			b.emplace(b2);
		}
	}
	set<int> t;
	for (auto it : b) {
		t.emplace(find(it));
	}
	cout << t.size() << " " << b.size() << "\n";
	int q;
	cin >> q;
	for (int qq = 0; qq < q; qq++) {
		int b1, b2;
		cin >> b1 >> b2;
		if (find(b1) == find(b2)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}