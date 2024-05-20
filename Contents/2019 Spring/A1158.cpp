/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 16:15:13
 *	modified:	2023-04-05 16:33:33
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <map>
#include <numeric>
#include <set>
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
		if (fa < fb) {
			swap(fa, fb);
		}
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int k, n, m;
	cin >> k >> n >> m;
	vector<vector<int>> dur(n + 1, vector<int>(n + 1));
	vector<vector<int>> d(m, vector<int>(3));
	for (int i = 0; i < m; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
		dur[d[i][0]][d[i][1]] += d[i][2];
	}
	vector<set<int>> rec(n + 1);
	for (int i = 0; i < m; i++) {
		if (dur[d[i][0]][d[i][1]] <= 5) {
			rec[d[i][0]].emplace(d[i][1]);
		}
	}
	vector<int> sus;
	for (int i = 1; i <= n; i++) {
		if ((int)rec[i].size() > k) {
			int cb = 0;
			for (auto it : rec[i]) {
				if (dur[it][i] > 0) {
					++cb;
				}
			}
			if ((double)cb / rec[i].size() <= 0.2) {
				sus.emplace_back(i);
			}
		}
	}
	if (sus.empty()) {
		cout << "None\n";
	} else {
		f.resize(n + 1);
		iota(f.begin(), f.end(), 0);
		for (auto it : sus) {
			for (auto is : sus) {
				if (it != is) {
					if (dur[it][is] > 0 && dur[is][it] > 0) {
						joint(it, is);
					}
				}
			}
		}
		map<int, vector<int>> gang;
		for (auto it : sus) {
			gang[find(it)].emplace_back(it);
		}
		for (auto it : gang) {
			int size = it.second.size();
			for (auto is : it.second) {
				cout << is;
				--size > 0 ? cout << " " : cout << "\n";
			}
		}
	}

	return 0;
}