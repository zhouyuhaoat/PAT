/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 17:29:05
 *	modified:	2023-04-04 18:22:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		d[a][b] = d[b][a] = dist;
	}
	int k;
	cin >> k;
	int minid = -1, mindist = INT_MAX;
	for (int q = 0; q < k; q++) {
		set<int> path;
		int nv, st;
		cin >> nv >> st;
		int lastid = st, en, dist = 0;
		bool isarr = true;
		for (int i = 1; i < nv; i++) {
			cin >> en;
			dist += d[lastid][en];
			if (d[lastid][en] == 0) {
				isarr = false;
			}
			path.emplace(en);
			lastid = en;
		}
		bool issic = false, iscyc = false;
		if (st == en && isarr) {
			if (nv == n + 1 && (int)path.size() == n) {
				issic = true;
			} else if (nv > n + 1 && (int)path.size() == n) {
				iscyc = true;
			}
		}
		bool notacc = !issic && !iscyc;
		cout << "Path " << q + 1 << ": ";
		if (isarr) {
			cout << dist;
			if (!notacc && dist < mindist) {
				mindist = dist;
				minid = q + 1;
			}
		} else {
			cout << "NA";
		}
		if (issic) {
			cout << " (TS simple cycle)\n";
		} else if (iscyc) {
			cout << " (TS cycle)\n";
		} else {
			cout << " (Not a TS cycle)\n";
		}
	}
	cout << "Shortest Dist(" << minid << ") = " << mindist << "\n";

	return 0;
}