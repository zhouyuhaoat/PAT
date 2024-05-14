/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 18:39:17
 *	modified:	2023-04-03 18:47:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct node {
	int dis, num;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int dis;
		cin >> dis;
		++cnt[dis];
	}
	vector<node> d;
	for (auto it : cnt) {
		d.emplace_back(node{it.first, it.second});
	}
	int sum = 0;
	priority_queue<int, vector<int>, less<int>> q;
	for (int i = 0; i < (int)d.size(); i++) {
		sum += d[i].num;
		if (n - sum >= d[i].dis) {
			q.emplace(d[i].dis);
		} else {
			sum -= d[i].num;
			if (i > 0) {
				for (int j = d[i - 1].dis + 1; j < d[i].dis; j++) {
					if (n - sum >= j) {
						q.emplace(j);
					}
				}
			} else {
				for (int j = 0; j < d[i].dis; j++) {
					if (n - sum >= j) {
						q.emplace(j);
					}
				}
			}
			break;
		}
	}
	cout << q.top() << "\n";

	return 0;
}