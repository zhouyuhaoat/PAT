/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 23:17:36
 *	modified:	2024-05-16 23:24:27
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	priority_queue<int, vector<int>, greater<int>> q1, q2;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (i < m) {
			q1.emplace(d[i]);
		}
	}
	int idx = m;
	while (!q1.empty()) {
		int t = q1.top();
		q1.pop();
		cout << t;
		if (idx < n) {
			if (d[idx] < t) {
				q2.emplace(d[idx]);
			} else {
				q1.emplace(d[idx]);
			}
			++idx;
		}
		if (!q1.empty()) {
			cout << " ";
		} else {
			swap(q1, q2);
			cout << "\n";
		}
	}

	return 0;
}