/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 22:37:25
 *	modified:	2023-03-29 23:36:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

vector<int> f;

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
	f.resize(n + 1);
	iota(f.begin(), f.end(), 0);
	map<int, int> h;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		getchar();
		for (int j = 0; j < k; j++) {
			int id;
			cin >> id;
			if (h[id] == 0) {
				h[id] = i + 1;
			}
			joint(i + 1, h[id]);
		}
	}
	map<int, int> c;
	for (int i = 1; i <= n; i++) {
		++c[find(i)];
	}
	vector<int> clu(c.size());
	transform(c.begin(), c.end(), clu.begin(), [](pair<int, int> p) -> int {
		return p.second;
	});
	sort(clu.begin(), clu.end(), greater<int>());
	cout << clu.size() << "\n";
	for (int i = 0; i < (int)clu.size(); i++) {
		cout << clu[i];
		i < (int)clu.size() - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}